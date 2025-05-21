
module Lab6_v2_NiosProc (
	clk_clk,
	pushbuttons_export,
	reset_reset_n,
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
	us_counter_export);	

	input		clk_clk;
	input	[1:0]	pushbuttons_export;
	input		reset_reset_n;
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
	input	[31:0]	us_counter_export;
endmodule
