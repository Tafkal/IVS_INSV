/**
 * @file ringbuf.h
 * @date 2017
 */

#ifndef RINGBUF_H_
#define RINGBUF_H_

#include <stdint.h>

/**
 * Structure of item that is used in ring buffer
 */
typedef struct DESC
{
	uint32_t id;
	uint32_t row_start;
	uint32_t col_start;
	uint32_t region_width;
	uint32_t region_height;
	uint32_t input_matrix;
	// uint32_t output_matrix;
	// uint32_t status; umesto toga =>
	uint32_t reserved[2]; // od [2] jer bez output_mat
} item_t;

// bez statusa
/*typedef enum DESC_STATUS_ENUM
{
	DESC_READY,
	DESC_PROCESSING,
	DESC_DONE
} desc_status_t;*/

/**
 * @brief Initialize ring buffer
 * @param writer Used to signal if caller writes to buffer or reads from it
 */
extern void ringbuf_init(uint32_t writer);

/**
 * @brief Enqueue data to buffer
 * @param data Data to enqueue
 */
extern uint32_t ringbuf_enqueue(item_t *data);

/**
 * @brief Dequeue data from buffer
 * @param data Data buffer where read data is saved
 */
extern uint32_t ringbuf_dequeue(item_t *data);

#endif /* RINGBUF_H_ */
