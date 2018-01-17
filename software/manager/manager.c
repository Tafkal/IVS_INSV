/**
 * @file manager.c
 * @brief Programing code for the main processor
 *
 * The manager is a processor with the following tasks:
 * 	- reading of the matrices parameters and the heat sources values
 * 	and positions from the computer
 * 	- initializing two matrices in SDRAM for heat transfer calculation
 *	- organization of the task division between workers in the On-Chip memory;
 *	the task must contain the information of the region that the worker must
 *	process and the information from which matrix to read the elements, ie.
 *	to which matrix to store the new elements
 *	- sending the calculated heat transfer map to the computer
 *
 * @date 2018
 * @authors Ivana Nikolic, Stefan Vukcevic
 */

/* Standard includes */
#include <stdio.h>
#include <math.h>

/* Hardware includes */
#include "system.h"
#include "altera_avalon_mutex.h"
#include "altera_avalon_fifo_util.h"

/* Software includes */
#include "common.h"
#include "ringbuf.h"

/* To measure the speed of the system for different number of workers,
 * leave this define uncommented
 */
#define MEASURE_PERFORMANCE

/* Necessary include for performance measurement */
#ifdef MEASURE_PERFORMANCE
#include "altera_avalon_performance_counter.h"
#endif

/* pointers to memory locations where
 * the matrix dimensions will be stored
 */
uint32_t *width = (uint32_t *)MAT_WIDTH_ADDR;
uint32_t *height = (uint32_t *)MAT_HEIGHT_ADDR;

/* pointers to memory locations where the
 * heat transfer coefficients will be stored
 */
int16_t *c_x = (int16_t *)MAT_X_COEFF_ADDR;
int16_t *c_y = (int16_t *)MAT_Y_COEFF_ADDR;

/* pointers to memory locations where the two matrices
 * are stored; the matrices represent the transfer in 2D area
 */
int16_t *matrix1 = (int16_t*)MAT_BUF1_ADDR;
int16_t *matrix2 = (int16_t *)MAT_BUF2_ADDR;

/* pointers to memory locations where the number of
 * heat sources and the heat sources are stored;
 */
uint16_t *nr_heat_src = (uint16_t *)MAT_NR_HEAT_SRC_ADDR;
heat_src_t *heat_srcs = (heat_src_t *)MAT_HEAT_SOURCES_ADDR;

/* mutex for the synchronization of the processors */
alt_mutex_dev* mutex;

/**
 * @brief Function that implements the manager's tasks.
 */
int main()
{
	/* variable necessarry to pack all the information
	 * the manager has to send to the workers;
	 * it represents a task for one worker
	 */
	item_t item = { { 0 } };

	/* return value of the ringbuf_enqueue function
	 * necessarry for new task generation
	 */
	uint8_t retval;

	/* variables that tracks the generation
	 * and completition of the tasks
	 */
	uint32_t assigned = 0;
	uint32_t processing = 0;

	/* the number of matrix elements */
	uint32_t matrix_size;

	/* the number of iteration for heat transfer calculation */
	uint32_t iter = 0;

	/* variable necessarry to store the acknowledment
	 * from the worker
	 */
	uint32_t msg;

	/* pointer to a .bin file */
	FILE *p_file;

	/* .bin file name containing the heat sources */
	char src[64];

	/* .bin file name to which the final heat
	 * transfer map will be writen
	 */
	char fout[64];

	/* temporary variable for saving used .bin file names */
	char tmp[64];

	/* varibles that indicate from which matrix is currently
	 * being read, and to which one is currently being writen
	 */
	int32_t input_mat = MAT_BUF1_ADDR;
	int32_t output_mat = MAT_BUF2_ADDR;

	// mutex initialization
	mutex = altera_avalon_mutex_open(MUTEX_NAME);

	// fifo initialization
	altera_avalon_fifo_init(ACK_FIFO_OUT_CSR_BASE, 0, 2, 12);

	// ringbuffer initialization
	ringbuf_init(1);

	while (1)
	{
// setup the performance counter unit
#ifdef MEASURE_PERFORMANCE
		PERF_RESET(PCU_BASE);

    	PERF_START_MEASURING(PCU_BASE);
#endif /* MEASURE_PERFORMANCE */

		printf("PROGRAM START\n");

		// ask the user to write the matrix dimensions
		printf("Enter matrix width ");
		scanf("%lu", width);
		printf("Enter matrix height ");
		scanf("%lu", height);

		// ask the user to write the .bin file name
		// for the heat sources
		printf("Enter sources file name ");
		scanf("%s", tmp);
		snprintf(src, sizeof(src), "%s/%s", ALTERA_HOSTFS_NAME, tmp);

		// atach a pointer to a file
		p_file = fopen(src, "rb");

		// read the heat transfer coefficients and the number
		// of heat sources
		fread(c_x, sizeof(*c_x), 1, p_file);
		fread(c_y, sizeof(*c_y), 1, p_file);
		fread(nr_heat_src, sizeof(*nr_heat_src), 1, p_file);

		// read the heat sources
		fread(heat_srcs, sizeof(heat_src_t), *nr_heat_src, p_file);

		// deatach the pointer from the file
		fclose(p_file);

		// ask the user to write the .bin file name
		// to which the final heat transfer map will be writen
		printf("Enter output file name ");
		scanf("%s", tmp);
		snprintf(fout, sizeof(fout), "%s/%s", ALTERA_HOSTFS_NAME, tmp);

		// ask the user to write number of iterations
		printf("Enter number of iterations ");
		scanf("%lu", &iter);

		// calucalte the number of matrix elements
		matrix_size = *width * *height;

		// initialize both matrices
		for (int it = 0; it < matrix_size; it++)
		{
			matrix1[it] = 0;
			matrix2[it] = 0;
		}

		// initialize heat sources
		for (int src = 0; src < *nr_heat_src; src++)
		{
			matrix1[heat_srcs[src].ypos * *width + heat_srcs[src].xpos] = heat_srcs[src].heat;
		}

// mark beginning of code for which we are interested in performance
#ifdef MEASURE_PERFORMANCE
		PERF_BEGIN(PCU_BASE,1);
#endif /* MEASURE_PERFORMANCE */

		// begin the heat transfer calculation
		for (int it = 0; it < iter; it++)
		{
			// assing the number of tasks that can be stored
			// into the ringbuffer; it is chosen to divide the
			// matrix into the horizontal parts
			do
			{
				item.id = assigned;
				item.col_start = 0;
				item.row_start = assigned * (*height / TOTAL_NUM_OF_TASKS);
				item.region_width = *width;
				item.region_height = *height / TOTAL_NUM_OF_TASKS;
				item.input_matrix = input_mat;
				//item.output_matrix = output_mat;

				retval = ringbuf_enqueue(&item);

				// if the ringbuffer is not full,
				// the assignement was successful
				if (retval != 1)
				{
					assigned++;
					processing++;
				}
			} while (retval != 1);

			// realase the mutex (it was given to the manager
			// by default in the .qsys files
			altera_avalon_mutex_unlock(mutex);

			// wait until all matrix is processed
			do
			{
				// wait until a task is processed
				while(!altera_avalon_read_fifo(ACK_FIFO_OUT_BASE,
									ACK_FIFO_OUT_CSR_BASE, &msg));

				// decrease the processing variable because
				// a task is finished
				processing--;

				// take the mutex
				altera_avalon_mutex_lock(mutex, 0x5A);

				// assign a new task if there are still
				// those that were not assigned
				if (assigned < TOTAL_NUM_OF_TASKS)
				{
					item.id = assigned;
					item.col_start = 0;
					item.row_start = assigned * (*height / TOTAL_NUM_OF_TASKS);
					item.region_width = *width;
					item.region_height = *height / TOTAL_NUM_OF_TASKS;
					item.input_matrix = input_mat;
					//item.output_matrix = output_mat;

					// retval is not necessarry here because we are certain
					// there is a place for a new task in the ringbuffer
					ringbuf_enqueue(&item);

					assigned++;
					processing++;
				}

				// release the mutex
				altera_avalon_mutex_unlock(mutex);

			} while (processing > 0);

			// before the new iteration starts,
			// we need to swap the matrices
			int32_t swap = input_mat;
			input_mat = output_mat;
			output_mat = swap;
		}

#ifdef MEASURE_PERFORMANCE
		PERF_END(PCU_BASE,1);
#endif /* MEASURE_PERFORMANCE */

		printf("MATRIX BEGIN\n");

		// atach a pointer to a file
		p_file = fopen(fout, "wb");

		// write the matrix dimensions
		fwrite(width, sizeof(uint32_t), 1, p_file);
		fwrite(height, sizeof(uint32_t), 1, p_file);

		// wrote the final heat transfer map based on the
		// value of the variable output_mat
		if (output_mat == MAT_BUF1_ADDR)
		{
			fwrite(matrix1,sizeof(uint16_t), matrix_size, p_file);
		}
		else
		{
			fwrite(matrix2,sizeof(uint16_t), matrix_size, p_file);
		}

		// flush the pointer
		fflush(p_file);

		// deatach the pointer from the file
		fclose(p_file);

		printf("MATRIX END\n");

		printf("PERF BEGIN\n");

// stop performance measurement and print it
#ifdef MEASURE_PERFORMANCE
		PERF_STOP_MEASURING(PCU_BASE);

		perf_print_formatted_report((void *)PCU_BASE,
									alt_get_cpu_freq(),
									PCU_HOW_MANY_SECTIONS);
#endif /* MEASURE_PERFORMANCE */

		printf("PERF END\n");
	}
}
