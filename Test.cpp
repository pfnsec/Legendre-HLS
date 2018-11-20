#include <iostream>
#include "Legendre.hpp"

using namespace std;

int main()
{
  data_t pn ;

  cout.precision(5) ;

  for (iter_t n = 0 ; n <= 5 ; n++)
  {
    for (data_t x = (data_t) -1.0 ; x <= (data_t) 1.0 ; x = x + (data_t) 0.1)
    { 
      pn = Pn(n, x) ;
      cout << "P" << n << "(" << x << ") = " << pn << endl ;
    }
    cout << endl ;
  }

  return 0 ;
}


