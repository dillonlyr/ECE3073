	lab3_component u0 (
		.clk_clk             (<connected-to-clk_clk>),             //          clk.clk
		.clk_20bit_export    (<connected-to-clk_20bit_export>),    //    clk_20bit.export
		.clk_25mhz_export    (<connected-to-clk_25mhz_export>),    //    clk_25mhz.export
		.dram_addr           (<connected-to-dram_addr>),           //         dram.addr
		.dram_ba             (<connected-to-dram_ba>),             //             .ba
		.dram_cas_n          (<connected-to-dram_cas_n>),          //             .cas_n
		.dram_cke            (<connected-to-dram_cke>),            //             .cke
		.dram_cs_n           (<connected-to-dram_cs_n>),           //             .cs_n
		.dram_dq             (<connected-to-dram_dq>),             //             .dq
		.dram_dqm            (<connected-to-dram_dqm>),            //             .dqm
		.dram_ras_n          (<connected-to-dram_ras_n>),          //             .ras_n
		.dram_we_n           (<connected-to-dram_we_n>),           //             .we_n
		.gpio_export         (<connected-to-gpio_export>),         //         gpio.export
		.hex2to0_export      (<connected-to-hex2to0_export>),      //      hex2to0.export
		.hex5to3_export      (<connected-to-hex5to3_export>),      //      hex5to3.export
		.key1to0_export      (<connected-to-key1to0_export>),      //      key1to0.export
		.led9to0_export      (<connected-to-led9to0_export>),      //      led9to0.export
		.stepper_pin1_export (<connected-to-stepper_pin1_export>), // stepper_pin1.export
		.stepper_pin2_export (<connected-to-stepper_pin2_export>), // stepper_pin2.export
		.stepper_pin3_export (<connected-to-stepper_pin3_export>), // stepper_pin3.export
		.stepper_pin4_export (<connected-to-stepper_pin4_export>), // stepper_pin4.export
		.sw9to0_export       (<connected-to-sw9to0_export>)        //       sw9to0.export
	);

