
module lab3_component (
	clk_clk,
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
	key1_export,
	led_export,
	led8_export,
	msb_export);	

	input		clk_clk;
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
	input		key1_export;
	output	[7:0]	led_export;
	output		led8_export;
	input		msb_export;
endmodule
