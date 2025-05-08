
module Lab6_NIOS (
	key1_export,
	sdram_shared_wire_addr,
	sdram_shared_wire_ba,
	sdram_shared_wire_cas_n,
	sdram_shared_wire_cke,
	sdram_shared_wire_cs_n,
	sdram_shared_wire_dq,
	sdram_shared_wire_dqm,
	sdram_shared_wire_ras_n,
	sdram_shared_wire_we_n,
	slider_switches_export,
	sys_pll_ref_clk_clk,
	sys_pll_ref_reset_reset,
	sys_pll_sdram_clk_clk,
	us_counter_export);	

	input	[1:0]	key1_export;
	output	[12:0]	sdram_shared_wire_addr;
	output	[1:0]	sdram_shared_wire_ba;
	output		sdram_shared_wire_cas_n;
	output		sdram_shared_wire_cke;
	output		sdram_shared_wire_cs_n;
	inout	[15:0]	sdram_shared_wire_dq;
	output	[1:0]	sdram_shared_wire_dqm;
	output		sdram_shared_wire_ras_n;
	output		sdram_shared_wire_we_n;
	input	[9:0]	slider_switches_export;
	input		sys_pll_ref_clk_clk;
	input		sys_pll_ref_reset_reset;
	output		sys_pll_sdram_clk_clk;
	input	[31:0]	us_counter_export;
endmodule
