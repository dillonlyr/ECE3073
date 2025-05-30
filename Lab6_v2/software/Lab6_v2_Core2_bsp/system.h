/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'Nios2_Core2' in SOPC Builder design 'Lab6_v2_NiosProc'
 * SOPC Builder design path: ../../Lab6_v2_NiosProc.sopcinfo
 *
<<<<<<< HEAD
 * Generated: Thu May 15 14:56:58 SGT 2025
=======
 * Generated: Sun May 18 20:27:29 SGT 2025
>>>>>>> a912d808b13f941d5065f4fc6f67c213a7f39d38
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
#define ALT_CPU_BREAK_ADDR 0x00020820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000001
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1c
#define ALT_CPU_DCACHE_BYPASS_MASK 0x80000000
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x00010020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
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
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x1b
#define ALT_CPU_NAME "Nios2_Core2"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_PERIPHERAL_REGION_BASE 0x00021000
#define ALT_CPU_PERIPHERAL_REGION_PRESENT
#define ALT_CPU_PERIPHERAL_REGION_SIZE 0x00001000
#define ALT_CPU_RESET_ADDR 0x00010000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00020820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000001
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1c
#define NIOS2_DCACHE_BYPASS_MASK 0x80000000
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x00010020
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
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x1b
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_OCI_VERSION 1
#define NIOS2_PERIPHERAL_REGION_BASE 0x00021000
#define NIOS2_PERIPHERAL_REGION_PRESENT
#define NIOS2_PERIPHERAL_REGION_SIZE 0x00001000
#define NIOS2_RESET_ADDR 0x00010000


/*
 * Core2_JTAG_UART configuration
 *
 */

#define ALT_MODULE_CLASS_Core2_JTAG_UART altera_avalon_jtag_uart
#define CORE2_JTAG_UART_BASE 0x21030
#define CORE2_JTAG_UART_IRQ 1
#define CORE2_JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define CORE2_JTAG_UART_NAME "/dev/Core2_JTAG_UART"
#define CORE2_JTAG_UART_READ_DEPTH 64
#define CORE2_JTAG_UART_READ_THRESHOLD 8
#define CORE2_JTAG_UART_SPAN 8
#define CORE2_JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define CORE2_JTAG_UART_WRITE_DEPTH 64
#define CORE2_JTAG_UART_WRITE_THRESHOLD 8


/*
 * Core2_RAM configuration
 *
 */

#define ALT_MODULE_CLASS_Core2_RAM altera_avalon_onchip_memory2
#define CORE2_RAM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define CORE2_RAM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define CORE2_RAM_BASE 0x10000
#define CORE2_RAM_CONTENTS_INFO ""
#define CORE2_RAM_DUAL_PORT 0
#define CORE2_RAM_GUI_RAM_BLOCK_TYPE "AUTO"
#define CORE2_RAM_INIT_CONTENTS_FILE "Lab6_v2_NiosProc_Core2_RAM"
#define CORE2_RAM_INIT_MEM_CONTENT 1
#define CORE2_RAM_INSTANCE_ID "NONE"
#define CORE2_RAM_IRQ -1
#define CORE2_RAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CORE2_RAM_NAME "/dev/Core2_RAM"
#define CORE2_RAM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define CORE2_RAM_RAM_BLOCK_TYPE "AUTO"
#define CORE2_RAM_READ_DURING_WRITE_MODE "DONT_CARE"
#define CORE2_RAM_SINGLE_CLOCK_OP 0
#define CORE2_RAM_SIZE_MULTIPLE 1
#define CORE2_RAM_SIZE_VALUE 65536
#define CORE2_RAM_SPAN 65536
#define CORE2_RAM_TYPE "altera_avalon_onchip_memory2"
#define CORE2_RAM_WRITABLE 1


/*
 * Core2_RX configuration
 *
 */

#define ALT_MODULE_CLASS_Core2_RX altera_avalon_pio
#define CORE2_RX_BASE 0x21000
#define CORE2_RX_BIT_CLEARING_EDGE_REGISTER 0
#define CORE2_RX_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CORE2_RX_CAPTURE 1
#define CORE2_RX_DATA_WIDTH 1
#define CORE2_RX_DO_TEST_BENCH_WIRING 0
#define CORE2_RX_DRIVEN_SIM_VALUE 0
#define CORE2_RX_EDGE_TYPE "RISING"
#define CORE2_RX_FREQ 50000000
#define CORE2_RX_HAS_IN 1
#define CORE2_RX_HAS_OUT 0
#define CORE2_RX_HAS_TRI 0
#define CORE2_RX_IRQ 2
#define CORE2_RX_IRQ_INTERRUPT_CONTROLLER_ID 0
#define CORE2_RX_IRQ_TYPE "EDGE"
#define CORE2_RX_NAME "/dev/Core2_RX"
#define CORE2_RX_RESET_VALUE 0
#define CORE2_RX_SPAN 16
#define CORE2_RX_TYPE "altera_avalon_pio"


/*
 * Core2_TX configuration
 *
 */

#define ALT_MODULE_CLASS_Core2_TX altera_avalon_pio
#define CORE2_TX_BASE 0x21020
#define CORE2_TX_BIT_CLEARING_EDGE_REGISTER 0
#define CORE2_TX_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CORE2_TX_CAPTURE 0
#define CORE2_TX_DATA_WIDTH 1
#define CORE2_TX_DO_TEST_BENCH_WIRING 0
#define CORE2_TX_DRIVEN_SIM_VALUE 0
#define CORE2_TX_EDGE_TYPE "NONE"
#define CORE2_TX_FREQ 50000000
#define CORE2_TX_HAS_IN 0
#define CORE2_TX_HAS_OUT 1
#define CORE2_TX_HAS_TRI 0
#define CORE2_TX_IRQ -1
#define CORE2_TX_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CORE2_TX_IRQ_TYPE "NONE"
#define CORE2_TX_NAME "/dev/Core2_TX"
#define CORE2_TX_RESET_VALUE 0
#define CORE2_TX_SPAN 16
#define CORE2_TX_TYPE "altera_avalon_pio"


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_MUTEX
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_NIOS2_GEN2


/*
 * Pushbuttons configuration
 *
 */

#define ALT_MODULE_CLASS_Pushbuttons altera_avalon_pio
#define PUSHBUTTONS_BASE 0x21010
#define PUSHBUTTONS_BIT_CLEARING_EDGE_REGISTER 0
#define PUSHBUTTONS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PUSHBUTTONS_CAPTURE 1
#define PUSHBUTTONS_DATA_WIDTH 2
#define PUSHBUTTONS_DO_TEST_BENCH_WIRING 0
#define PUSHBUTTONS_DRIVEN_SIM_VALUE 0
#define PUSHBUTTONS_EDGE_TYPE "RISING"
#define PUSHBUTTONS_FREQ 50000000
#define PUSHBUTTONS_HAS_IN 1
#define PUSHBUTTONS_HAS_OUT 0
#define PUSHBUTTONS_HAS_TRI 0
#define PUSHBUTTONS_IRQ 0
#define PUSHBUTTONS_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PUSHBUTTONS_IRQ_TYPE "EDGE"
#define PUSHBUTTONS_NAME "/dev/Pushbuttons"
#define PUSHBUTTONS_RESET_VALUE 0
#define PUSHBUTTONS_SPAN 16
#define PUSHBUTTONS_TYPE "altera_avalon_pio"


/*
 * SDRAM_shared configuration
 *
 */

#define ALT_MODULE_CLASS_SDRAM_shared altera_avalon_new_sdram_controller
#define SDRAM_SHARED_BASE 0x4000000
#define SDRAM_SHARED_CAS_LATENCY 3
#define SDRAM_SHARED_CONTENTS_INFO
#define SDRAM_SHARED_INIT_NOP_DELAY 0.0
#define SDRAM_SHARED_INIT_REFRESH_COMMANDS 2
#define SDRAM_SHARED_IRQ -1
#define SDRAM_SHARED_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_SHARED_IS_INITIALIZED 1
#define SDRAM_SHARED_NAME "/dev/SDRAM_shared"
#define SDRAM_SHARED_POWERUP_DELAY 100.0
#define SDRAM_SHARED_REFRESH_PERIOD 15.625
#define SDRAM_SHARED_REGISTER_DATA_IN 1
#define SDRAM_SHARED_SDRAM_ADDR_WIDTH 0x19
#define SDRAM_SHARED_SDRAM_BANK_WIDTH 2
#define SDRAM_SHARED_SDRAM_COL_WIDTH 10
#define SDRAM_SHARED_SDRAM_DATA_WIDTH 16
#define SDRAM_SHARED_SDRAM_NUM_BANKS 4
#define SDRAM_SHARED_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_SHARED_SDRAM_ROW_WIDTH 13
#define SDRAM_SHARED_SHARED_DATA 0
#define SDRAM_SHARED_SIM_MODEL_BASE 0
#define SDRAM_SHARED_SPAN 67108864
#define SDRAM_SHARED_STARVATION_INDICATOR 0
#define SDRAM_SHARED_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_SHARED_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_SHARED_T_AC 5.5
#define SDRAM_SHARED_T_MRD 3
#define SDRAM_SHARED_T_RCD 20.0
#define SDRAM_SHARED_T_RFC 70.0
#define SDRAM_SHARED_T_RP 20.0
#define SDRAM_SHARED_T_WR 14.0


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "MAX 10"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/Core2_JTAG_UART"
#define ALT_STDERR_BASE 0x21030
#define ALT_STDERR_DEV Core2_JTAG_UART
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/Core2_JTAG_UART"
#define ALT_STDIN_BASE 0x21030
#define ALT_STDIN_DEV Core2_JTAG_UART
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/Core2_JTAG_UART"
#define ALT_STDOUT_BASE 0x21030
#define ALT_STDOUT_DEV Core2_JTAG_UART
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "Lab6_v2_NiosProc"


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
#define MUTEX_BASE 0x8021040
#define MUTEX_IRQ -1
#define MUTEX_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MUTEX_NAME "/dev/mutex"
#define MUTEX_OWNER_INIT 0
#define MUTEX_OWNER_WIDTH 16
#define MUTEX_SPAN 8
#define MUTEX_TYPE "altera_avalon_mutex"
#define MUTEX_VALUE_INIT 0
#define MUTEX_VALUE_WIDTH 16


/*
 * us_counter configuration
 *
 */

#define ALT_MODULE_CLASS_us_counter altera_avalon_pio
#define US_COUNTER_BASE 0x8021020
#define US_COUNTER_BIT_CLEARING_EDGE_REGISTER 0
#define US_COUNTER_BIT_MODIFYING_OUTPUT_REGISTER 0
#define US_COUNTER_CAPTURE 0
#define US_COUNTER_DATA_WIDTH 32
#define US_COUNTER_DO_TEST_BENCH_WIRING 0
#define US_COUNTER_DRIVEN_SIM_VALUE 0
#define US_COUNTER_EDGE_TYPE "NONE"
#define US_COUNTER_FREQ 50000000
#define US_COUNTER_HAS_IN 1
#define US_COUNTER_HAS_OUT 0
#define US_COUNTER_HAS_TRI 0
#define US_COUNTER_IRQ -1
#define US_COUNTER_IRQ_INTERRUPT_CONTROLLER_ID -1
#define US_COUNTER_IRQ_TYPE "NONE"
#define US_COUNTER_NAME "/dev/us_counter"
#define US_COUNTER_RESET_VALUE 0
#define US_COUNTER_SPAN 16
#define US_COUNTER_TYPE "altera_avalon_pio"

#endif /* __SYSTEM_H_ */
