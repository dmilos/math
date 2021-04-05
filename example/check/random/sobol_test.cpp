#include <iostream>
#include <iomanip>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  typedef ::math::random::sobol2D< double > sobol_type;
  sobol_type s1;
  sobol_type s2;

  for( int i=0; i< 20; i++ )
   {
    sobol_type::scalar_type x, y;
    s1.next( x, y );
    
    cout << setw(14) << x <<  ";";
    cout << setw(14) << y <<  endl;
   }

  return EXIT_SUCCESS;
 }

