
module workers (
	clk_clk,
	reset_reset_n,
	w_data_out_waitrequest,
	w_data_out_readdata,
	w_data_out_readdatavalid,
	w_data_out_burstcount,
	w_data_out_writedata,
	w_data_out_address,
	w_data_out_write,
	w_data_out_read,
	w_data_out_byteenable,
	w_data_out_debugaccess,
	w_all_out_waitrequest,
	w_all_out_readdata,
	w_all_out_readdatavalid,
	w_all_out_burstcount,
	w_all_out_writedata,
	w_all_out_address,
	w_all_out_write,
	w_all_out_read,
	w_all_out_byteenable,
	w_all_out_debugaccess);	

	input		clk_clk;
	input		reset_reset_n;
	input		w_data_out_waitrequest;
	input	[31:0]	w_data_out_readdata;
	input		w_data_out_readdatavalid;
	output	[0:0]	w_data_out_burstcount;
	output	[31:0]	w_data_out_writedata;
	output	[27:0]	w_data_out_address;
	output		w_data_out_write;
	output		w_data_out_read;
	output	[3:0]	w_data_out_byteenable;
	output		w_data_out_debugaccess;
	input		w_all_out_waitrequest;
	input	[31:0]	w_all_out_readdata;
	input		w_all_out_readdatavalid;
	output	[0:0]	w_all_out_burstcount;
	output	[31:0]	w_all_out_writedata;
	output	[27:0]	w_all_out_address;
	output		w_all_out_write;
	output		w_all_out_read;
	output	[3:0]	w_all_out_byteenable;
	output		w_all_out_debugaccess;
endmodule
