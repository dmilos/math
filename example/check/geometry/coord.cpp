#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

 ::math::linear::vector::point<double,3> a3,b3;
 ::math::linear::vector::point<double,2> a2,b2;

  b3 = ::math::geometry::cartesian2cylindric( a3 );
  b3 = ::math::geometry::spherical2cartesian( a3 );
  b3 = ::math::geometry::cylindric2cartesian( a3 );
  b3 = ::math::geometry::cartesian2spherical( a3 );
  b3 = ::math::geometry::spherical2cylindric( a3 );
  b3 = ::math::geometry::cylindric2spherical( a3 );
  b2 = ::math::geometry::cartesian2polar( a2 );
  b2 = ::math::geometry::polar2cartesian( a2 );

  cout << "-------------------------" << std::endl;
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
  
  cout << "-------------------------" << std::endl;
  cout << ::math::geometry::rad2deg( ::math::geometry::deg2rad(  -90 ) ) << std::endl;
  cout << ::math::geometry::rad2deg( ::math::geometry::deg2rad(  -60 ) ) << std::endl;
  cout << ::math::geometry::rad2deg( ::math::geometry::deg2rad(  -45 ) ) << std::endl;
  cout << ::math::geometry::rad2deg( ::math::geometry::deg2rad(  -30 ) ) << std::endl;
  cout << ::math::geometry::rad2deg( ::math::geometry::deg2rad(  -20 ) ) << std::endl;
  cout << ::math::geometry::rad2deg( ::math::geometry::deg2rad(    0 ) ) << std::endl;
  cout << ::math::geometry::rad2deg( ::math::geometry::deg2rad(   20 ) ) << std::endl;
  cout << ::math::geometry::rad2deg( ::math::geometry::deg2rad(   30 ) ) << std::endl;
  cout << ::math::geometry::rad2deg( ::math::geometry::deg2rad(   45 ) ) << std::endl;
  cout << ::math::geometry::rad2deg( ::math::geometry::deg2rad(   60 ) ) << std::endl;
  cout << ::math::geometry::rad2deg( ::math::geometry::deg2rad(   90 ) ) << std::endl;
  cout << ::math::geometry::rad2deg( ::math::geometry::deg2rad(  180 ) ) << std::endl;
  cout << ::math::geometry::rad2deg( ::math::geometry::deg2rad(  270 ) ) << std::endl;
  cout << ::math::geometry::rad2deg( ::math::geometry::deg2rad(  360 ) ) << std::endl;

  cout << "-------------------------" << std::endl;

  cout << ::math::geometry::slope2deg( ::math::geometry::deg2slope(  -90 ) ) << std::endl;
  cout << ::math::geometry::slope2deg( ::math::geometry::deg2slope(  -60 ) ) << std::endl;
  cout << ::math::geometry::slope2deg( ::math::geometry::deg2slope(  -45 ) ) << std::endl;
  cout << ::math::geometry::slope2deg( ::math::geometry::deg2slope(  -30 ) ) << std::endl;
  cout << ::math::geometry::slope2deg( ::math::geometry::deg2slope(  -20 ) ) << std::endl;
  cout << ::math::geometry::slope2deg( ::math::geometry::deg2slope(    0 ) ) << std::endl;
  cout << ::math::geometry::slope2deg( ::math::geometry::deg2slope(   20 ) ) << std::endl;
  cout << ::math::geometry::slope2deg( ::math::geometry::deg2slope(   30 ) ) << std::endl;
  cout << ::math::geometry::slope2deg( ::math::geometry::deg2slope(   45 ) ) << std::endl;
  cout << ::math::geometry::slope2deg( ::math::geometry::deg2slope(   60 ) ) << std::endl;
  cout << ::math::geometry::slope2deg( ::math::geometry::deg2slope(   90 ) ) << std::endl;
  cout << ::math::geometry::slope2deg( ::math::geometry::deg2slope(  180 ) ) << std::endl;
  cout << ::math::geometry::slope2deg( ::math::geometry::deg2slope(  270 ) ) << std::endl;
  cout << ::math::geometry::slope2deg( ::math::geometry::deg2slope(  360 ) ) << std::endl;

  cout << "-------------------------" << std::endl;

  cout << ::math::geometry::gon2deg( ::math::geometry::deg2gon(  -90 ) ) << std::endl;
  cout << ::math::geometry::gon2deg( ::math::geometry::deg2gon(  -60 ) ) << std::endl;
  cout << ::math::geometry::gon2deg( ::math::geometry::deg2gon(  -45 ) ) << std::endl;
  cout << ::math::geometry::gon2deg( ::math::geometry::deg2gon(  -30 ) ) << std::endl;
  cout << ::math::geometry::gon2deg( ::math::geometry::deg2gon(  -20 ) ) << std::endl;
  cout << ::math::geometry::gon2deg( ::math::geometry::deg2gon(    0 ) ) << std::endl;
  cout << ::math::geometry::gon2deg( ::math::geometry::deg2gon(   20 ) ) << std::endl;
  cout << ::math::geometry::gon2deg( ::math::geometry::deg2gon(   30 ) ) << std::endl;
  cout << ::math::geometry::gon2deg( ::math::geometry::deg2gon(   45 ) ) << std::endl;
  cout << ::math::geometry::gon2deg( ::math::geometry::deg2gon(   60 ) ) << std::endl;
  cout << ::math::geometry::gon2deg( ::math::geometry::deg2gon(   90 ) ) << std::endl;
  cout << ::math::geometry::gon2deg( ::math::geometry::deg2gon(  180 ) ) << std::endl;
  cout << ::math::geometry::gon2deg( ::math::geometry::deg2gon(  270 ) ) << std::endl;
  cout << ::math::geometry::gon2deg( ::math::geometry::deg2gon(  360 ) ) << std::endl;

  return EXIT_SUCCESS;
 }
