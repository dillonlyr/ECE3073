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
#include "stdio.h"

/* Declare volatile pointers to I/O registers. This will ensure that the resulting code will bypass the cache*/
volatile int * stepper_pin1 = (int *) 0x4009030; // GPIO
volatile int * stepper_pin2 = (int *) 0x4009020; // KEY[1]
volatile int * stepper_pin3 = (int *) 0x4009010; // LED[7:0]
volatile int * stepper_pin4 = (int *) 0x4009000; // LED[8]

// MSB PIO addresses
volatile int * Input_MSB = (int *) 0x4009060; // MSB

int temp_counter = 0;
volatile int stage = 1;

void sleep(void)
{
	for(int sleepy = 0; sleepy < 999999999; sleepy++)
	{
		temp_counter++; //for loop needs some code to be run
	}
}

int main()
{ 
	alt_putstr("Running stepper motor code\n");
	int prev_MSB_flag = *(Input_MSB);

	/* Event loop never exits. */
	while (1)
	{
		//MSB checking
		if ( (!prev_MSB_flag) && *(Input_MSB) && 0x01)// previous MSB state && current MSB state && 1
		{

			if (stage && 0x01)
			{
				*stepper_pin1 = 1;
				*stepper_pin2 = 0;
				*stepper_pin3 = 0;
				*stepper_pin4 = 0;
			}

			else if (stage && 0x02)
			{
				*stepper_pin1 = 0;
				*stepper_pin2 = 1;
				*stepper_pin3 = 0;
				*stepper_pin4 = 0;
			}

			else if (stage && 0x03)
			{
				*stepper_pin1 = 0;
				*stepper_pin2 = 0;
				*stepper_pin3 = 1;
				*stepper_pin4 = 0;
			}

			else if (stage && 0x04)
			{
				*stepper_pin1 = 0;
				*stepper_pin2 = 0;
				*stepper_pin3 = 0;
				*stepper_pin4 = 1;
			}

		}
		stage++;
		prev_MSB_flag = *(Input_MSB);
  }

  return 0;
}
