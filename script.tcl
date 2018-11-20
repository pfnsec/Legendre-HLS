open_project legendre_hls
set_top Pn

set tb_flags "-Wno-unknown-pragmas -D_XILINX"

add_files Legendre.cpp 
add_files Legendre.hpp 

add_files -tb Test.cpp -cflags $tb_flags

open_solution "legendre"

set_part {xczu3eg-sbva484-1-e} -tool vivado
create_clock -period 10 -name default
csim_design
csynth_design
cosim_design
export_design -format ip_catalog

