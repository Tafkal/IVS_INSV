/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'workers_cpu_3' in SOPC Builder design 'system'
 * SOPC Builder design path: ../../system.sopcinfo
 *
 * Generated: Tue Jan 16 14:20:29 CET 2018
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00000820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 100000000u
#define ALT_CPU_CPU_ID_SIZE 2
#define ALT_CPU_CPU_ID_VALUE 0x00000004
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1d
#define ALT_CPU_DCACHE_BYPASS_MASK 0x80000000
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x14006020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 100000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_EXTRA_EXCEPTION_INFO
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 2048
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x1d
#define ALT_CPU_NAME "workers_cpu_3"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x14006000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00000820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 100000000u
#define NIOS2_CPU_ID_SIZE 2
#define NIOS2_CPU_ID_VALUE 0x00000004
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1d
#define NIOS2_DCACHE_BYPASS_MASK 0x80000000
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x14006020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_EXTRA_EXCEPTION_INFO
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 2048
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x1d
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x14006000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_FIFO
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_MUTEX
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_NIOS2_GEN2


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/workers_jtag_uart_3"
#define ALT_STDERR_BASE 0x1008
#define ALT_STDERR_DEV workers_jtag_uart_3
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/workers_jtag_uart_3"
#define ALT_STDIN_BASE 0x1008
#define ALT_STDIN_DEV workers_jtag_uart_3
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/workers_jtag_uart_3"
#define ALT_STDOUT_BASE 0x1008
#define ALT_STDOUT_DEV workers_jtag_uart_3
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "system"


/*
 * ack_fifo_in configuration
 *
 */

#define ACK_FIFO_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define ACK_FIFO_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define ACK_FIFO_IN_BASE 0x10000020
#define ACK_FIFO_IN_BITS_PER_SYMBOL 16
#define ACK_FIFO_IN_CHANNEL_WIDTH 8
#define ACK_FIFO_IN_ERROR_WIDTH 8
#define ACK_FIFO_IN_FIFO_DEPTH 16
#define ACK_FIFO_IN_IRQ -1
#define ACK_FIFO_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ACK_FIFO_IN_NAME "/dev/ack_fifo_in"
#define ACK_FIFO_IN_SINGLE_CLOCK_MODE 0
#define ACK_FIFO_IN_SPAN 4
#define ACK_FIFO_IN_SYMBOLS_PER_BEAT 2
#define ACK_FIFO_IN_TYPE "altera_avalon_fifo"
#define ACK_FIFO_IN_USE_AVALONMM_READ_SLAVE 1
#define ACK_FIFO_IN_USE_AVALONMM_WRITE_SLAVE 1
#define ACK_FIFO_IN_USE_AVALONST_SINK 0
#define ACK_FIFO_IN_USE_AVALONST_SOURCE 0
#define ACK_FIFO_IN_USE_BACKPRESSURE 1
#define ACK_FIFO_IN_USE_IRQ 0
#define ACK_FIFO_IN_USE_PACKET 1
#define ACK_FIFO_IN_USE_READ_CONTROL 1
#define ACK_FIFO_IN_USE_REGISTER 0
#define ACK_FIFO_IN_USE_WRITE_CONTROL 1
#define ALT_MODULE_CLASS_ack_fifo_in altera_avalon_fifo


/*
 * ack_fifo_in_csr configuration
 *
 */

#define ACK_FIFO_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define ACK_FIFO_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define ACK_FIFO_IN_CSR_BASE 0x10000000
#define ACK_FIFO_IN_CSR_BITS_PER_SYMBOL 16
#define ACK_FIFO_IN_CSR_CHANNEL_WIDTH 8
#define ACK_FIFO_IN_CSR_ERROR_WIDTH 8
#define ACK_FIFO_IN_CSR_FIFO_DEPTH 16
#define ACK_FIFO_IN_CSR_IRQ -1
#define ACK_FIFO_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ACK_FIFO_IN_CSR_NAME "/dev/ack_fifo_in_csr"
#define ACK_FIFO_IN_CSR_SINGLE_CLOCK_MODE 0
#define ACK_FIFO_IN_CSR_SPAN 32
#define ACK_FIFO_IN_CSR_SYMBOLS_PER_BEAT 2
#define ACK_FIFO_IN_CSR_TYPE "altera_avalon_fifo"
#define ACK_FIFO_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define ACK_FIFO_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define ACK_FIFO_IN_CSR_USE_AVALONST_SINK 0
#define ACK_FIFO_IN_CSR_USE_AVALONST_SOURCE 0
#define ACK_FIFO_IN_CSR_USE_BACKPRESSURE 1
#define ACK_FIFO_IN_CSR_USE_IRQ 0
#define ACK_FIFO_IN_CSR_USE_PACKET 1
#define ACK_FIFO_IN_CSR_USE_READ_CONTROL 1
#define ACK_FIFO_IN_CSR_USE_REGISTER 0
#define ACK_FIFO_IN_CSR_USE_WRITE_CONTROL 1
#define ALT_MODULE_CLASS_ack_fifo_in_csr altera_avalon_fifo


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 4
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * mutex configuration
 *
 */

#define ALT_MODULE_CLASS_mutex altera_avalon_mutex
#define MUTEX_BASE 0x10001458
#define MUTEX_IRQ -1
#define MUTEX_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MUTEX_NAME "/dev/mutex"
#define MUTEX_OWNER_INIT 1
#define MUTEX_OWNER_WIDTH 16
#define MUTEX_SPAN 8
#define MUTEX_TYPE "altera_avalon_mutex"
#define MUTEX_VALUE_INIT 1
#define MUTEX_VALUE_WIDTH 16


/*
 * sdram configuration
 *
 */

#define ALT_MODULE_CLASS_sdram altera_avalon_new_sdram_controller
#define SDRAM_BASE 0x14000000
#define SDRAM_CAS_LATENCY 3
#define SDRAM_CONTENTS_INFO
#define SDRAM_INIT_NOP_DELAY 0.0
#define SDRAM_INIT_REFRESH_COMMANDS 2
#define SDRAM_IRQ -1
#define SDRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_IS_INITIALIZED 1
#define SDRAM_NAME "/dev/sdram"
#define SDRAM_POWERUP_DELAY 100.0
#define SDRAM_REFRESH_PERIOD 15.625
#define SDRAM_REGISTER_DATA_IN 1
#define SDRAM_SDRAM_ADDR_WIDTH 0x18
#define SDRAM_SDRAM_BANK_WIDTH 2
#define SDRAM_SDRAM_COL_WIDTH 10
#define SDRAM_SDRAM_DATA_WIDTH 16
#define SDRAM_SDRAM_NUM_BANKS 4
#define SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_SDRAM_ROW_WIDTH 12
#define SDRAM_SHARED_DATA 0
#define SDRAM_SIM_MODEL_BASE 0
#define SDRAM_SPAN 33554432
#define SDRAM_STARVATION_INDICATOR 0
#define SDRAM_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_T_AC 5.5
#define SDRAM_T_MRD 3
#define SDRAM_T_RCD 20.0
#define SDRAM_T_RFC 70.0
#define SDRAM_T_RP 20.0
#define SDRAM_T_WR 14.0


/*
 * shared_ocm configuration
 *
 */

#define ALT_MODULE_CLASS_shared_ocm altera_avalon_onchip_memory2
#define SHARED_OCM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define SHARED_OCM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define SHARED_OCM_BASE 0x10001000
#define SHARED_OCM_CONTENTS_INFO ""
#define SHARED_OCM_DUAL_PORT 1
#define SHARED_OCM_GUI_RAM_BLOCK_TYPE "AUTO"
#define SHARED_OCM_INIT_CONTENTS_FILE "system_shared_ocm"
#define SHARED_OCM_INIT_MEM_CONTENT 0
#define SHARED_OCM_INSTANCE_ID "NONE"
#define SHARED_OCM_IRQ -1
#define SHARED_OCM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SHARED_OCM_NAME "/dev/shared_ocm"
#define SHARED_OCM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define SHARED_OCM_RAM_BLOCK_TYPE "AUTO"
#define SHARED_OCM_READ_DURING_WRITE_MODE "DONT_CARE"
#define SHARED_OCM_SINGLE_CLOCK_OP 1
#define SHARED_OCM_SIZE_MULTIPLE 1
#define SHARED_OCM_SIZE_VALUE 1024
#define SHARED_OCM_SPAN 1024
#define SHARED_OCM_TYPE "altera_avalon_onchip_memory2"
#define SHARED_OCM_WRITABLE 1


/*
 * workers_jtag_uart_3 configuration
 *
 */

#define ALT_MODULE_CLASS_workers_jtag_uart_3 altera_avalon_jtag_uart
#define WORKERS_JTAG_UART_3_BASE 0x1008
#define WORKERS_JTAG_UART_3_IRQ 0
#define WORKERS_JTAG_UART_3_IRQ_INTERRUPT_CONTROLLER_ID 0
#define WORKERS_JTAG_UART_3_NAME "/dev/workers_jtag_uart_3"
#define WORKERS_JTAG_UART_3_READ_DEPTH 64
#define WORKERS_JTAG_UART_3_READ_THRESHOLD 8
#define WORKERS_JTAG_UART_3_SPAN 8
#define WORKERS_JTAG_UART_3_TYPE "altera_avalon_jtag_uart"
#define WORKERS_JTAG_UART_3_WRITE_DEPTH 64
#define WORKERS_JTAG_UART_3_WRITE_THRESHOLD 8

#endif /* __SYSTEM_H_ */
