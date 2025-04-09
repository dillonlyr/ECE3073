#include "nios2_ctrl_reg_macros.h"


// function prototypes int main(void);
void interrupt_handler(void); void the_exception(void);

/* Declare volatile pointers to I/O registers. This will ensure that the resulting code will bypass the cache*/

// Example declarations shown below
//volatile int * OutPort_LEDR = (int *) 0x04009040; // 8 Led
//volatile int * InPort_COUNTER = (int *) 0x04009020; // MSB
volatile int * GPIO = (int *) 0x04009030; // GPIO
volatile int * OutPort_LEDR = (int *) 0x04009040; // 8 LED
volatile int * InPort_SW2 = (int *) 0x04009010; // Key[1]
volatile int * OutPort_LEDG = (int *) 0x04009000; // Flag LED [LED 8]
volatile int *InPort_COUNTER = (int *) 0x04009020;  // Counter MSB
volatile int *InPort_COUNTER_IRQMASK = (int *) (0x04009028);  // IRQ mask
volatile int *InPort_COUNTER_EDGECAP = (int *) (0x0400902c);  // Edge capture
volatile int interrupt_count = 0;

int main(void)
{
	int sleepy = 0;
	int temp_counter = 0;
	int prev;
	prev = *(InPort_SW2);

	// Below 3 lines of code will be needed to set interrupts
	// 1. set up rising edge triggered interrupts for the counter PIO
	*InPort_COUNTER_IRQMASK = 1;  // Enable interrupt for counter
//	*InPort_COUNTER_EDGECAP = 0xFFFFFFFF;  // Clear any previous edge capture
	// 2. set interrupt enable mask bit for counter IRQ level 0
	NIOS2_WRITE_IENABLE(1);
	//3. enable Nios II interrupts (PIE bit in status register)
	NIOS2_WRITE_STATUS(0x1);

	while (1) //normal code infinite loop
	{

		// Write the code for toggling the LED8- same as poling part
		if ( (prev) && !*(InPort_SW2))
		{
			*(OutPort_LEDG) = *(OutPort_LEDG) + 0x01;
		}
		prev = *(InPort_SW2);
		// Add codes like below a long for loop that ensures debouncing //of switch not read
		for(sleepy = 0; sleepy < 10000; sleepy++)
		{
			temp_counter++; //for loop needs some code to be run
		}
	}
}
