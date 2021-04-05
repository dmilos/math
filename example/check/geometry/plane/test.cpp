#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  ::math::geometry::plane::no3d<double>              a;
  ::math::geometry::plane::parametric3d<double>      b;
  ::math::geometry::plane::noNd<double, 5>           c;

  a=b;
  b=a;


  return EXIT_SUCCESS;
 }
