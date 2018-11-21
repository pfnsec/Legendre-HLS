#ifndef LEGENDRE_HPP
#define LEGENDRE_HPP

#include "ap_int.h"
#include "ap_fixed.h"
#include "stdint.h"

//Set the precision as appropriate for your application
typedef ap_fixed<32,16> data_t;
typedef ap_fixed<64,32> accum_t;
typedef ap_int<8> iter_t;


data_t P0(data_t x);

data_t P1(data_t x);

data_t P2(data_t x);

data_t Pn(iter_t n, data_t x);

uint64_t LegendreTransform(uint64_t *srcBase, 
                           uint32_t  n,  
                           uint32_t  size);


#endif

