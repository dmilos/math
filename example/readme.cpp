#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  ::math::linear::vector::point<double,2>   point{100,100};
  ::math::geometry::direction::parametric<double,2>   direction({ 5,5}, { 1,2});

  ::math::geometry::ellipse::base2D<double>     b{ 20, 30 };
  ::math::geometry::ellipse::simple2D<double>   s{ {10, 15}, 20, 30   };
  ::math::geometry::ellipse::general2D<double>  g{ {10, 15}, 20, 30, ::math::geometry::deg2rad( 60 ) };

  // Convert from one representation to another
   g = g;  g= s;   g = b;
           s = s;  s = b;

  ::math::geometry::ellipse::distance( b, point );
  ::math::geometry::ellipse::distance( s, point );
  ::math::geometry::ellipse::distance( g, point );

  double l0, l1;

  ::math::geometry::ellipse::intersect( l0, l1, b, direction );
  ::math::geometry::ellipse::intersect( l0, l1, s, direction );
  ::math::geometry::ellipse::intersect( l0, l1, g, direction );


  return EXIT_SUCCESS;
 }
