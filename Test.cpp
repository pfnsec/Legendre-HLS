#include <iostream>
#include <fstream>
#include <cmath>
#include "Legendre.hpp"

using namespace std;

int main()
{
  data_t pn ;

  cout.precision(5) ;

  /*j
  for (iter_t n = 0 ; n <= 5 ; n++)
  {
    for (data_t x = (data_t) -1.0 ; x <= (data_t) 1.0 ; x = x + (data_t) 0.1)
    { 
      pn = Pn(n, x) ;
      cout << "P" << n << "(" << x << ") = " << pn << endl ;
    }
    cout << endl ;
  }
  */


  uint32_t size = 512;
  
  uint64_t data[size];

  //Number of Legendre transforms to run 
  int ncoffs = 5;

  data_t x_s = -1.0;
  data_t dx = 2.0 / size;

  accum_t coeffs[ncoffs];


  //Legendre polynomial arrays
  uint64_t L[ncoffs][size];

  for(int i = 0; i < ncoffs; i++) {
      for(int j = 0; j < size; j++) {
          L[i][j] = 0;

          //Sum up the contribution from C0*P0, C1*P1, etc, so that L[5] is the sum
          //of 5 Legendre polynomials 
          for(int k = 0; k < i; k++) {
              L[i][j] += (uint64_t) ((coeffs[i]) * Pn( 
                            (iter_t)  i, 
                            (x_s + dx * j)
                         ));
          }
      }
  }



  for (iter_t n = 0 ; n <= ncoffs; n++) {
      coeffs[n] = LegendreTransform(data, n, size);
  }


  std::ofstream outfile;
  outfile.open ("output.csv");
  for(int j = 0; j < size; j++) {
      outfile << (x_s + dx * j);

           
      for(int i = 0; i < ncoffs; i++) {

              outfile << ", ";

              outfile << (data_t) L[i][j];

      }

      outfile << "\n";
  }
  outfile.close();


  return 0 ;
}


