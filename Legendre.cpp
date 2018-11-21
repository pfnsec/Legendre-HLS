#include "ap_int.h"
#include "ap_fixed.h"
#include "stdint.h"

#include "Legendre.hpp"


// n = 0
inline data_t P0(data_t x)
{
  return (data_t) 1.0 ;
}

// n = 1
inline data_t P1(data_t x)
{
  return x ;
}

// n = 2
data_t P2(data_t x)
{
  return (((data_t) 3.0 * x*x) - (data_t) 1.0) * (data_t) 0.5 ;
}

/*
 *	Pn(x)
 */
data_t Pn(iter_t n, data_t x) {


  if (n == 0) {
    return P0(x);
  }

  if (n == 1) {
    return P1(x);
  } 

  if (n == 2) {
    return P2(x);
  }
  


  if (x == (data_t) 1.0) {
    return (data_t) 1.0 ;
  }

  if (x == (data_t) -1.0) {
    return ((n % 2 == 0) ? (data_t)  1.0 
                         : (data_t) -1.0) ;
  }

  if ((x == 0.0) && (n % 2)) {
    return 0.0 ;
  }



  data_t pnm1 = P2(x);
  data_t pnm2 = P1(x);
  data_t pn   = pnm1;

  for (iter_t l = 3 ; l <= n ; l++)
#pragma HLS unroll
  { 
    data_t i = (data_t) l;

    pn = ((2 * i) - 1) * x * pnm1;

    pn = pn - ((i - 1) * pnm2);

    pn = pn / i;

    pnm2 = pnm1;

    pnm1 = pn;
  }

  return pn;
}
