	component workers is
		port (
			clk_clk                  : in  std_logic                     := 'X';             -- clk
			reset_reset_n            : in  std_logic                     := 'X';             -- reset_n
			w_data_out_waitrequest   : in  std_logic                     := 'X';             -- waitrequest
			w_data_out_readdata      : in  std_logic_vector(31 downto 0) := (others => 'X'); -- readdata
			w_data_out_readdatavalid : in  std_logic                     := 'X';             -- readdatavalid
			w_data_out_burstcount    : out std_logic_vector(0 downto 0);                     -- burstcount
			w_data_out_writedata     : out std_logic_vector(31 downto 0);                    -- writedata
			w_data_out_address       : out std_logic_vector(27 downto 0);                    -- address
			w_data_out_write         : out std_logic;                                        -- write
			w_data_out_read          : out std_logic;                                        -- read
			w_data_out_byteenable    : out std_logic_vector(3 downto 0);                     -- byteenable
			w_data_out_debugaccess   : out std_logic;                                        -- debugaccess
			w_all_out_waitrequest    : in  std_logic                     := 'X';             -- waitrequest
			w_all_out_readdata       : in  std_logic_vector(31 downto 0) := (others => 'X'); -- readdata
			w_all_out_readdatavalid  : in  std_logic                     := 'X';             -- readdatavalid
			w_all_out_burstcount     : out std_logic_vector(0 downto 0);                     -- burstcount
			w_all_out_writedata      : out std_logic_vector(31 downto 0);                    -- writedata
			w_all_out_address        : out std_logic_vector(27 downto 0);                    -- address
			w_all_out_write          : out std_logic;                                        -- write
			w_all_out_read           : out std_logic;                                        -- read
			w_all_out_byteenable     : out std_logic_vector(3 downto 0);                     -- byteenable
			w_all_out_debugaccess    : out std_logic                                         -- debugaccess
		);
	end component workers;

	u0 : component workers
		port map (
			clk_clk                  => CONNECTED_TO_clk_clk,                  --        clk.clk
			reset_reset_n            => CONNECTED_TO_reset_reset_n,            --      reset.reset_n
			w_data_out_waitrequest   => CONNECTED_TO_w_data_out_waitrequest,   -- w_data_out.waitrequest
			w_data_out_readdata      => CONNECTED_TO_w_data_out_readdata,      --           .readdata
			w_data_out_readdatavalid => CONNECTED_TO_w_data_out_readdatavalid, --           .readdatavalid
			w_data_out_burstcount    => CONNECTED_TO_w_data_out_burstcount,    --           .burstcount
			w_data_out_writedata     => CONNECTED_TO_w_data_out_writedata,     --           .writedata
			w_data_out_address       => CONNECTED_TO_w_data_out_address,       --           .address
			w_data_out_write         => CONNECTED_TO_w_data_out_write,         --           .write
			w_data_out_read          => CONNECTED_TO_w_data_out_read,          --           .read
			w_data_out_byteenable    => CONNECTED_TO_w_data_out_byteenable,    --           .byteenable
			w_data_out_debugaccess   => CONNECTED_TO_w_data_out_debugaccess,   --           .debugaccess
			w_all_out_waitrequest    => CONNECTED_TO_w_all_out_waitrequest,    --  w_all_out.waitrequest
			w_all_out_readdata       => CONNECTED_TO_w_all_out_readdata,       --           .readdata
			w_all_out_readdatavalid  => CONNECTED_TO_w_all_out_readdatavalid,  --           .readdatavalid
			w_all_out_burstcount     => CONNECTED_TO_w_all_out_burstcount,     --           .burstcount
			w_all_out_writedata      => CONNECTED_TO_w_all_out_writedata,      --           .writedata
			w_all_out_address        => CONNECTED_TO_w_all_out_address,        --           .address
			w_all_out_write          => CONNECTED_TO_w_all_out_write,          --           .write
			w_all_out_read           => CONNECTED_TO_w_all_out_read,           --           .read
			w_all_out_byteenable     => CONNECTED_TO_w_all_out_byteenable,     --           .byteenable
			w_all_out_debugaccess    => CONNECTED_TO_w_all_out_debugaccess     --           .debugaccess
		);

