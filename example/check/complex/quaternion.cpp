#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

::math::complex::quaternion::structure<double> a,b,c,d;


  ::math::complex::quaternion::addition( a, b );
  ::math::complex::quaternion::addition( a, b, c );

  ::math::complex::quaternion::divide( a, b );
  ::math::complex::quaternion::divide( a, b, c );

  ::math::complex::quaternion::inverse( a );
  ::math::complex::quaternion::inverse( a, b );

  ::math::complex::quaternion::length( a );

  ::math::complex::quaternion::multiply( a, b );
  ::math::complex::quaternion::multiply( a, b, c );

  ::math::complex::quaternion::scale( a, 10, b );
  ::math::complex::quaternion::scale( a, 10  );

  ::math::complex::quaternion::subtraction( a, b );
  ::math::complex::quaternion::subtraction( a, b, c );

  return EXIT_SUCCESS;
 }

