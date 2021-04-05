#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  ::math::function::bais<float>(0,1);
  ::math::function::bais<float>(0.25,1);
  ::math::function::bais<float>(0.5,1);
  ::math::function::bais<float>(0.75,1);
  ::math::function::bais<float>(1,1);
  ::math::function::bais<double>(0,1);
  ::math::function::bais<double>(0.25,1);
  ::math::function::bais<double>(0.5,1);
  ::math::function::bais<double>(0.75,1);
  ::math::function::bais<double>(1,1);
  
  return EXIT_SUCCESS;
 }

