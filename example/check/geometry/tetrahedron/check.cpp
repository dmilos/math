#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  ::math::geometry::tetrahedron::structure< float, 10 >  t10{0};  t10 = t10;
  ::math::geometry::tetrahedron::structure< float, 3 >  t3;
  ::math::linear::vector::structure< float, 10 >  v10;

  ::math::geometry::tetrahedron::volume( t3 );
  ::math::geometry::tetrahedron::centroid( v10, t10 );

  return EXIT_SUCCESS;
 }
