#include <stdio.h>
#include <math.h>

#include "system.h"
#include "common.h"
#include "ringbuf.h"

#include "altera_avalon_mutex.h"
#include "altera_avalon_fifo_util.h"

#define MEASURE_PERFORMANCE
#ifdef MEASURE_PERFORMANCE
#include "altera_avalon_performance_counter.h"
#endif

uint32_t *width = (uint32_t *)MAT_WIDTH_ADDR;
uint32_t *height = (uint32_t *)MAT_HEIGHT_ADDR;
int16_t *c_x = (int16_t *)MAT_X_COEFF_ADDR;
int16_t *c_y = (int16_t *)MAT_Y_COEFF_ADDR;
int16_t *matrix1 = (int16_t*)MAT_BUF1_ADDR;
int16_t *matrix2 = (int16_t *)MAT_BUF2_ADDR;
uint16_t *nr_heat_src = (uint16_t *)MAT_NR_HEAT_SRC_ADDR;
heat_src_t *heat_srcs = (heat_src_t *)MAT_HEAT_SOURCES_ADDR;

alt_mutex_dev* mutex;

int main()
{
	item_t item = { { 0 } };
	uint8_t retval;

	uint32_t assigned = 0;
	uint32_t processing = 0;

	uint32_t matrix_size;
	uint32_t iter = 0;

	uint32_t msg;

	FILE *fd;
	char fout[64];
	char src[64];
	char tmp[64];

	int32_t input_mat = MAT_BUF1_ADDR;
	int32_t output_mat = MAT_BUF2_ADDR;

	// initialize mutex
	mutex = altera_avalon_mutex_open(MUTEX_NAME);

	// initialize fifo
	altera_avalon_fifo_init(ACK_FIFO_OUT_CSR_BASE, 0, 2, 12);

	// initialize ringbuffer
	ringbuf_init(1);

	while (1)
	{
#ifdef MEASURE_PERFORMANCE
		PERF_RESET(PCU_BASE);

    	PERF_START_MEASURING(PCU_BASE);
#endif /* MEASURE_PERFORMANCE */

		printf("PROGRAM START\n");

		printf("Enter matrix width ");
		scanf("%lu", width);
		printf("Enter matrix height ");
		scanf("%lu", height);
		printf("Enter sources file name ");
		scanf("%s", tmp);
		snprintf(src, sizeof(src), "%s/%s", ALTERA_HOSTFS_NAME, tmp);

		fd = fopen(src, "rb");
		fread(c_x, sizeof(*c_x), 1, fd);
		fread(c_y, sizeof(*c_y), 1, fd);
		fread(nr_heat_src, sizeof(*nr_heat_src), 1, fd);

		fread(heat_srcs, sizeof(heat_src_t), *nr_heat_src, fd);

		fclose(fd);

		printf("Enter output file name ");
		scanf("%s", tmp);
		snprintf(fout, sizeof(fout), "%s/%s", ALTERA_HOSTFS_NAME, tmp);
		printf("Enter number of iterations ");
		scanf("%lu", &iter);

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

		for (int it = 0; it < iter; it++)
		{
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
				if (retval != 1)
				{
					assigned++;
					processing++;
				}
			} while (retval != 1);

			altera_avalon_mutex_unlock(mutex);

	#ifdef MEASURE_PERFORMANCE
		// mark beginning of code for which we are interested in performance
			PERF_BEGIN(PCU_BASE,1);
	#endif /* MEASURE_PERFORMANCE */

			do
			{
				while(!altera_avalon_read_fifo(ACK_FIFO_OUT_BASE,
									ACK_FIFO_OUT_CSR_BASE, &msg));
				processing--;

				altera_avalon_mutex_lock(mutex, 0x5A);

				if (assigned < TOTAL_NUM_OF_TASKS)
				{
					item.id = assigned;
					item.col_start = 0;
					item.row_start = assigned * (*height / TOTAL_NUM_OF_TASKS);
					item.region_width = *width;
					item.region_height = *height / TOTAL_NUM_OF_TASKS;
					item.input_matrix = input_mat;
					//item.output_matrix = output_mat;
					assigned++;
					processing++;
				}

				altera_avalon_mutex_unlock(mutex);

			} while (processing > 0);

			int32_t swap = input_mat;
			input_mat = output_mat;
			output_mat = swap;
		}

#ifdef MEASURE_PERFORMANCE
		PERF_END(PCU_BASE,1);
#endif /* MEASURE_PERFORMANCE */

		printf("MATRIX BEGIN\n");

		fd = fopen(fout, "wb");

		fwrite(width, sizeof(uint32_t), 1, fd);
		fwrite(height, sizeof(uint32_t), 1, fd);
		if (output_mat == MAT_BUF1_ADDR)
		{
			fwrite(matrix1,sizeof(uint16_t),matrix_size,fd);
		}
		else
		{
			fwrite(matrix2,sizeof(uint16_t),matrix_size,fd);
		}
		fflush(fd);

		fclose(fd);

		printf("MATRIX END\n");

		printf("PERF BEGIN\n");
#ifdef MEASURE_PERFORMANCE
		PERF_STOP_MEASURING(PCU_BASE);

		perf_print_formatted_report((void *)PCU_BASE,
									alt_get_cpu_freq(),
									PCU_HOW_MANY_SECTIONS);
#endif /* MEASURE_PERFORMANCE */
		printf("PERF END\n");
	}
}
