#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  ::math::geometry::triangle::structure<double, 10>   a10{0}; a10 = a10;
  ::math::geometry::triangle::structure<double, 3>   a3;
  ::math::geometry::triangle::structure<double, 2>   a2;

  ::math::linear::vector::structure< float, 2 >  vC, vA0, vA1, vA2;

  ::math::geometry::triangle::area( a2[0], a2[1], a2[2] );
  ::math::geometry::triangle::area( a3 );
  ::math::geometry::triangle::centroid( vC , vA0, vA1, vA2 );
  
  ::math::geometry::triangle::inradius( a3 );
  ::math::geometry::triangle::circumradius( a3 );

  return EXIT_SUCCESS;
 }
