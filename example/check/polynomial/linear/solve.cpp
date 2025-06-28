#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  std::array<float, 1>   r1;
  std::array<float, 2>   c2{ 1,2 };

  ::math::polynomial::solve::linear<float>(r1, c2);

  return EXIT_SUCCESS;
 }

