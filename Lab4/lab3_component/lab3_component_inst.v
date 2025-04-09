	lab3_component u0 (
		.clk_clk     (<connected-to-clk_clk>),     //  clk.clk
		.dram_addr   (<connected-to-dram_addr>),   // dram.addr
		.dram_ba     (<connected-to-dram_ba>),     //     .ba
		.dram_cas_n  (<connected-to-dram_cas_n>),  //     .cas_n
		.dram_cke    (<connected-to-dram_cke>),    //     .cke
		.dram_cs_n   (<connected-to-dram_cs_n>),   //     .cs_n
		.dram_dq     (<connected-to-dram_dq>),     //     .dq
		.dram_dqm    (<connected-to-dram_dqm>),    //     .dqm
		.dram_ras_n  (<connected-to-dram_ras_n>),  //     .ras_n
		.dram_we_n   (<connected-to-dram_we_n>),   //     .we_n
		.gpio_export (<connected-to-gpio_export>), // gpio.export
		.key1_export (<connected-to-key1_export>), // key1.export
		.led_export  (<connected-to-led_export>),  //  led.export
		.led8_export (<connected-to-led8_export>), // led8.export
		.msb_export  (<connected-to-msb_export>)   //  msb.export
	);

