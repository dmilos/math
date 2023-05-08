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

  interval_t  i1, i2, i3;
  point_t  p1, p2, p3;

  ::math::geometry::interval::center( p1, i1 );

  ::math::geometry::interval::volume( i1 );
  ::math::geometry::interval::valid( i1 );
  ::math::geometry::interval::center( p1, i1 );

  ::math::geometry::interval::correct( i1 );
  ::math::geometry::interval::correct( i1, i1 );
  
  ::math::geometry::interval::extend( i1, p1 );
  ::math::geometry::interval::extend( i1, i1 );
  
  ::math::geometry::interval::in(  i1, p1 );
  ::math::geometry::interval::out( i1, p1 );

  ::math::geometry::interval::intersect( i1, i1, i1 );
  ::math::geometry::interval::intersect_weak( i1, i1, i1 );
  
  ::math::geometry::interval::translate( i1, p1 );
    
   ::math::geometry::interval::reframe( i1, p1 );
   ::math::geometry::interval::reframe( i1, i2, p1 );

  
  return EXIT_SUCCESS;
 }
