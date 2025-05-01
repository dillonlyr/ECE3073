/* Declare volatile pointers to I/O registers. This will ensure the
compiler does not optimize the variable out of the disassembly */

# include "sys/alt_stdio.h"
# include "io.h"

volatile int * dram_address = (int *) 0x0000000;

int main()
{

	for (int i = 0; i < 1000; i++)
	{
		int memory_loc_val = (int)dram_address;
		// writing
		IOWR_32DIRECT(dram_address + i, 0, memory_loc_val + 4*i);

		// reading
		int readValue = IORD_32DIRECT(dram_address + i, 0);

		if (readValue == (memory_loc_val + 4*i))
			alt_putstr("yes\n");
		else
			alt_putstr("no\n");
	}
	// alt_printf("Number: 0x%08X\n",(unsigned long)readValue );

	return 0;
}
// 0x00000001
// 0x02000001
