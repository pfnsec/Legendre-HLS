#ifndef LEGENDRE_HPP
#define LEGENDRE_HPP

#include "ap_int.h"
#include "ap_fixed.h"
#include "stdint.h"

//Set the precision as appropriate for your application
typedef ap_fixed<16,8> data_t;
typedef ap_int<8> iter_t;


data_t P0(data_t x);

data_t P1(data_t x);

data_t P2(data_t x);

data_t Pn(iter_t n, data_t x);


#endif

