#include <iostream>
#include <iomanip>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  ::math::random::congruent<double, 1> c1d ;
  ::math::random::congruent<double, 1> c1dx(1,2);
  ::math::random::congruent<double, 2> c2d ;
  ::math::random::congruent<double, 2> c2dx( {1,2}, {1,2}  );
  ::math::random::congruent<double, 3> c3d ;
  ::math::random::congruent<double, 3> c3dx( {1,2,3}, {1,2,3}  );

  ::math::random::congruent<double, 2>::point_type p2;
  ::math::random::congruent<double, 3>::point_type p3;

   c1d .next();
   c1dx.next();
   c2d .next( p2 );
   c2dx.next( p2 );
   c3d .next( p3 );
   c3dx.next( p3 );

  return EXIT_SUCCESS;
 }

