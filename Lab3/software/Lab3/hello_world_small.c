/* Declare volatile pointers to I/O registers. This will ensure the
compiler does not optimize the variable out of the disassembly */

# include "sys/alt_stdio.h"
#include "stdio.h"

volatile int * GPIO = (int *) 0x4009030; // GPIO
volatile int * Input_Key1 = (int *) 0x4009010; // KEY[1]
volatile int * Output_LEDR = (int *) 0x4009040; // LED[7:0]
volatile int * Output_LED8 = (int *) 0x4009000; // LED[8]
volatile int * Input_MSB = (int *) 0x4009020; // MSB

int main()
{
	puts("Running NIOS II int main()\n");

	int LED_counter = 1;
	int prev_MSB_flag;
	prev_MSB_flag = *(Input_MSB);
	int prev_Key1;
	prev_Key1 = 1;
	int output_LED = 1;


	alt_putstr("Running NIOS II\n");

	while(1)
	{
		// MSB checking
		if ( (!prev_MSB_flag) && *(Input_MSB) && 0x01)// previous MSB state && current MSB state && 1
		{
			*(GPIO) = 0x01;
			*(Output_LEDR) = LED_counter++;
			*(GPIO) = 0x00;
		}
		prev_MSB_flag = *(Input_MSB);
		//*(Output_LEDR) = LED_counter; // transfer the value to LEDR 1

		// KEY[1] checking
		if ( (!prev_Key1) && *(Input_Key1))// previous Key[1] state && current Key[1] state
		{
			*(Output_LED8) = *(Output_LED8) + 1;
		}
		prev_Key1 = *(Input_Key1);
	}

	return 0;
}
