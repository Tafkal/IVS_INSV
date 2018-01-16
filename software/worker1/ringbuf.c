/**
 * @file ringbuf.c
 * @date 2017
 *
 * Ring buffer implementation.
 * Bit 31 is used for cache bypass.
 */

#include "common.h"
#include "ringbuf.h"
#include "system.h"

#define RINGBUF_BASE		(MAT_TASK_DESC_ADDR)
#define RINGBUF_MAX_COUNT	((SHARED_OCM_REGION_SPAN - 0x20 - MAT_TASK_DESC_OFFSET)/sizeof(item_t))
#define RINGBUF_START_ADDR	(0x0)
#define RINGBUF_END_ADDR	(RINGBUF_MAX_COUNT-1)


typedef volatile struct RINGBUF_STRUCT {
	// first 32 bytes
	uint32_t head;
	uint32_t tail;
	uint32_t end;
	uint32_t cnt;
	uint32_t max_cnt;
	uint8_t reserved[4];
	// descriptors array
	item_t buffer[RINGBUF_MAX_COUNT];
} RingBuffer_t;

/**
 * Data which holds pointers to Ringbuffer
 */
static RingBuffer_t * const shared_buffer = (RingBuffer_t *)RINGBUF_BASE;

/**
 * @brief Initialize ring buffer
 * @param writer Used to signal if caller writes to buffer or reads from it
 */
void ringbuf_init(uint32_t writer)
{
    if (1 == writer)
    {
    	shared_buffer->head = RINGBUF_START_ADDR;
    	shared_buffer->tail = RINGBUF_START_ADDR;
    	shared_buffer->end = RINGBUF_END_ADDR;
    	shared_buffer->cnt = 0;
    	shared_buffer->max_cnt = RINGBUF_MAX_COUNT;
    }
}

/**
 * @brief Enqueue data to buffer
 * @param data Data to enqueue
 */
uint32_t ringbuf_enqueue(item_t *data)
{
    // store data
	if ((shared_buffer->cnt + 1) <= shared_buffer->max_cnt)
	{
		shared_buffer->buffer[shared_buffer->head] = *data;

		// update Head pointer
		if (shared_buffer->head == shared_buffer->end)
		{
			shared_buffer->head = 0;
		}
		else
		{
			shared_buffer->head++;
		}

		// update data count
		shared_buffer->cnt++;

		return 0;
	}
	else
	{
		return 1;
	}
}

/**
 * @brief Dequeue data from buffer
 * @param data Data buffer where read data is saved
 */
uint32_t ringbuf_dequeue(item_t *data)
{
    // check if buffer is empty
    if ((shared_buffer->head == shared_buffer->tail) && (shared_buffer->cnt == 0))
    {
        return 1;
    }
    else
    {
        // if there is data, read it
        *data = shared_buffer->buffer[shared_buffer->tail];

        // update Tail pointer
        if (shared_buffer->tail == shared_buffer->end)
        {
            shared_buffer->tail = 0;
        }
        else
        {
            shared_buffer->tail++;
        }

        // update data count
        if (shared_buffer->cnt > 0)
        {
            shared_buffer->cnt--;
        }
    }

    return 0;
}
