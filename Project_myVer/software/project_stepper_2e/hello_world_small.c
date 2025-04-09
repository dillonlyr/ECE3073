//#include "nios2_ctrl_reg_macros.h"
#include "stdio.h"
#include <stdint.h>
#include <math.h>

// Function prototypes
void interrupt_handler(void); void the_exception(void);
void digit_circles(volatile int* hex_base_ptr, int delay_ms);
void display_idle(volatile int* hex0_base_ptr, volatile int* hex1_base_ptr,
		volatile int* hex2_base_ptr, volatile int* hex3_base_ptr, int delay_ms);
void increment_leds(volatile int* led_5_7_base_ptr, int delay_ms);
void delay(int delay_ms);
void stepper_motor(float degrees);
void rotate();

volatile int *STEPPER_MOTOR = (int *) 0x04041000;
volatile int *TIMER = (int *) 0x04041010;

int main()
{
	// Instantiate base addresses
	// 7-segments
	volatile int *HEX0 = (int *) 0x04041080;
	volatile int *HEX1 = (int *) 0x04041040;
	volatile int *HEX2 = (int *) 0x04041050;
	volatile int *HEX3 = (int *) 0x04041060;
	volatile int *HEX4 = (int *) 0x04041070;
	// LEDs
	volatile int *LED0 = (int *) 0x04041090;
	volatile int *LED1 = (int *) 0x04041030;
	volatile int *LED_5_7 = (int *) 0x04041020;


	printf("Hello from Nios II!\n");
	// Turn off all 7-segments
	*HEX0 = 0xFF;
	*HEX1 = 0xFF;
	*HEX2 = 0xFF;
	*HEX3 = 0xFF;
	*HEX4 = 0xFF;

	// Turn off all LEDs
	*LED0 = 0x0;
	*LED1 = 0x0;
	*LED_5_7 = 0x0;

	stepper_motor(90);

	/* Event loop never exits. */
	while (1)
	{
//		printf("Hello from Nios II!\n");
//		for (int i = 0; i < 3; i++)
//		{
//			increment_leds(LED_5_7, 1000);
//		}
//		*LED_5_7 = 0x0;steps

//		display_idle(HEX0, HEX1, HEX2, HEX3, 10000000);
	}

	return 0;
}

void digit_circles(volatile int* hex_base_ptr, int delay_ms)
{
	if (*hex_base_ptr == 0x00 || *hex_base_ptr == 0xFF) {
		*hex_base_ptr = 0b11111110;
	}
	else {
		*hex_base_ptr = 0b11000001 | (*hex_base_ptr << 0x1);
	}
	delay(delay_ms);
}

void display_idle(volatile int *hex0_base_ptr, volatile int* hex1_base_ptr,
		volatile int* hex2_base_ptr, volatile int* hex3_base_ptr, int delay_ms)
{
    // Display "IDLE" from hex3 to hex0
    *hex3_base_ptr = 0b11111001; // I
    *hex2_base_ptr = 0b10100001; // D
    *hex1_base_ptr = 0b11000111; // L
    *hex0_base_ptr = 0b10000110; // E

    // Delay for visibility or pacing
    delay(delay_ms);
}

void increment_leds(volatile int *led_5_7_base_ptr, int delay_ms) {
	*led_5_7_base_ptr = ((*led_5_7_base_ptr) << 1) | 0x1;
	delay(delay_ms);
}

void delay(int delay_ms) {
	int prev = 0;
	int counter = delay_ms * 10;
	while (counter > 0) {
		if (prev != (*TIMER)) {
				counter--;
		}
		prev = *TIMER;
	}
}

void stepper_motor(float degrees){

	float deg_per_step = 360.0/2048.0; // 0.17578125
	float steps = degrees / deg_per_step; //

	int half_step_sequence[8] =
	{
	    1, // 0b0001
	    3, // 0b0011
	    2, // 0b0010
	    5, // 0b0110
	    4, // 0b0100
	    12,// 0b1100
	    8, // 0b1000
	    9  // 0b1001
	};

	int full_step_sequence[8] =
	{
	    1, // 0b0001
	    2, // 0b0010
	    4, // 0b0100
	    8  // 0b1000
	};

	for (int i = 0; i < steps; i++)
	{
		int idx = i % 4;
		*(STEPPER_MOTOR) = full_step_sequence[idx];
		delay(3);
	}
}

