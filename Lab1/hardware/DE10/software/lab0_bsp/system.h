/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'Nios2' in SOPC Builder design 'Computer_System'
 * SOPC Builder design path: ../../Computer_System.sopcinfo
 *
 * Generated: Tue Mar 11 11:23:59 SGT 2025
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
 * ADC configuration
 *
 */

#define ADC_BASE 0xff204000
#define ADC_IRQ -1
#define ADC_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ADC_NAME "/dev/ADC"
#define ADC_SPAN 32
#define ADC_TYPE "altera_up_avalon_adc"
#define ALT_MODULE_CLASS_ADC altera_up_avalon_adc


/*
 * Accelerometer configuration
 *
 */

#define ACCELEROMETER_BASE 0xff204020
#define ACCELEROMETER_IRQ 15
#define ACCELEROMETER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define ACCELEROMETER_NAME "/dev/Accelerometer"
#define ACCELEROMETER_SPAN 2
#define ACCELEROMETER_TYPE "altera_up_avalon_accelerometer_spi"
#define ALT_MODULE_CLASS_Accelerometer altera_up_avalon_accelerometer_spi


/*
 * Arduino_GPIO configuration
 *
 */

#define ALT_MODULE_CLASS_Arduino_GPIO altera_avalon_pio
#define ARDUINO_GPIO_BASE 0xff200100
#define ARDUINO_GPIO_BIT_CLEARING_EDGE_REGISTER 1
#define ARDUINO_GPIO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define ARDUINO_GPIO_CAPTURE 1
#define ARDUINO_GPIO_DATA_WIDTH 16
#define ARDUINO_GPIO_DO_TEST_BENCH_WIRING 1
#define ARDUINO_GPIO_DRIVEN_SIM_VALUE 0
#define ARDUINO_GPIO_EDGE_TYPE "FALLING"
#define ARDUINO_GPIO_FREQ 100000000
#define ARDUINO_GPIO_HAS_IN 0
#define ARDUINO_GPIO_HAS_OUT 0
#define ARDUINO_GPIO_HAS_TRI 1
#define ARDUINO_GPIO_IRQ 13
#define ARDUINO_GPIO_IRQ_INTERRUPT_CONTROLLER_ID 0
#define ARDUINO_GPIO_IRQ_TYPE "EDGE"
#define ARDUINO_GPIO_NAME "/dev/Arduino_GPIO"
#define ARDUINO_GPIO_RESET_VALUE 0
#define ARDUINO_GPIO_SPAN 16
#define ARDUINO_GPIO_TYPE "altera_avalon_pio"


/*
 * Arduino_Reset_N configuration
 *
 */

#define ALT_MODULE_CLASS_Arduino_Reset_N altera_avalon_pio
#define ARDUINO_RESET_N_BASE 0xff200110
#define ARDUINO_RESET_N_BIT_CLEARING_EDGE_REGISTER 1
#define ARDUINO_RESET_N_BIT_MODIFYING_OUTPUT_REGISTER 0
#define ARDUINO_RESET_N_CAPTURE 0
#define ARDUINO_RESET_N_DATA_WIDTH 1
#define ARDUINO_RESET_N_DO_TEST_BENCH_WIRING 0
#define ARDUINO_RESET_N_DRIVEN_SIM_VALUE 0
#define ARDUINO_RESET_N_EDGE_TYPE "NONE"
#define ARDUINO_RESET_N_FREQ 100000000
#define ARDUINO_RESET_N_HAS_IN 0
#define ARDUINO_RESET_N_HAS_OUT 1
#define ARDUINO_RESET_N_HAS_TRI 0
#define ARDUINO_RESET_N_IRQ -1
#define ARDUINO_RESET_N_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ARDUINO_RESET_N_IRQ_TYPE "NONE"
#define ARDUINO_RESET_N_NAME "/dev/Arduino_Reset_N"
#define ARDUINO_RESET_N_RESET_VALUE 0
#define ARDUINO_RESET_N_SPAN 16
#define ARDUINO_RESET_N_TYPE "altera_avalon_pio"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x0a000020
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 100000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x20
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00000020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 100000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 1
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 1
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_DIVISION_ERROR_EXCEPTION
#define ALT_CPU_HAS_EXTRA_EXCEPTION_INFO
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INST_ADDR_WIDTH 0x1c
#define ALT_CPU_NAME "Nios2"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x00000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x0a000020
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 100000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x20
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00000020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 1
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 1
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_DIVISION_ERROR_EXCEPTION
#define NIOS2_HAS_EXTRA_EXCEPTION_INFO
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INST_ADDR_WIDTH 0x1c
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x00000000


/*
 * Custom instruction macros
 *
 */

#define ALT_CI_NIOS2_FLOATING_POINT(n,A,B) __builtin_custom_inii(ALT_CI_NIOS2_FLOATING_POINT_N+(n&ALT_CI_NIOS2_FLOATING_POINT_N_MASK),(A),(B))
#define ALT_CI_NIOS2_FLOATING_POINT_N 0xfc
#define ALT_CI_NIOS2_FLOATING_POINT_N_MASK ((1<<2)-1)


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_GEN2
#define __ALTERA_NIOS_CUSTOM_INSTR_FLOATING_POINT
#define __ALTERA_UP_AVALON_ACCELEROMETER_SPI
#define __ALTERA_UP_AVALON_ADC
#define __ALTERA_UP_AVALON_VIDEO_DMA_CONTROLLER
#define __ALTERA_UP_AVALON_VIDEO_RGB_RESAMPLER


/*
 * Expansion_JP1 configuration
 *
 */

#define ALT_MODULE_CLASS_Expansion_JP1 altera_avalon_pio
#define EXPANSION_JP1_BASE 0xff200060
#define EXPANSION_JP1_BIT_CLEARING_EDGE_REGISTER 1
#define EXPANSION_JP1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define EXPANSION_JP1_CAPTURE 1
#define EXPANSION_JP1_DATA_WIDTH 32
#define EXPANSION_JP1_DO_TEST_BENCH_WIRING 1
#define EXPANSION_JP1_DRIVEN_SIM_VALUE 0
#define EXPANSION_JP1_EDGE_TYPE "FALLING"
#define EXPANSION_JP1_FREQ 100000000
#define EXPANSION_JP1_HAS_IN 0
#define EXPANSION_JP1_HAS_OUT 0
#define EXPANSION_JP1_HAS_TRI 1
#define EXPANSION_JP1_IRQ 11
#define EXPANSION_JP1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define EXPANSION_JP1_IRQ_TYPE "EDGE"
#define EXPANSION_JP1_NAME "/dev/Expansion_JP1"
#define EXPANSION_JP1_RESET_VALUE 0
#define EXPANSION_JP1_SPAN 16
#define EXPANSION_JP1_TYPE "altera_avalon_pio"


/*
 * HEX3_HEX0 configuration
 *
 */

#define ALT_MODULE_CLASS_HEX3_HEX0 altera_avalon_pio
#define HEX3_HEX0_BASE 0xff200020
#define HEX3_HEX0_BIT_CLEARING_EDGE_REGISTER 0
#define HEX3_HEX0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX3_HEX0_CAPTURE 0
#define HEX3_HEX0_DATA_WIDTH 32
#define HEX3_HEX0_DO_TEST_BENCH_WIRING 0
#define HEX3_HEX0_DRIVEN_SIM_VALUE 0
#define HEX3_HEX0_EDGE_TYPE "NONE"
#define HEX3_HEX0_FREQ 100000000
#define HEX3_HEX0_HAS_IN 0
#define HEX3_HEX0_HAS_OUT 1
#define HEX3_HEX0_HAS_TRI 0
#define HEX3_HEX0_IRQ -1
#define HEX3_HEX0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX3_HEX0_IRQ_TYPE "NONE"
#define HEX3_HEX0_NAME "/dev/HEX3_HEX0"
#define HEX3_HEX0_RESET_VALUE 0
#define HEX3_HEX0_SPAN 16
#define HEX3_HEX0_TYPE "altera_avalon_pio"


/*
 * HEX5_HEX4 configuration
 *
 */

#define ALT_MODULE_CLASS_HEX5_HEX4 altera_avalon_pio
#define HEX5_HEX4_BASE 0xff200030
#define HEX5_HEX4_BIT_CLEARING_EDGE_REGISTER 0
#define HEX5_HEX4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX5_HEX4_CAPTURE 0
#define HEX5_HEX4_DATA_WIDTH 16
#define HEX5_HEX4_DO_TEST_BENCH_WIRING 0
#define HEX5_HEX4_DRIVEN_SIM_VALUE 0
#define HEX5_HEX4_EDGE_TYPE "NONE"
#define HEX5_HEX4_FREQ 100000000
#define HEX5_HEX4_HAS_IN 0
#define HEX5_HEX4_HAS_OUT 1
#define HEX5_HEX4_HAS_TRI 0
#define HEX5_HEX4_IRQ -1
#define HEX5_HEX4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX5_HEX4_IRQ_TYPE "NONE"
#define HEX5_HEX4_NAME "/dev/HEX5_HEX4"
#define HEX5_HEX4_RESET_VALUE 0
#define HEX5_HEX4_SPAN 16
#define HEX5_HEX4_TYPE "altera_avalon_pio"


/*
 * Interval_Timer configuration
 *
 */

#define ALT_MODULE_CLASS_Interval_Timer altera_avalon_timer
#define INTERVAL_TIMER_ALWAYS_RUN 0
#define INTERVAL_TIMER_BASE 0xff202000
#define INTERVAL_TIMER_COUNTER_SIZE 32
#define INTERVAL_TIMER_FIXED_PERIOD 0
#define INTERVAL_TIMER_FREQ 100000000
#define INTERVAL_TIMER_IRQ 0
#define INTERVAL_TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define INTERVAL_TIMER_LOAD_VALUE 12499999
#define INTERVAL_TIMER_MULT 0.001
#define INTERVAL_TIMER_NAME "/dev/Interval_Timer"
#define INTERVAL_TIMER_PERIOD 125.0
#define INTERVAL_TIMER_PERIOD_UNITS "ms"
#define INTERVAL_TIMER_RESET_OUTPUT 0
#define INTERVAL_TIMER_SNAPSHOT 1
#define INTERVAL_TIMER_SPAN 32
#define INTERVAL_TIMER_TICKS_PER_SEC 8
#define INTERVAL_TIMER_TIMEOUT_PULSE_OUTPUT 0
#define INTERVAL_TIMER_TYPE "altera_avalon_timer"


/*
 * Interval_Timer_2 configuration
 *
 */

#define ALT_MODULE_CLASS_Interval_Timer_2 altera_avalon_timer
#define INTERVAL_TIMER_2_ALWAYS_RUN 0
#define INTERVAL_TIMER_2_BASE 0xff202020
#define INTERVAL_TIMER_2_COUNTER_SIZE 32
#define INTERVAL_TIMER_2_FIXED_PERIOD 0
#define INTERVAL_TIMER_2_FREQ 100000000
#define INTERVAL_TIMER_2_IRQ 2
#define INTERVAL_TIMER_2_IRQ_INTERRUPT_CONTROLLER_ID 0
#define INTERVAL_TIMER_2_LOAD_VALUE 12499999
#define INTERVAL_TIMER_2_MULT 0.001
#define INTERVAL_TIMER_2_NAME "/dev/Interval_Timer_2"
#define INTERVAL_TIMER_2_PERIOD 125.0
#define INTERVAL_TIMER_2_PERIOD_UNITS "ms"
#define INTERVAL_TIMER_2_RESET_OUTPUT 0
#define INTERVAL_TIMER_2_SNAPSHOT 1
#define INTERVAL_TIMER_2_SPAN 32
#define INTERVAL_TIMER_2_TICKS_PER_SEC 8
#define INTERVAL_TIMER_2_TIMEOUT_PULSE_OUTPUT 0
#define INTERVAL_TIMER_2_TYPE "altera_avalon_timer"


/*
 * JTAG_UART configuration
 *
 */

#define ALT_MODULE_CLASS_JTAG_UART altera_avalon_jtag_uart
#define JTAG_UART_BASE 0xff201000
#define JTAG_UART_IRQ 8
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/JTAG_UART"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * LEDs configuration
 *
 */

#define ALT_MODULE_CLASS_LEDs altera_avalon_pio
#define LEDS_BASE 0xff200000
#define LEDS_BIT_CLEARING_EDGE_REGISTER 0
#define LEDS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDS_CAPTURE 0
#define LEDS_DATA_WIDTH 10
#define LEDS_DO_TEST_BENCH_WIRING 0
#define LEDS_DRIVEN_SIM_VALUE 0
#define LEDS_EDGE_TYPE "NONE"
#define LEDS_FREQ 100000000
#define LEDS_HAS_IN 0
#define LEDS_HAS_OUT 1
#define LEDS_HAS_TRI 0
#define LEDS_IRQ -1
#define LEDS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDS_IRQ_TYPE "NONE"
#define LEDS_NAME "/dev/LEDs"
#define LEDS_RESET_VALUE 0
#define LEDS_SPAN 16
#define LEDS_TYPE "altera_avalon_pio"


/*
 * Onchip_SRAM configuration
 *
 */

#define ALT_MODULE_CLASS_Onchip_SRAM altera_avalon_onchip_memory2
#define ONCHIP_SRAM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_SRAM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_SRAM_BASE 0x8000000
#define ONCHIP_SRAM_CONTENTS_INFO ""
#define ONCHIP_SRAM_DUAL_PORT 1
#define ONCHIP_SRAM_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_SRAM_INIT_CONTENTS_FILE "Computer_System_Onchip_SRAM"
#define ONCHIP_SRAM_INIT_MEM_CONTENT 1
#define ONCHIP_SRAM_INSTANCE_ID "NONE"
#define ONCHIP_SRAM_IRQ -1
#define ONCHIP_SRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_SRAM_NAME "/dev/Onchip_SRAM"
#define ONCHIP_SRAM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_SRAM_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_SRAM_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_SRAM_SINGLE_CLOCK_OP 1
#define ONCHIP_SRAM_SIZE_MULTIPLE 1
#define ONCHIP_SRAM_SIZE_VALUE 65536
#define ONCHIP_SRAM_SPAN 65536
#define ONCHIP_SRAM_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_SRAM_WRITABLE 1


/*
 * Pushbuttons configuration
 *
 */

#define ALT_MODULE_CLASS_Pushbuttons altera_avalon_pio
#define PUSHBUTTONS_BASE 0xff200050
#define PUSHBUTTONS_BIT_CLEARING_EDGE_REGISTER 1
#define PUSHBUTTONS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PUSHBUTTONS_CAPTURE 1
#define PUSHBUTTONS_DATA_WIDTH 2
#define PUSHBUTTONS_DO_TEST_BENCH_WIRING 1
#define PUSHBUTTONS_DRIVEN_SIM_VALUE 0
#define PUSHBUTTONS_EDGE_TYPE "FALLING"
#define PUSHBUTTONS_FREQ 100000000
#define PUSHBUTTONS_HAS_IN 1
#define PUSHBUTTONS_HAS_OUT 0
#define PUSHBUTTONS_HAS_TRI 0
#define PUSHBUTTONS_IRQ 1
#define PUSHBUTTONS_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PUSHBUTTONS_IRQ_TYPE "EDGE"
#define PUSHBUTTONS_NAME "/dev/Pushbuttons"
#define PUSHBUTTONS_RESET_VALUE 0
#define PUSHBUTTONS_SPAN 16
#define PUSHBUTTONS_TYPE "altera_avalon_pio"


/*
 * SDRAM configuration
 *
 */

#define ALT_MODULE_CLASS_SDRAM altera_avalon_new_sdram_controller
#define SDRAM_BASE 0x0
#define SDRAM_CAS_LATENCY 3
#define SDRAM_CONTENTS_INFO
#define SDRAM_INIT_NOP_DELAY 0.0
#define SDRAM_INIT_REFRESH_COMMANDS 2
#define SDRAM_IRQ -1
#define SDRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_IS_INITIALIZED 1
#define SDRAM_NAME "/dev/SDRAM"
#define SDRAM_POWERUP_DELAY 100.0
#define SDRAM_REFRESH_PERIOD 15.625
#define SDRAM_REGISTER_DATA_IN 1
#define SDRAM_SDRAM_ADDR_WIDTH 0x19
#define SDRAM_SDRAM_BANK_WIDTH 2
#define SDRAM_SDRAM_COL_WIDTH 10
#define SDRAM_SDRAM_DATA_WIDTH 16
#define SDRAM_SDRAM_NUM_BANKS 4
#define SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_SDRAM_ROW_WIDTH 13
#define SDRAM_SHARED_DATA 0
#define SDRAM_SIM_MODEL_BASE 1
#define SDRAM_SPAN 67108864
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
 * Slider_Switches configuration
 *
 */

#define ALT_MODULE_CLASS_Slider_Switches altera_avalon_pio
#define SLIDER_SWITCHES_BASE 0xff200040
#define SLIDER_SWITCHES_BIT_CLEARING_EDGE_REGISTER 0
#define SLIDER_SWITCHES_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SLIDER_SWITCHES_CAPTURE 0
#define SLIDER_SWITCHES_DATA_WIDTH 10
#define SLIDER_SWITCHES_DO_TEST_BENCH_WIRING 1
#define SLIDER_SWITCHES_DRIVEN_SIM_VALUE 0
#define SLIDER_SWITCHES_EDGE_TYPE "NONE"
#define SLIDER_SWITCHES_FREQ 100000000
#define SLIDER_SWITCHES_HAS_IN 1
#define SLIDER_SWITCHES_HAS_OUT 0
#define SLIDER_SWITCHES_HAS_TRI 0
#define SLIDER_SWITCHES_IRQ -1
#define SLIDER_SWITCHES_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SLIDER_SWITCHES_IRQ_TYPE "NONE"
#define SLIDER_SWITCHES_NAME "/dev/Slider_Switches"
#define SLIDER_SWITCHES_RESET_VALUE 0
#define SLIDER_SWITCHES_SPAN 16
#define SLIDER_SWITCHES_TYPE "altera_avalon_pio"


/*
 * SysID configuration
 *
 */

#define ALT_MODULE_CLASS_SysID altera_avalon_sysid_qsys
#define SYSID_BASE 0xff202040
#define SYSID_ID 0
#define SYSID_IRQ -1
#define SYSID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_NAME "/dev/SysID"
#define SYSID_SPAN 8
#define SYSID_TIMESTAMP 1555013122
#define SYSID_TYPE "altera_avalon_sysid_qsys"


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "MAX 10"
#define ALT_IRQ_BASE NULL
#define ALT_LEGACY_INTERRUPT_API_PRESENT
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/JTAG_UART"
#define ALT_STDERR_BASE 0xff201000
#define ALT_STDERR_DEV JTAG_UART
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/JTAG_UART"
#define ALT_STDIN_BASE 0xff201000
#define ALT_STDIN_DEV JTAG_UART
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/JTAG_UART"
#define ALT_STDOUT_BASE 0xff201000
#define ALT_STDOUT_DEV JTAG_UART
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "Computer_System"


/*
 * VGA_Subsystem_Char_Buf_Subsystem_Char_Buf_DMA configuration
 *
 */

#define ALT_MODULE_CLASS_VGA_Subsystem_Char_Buf_Subsystem_Char_Buf_DMA altera_up_avalon_video_dma_controller
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_CHAR_BUF_DMA_BASE 0xff203030
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_CHAR_BUF_DMA_IRQ -1
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_CHAR_BUF_DMA_IRQ_INTERRUPT_CONTROLLER_ID -1
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_CHAR_BUF_DMA_NAME "/dev/VGA_Subsystem_Char_Buf_Subsystem_Char_Buf_DMA"
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_CHAR_BUF_DMA_SPAN 16
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_CHAR_BUF_DMA_TYPE "altera_up_avalon_video_dma_controller"


/*
 * VGA_Subsystem_Char_Buf_Subsystem_Onchip_SRAM configuration
 *
 */

#define ALT_MODULE_CLASS_VGA_Subsystem_Char_Buf_Subsystem_Onchip_SRAM altera_avalon_onchip_memory2
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_BASE 0x9000000
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_CONTENTS_INFO ""
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_DUAL_PORT 1
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_GUI_RAM_BLOCK_TYPE "AUTO"
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_INIT_CONTENTS_FILE "Computer_System_VGA_Subsystem_Char_Buf_Subsystem_Onchip_SRAM"
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_INIT_MEM_CONTENT 1
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_INSTANCE_ID "NONE"
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_IRQ -1
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_NAME "/dev/VGA_Subsystem_Char_Buf_Subsystem_Onchip_SRAM"
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_RAM_BLOCK_TYPE "AUTO"
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_READ_DURING_WRITE_MODE "DONT_CARE"
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_SINGLE_CLOCK_OP 1
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_SIZE_MULTIPLE 1
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_SIZE_VALUE 8192
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_SPAN 8192
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_TYPE "altera_avalon_onchip_memory2"
#define VGA_SUBSYSTEM_CHAR_BUF_SUBSYSTEM_ONCHIP_SRAM_WRITABLE 1


/*
 * VGA_Subsystem_VGA_Pixel_DMA configuration
 *
 */

#define ALT_MODULE_CLASS_VGA_Subsystem_VGA_Pixel_DMA altera_up_avalon_video_dma_controller
#define VGA_SUBSYSTEM_VGA_PIXEL_DMA_BASE 0xff203020
#define VGA_SUBSYSTEM_VGA_PIXEL_DMA_IRQ -1
#define VGA_SUBSYSTEM_VGA_PIXEL_DMA_IRQ_INTERRUPT_CONTROLLER_ID -1
#define VGA_SUBSYSTEM_VGA_PIXEL_DMA_NAME "/dev/VGA_Subsystem_VGA_Pixel_DMA"
#define VGA_SUBSYSTEM_VGA_PIXEL_DMA_SPAN 16
#define VGA_SUBSYSTEM_VGA_PIXEL_DMA_TYPE "altera_up_avalon_video_dma_controller"


/*
 * VGA_Subsystem_VGA_Pixel_RGB_Resampler configuration
 *
 */

#define ALT_MODULE_CLASS_VGA_Subsystem_VGA_Pixel_RGB_Resampler altera_up_avalon_video_rgb_resampler
#define VGA_SUBSYSTEM_VGA_PIXEL_RGB_RESAMPLER_BASE 0xff203010
#define VGA_SUBSYSTEM_VGA_PIXEL_RGB_RESAMPLER_IRQ -1
#define VGA_SUBSYSTEM_VGA_PIXEL_RGB_RESAMPLER_IRQ_INTERRUPT_CONTROLLER_ID -1
#define VGA_SUBSYSTEM_VGA_PIXEL_RGB_RESAMPLER_NAME "/dev/VGA_Subsystem_VGA_Pixel_RGB_Resampler"
#define VGA_SUBSYSTEM_VGA_PIXEL_RGB_RESAMPLER_SPAN 4
#define VGA_SUBSYSTEM_VGA_PIXEL_RGB_RESAMPLER_TYPE "altera_up_avalon_video_rgb_resampler"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK INTERVAL_TIMER
#define ALT_TIMESTAMP_CLK none

#endif /* __SYSTEM_H_ */
