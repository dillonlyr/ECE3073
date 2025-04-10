#include "nios2_ctrl_reg_macros.h"
#include "stdio.h"
#include "alt_types.h"
#include "io.h"

// function prototypes int main(void);
void interrupt_handler(void); void the_exception(void);

/* Declare volatile pointers to I/O registers. This will ensure that the resulting code will bypass the cache*/
volatile int * GPIO = (int *) 0x4009030; // GPIO
volatile int * Input_Key1 = (int *) 0x4009010; // KEY[1]
volatile int * Output_LEDR = (int *) 0x4009040; // LED[7:0]
volatile int * Output_LED8 = (int *) 0x4009000; // LED[8]

// MSB PIO addresses
volatile int * Input_MSB = (int *) 0x4009020; // MSB
volatile int * Input_MSB_IRQ = (int *) 0x4009028;
volatile int * Input_MSB_EDGECAPTURE = (int *) 0x400902C;

// MSB counter
volatile int interrupt_counter = 0;

int main(void)
{
	puts("Running Lab4\n");

	int sleepy = 0;
	int temp_counter = 0;

	// KEY[1] LED[8] variables
	int prev_Key1 = 1;

	// Below 3 lines of code will be needed to set interrupts 
	// 1. set up rising edge triggered interrupts for the counter PIO
	* Input_MSB_IRQ = 0x01;
	// 2. set interrupt enable mask bit for counter IRQ level 0
	NIOS2_WRITE_IENABLE(0x01);
	// 3. enable NIOS II interrupts (PIE bit in status register)
	NIOS2_WRITE_STATUS(0x01);

	while (1) // infinite loop
	{
		if ( (!prev_Key1) && *(Input_Key1))// previous Key[1] state && current Key[1] state
		{
			*(Output_LED8) = ++*(Output_LED8);
		}
		prev_Key1 = *(Input_Key1);

		// Write the code for toggling the LED8- same as poling part
		// Add codes like below a long for loop that ensures debouncing // of switch not read
		for(sleepy = 0; sleepy < 10000; sleepy++)
		{
			temp_counter++; //for loop needs some code to be run
		}
	}
}
