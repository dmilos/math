#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"
#include "math/polynomial/quadric/fit.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  typedef ::math::polynomial::quadric::fit<double>  fit_type;

  fit_type  fitter;
  fit_type::cloud_type cloud;
  fit_type::quadric_type q;

   double A = 1.9;
   double B = 0.5;
   double C = 1;

   double X ;

  X = -4; cloud.push_back( { X, C + X*B + X*X * A } );
  X = -3; cloud.push_back( { X, C + X*B + X*X * A } );
  X = -2; cloud.push_back( { X, C + X*B + X*X * A } );
  X = -1; cloud.push_back( { X, C + X*B + X*X * A } );

  X = 0;  cloud.push_back( { X, C + X*B + X*X * A } );

  X = +1; cloud.push_back( { X, C + X*B + X*X * A } );
  X = +2; cloud.push_back( { X, C + X*B + X*X * A } );
  X = +3; cloud.push_back( { X, C + X*B + X*X * A } );
  X = +4; cloud.push_back( { X, C + X*B + X*X * A } );

  fitter.caruana( q, cloud );

  std::cout
    << "C: " << q[0] << "; "
    << "B: " << q[1] << "; "
    << "A: " << q[2] << "; " << std::endl;

  fitter.hongwei( q, cloud );

  std::cout
    << "C: " << q[0] << "; "
    << "B: " << q[1] << "; "
    << "A: " << q[2] << "; " << std::endl;

  return EXIT_SUCCESS;
 }

