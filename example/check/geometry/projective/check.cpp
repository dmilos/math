#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  ::math::geometry::plane::no3d<double>              a, no3d;
  ::math::geometry::plane::parametric3d<double>      parametric3d;
  ::math::geometry::plane::noNd<double, 5>           c;

//::math::linear::vector::point<double,3>             point3;
  ::math::linear::vector::point<double,2>             point2;
  ::math::geometry::direction::ABC2D<double>             abc;
  ::math::linear::vector::point<double,3>             h1, h2, o;


  ::math::geometry::projective::plane( no3d.normal(), abc, abc, abc, abc );
  ::math::geometry::projective::plane( no3d.normal(), point2, point2, point2, point2 );
  ::math::geometry::projective::plane( no3d.normal(), h1, h2 );

  return EXIT_SUCCESS;
 }
