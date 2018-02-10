/**
 * @file common.h
 * @brief Necessary defines and structures
 *
 * This file has the definitions of the addresses where all the parameters and
 * matrices will be stored.
 *
 * @date 2018
 * @authors Strahinja Jankovic, Ivana Nikolic, Stefan Vukcevic
 */

#ifndef COMMON_H_
#define COMMON_H_

/* Standard include */
#include <stdint.h>

/* BASES */
/* parameters are stored in shared OCM */
#define MAT_PARAM_BASE	(SHARED_OCM_REGION_BASE + 0x80000000)
/* matrices are stored in shared SDRAM */
#define MAT_BUFFER_BASE	(SHARED_SDRAM_REGION_BASE + 0x80000000)

/* OFFSETS */
/* matrix dimensions */
#define MAT_WIDTH_OFFSET	(0x00)
#define MAT_HEIGHT_OFFSET	(0x04)

/* heat transfer coefficients */
#define MAT_X_COEFF_OFFSET	(0x08)
#define MAT_Y_COEFF_OFFSET	(0x0A)

/* number of heat sources */
#define MAT_NR_HEAT_SRC_OFFSET	(0x0C)

/* heat sources */
#define MAT_HEAT_SRCS_OFFSET	(0x10)

/* task descriptions */
#define MAT_TASK_DESC_OFFSET	(0x40)

/* matrix buffers, allocate 4MB for each */
#define MAT_BUF1_OFFSET		(0x00000000)
#define MAT_BUF2_OFFSET		(0x00400000)

/* ADRESSES */
/* matrix dimensions */
#define MAT_WIDTH_ADDR		(MAT_PARAM_BASE + MAT_WIDTH_OFFSET)
#define MAT_HEIGHT_ADDR		(MAT_PARAM_BASE + MAT_HEIGHT_OFFSET)

/* heat transfer coefficients */
#define MAT_X_COEFF_ADDR	(MAT_PARAM_BASE + MAT_X_COEFF_OFFSET)
#define MAT_Y_COEFF_ADDR	(MAT_PARAM_BASE + MAT_Y_COEFF_OFFSET)

/* number of heat sources */
#define MAT_NR_HEAT_SRC_ADDR	(MAT_PARAM_BASE + MAT_NR_HEAT_SRC_OFFSET)

/* heat sources */
#define MAT_HEAT_SOURCES_ADDR	(MAT_PARAM_BASE + MAT_HEAT_SRCS_OFFSET)

/* task descriptions */
#define MAT_TASK_DESC_ADDR	(MAT_PARAM_BASE + MAT_TASK_DESC_OFFSET)

/* matrix buffers */
#define MAT_BUF1_ADDR		(MAT_BUFFER_BASE + MAT_BUF1_OFFSET)
#define MAT_BUF2_ADDR		(MAT_BUFFER_BASE + MAT_BUF2_OFFSET)

/* heat sources structure contains:
 * 	xpos - row where the heat source is located
 * 	ypos - column where the heat source is located
 * 	heat - value of the heat source corresponding to xpos and ypos
 */
typedef struct HEAT_SRC
{
	uint16_t xpos;
	uint16_t ypos;
	int16_t heat;
} heat_src_t;

/* maximum number of heat sources */
#define MAX_HEAT_SRCS		(5)

/* total number of tasks */
#define TOTAL_NUM_OF_TASKS  	(32)

/* defines that indicate from which matrix is currently
 * being read, and to which one is currently being written
 */
#define BUF_1				(1)
#define BUF_2				(2)

#endif /* COMMON_H_ */
