/* 
 * "Small Hello World" example. 
 * 
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example 
 * designs. It requires a STDOUT  device in your system's hardware. 
 *
 * The purpose of this example is to demonstrate the smallest possible Hello 
 * World application, using the Nios II HAL library.  The memory footprint
 * of this hosted application is ~332 bytes by default using the standard 
 * reference design.  For a more fully featured Hello World application
 * example, see the example titled "Hello World".
 *
 * The memory footprint of this example has been reduced by making the
 * following changes to the normal "Hello World" example.
 * Check in the Nios II Software Developers Manual for a more complete 
 * description.
 * 
 * In the SW Application project (small_hello_world):
 *
 *  - In the C/C++ Build page
 * 
 *    - Set the Optimization Level to -Os
 * 
 * In System Library project (small_hello_world_syslib):
 *  - In the C/C++ Build page
 * 
 *    - Set the Optimization Level to -Os
 * 
 *    - Define the preprocessor option ALT_NO_INSTRUCTION_EMULATION 
 *      This removes software exception handling, which means that you cannot 
 *      run code compiled for Nios II cpu with a hardware multiplier on a core 
 *      without a the multiply unit. Check the Nios II Software Developers 
 *      Manual for more details.
 *
 *  - In the System Library page:
 *    - Set Periodic system timer and Timestamp timer to none
 *      This prevents the automatic inclusion of the timer driver.
 *
 *    - Set Max file descriptors to 4
 *      This reduces the size of the file handle pool.
 *
 *    - Check Main function does not exit
 *    - Uncheck Clean exit (flush buffers)
 *      This removes the unneeded call to exit when main returns, since it
 *      won't.
 *
 *    - Check Don't use C++
 *      This builds without the C++ support code.
 *
 *    - Check Small C library
 *      This uses a reduced functionality C library, which lacks  
 *      support for buffering, file IO, floating point and getch(), etc. 
 *      Check the Nios II Software Developers Manual for a complete list.
 *
 *    - Check Reduced device drivers
 *      This uses reduced functionality drivers if they're available. For the
 *      standard design this means you get polled UART and JTAG UART drivers,
 *      no support for the LCD driver and you lose the ability to program 
 *      CFI compliant flash devices.
 *
 *    - Check Access device drivers directly
 *      This bypasses the device file system to access device drivers directly.
 *      This eliminates the space required for the device file system services.
 *      It also provides a HAL version of libc services that access the drivers
 *      directly, further reducing space. Only a limited number of libc
 *      functions are available in this configuration.
 *
 *    - Use ALT versions of stdio routines:
 *
 *           Function                  Description
 *        ===============  =====================================
 *        alt_printf       Only supports %s, %x, and %c ( < 1 Kbyte)
 *        alt_putstr       Smaller overhead than puts with direct drivers
 *                         Note this function doesn't add a newline.
 *        alt_putchar      Smaller overhead than putchar with direct drivers
 *        alt_getchar      Smaller overhead than getchar with direct drivers
 *
 */

#include "sys/alt_stdio.h"
#include "altera_avalon_mutex.h"
#include "nios2_ctrl_reg_macros.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_irq.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <system.h>

// Matrix SDRAM storage base addresses
#define MATRIX_A_ADDR (SDRAM_SHARED_BASE + 0x1000)
#define MATRIX_B_ADDR (SDRAM_SHARED_BASE + 0x2000)
#define MATRIX_C_ADDR (SDRAM_SHARED_BASE + 0x3000)
#define MATRIX_SIZE_ADDR (SDRAM_SHARED_BASE + 0x5000)

#define UNCACHE(addr) ((volatile int *)((int)(addr) | 0x80000000))

volatile int * us_counter = (volatile int *) US_COUNTER_BASE;

volatile int * core2_tx = (int *) CORE2_TX_BASE;
volatile int * core2_rx = (int *) CORE2_RX_BASE;
volatile int * core2_rx_irq = (int *) (CORE2_RX_BASE + 0x08);
volatile int * core2_rx_edge = (int *) (CORE2_RX_BASE + 0x0C);

volatile int *shared_N = UNCACHE(MATRIX_SIZE_ADDR);


// Function prototype
void matrix_rng(int N, volatile int * matrix_address);
void matrix_partial_multiply(int N, volatile int *A, volatile int *B, volatile int *C, int start_row, int end_row);
void print_matrix(int N, volatile int * matrix_address);
void print_matrix_w_addresses(int N, volatile int *matrix_address);

// Global variables
volatile int stage = 0;
volatile int ready1 = 0;
volatile int ready2 = 0;
volatile int N = 0;

// mutex
alt_mutex_dev *mutex;

int main()
{ 
	 * core2_tx = 0;

	int init = * us_counter;
	printf("CPU2 startup time: %.d\n", init);
//  alt_putstr("Hello from CORE 2!\n");

  // Enable IRQ from PIO
  * core2_rx_edge = 0x1;
  * core2_rx_irq = 0x1;
  * core2_rx_edge = 0x1;
  NIOS2_WRITE_STATUS(0x1);	// Enable global interrupts
  NIOS2_WRITE_IENABLE(0x4);	// Set IRQ bit

//  * core2_tx = 0;
//  * core2_tx = 1;
//  * core2_tx = 0;

  // mutex
  mutex = altera_avalon_mutex_open("/dev/mutex");
  if (!mutex) {
	  printf("Failed to open mutex!\n");
	  while (1);  // Halt here if mutex can't be opened
  }
  alt_putstr("Mutex opened\n");
//  altera_avalon_mutex_unlock(mutex);

  // Stage 1, generate matrix B
  while (1) {
//      altera_avalon_mutex_lock(mutex, 1);
      if (ready1 == 1) {
    	  alt_putstr("\nReceived N ready signal\n");
//    	  printf("Time: %.d\n", * us_counter);
//          altera_avalon_mutex_unlock(mutex);
          break;
      }
//      altera_avalon_mutex_unlock(mutex);
  }

  int N = * shared_N;
  printf("N = %.d\n", N);

  volatile int *A = UNCACHE(MATRIX_A_ADDR);
  volatile int *B = UNCACHE(MATRIX_B_ADDR);
  volatile int *C = UNCACHE(MATRIX_C_ADDR);
  matrix_rng(N, B);
  printf("\nB :\n");
  print_matrix_w_addresses(N, B);


  // Stage 2, Multiply matrix A & B
  while (1) {
//      altera_avalon_mutex_lock(mutex, 1);
      if (ready2 == 1) {
    	  alt_putstr("\nReceived Matrix A ready signal\n");
//    	  printf("Time: %.d", * us_counter);
//          altera_avalon_mutex_unlock(mutex);
          break;
      }
//      altera_avalon_mutex_unlock(mutex);
  }

//  unsigned int start_time = *us_counter;
  matrix_partial_multiply(N, A, B, C, N/2, N);
//  unsigned int end_time = *us_counter;

  // signal core 1 matmul is done
    * core2_tx = 0;
    * core2_tx = 1;
//    * core2_tx = 0;

//  unsigned int elapsed_cycles = end_time - start_time;
//  printf("\nCore 2 Matmul Elapsed time: %u us\n", elapsed_cycles);

//  altera_avalon_mutex_lock(mutex, 1);
//  altera_avalon_mutex_unlock(mutex);


  return 0;

}

void matrix_rng(int N, volatile int * matrix_address)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int value = rand() % 10;
			* ( matrix_address + (N * i + j)) = value;
		}
	}
}

void matrix_partial_multiply(int N, volatile int *A, volatile int *B, volatile int *C, int start_row, int end_row)
{
	for (int i = start_row; i < end_row; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int sum = 0;

			for (int k = 0; k < N; k++)
			{
				int a = *(A + (i * N + k));
				int b = *(B + (k * N + j));
				sum += a * b;
			}

			*(C + (i * N + j)) = sum;
//			printf("Writing to C[%d][%d] = %d (addr: 0x%x)\n", i, j, sum, (unsigned int)(C + (i*N + j)));

		}
//		alt_putstr("\n");
    }
}

void print_matrix(int N, volatile int * matrix_address)
{
	for (int i = 0; i < N; i++)
	{

		for (int j = 0; j < N; j++)
		{
			int value = * (matrix_address + (N * i + j));
			printf("%d\t", value);
		}
		printf("\n");
	}
	printf("\n");
}

void print_matrix_w_addresses(int N, volatile int *matrix_address)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int *addr = matrix_address + (N * i + j);
            printf("%d (0x%x)\t", *addr, addr);
        }
        printf("\n");
    }
}
