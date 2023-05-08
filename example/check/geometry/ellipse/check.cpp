#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

   ::math::linear::vector::point<double,2>   point;
   ::math::geometry::direction::parametric<double,2>   direction;

   ::math::geometry::ellipse::base2D<double>      b;
   ::math::geometry::ellipse::simple2D<double>    s;
   ::math::geometry::ellipse::general2D<double>   g;
   ::math::geometry::ellipse::implicit2D<double>  i;

    g = g;  g = s;   g = b;
            s = s;  s = b;
    i = g;  i = s;  i = b;

   ::math::geometry::ellipse::distance( b, point );
   ::math::geometry::ellipse::distance( s, point );
   ::math::geometry::ellipse::distance( g, point );

   double l0, l1;

   ::math::geometry::ellipse::intersect( l0, l1, b, direction );
   ::math::geometry::ellipse::intersect( l0, l1, s, direction );
   ::math::geometry::ellipse::intersect( l0, l1, g, direction );


  return EXIT_SUCCESS;
 }
