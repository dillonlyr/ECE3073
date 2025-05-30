#include "stdio.h"
#include <unistd.h>   // for usleep()

/* Declare volatile pointers to I/O registers. This will ensure that the resulting code will bypass the cache*/

// Lab 3 pins
volatile int * GPIO = (int *) 0x4009070; // GPIO
volatile int * Input_Key1 = (int *) 0x4009050; // KEY[1]
volatile int * Output_LEDR = (int *) 0x4009080; // LED[7:0]
volatile int * Output_LED8 = (int *) 0x4009040; // LED[8]

// MSB PIO addresses
volatile int * Input_MSB = (int *) 0x4009060; // MSB
volatile int * Input_MSB_IRQ = (int *) 0x4009068;
volatile int * Input_MSB_EDGECAPTURE = (int *) 0x400906C;

// Stepper motor pinouts
volatile int * stepper_pin1 = (int *) 0x4009030; //
volatile int * stepper_pin2 = (int *) 0x4009020; //
volatile int * stepper_pin3 = (int *) 0x4009010; //
volatile int * stepper_pin4 = (int *) 0x4009000; //

// MSB counters
volatile int interrupt_counter = 0;

int main(void)
{
	puts("Stepper motor code\n");

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
	int delay = 1000;

	while (1) // infinite loop
	{
//		//--- MSB checking ------------------------------------------------------------------------------/
//		if ( (!prev_MSB_flag) && *(Input_MSB) && 0x01)// previous MSB state && current MSB state && 1
//		{
//			*(GPIO) = 0x01;
//			*(Output_LEDR) = *(Output_LEDR) + 1;
//			*(GPIO) = 0x00;

			//--- Cycle 4 pins ------------------//
			if (stage == 1)
			{
				*stepper_pin1 = 1;
				*stepper_pin2 = 0;
				*stepper_pin3 = 0;
				*stepper_pin4 = 0;
				stage = 0x2;
//				puts("In Stage 1\n");
				usleep(delay);
			}
			else if (stage == 2)
			{
				*stepper_pin1 = 1;
				*stepper_pin2 = 1;
				*stepper_pin3 = 0;
				*stepper_pin4 = 0;
				stage = 0x3;
//				puts("In Stage 2\n");
				usleep(delay);
			}
			else if (stage == 3)
			{
				*stepper_pin1 = 0;
				*stepper_pin2 = 1;
				*stepper_pin3 = 0;
				*stepper_pin4 = 0;
				stage = 0x4;
//				puts("In Stage 3\n");
				usleep(delay);
			}
			else if (stage == 4)
			{
				*stepper_pin1 = 0;
				*stepper_pin2 = 1;
				*stepper_pin3 = 1;
				*stepper_pin4 = 0;
				stage = 5;
//				puts("In Stage 4\n");
				usleep(delay);
			}
			else if (stage == 5)
			{
				*stepper_pin1 = 0;
				*stepper_pin2 = 0;
				*stepper_pin3 = 1;
				*stepper_pin4 = 0;
				stage = 6;
//				puts("In Stage 5\n");
				usleep(delay);
			}
			else if (stage == 6)
			{
				*stepper_pin1 = 0;
				*stepper_pin2 = 0;
				*stepper_pin3 = 1;
				*stepper_pin4 = 1;
				stage = 7;
//				puts("In Stage 6\n");
				usleep(delay);
			}
			else if (stage == 7)
			{
				*stepper_pin1 = 0;
				*stepper_pin2 = 0;
				*stepper_pin3 = 0;
				*stepper_pin4 = 1;
				stage = 8;
//				puts("In Stage 7\n");
				usleep(delay);
			}
			else if (stage == 8)
			{
				*stepper_pin1 = 1;
				*stepper_pin2 = 0;
				*stepper_pin3 = 0;
				*stepper_pin4 = 1;
				stage = 1;
//				puts("In Stage 8\n");
				usleep(delay);
			}
			//-----------------------------------//

//		}
//		prev_MSB_flag = *(Input_MSB);
		//-----------------------------------------------------------------------------------------------/


		//--- KEY[1] checking ---------------------------------------------------------------------------/
//		if ( (!prev_Key1) && *(Input_Key1))// previous Key[1] state && current Key[1] state
//		{
//			*(Output_LED8) = ++*(Output_LED8);
//		}
//		prev_Key1 = *(Input_Key1);
		//-----------------------------------------------------------------------------------------------/

		// Write the code for toggling the LED8- same as poling part
		// Add codes like below a long for loop that ensures debouncing // of switch not read
//		for(sleepy = 0; sleepy < 10000; sleepy++)
//		{
//			temp_counter++; //for loop needs some code to be run
//		}
	}
}
