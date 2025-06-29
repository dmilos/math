#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

//std::array<float,10>   r;
  std::array<float,1>   r1;
  std::array<float,2>   r2;
  std::array<float,3>   r3;
  std::array<float,4>   r4;

 // std::array<float,10>   c;
  std::array<float,2>   c2;
  std::array<float,3>   c3;
  std::array<float,4>   c4{1,2,3,4};
  std::array<float,5>   c5{ 1,2,3,4,5};


  ::math::polynomial::solve::linear<float>( r1, c2 );
  ::math::polynomial::solve::linear<float>( r1.data(), c2.data() );

  ::math::polynomial::quadric::solve::general<float>( r2, c3 );
  ::math::polynomial::cubic::solve::general<float>( r3, c4 );

  ::math::polynomial::quartic::solve::bi<float>(        r4.data(), c5.data() );
  ::math::polynomial::quartic::solve::general<float>(r4.data(), c5.data());

  ::math::polynomial::quartic::shift<float>( c5, +1.12346, c5 );
  ::math::polynomial::quartic::shift<float>( c5, -1.12346, c5 );


  
  return EXIT_SUCCESS;
 }

