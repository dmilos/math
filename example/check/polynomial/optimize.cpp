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

  ::math::polynomial::optimize( c1  );
  ::math::polynomial::optimize( c2  );
  ::math::polynomial::optimize( c3  );
  ::math::polynomial::optimize( c4  );
  ::math::polynomial::optimize( c5  );
  ::math::polynomial::optimize( c6  );
  ::math::polynomial::optimize( c10 );

  
  return EXIT_SUCCESS;
 }

