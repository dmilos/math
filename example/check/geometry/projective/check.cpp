#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

using namespace std;

void camera_triangle1( )
 {
  double w = 1;
  double a = ::math::geometry::deg2rad( 90 );
  double f = 1;
  
  f = ::math::geometry::projective::camera::w2f( w, ::math::geometry::deg2rad( 120 ) );
  f = ::math::geometry::projective::camera::w2f( w, ::math::geometry::deg2rad(  90 ) );
  f = ::math::geometry::projective::camera::w2f( w, ::math::geometry::deg2rad(  60 ) );

  w = ::math::geometry::projective::camera::f2w<double>( 1, ::math::geometry::deg2rad( 120 ) );
  w = ::math::geometry::projective::camera::f2w<double>( 1, ::math::geometry::deg2rad(  90 ) );
  w = ::math::geometry::projective::camera::f2w<double>( 1, ::math::geometry::deg2rad(  60 ) );
  w = ::math::geometry::projective::camera::f2w<double>( 1, ::math::geometry::deg2rad(  30 ) );

  f = ::math::geometry::projective::camera::a2f<double>( ::math::geometry::deg2rad( 120 ), 1 );
  f = ::math::geometry::projective::camera::a2f<double>( ::math::geometry::deg2rad(  90 ), 1 );
  f = ::math::geometry::projective::camera::a2f<double>( ::math::geometry::deg2rad(  60 ), 1 );
  f = ::math::geometry::projective::camera::a2f<double>( ::math::geometry::deg2rad(  30 ), 1 );

  a = ::math::geometry::rad2deg( ::math::geometry::projective::camera::w2a<double>( tan( ::math::geometry::deg2rad( 120 / 2 ) ), 1 ) );
  a = ::math::geometry::rad2deg( ::math::geometry::projective::camera::w2a<double>( tan( ::math::geometry::deg2rad(  90 / 2 ) ), 1 ) );
  a = ::math::geometry::rad2deg( ::math::geometry::projective::camera::w2a<double>( tan( ::math::geometry::deg2rad(  60 / 2 ) ), 1 ) );

  a = ::math::geometry::rad2deg( ::math::geometry::projective::camera::f2a<double>( 1, tan( ::math::geometry::deg2rad( 120 / 2 ) ) ) );
  a = ::math::geometry::rad2deg( ::math::geometry::projective::camera::f2a<double>( 1, tan( ::math::geometry::deg2rad(  90 / 2 ) ) ) );
  a = ::math::geometry::rad2deg( ::math::geometry::projective::camera::f2a<double>( 1, tan( ::math::geometry::deg2rad(  60 / 2 ) ) ) );

  ::math::geometry::projective::camera::w2a( w );
  ::math::geometry::projective::camera::f2a( f );
}

void camera_triangle2()
 {
  double w = 1;
  double f = 10;
  double a = 2 * atan2( w, f ); 
  double aD = ::math::geometry::rad2deg( a );
  double aO = a;

  std::cout << "f: " << f << "; " << "w: " << w << "; " << "a: " << ::math::geometry::rad2deg(a) << "; " << std::endl;
  f = ::math::geometry::projective::camera::w2f( w, a ); std::cout << "f: " << f << "; " << "w: " << w << "; " << "a: " << ::math::geometry::rad2deg( a ) << "; " << std::endl;
  w = ::math::geometry::projective::camera::f2w( f, a ); std::cout << "f: " << f << "; " << "w: " << w << "; " << "a: " << ::math::geometry::rad2deg( a ) << "; " << std::endl;
  a = ::math::geometry::projective::camera::w2a( w, f ); std::cout << "f: " << f << "; " << "w: " << w << "; " << "a: " << ::math::geometry::rad2deg( a ) << "; " << std::endl;
  f = ::math::geometry::projective::camera::a2f( a, w ); std::cout << "f: " << f << "; " << "w: " << w << "; " << "a: " << ::math::geometry::rad2deg( a ) << "; " << std::endl;
  a = ::math::geometry::projective::camera::f2a( f, w ); std::cout << "f: " << f << "; " << "w: " << w << "; " << "a: " << ::math::geometry::rad2deg( a ) << "; " << std::endl;
  
 }


int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;
  camera_triangle2();
  camera_triangle1();

  ::math::geometry::plane::no3d<double>              a, no3d;
  ::math::geometry::plane::parametric3d<double>      parametric3d;
  ::math::geometry::plane::noNd<double, 5>           c;

//::math::linear::vector::point<double,3>             point3;
  ::math::linear::vector::point<double,2>             point2;
  ::math::geometry::direction::ABC2D<double>             abc;
  ::math::linear::vector::point<double,3>             h1, h2;


  ::math::geometry::projective::plane( no3d.normal(), abc, abc, abc, abc );
  ::math::geometry::projective::plane( no3d.normal(), point2, point2, point2, point2 );
  ::math::geometry::projective::plane( no3d.normal(), h1, h2 );

  return EXIT_SUCCESS;
 }
