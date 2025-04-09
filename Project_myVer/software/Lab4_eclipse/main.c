#include "nios2_ctrl_reg_macros.h"
#include "stdio.h"
#include <unistd.h>   // for usleep()

// function prototypes int main(void);
void interrupt_handler(void); void the_exception(void);

/* Declare volatile pointers to I/O registers. This will ensure that the resulting code will bypass the cache*/

// Lab 3 pins
volatile int * GPIO = (int *) 0x40090a0; // GPIO
volatile int * Output_LEDR = (int *) 0x40090b0; // LED[9:0]

// MSB PIO addresses
volatile int * Input_MSB = (int *) 0x4009090; // MSB
volatile int * Input_MSB_IRQ = (int *) 0x4009098;
volatile int * Input_MSB_EDGECAPTURE = (int *) 0x400909C;

// Stepper motor pinouts
volatile int * stepper_pin1 = (int *) 0x4009070; //
volatile int * stepper_pin2 = (int *) 0x4009060; //
volatile int * stepper_pin3 = (int *) 0x4009050; //
volatile int * stepper_pin4 = (int *) 0x4009040; //

// MSB counter
volatile int interrupt_counter = 0;

int main(void)
{
	puts("Running Lab4\n");

	int sleepy = 0;
	int temp_counter = 0;
	int stage = 1;
	int one = 1;
	int two = 2;
	int three = 3;
	int four = 4;

	// KEY[1] variables
	int prev_Key1 = 1;
	// MSB clock variables
	int prev_MSB_flag = *(Input_MSB);

	// Below 3 lines of code will be needed to set interrupts (set all to 1 to turn on)
	// 1. set up rising edge triggered interrupts for the counter PIO
	* Input_MSB_IRQ = 0x00;
	// 2. set interrupt enable mask bit for counter IRQ level 0
	NIOS2_WRITE_IENABLE(0x01);
	// 3. enable NIOS II interrupts (PIE bit in status register)
	NIOS2_WRITE_STATUS(0x01);

	while (1) // infinite loop
	{
		//--- MSB checking ------------------------------------------------------------------------------/
		if ( (!prev_MSB_flag) && *(Input_MSB) && 0x01)// previous MSB state && current MSB state && 1
		{
			*(GPIO) = 0x01;
			*(Output_LEDR) = *(Output_LEDR) + 1;
			*(GPIO) = 0x00;

			//--- Cycle 4 pins ------------------//
			if (stage == 1)
			{
				*stepper_pin1 = 1;
				*stepper_pin2 = 0;
				*stepper_pin3 = 0;
				*stepper_pin4 = 0;
				stage = 0x2;
//				puts("In Stage 1\n");
				usleep(1000);
			}
			else if (stage == 2)
			{
				*stepper_pin1 = 1;
				*stepper_pin2 = 1;
				*stepper_pin3 = 0;
				*stepper_pin4 = 0;
				stage = 0x3;
//				puts("In Stage 2\n");
				usleep(1000);
			}
			else if (stage == 3)
			{
				*stepper_pin1 = 0;
				*stepper_pin2 = 1;
				*stepper_pin3 = 0;
				*stepper_pin4 = 0;
				stage = 0x4;
//				puts("In Stage 3\n");
				usleep(1000);
			}
			else if (stage == 4)
			{
				*stepper_pin1 = 0;
				*stepper_pin2 = 1;
				*stepper_pin3 = 1;
				*stepper_pin4 = 0;
				stage = 5;
//				puts("In Stage 4\n");
				usleep(1000);
			}
			else if (stage == 5)
			{
				*stepper_pin1 = 0;
				*stepper_pin2 = 0;
				*stepper_pin3 = 1;
				*stepper_pin4 = 0;
				stage = 6;
//				puts("In Stage 5\n");
				usleep(1000);
			}
			else if (stage == 6)
			{
				*stepper_pin1 = 0;
				*stepper_pin2 = 0;
				*stepper_pin3 = 1;
				*stepper_pin4 = 1;
				stage = 7;
//				puts("In Stage 6\n");
				usleep(1000);
			}
			else if (stage == 7)
			{
				*stepper_pin1 = 0;
				*stepper_pin2 = 0;
				*stepper_pin3 = 0;
				*stepper_pin4 = 1;
				stage = 8;
//				puts("In Stage 7\n");
				usleep(1000);
			}
			else if (stage == 8)
			{
				*stepper_pin1 = 1;
				*stepper_pin2 = 0;
				*stepper_pin3 = 0;
				*stepper_pin4 = 1;
				stage = 1;
//				puts("In Stage 8\n");
				usleep(1000);
			}
			//-----------------------------------//

		}
		prev_MSB_flag = *(Input_MSB);
		//-----------------------------------------------------------------------------------------------/


		// Write the code for toggling the LED8- same as poling part
		// Add codes like below a long for loop that ensures debouncing // of switch not read
//		for(sleepy = 0; sleepy < 10000; sleepy++)
//		{
//			temp_counter++; //for loop needs some code to be run
//		}
	}
}
