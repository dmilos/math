#include <iostream>
#include <iomanip>
#include <string>
#include <array>

#include "math/math.hpp"


using namespace std;

void linear(  )
 {
  double coeff[2];

  ::math::polynomial::linear::interpolate<double>( coeff, 0,1, 1,1 );
  ::math::polynomial::linear::interpolate<double>( coeff, 0,1, 1,2 );
}

void quadric( )
{
  double coeff[3];
  ::math::polynomial::quadric::interpolate<double>( coeff, 0,1, 1,1 , 2,1 );
  ::math::polynomial::quadric::interpolate<double>( coeff, 0,1, 1,2 , 2,3 );
}

void cubic( )
{
  double coeff[4];
  ::math::polynomial::cubic::interpolate<double>( coeff, 0,1, 1,1 , 2,1 , 3,1 );
  ::math::polynomial::cubic::interpolate<double>( coeff, 0,1, 1,2 , 2,3 , 3,4 );
}

void quartic(  )
{
  double coeff[5];
  ::math::polynomial::quartic::interpolate<double>( coeff, 0,1, 1,1 , 2,1 , 3,1, 4,1 );
  ::math::polynomial::quartic::interpolate<double>( coeff, 0,1, 1,2 , 2,3 , 3,4, 4,5 );
}

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  linear();

  quadric();

  cubic();

  quartic( );
  
  return EXIT_SUCCESS;
 }

