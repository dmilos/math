#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  ::math::geometry::circle::simple<float,6>  simple;
  ::math::geometry::circle::simple<float,2>  simple2D;
  ::math::geometry::circle::simple<float,3>  simple3D;
  ::math::geometry::circle::unit<float,6>    unit;

  ::math::linear::vector::point<float,6>    point;
  ::math::linear::vector::point<float,2>    p2a,p2b,p2c;
  ::math::linear::vector::point<float,3>    p3a,p3b,p3c,p3d;

  simple = unit;

  ::math::geometry::circle::distance<float>( unit, point );
  ::math::geometry::circle::distance<float>( simple, point );

   float  lambda0;
   float  lambda1;
   ::math::geometry::direction::parametric<float,6> direction;

  ::math::geometry::circle::intersect( lambda0, lambda1, direction );
  ::math::geometry::circle::intersect( lambda0, lambda1, simple, direction );
  
  ::math::geometry::circle::construct( simple2D,  p2a,p2b,p2c );
  ::math::geometry::circle::construct( simple3D,  p3a,p3b,p3c,p3d );

  
  return EXIT_SUCCESS;
 }
