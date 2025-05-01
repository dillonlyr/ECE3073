#include "nios2_ctrl_reg_macros.h"
#include "stdio.h"

#define UART_IRQ_GLOBAL   (1u << 8)   // ie
#define UART_IRQ_RXRDY    (1u << 7)   // irrdy

// function prototypes int main(void);
void interrupt_handler(void); void the_exception(void);

/* Declare volatile pointers to I/O registers. This will ensure that the resulting code will bypass the cache*/
volatile int * UART = (int *) 0x4009000; // UART
//volatile int * uart_status = (int *) 0x40090;
volatile int * uart_ctrl = (int *) 0x400900C;
volatile int * UART_TX = (int *) 0x4009004;

volatile int * Input_Key1 = (int *) 0x04009040; // KEY[1]
volatile int * Output_LEDR = (int *) 0x04009070; // LED[7:0]
volatile int * Output_LED8 = (int *) 0x04009030; // LED[8]

volatile int * HEX0 = (int *) 0x04009020;

// MSB PIO addresses
volatile int * Input_MSB = (int *) 0x04009050; // MSB
volatile int * Input_MSB_IRQ = (int *) 0x04009058;
volatile int * Input_MSB_EDGECAPTURE = (int *) 0x0400905C;


// On the Altera RS-232 IP, bit-0 of the control reg is “RXRDYIE”


// MSB PIO addresses
//volatile int * Input_MSB = (int *) 0x4009020; // MSB
//volatile int * Input_MSB_IRQ = (int *) 0x4009028;
//volatile int * Input_MSB_EDGECAPTURE = (int *) 0x400902C;

// MSB counter
volatile int interrupt_counter = 0;

int main(void)
{
//	puts("\nRunning Lab5\n");
//	printf("interrupt_counter = %d\r\n", interrupt_counter);


	int sleepy = 0;
	int temp_counter = 0;

	// KEY[1] LED[8] variables
	int prev_Key1 = 1;

	// Below 3 lines of code will be needed to set interrupts
	* uart_ctrl = 0b10000000;
	* HEX0 = 0b11111111;
	* Input_MSB_EDGECAPTURE = 0x1;
	* Input_MSB_IRQ = 1;
	* Input_MSB_EDGECAPTURE = 0x1;
	NIOS2_WRITE_STATUS(0x1);	// Enable global interrupts (PIE = 1)
	NIOS2_WRITE_IENABLE(0x3);	// Set IRQ bit


	while (1) // infinite loop
	{
//		ald_putstr()

//		if (*uart_status & (1 << 7))
//		{ // Check IRRDY bit
//			char rec = (*UART) & 0xFF;
//			alt_putstr("RECEIVED: ");
//			alt_putchar(rec);
//			alt_putchar('\n');
//		}

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
