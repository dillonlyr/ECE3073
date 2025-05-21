	Lab6_v2_NiosProc u0 (
		.pushbuttons_export         (<connected-to-pushbuttons_export>),         //          pushbuttons.export
		.sdram_shared_wire_addr     (<connected-to-sdram_shared_wire_addr>),     //    sdram_shared_wire.addr
		.sdram_shared_wire_ba       (<connected-to-sdram_shared_wire_ba>),       //                     .ba
		.sdram_shared_wire_cas_n    (<connected-to-sdram_shared_wire_cas_n>),    //                     .cas_n
		.sdram_shared_wire_cke      (<connected-to-sdram_shared_wire_cke>),      //                     .cke
		.sdram_shared_wire_cs_n     (<connected-to-sdram_shared_wire_cs_n>),     //                     .cs_n
		.sdram_shared_wire_dq       (<connected-to-sdram_shared_wire_dq>),       //                     .dq
		.sdram_shared_wire_dqm      (<connected-to-sdram_shared_wire_dqm>),      //                     .dqm
		.sdram_shared_wire_ras_n    (<connected-to-sdram_shared_wire_ras_n>),    //                     .ras_n
		.sdram_shared_wire_we_n     (<connected-to-sdram_shared_wire_we_n>),     //                     .we_n
		.slider_switches_export     (<connected-to-slider_switches_export>),     //      slider_switches.export
		.system_pll_ref_clk_clk     (<connected-to-system_pll_ref_clk_clk>),     //   system_pll_ref_clk.clk
		.system_pll_ref_reset_reset (<connected-to-system_pll_ref_reset_reset>), // system_pll_ref_reset.reset
		.system_pll_sdram_clk_clk   (<connected-to-system_pll_sdram_clk_clk>),   // system_pll_sdram_clk.clk
		.us_counter_export          (<connected-to-us_counter_export>)           //           us_counter.export
	);

