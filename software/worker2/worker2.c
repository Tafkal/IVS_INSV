/**
 * @file worker2.c
 * @brief Programming code for the worker processor
 *
 * All workers are processors with the following tasks:
 * 	- processing of the region assigned by the manager and placing the new
 * 	elements into the output matrix stored in SDRAM
 * 	- notifying the manager that the task is done
 *
 * @date 2018
 * @authors Ivana Nikolic, Stefan Vukcevic
 */

/* Standard includes */
#include <stdio.h>
#include <math.h>
#include <unistd.h>

/* Hardware includes */
#include "system.h"
#include "altera_avalon_mutex.h"
#include "altera_avalon_fifo_util.h"

/* Software includes */
#include "common.h"
#include "ringbuf.h"

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

/* number of integer bits for Q2.14 fixed point representation
 */
#define FP_INT		(2)

/* number of fraction bits for Q2.14 fixed point representation
 */
#define FP_FRAC		(14)

/* correction factor for Q2.14 fixed-point multiplication
 */
#define K    (1 << (FP_FRAC-1))

/* number 1.0 in Q2.14
 */
#define ONE    (1 << FP_FRAC)

/* worker's ID
 */
#define MY_ID	(2)

/* mutex for the synchronization of the processors */
alt_mutex_dev* mutex;

/**
 * @brief Function that multiplies two Q2.14 fixed-point numbers.
 * Note: Overflow isn't included since numbers are < 1
 */
int16_t _fp_mult(int16_t a, int16_t b)
{
    int16_t res;
    int32_t tmp;

    tmp = (int32_t)a * (int32_t)b; // result type is operand's type

    // rounding: mid values are rounded up
    tmp += K;

    // correct by dividing by base
    res = tmp >> FP_FRAC;

    return res;
}

/**
 * @brief Function that implements the worker's tasks.
 */
int main()
{
	/* variables that pass through the rows and columns
	 * of the assigned matrix part; the width is set to one
	 * because the most left and right columns of all task
	 * should not be changed
	 */
	int h = 0;
	int w = 1;

	/* variables that pass through the rows and columns of
	 * the input matrix calculated based on the varibles w and h
	 */
	uint32_t x, y;

	/* variable in which all the information the manager
	 * sent to the worker is packed; it represents a task
	 * for one worker
	 */
	item_t item = { { 0 } };

	/* return value of the ringbuf_dequeue function
	 * necessary for the start of the matrix part processing
	 */
	uint8_t retval;

	// mutex initialization
	mutex = altera_avalon_mutex_open(MUTEX_NAME);

	// fifo initialization
	altera_avalon_fifo_init(ACK_FIFO_IN_CSR_BASE, 0, 2, 12);

	while (1)
	{
		// worker tries to take the mutex every 1 ms
		while (altera_avalon_mutex_trylock(mutex, 0x5A) != 0)
		{
			usleep(1000); // 1 ms
		}

		// if the mutex is successfully taken, get an assignment
		retval = ringbuf_dequeue(&item);

		// release the mutex
		altera_avalon_mutex_unlock(mutex);

		// if the ringbuffer is empty, wait 100 ms until
		// the next try
		if (retval == 1)
		{
			usleep(1000000); // 100 ms
		}
		// otherwise, begin processing
		else
		{
			// if the assigned horizontal part is the top one,
			// the first row should not be processed
			if (item.id == 0)
			{
				h++;
			}
			// pass through all the rows
			while (h < item.region_height)
			{
				// if the assigned horizontal part is the bottom one,
				// the last row should not be processed
				if ((h == item.region_height - 1) && (item.id == TOTAL_NUM_OF_TASKS - 1))
				{
					break;
				}

				// pass through all the columns
				while (w < item.region_width - 1)
				{
					// calculate the exact row and column of
					// the input matrix
					x = item.col_start + w;
					y = item.row_start + h;

                    // don't update heat for sources
					uint8_t is_source = 0;

					for (int src = 0; src < *nr_heat_src; src++)
					{
						if ((heat_srcs[src].xpos == x) && (heat_srcs[src].ypos == y))
						{
							is_source = 1;
							break;
						}
					}

					// calculate the position of the element
					// to be processed
					uint32_t id = y * *width + x;

					// set the element in the output matrix based
					// on the value of item.input_matrix variable
					if (item.input_matrix == BUF_1)
					{
						matrix2[id] = matrix1[id];

						// modify the element only if it is not heat source
						if (!is_source)
						{
							// calculate the transfer across the x axis
							matrix2[id] += _fp_mult(*c_x, (matrix1[id + 1] + matrix1[id - 1] - (matrix1[id] << 1)));
							// calculate the transfer across the y axis
							matrix2[id] += _fp_mult(*c_y, (matrix1[id + *width] + matrix1[id - *width] - (matrix1[id] << 1)));
						}
					}
					else
					{
						matrix1[id] = matrix2[id];

						// modify the element only if it is not heat source
						if (!is_source)
						{
							// calculate the transfer across the x axis
							matrix1[id] += _fp_mult(*c_x, (matrix2[id + 1] + matrix2[id - 1] - (matrix2[id] << 1)));
							// calculate the transfer across the y axis
							matrix1[id] += _fp_mult(*c_y, (matrix2[id + *width] + matrix2[id - *width] - (matrix2[id] << 1)));
						}
					}
					w++;
				}
				w = 1;
				h++;
			}
			h = 0;
			// notify the manager that the task is completed
			altera_avalon_fifo_write_fifo(ACK_FIFO_IN_BASE, ACK_FIFO_IN_CSR_BASE, MY_ID);
		}
	}
}
