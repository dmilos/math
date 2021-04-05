#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

 ::math::linear::vector::point<double,3> a3,b3,c3;
 ::math::linear::vector::point<double,2> a2,b2,c2;

  b3 = ::math::geometry::cartesian2cylindric( a3 );
  b3 = ::math::geometry::spherical2cartesian( a3 );
  b3 = ::math::geometry::cylindric2cartesian( a3 );
  b3 = ::math::geometry::cartesian2spherical( a3 );
  b3 = ::math::geometry::spherical2cylindric( a3 );
  b3 = ::math::geometry::cylindric2spherical( a3 );
  b2 = ::math::geometry::cartesian2polar( a2 );
  b2 = ::math::geometry::polar2cartesian( a2 );

  cout << ::math::geometry::deg2rad(  -90 ) << std::endl;
  cout << ::math::geometry::deg2rad(  -60 ) << std::endl;
  cout << ::math::geometry::deg2rad(  -45 ) << std::endl;
  cout << ::math::geometry::deg2rad(  -30 ) << std::endl;
  cout << ::math::geometry::deg2rad(  -20 ) << std::endl;
  cout << ::math::geometry::deg2rad(    0 ) << std::endl;
  cout << ::math::geometry::deg2rad(   20 ) << std::endl;
  cout << ::math::geometry::deg2rad(   30 ) << std::endl;
  cout << ::math::geometry::deg2rad(   45 ) << std::endl;
  cout << ::math::geometry::deg2rad(   60 ) << std::endl;
  cout << ::math::geometry::deg2rad(   90 ) << std::endl;
  cout << ::math::geometry::deg2rad(  180 ) << std::endl;
  cout << ::math::geometry::deg2rad(  270 ) << std::endl;
  cout << ::math::geometry::deg2rad(  360 ) << std::endl;
  // TODO ::math::geometry::rad2deg

  return EXIT_SUCCESS;
 }
