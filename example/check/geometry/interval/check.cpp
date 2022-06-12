#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  typedef ::math::geometry::interval::structure<float,10> interval_t;
  typedef ::math::geometry::interval::structure<float,10>::point_type point_t;
  typedef ::math::linear::affine::structure<float,10> affine10_t;
  typedef ::math::geometry::direction::parametric<float,10> parametric10_t;
  typedef ::math::geometry::direction::two<float,10> two10_t;

  typedef ::math::geometry::interval::structure<float,3> interval3_t;
  typedef ::math::geometry::interval::structure<float,3>::point_type point3_t;
  typedef ::math::linear::affine::structure<float,3> affine3_t;

  interval_t  i1, i2, i3;
  point_t  p1, p2{0}, p3{0};  p2 = p2; p3=p3;
  parametric10_t dp0;
  two10_t     dt0;

  ::math::geometry::interval::center( p1, i1 );
  ::math::geometry::interval::center( i1 );
  ::math::geometry::interval::center( i1, p1 );

  ::math::geometry::interval::volume( i1 );
  ::math::geometry::interval::valid( i1 );
  ::math::geometry::interval::center( p1, i1 );
  ::math::geometry::interval::size( p1, i1 );

  ::math::geometry::interval::unit( i1 );

  ::math::geometry::interval::correct( i1 );
  ::math::geometry::interval::correct( i1, i1 );

  ::math::geometry::interval::extend( i1, p1 );
  ::math::geometry::interval::extend( i1, i1 );

  ::math::geometry::interval::in(  i1, p1 );
  ::math::geometry::interval::out( i1, p1 );

  ::math::geometry::interval::intersect( i1, i1, i1 );
  ::math::geometry::interval::intersect_weak( i1, i1, i1 );

    ::math::geometry::interval::translate( i1, p1 );

    ::math::geometry::interval::inflate( i1, p1, p1, i2 );
    ::math::geometry::interval::inflate( i1, p1, i2 );

    ::math::geometry::interval::inflate( i1, p1, 1.1f, i2 );
    ::math::geometry::interval::inflate( i1, 1.1f, i2 );

    ::math::geometry::interval::confine( p1, p1, i2 );
    ::math::geometry::interval::confine( p1, i2 );

    ::math::geometry::interval::confine( dt0, i2 );
    ::math::geometry::interval::confine( dp0, i2 );

  affine10_t  a10;
  ::math::geometry::interval::transform(i1, a10, i2 );

  affine3_t  a3;

  interval3_t  i3_1, i3_2;
  ::math::geometry::interval::transform( i3_1, a3, i3_2 );


  return EXIT_SUCCESS;
 }
