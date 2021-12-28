#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

#include "math/geometry/plane/horizon.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  ::math::geometry::plane::no3d<double>              a;
  ::math::geometry::plane::parametric3d<double>      b;
  ::math::geometry::plane::noNd<double, 5>           c;
  ::math::geometry::plane::ABCD3D<double>            d;

  a=b;
  b=a;

::math::geometry::direction::ABC2D<double> line;
  ::math::linear::vector::load( a.origin(), 0, 0, 0 ); 
  ::math::linear::vector::load( a.normal(), 1, 1, 0 );

 ::math::geometry::plane::horizon<double>::process( line, a );

  return EXIT_SUCCESS;
 }
