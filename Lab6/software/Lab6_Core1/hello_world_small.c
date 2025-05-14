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
#include <stdlib.h>
#include <system.h>

// Matrix SDRAM storage base addresses
#define MATRIX_A_ADDR (SDRAM_SHARED_BASE + 0x1000)
#define MATRIX_B_ADDR (SDRAM_SHARED_BASE + 0x2000)
#define MATRIX_C_ADDR (SDRAM_SHARED_BASE + 0x3000)
#define MATRIX_SIZE_ADDR (SDRAM_SHARED_BASE + 0x5000)

// Volatile IO variables
volatile int * switches = (volatile int *) SLIDER_SWITCHES_BASE;
volatile int * us_counter = (volatile int *) US_COUNTER_BASE;

volatile int * core1_tx = (int *) CORE1_IRQ_TX_BASE;
volatile int * core1_rx = (int *) CORE1_IRQ_RX_BASE;
volatile int * core1_rx_irq = (int *) (CORE1_IRQ_TX_BASE + 0x08);
volatile int * core1_rx_edge = (int *) (CORE1_IRQ_TX_BASE + 0x0C);

volatile int * shared_N  = (int*) MATRIX_SIZE_ADDR;

// Global variables
volatile int core2_ready = 0;

// Mutex
alt_mutex_dev *mutex;

// Function prototype
void matrix_multiplication(int N, int(*A)[N], int (*B)[N]);
void matrix_rng(int N, int (*M)[N]);
void matrix_mult_partial(int N, int (*A)[N], int (*B)[N], int start_row, int end_row);

int main()
{ 

  alt_putstr("Hello from CORE 1!\n");

//   Enable IRQ from PIO
  * core1_rx_edge = 0x1;
  * core1_rx_irq = 1;
  * core1_rx_edge = 0x1;
  NIOS2_WRITE_STATUS(0x1);	// Enable global interrupts
  NIOS2_WRITE_IENABLE(0x2);	// Set IRQ bit

  // mutex
  mutex = altera_avalon_mutex_open("/dev/SDRAM_mutex");
  if (!mutex) {
	  printf("Failed to open mutex!\n");
	  while (1);  // Halt here if mutex can't be opened
  }
  alt_putstr("Mutex opened\n");

  int N = *switches;
  *shared_N = N;
  printf("N = %2d\n", N);
  // send interrupt to core2's RX
  * core1_tx = 1;


  int (*A)[N] = (int (*)[N]) MATRIX_A_ADDR;       //  A: base
  matrix_rng(N, A);
  int (*B)[N] = (int (*)[N]) MATRIX_B_ADDR;       //  A: base
  matrix_rng(N, B);

  // print matrix A
  printf("A :\n");
  for (int i = 0; i < N; i++)
  {
	  for (int j = 0; j < N; j++)
	  {
		  printf("%d\t", A[i][j]);  // tab for spacing
	  }
	  printf("\n");  // new line after each row
  }

  // print matrix B
  printf("\nB :\n");
  for (int i = 0; i < N; i++)
  {
	  for (int j = 0; j < N; j++)
	  {
		  printf("%d\t", B[i][j]);  // tab for spacing
	  }
	  printf("\n");  // new line after each row
  }

  // start timer and compute
  unsigned int start_time = *us_counter;
  matrix_mult_partial(N, A, B, 0, N/2);

  // wait for core 2
  while (1) {
      altera_avalon_mutex_lock(mutex, 1);
      if (core2_ready == 1) {
          altera_avalon_mutex_unlock(mutex);
          break;
      }
      altera_avalon_mutex_unlock(mutex);
  }

  // end timer once core 2 writes to handshake
  unsigned int end_time = *us_counter;

  int (*C)[N] = (int (*)[N]) MATRIX_C_ADDR;       //  A: base

  // print matrix C
  printf("\nC :\n");
  for (int i = 0; i < N; i++)
  {
	  for (int j = 0; j < N; j++)
	  {
		  printf("%d\t", C[i][j]);  // tab for spacing
	  }
	  printf("\n");  // new line after each row
  }


  unsigned int elapsed_cycles = end_time - start_time;
  printf("\nElapsed time: %u us\n", elapsed_cycles);


  /* Event loop never exits. */
  while (1);

  return 0;
}

void matrix_multiplication(int N, int(*A)[N], int (*B)[N])
{
	int (*C)[N] = (int (*)[N]) MATRIX_C_ADDR;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			C[i][j] = 0;

			for (int k = 0; k < N; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	// Output result matrix C in the format shown
	printf("\nAxB :\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		{
			printf("%d\t", C[i][j]);  // tab for spacing
		}
		printf("\n");  // new line after each row
	}
}

void matrix_rng(int N, int (*M)[N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			M[i][j] = rand() % 10;  // Random values from 0 to 9
		}
	}
}

void matrix_mult_partial(int N, int (*A)[N], int (*B)[N], int start_row, int end_row)
{
	int (*C)[N] = (int (*)[N]) MATRIX_C_ADDR;

	for (int i = start_row; i < end_row; i++) {
		for (int j = 0; j < N; j++) {
			C[i][j] = 0;

			for (int k = 0; k < N; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

