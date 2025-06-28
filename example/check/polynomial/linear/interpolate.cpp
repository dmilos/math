#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;
  
  std::array<float, 2>   c{ 1,2 };
  float x0=0, y0=1, x1=1, y1=2;

  ::math::polynomial::linear::interpolate(c.data(), x0, y0, x1, y1);
  cout << ::math::polynomial::linear::evaluate( x0, c.data() ) << std::endl;
  cout << ::math::polynomial::linear::evaluate( x1, c.data() ) << std::endl;

  cin.get();
  return EXIT_SUCCESS;
 }

