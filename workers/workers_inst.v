	workers u0 (
		.clk_clk                  (<connected-to-clk_clk>),                  //        clk.clk
		.reset_reset_n            (<connected-to-reset_reset_n>),            //      reset.reset_n
		.w_data_out_waitrequest   (<connected-to-w_data_out_waitrequest>),   // w_data_out.waitrequest
		.w_data_out_readdata      (<connected-to-w_data_out_readdata>),      //           .readdata
		.w_data_out_readdatavalid (<connected-to-w_data_out_readdatavalid>), //           .readdatavalid
		.w_data_out_burstcount    (<connected-to-w_data_out_burstcount>),    //           .burstcount
		.w_data_out_writedata     (<connected-to-w_data_out_writedata>),     //           .writedata
		.w_data_out_address       (<connected-to-w_data_out_address>),       //           .address
		.w_data_out_write         (<connected-to-w_data_out_write>),         //           .write
		.w_data_out_read          (<connected-to-w_data_out_read>),          //           .read
		.w_data_out_byteenable    (<connected-to-w_data_out_byteenable>),    //           .byteenable
		.w_data_out_debugaccess   (<connected-to-w_data_out_debugaccess>),   //           .debugaccess
		.w_all_out_waitrequest    (<connected-to-w_all_out_waitrequest>),    //  w_all_out.waitrequest
		.w_all_out_readdata       (<connected-to-w_all_out_readdata>),       //           .readdata
		.w_all_out_readdatavalid  (<connected-to-w_all_out_readdatavalid>),  //           .readdatavalid
		.w_all_out_burstcount     (<connected-to-w_all_out_burstcount>),     //           .burstcount
		.w_all_out_writedata      (<connected-to-w_all_out_writedata>),      //           .writedata
		.w_all_out_address        (<connected-to-w_all_out_address>),        //           .address
		.w_all_out_write          (<connected-to-w_all_out_write>),          //           .write
		.w_all_out_read           (<connected-to-w_all_out_read>),           //           .read
		.w_all_out_byteenable     (<connected-to-w_all_out_byteenable>),     //           .byteenable
		.w_all_out_debugaccess    (<connected-to-w_all_out_debugaccess>)     //           .debugaccess
	);

