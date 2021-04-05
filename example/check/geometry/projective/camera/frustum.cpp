#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  ::math::geometry::direction::two<      double, 3 > two{ { 20, 20 , 0},{ -2, 0, 0} };
  ::math::geometry::direction::parametric<      double, 3 > parametric{ { 20, 20 , 0},{ -2, 0, 0} };
  ::math::geometry::interval::structure<double, 2>  window{{-1,-1},{1,1}};
  ::math::geometry::interval::structure< double, 1 > focus{ 1, 10 };
  ::math::linear::vector::point< double, 3 > point{0,3,0};

  ::math::geometry::projective::camera::frustum::clip( two, window, focus );
  ::math::geometry::projective::camera::frustum::confine( parametric, window, focus );
  ::math::geometry::projective::camera::frustum::in( point, window, focus );
  ::math::geometry::projective::camera::frustum::location( point, window, focus );

  ::math::geometry::projective::camera::frustum::out( point, window, focus );
  ::math::geometry::projective::camera::frustum::side( point, focus );

  ::math::geometry::projective::camera::frustum::location( point, window, focus, 0.01 );


  return EXIT_SUCCESS;
 }
