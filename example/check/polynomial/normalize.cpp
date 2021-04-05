#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  std::array<float,1>   c1{1.234f};
  std::array<float,2>   c2{1,2};
  std::array<float,3>   c3{1,2,3,};
  std::array<float,4>   c4{1,2,3,4};
  std::array<float,5>   c5{1,2,3,4,5};
  std::array<float,6>   c6{1,2,3,4,5,6};
  std::array<float,10>  c10{1,2,3,4,5,6,7,8,9,10};

  std::cout << ::math::polynomial::normalize<float>( c1  )  << std::endl;
  std::cout << ::math::polynomial::normalize<float>( c2  )  << std::endl;
  std::cout << ::math::polynomial::normalize<float>( c3  )  << std::endl;
  std::cout << ::math::polynomial::normalize<float>( c4  )  << std::endl;
  std::cout << ::math::polynomial::normalize<float>( c5  )  << std::endl;
  std::cout << ::math::polynomial::normalize<float>( c6  )  << std::endl;
  std::cout << ::math::polynomial::normalize<float>( c10 ) << std::endl;

  
  return EXIT_SUCCESS;
 }

