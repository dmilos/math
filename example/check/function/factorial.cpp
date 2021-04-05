#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  ::math::function::factorial<0>();
  ::math::function::factorial<1>();
  ::math::function::factorial<2>();
  ::math::function::factorial<3>();
  ::math::function::factorial<4>();
  ::math::function::factorial<5>();
  ::math::function::factorial<6>();
  ::math::function::factorial<7>();
  ::math::function::factorial<8>();
  ::math::function::factorial<9>();
  
  
  return EXIT_SUCCESS;
 }

