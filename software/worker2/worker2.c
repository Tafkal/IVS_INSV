#include <stdio.h>
#include <math.h>
#include <unistd.h>

#include "system.h"
#include "common.h"
#include "ringbuf.h"

#include "altera_avalon_mutex.h"
#include "altera_avalon_fifo_util.h"

uint32_t *width = (uint32_t *)MAT_WIDTH_ADDR;
uint32_t *height = (uint32_t *)MAT_HEIGHT_ADDR;
int16_t *c_x = (int16_t *)MAT_X_COEFF_ADDR;
int16_t *c_y = (int16_t *)MAT_Y_COEFF_ADDR;
int16_t *matrix1 = (int16_t*)MAT_BUF1_ADDR;
int16_t *matrix2 = (int16_t *)MAT_BUF2_ADDR;
uint16_t *nr_heat_src = (uint16_t *)MAT_NR_HEAT_SRC_ADDR;
heat_src_t *heat_srcs = (heat_src_t *)MAT_HEAT_SOURCES_ADDR;

/**
 * Number of integer bits for Q2.14 fixed point representation
 */
#define FP_INT		(2)

/**
 * Number of fraction bits for Q2.14 fixed point representation
 */
#define FP_FRAC		(14)

/**
 * @brief Correction factor for Q2.14 fixed-point multiplication
 */
#define K    (1 << (FP_FRAC-1))

/**
 * @brief Number 1.0 in Q2.14
 */
#define ONE    (1 << FP_FRAC)

alt_mutex_dev* mutex;
/**
 * @brief Function that multiplies two Q2.14 fixed-point numbers.
 * Note: Overflow isn't included since numbers are <1
 */
int16_t _fp_mult(int16_t a, int16_t b)
{
    int16_t res;
    int32_t tmp;

    tmp = (int32_t)a * (int32_t)b; // result type is operand's type
    // Rounding; mid values are rounded up
    tmp += K;
    // Correct by dividing by base
    res = tmp >> FP_FRAC;

    return res;
}

int main()
{
	int h = 0;
	int w = 1; // !!!!!

	uint32_t x, y;

	item_t item = { { 0 } };

	uint8_t retval = 0;

	// init mutex
	mutex = altera_avalon_mutex_open(MUTEX_NAME);

	// init fifo
	altera_avalon_fifo_init(ACK_FIFO_IN_CSR_BASE, 0, 2, 12);

	while (1)
	{
		while (altera_avalon_mutex_trylock(mutex, 0x5A) != 0)
		{
			usleep(1000); // 1 ms
		}

		retval = ringbuf_dequeue(&item);

		altera_avalon_mutex_unlock(mutex);

		if (retval == 1)
		{
			usleep(1000000); // 100 ms
		}
		else
		{
			if (item.id == 0)
			{
				h++;
			}
			while (h < item.region_height)
			{
				if ((h == item.region_height - 1) && (item.id == TOTAL_NUM_OF_TASKS - 1))
				{
					break;
				}
				while (w < item.region_width - 1)
				{
					x = item.col_start + w;
					y = item.row_start + h;

                    // don't update heat for sources
					uint8_t is_source = 0;

					for (int src = 0; src < *nr_heat_src; src++)
					{
						if ((heat_srcs[src].xpos == x) && (heat_srcs[src].ypos == y))
						{
							is_source = 1;
						}
					}

					uint32_t id = y * *width + x;

					if (item.input_matrix == MAT_BUF1_ADDR)
					{
						matrix2[id] = matrix1[id];

						if (!is_source)
						{
							matrix2[id] += _fp_mult(*c_x, (matrix1[id+1] + matrix1[id-1] - (matrix1[id]<<1)));
							matrix2[id] += _fp_mult(*c_y, (matrix1[id+*width] + matrix1[id-*width] - (matrix1[id]<<1)));
						}
					}
					else
					{
						matrix1[id] = matrix2[id];

						if (!is_source)
						{
							matrix1[id] += _fp_mult(*c_x, (matrix2[id+1] + matrix2[id-1] - (matrix2[id]<<1)));
							matrix1[id] += _fp_mult(*c_y, (matrix2[id+*width] + matrix2[id-*width] - (matrix2[id]<<1)));
						}
					}
				}
			}

		}
	}
}
