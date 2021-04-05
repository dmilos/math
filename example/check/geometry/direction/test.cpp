#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

   ::math::geometry::direction::two<double,2>            t;
   ::math::geometry::direction::polar<double>            po;
   ::math::geometry::direction::parametric<double, 2>    pp;
   ::math::geometry::direction::ABC2D<double>            a;

  t = t; t = po; t = pp; t = a;
  po = t; po = po; po = pp; po = a;
  pp = t; pp = po; pp = pp; pp = a;
  a = t; a = po; a = pp; a = a;

  ::math::geometry::direction::rotate( t, 123, t );
  ::math::geometry::direction::rotate( po, 123, po );
  ::math::geometry::direction::rotate( pp, 123, pp );
  ::math::geometry::direction::rotate( a, 123, a );

  ::math::geometry::direction::rotate( t, {1,2}, 12, t );


  
  return EXIT_SUCCESS;
 }
