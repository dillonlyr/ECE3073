
module lab3_component (
	clk_clk,
	clk_20bit_export,
	clk_25mhz_export,
	dram_addr,
	dram_ba,
	dram_cas_n,
	dram_cke,
	dram_cs_n,
	dram_dq,
	dram_dqm,
	dram_ras_n,
	dram_we_n,
	gpio_export,
	hex2to0_export,
	hex5to3_export,
	key1to0_export,
	led9to0_export,
	stepper_pin1_export,
	stepper_pin2_export,
	stepper_pin3_export,
	stepper_pin4_export,
	sw9to0_export);	

	input		clk_clk;
	input		clk_20bit_export;
	input		clk_25mhz_export;
	output	[12:0]	dram_addr;
	output	[1:0]	dram_ba;
	output		dram_cas_n;
	output		dram_cke;
	output		dram_cs_n;
	inout	[15:0]	dram_dq;
	output	[1:0]	dram_dqm;
	output		dram_ras_n;
	output		dram_we_n;
	output		gpio_export;
	output	[23:0]	hex2to0_export;
	output	[23:0]	hex5to3_export;
	input	[1:0]	key1to0_export;
	output	[9:0]	led9to0_export;
	output		stepper_pin1_export;
	output		stepper_pin2_export;
	output		stepper_pin3_export;
	output		stepper_pin4_export;
	input	[9:0]	sw9to0_export;
endmodule
