#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  ::math::function::power<0,0>();
  ::math::function::power<1,0>();
  ::math::function::power<2,0>();
  ::math::function::power<2,0>();
  ::math::function::power<3,0>();
  ::math::function::power<4,0>();
  ::math::function::power<5,0>();

  ::math::function::power<0,1>();
  ::math::function::power<1,1>();
  ::math::function::power<2,1>();
  ::math::function::power<3,1>();
  ::math::function::power<4,1>();
  ::math::function::power<5,1>();


  
  return EXIT_SUCCESS;
 }

