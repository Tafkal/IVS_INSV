set_global_assignment -name FAMILY "Cyclone IV E"
set_global_assignment -name DEVICE EP4CE22F17C6
set_global_assignment -name DEVICE_FILTER_PACKAGE FBGA
set_global_assignment -name DEVICE_FILTER_PIN_COUNT 256
set_global_assignment -name DEVICE_FILTER_SPEED_GRADE 6
set_global_assignment -name RESERVE_ALL_UNUSED_PINS "AS INPUT TRI-STATED"

# clock
set_location_assignment PIN_R8 -to clk_50MHz
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to clk_50MHz

# reset - button
set_location_assignment PIN_J15 -to reset_n
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to reset_n

set_location_assignment PIN_P2  -to sdram_addr[0]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_addr[0]
set_location_assignment PIN_N5  -to sdram_addr[1]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_addr[1]
set_location_assignment PIN_N6  -to sdram_addr[2]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_addr[2]
set_location_assignment PIN_M8  -to sdram_addr[3]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_addr[3]
set_location_assignment PIN_P8  -to sdram_addr[4]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_addr[4]
set_location_assignment PIN_T7  -to sdram_addr[5]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_addr[5]
set_location_assignment PIN_N8  -to sdram_addr[6]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_addr[6]
set_location_assignment PIN_T6  -to sdram_addr[7]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_addr[7]
set_location_assignment PIN_R1  -to sdram_addr[8]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_addr[8]
set_location_assignment PIN_P1  -to sdram_addr[9]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_addr[9]
set_location_assignment PIN_N2  -to sdram_addr[10]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_addr[10]
set_location_assignment PIN_N1  -to sdram_addr[11]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_addr[11]
set_location_assignment PIN_L4  -to sdram_addr[12]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_addr[12]

set_location_assignment PIN_G2  -to sdram_dq[0]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_dq[0]
set_location_assignment PIN_G1  -to sdram_dq[1]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_dq[1]
set_location_assignment PIN_L8  -to sdram_dq[2]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_dq[2]
set_location_assignment PIN_K5  -to sdram_dq[3]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_dq[3]
set_location_assignment PIN_K2  -to sdram_dq[4]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_dq[4]
set_location_assignment PIN_J2  -to sdram_dq[5]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_dq[5]
set_location_assignment PIN_J1  -to sdram_dq[6]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_dq[6]
set_location_assignment PIN_R7  -to sdram_dq[7]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_dq[7]
set_location_assignment PIN_T4  -to sdram_dq[8]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_dq[8]
set_location_assignment PIN_T2  -to sdram_dq[9]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_dq[9]
set_location_assignment PIN_T3  -to sdram_dq[10]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_dq[10]
set_location_assignment PIN_R3  -to sdram_dq[11]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_dq[11]
set_location_assignment PIN_R5  -to sdram_dq[12]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_dq[12]
set_location_assignment PIN_P3  -to sdram_dq[13]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_dq[13]
set_location_assignment PIN_N3  -to sdram_dq[14]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_dq[14]
set_location_assignment PIN_K1  -to sdram_dq[15]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_dq[15]


set_location_assignment PIN_M7  -to sdram_ba[0]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_ba[0]
set_location_assignment PIN_M6  -to sdram_ba[1]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_ba[1]

set_location_assignment PIN_R6  -to sdram_dqm[0]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_dqm[0]
set_location_assignment PIN_T5  -to sdram_dqm[1]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_dqm[1]

set_location_assignment PIN_L7  -to sdram_cke
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_cke
set_location_assignment PIN_R4  -to sdram_clk
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_clk

set_location_assignment PIN_P6  -to sdram_cs_n
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_cs_n
set_location_assignment PIN_L2  -to sdram_ras_n
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_ras_n
set_location_assignment PIN_L1  -to sdram_cas_n
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_cas_n
set_location_assignment PIN_C2  -to sdram_we_n
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sdram_we_n

