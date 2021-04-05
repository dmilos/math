#include <iostream>
#include <iomanip>
#include <string>


#include "math/math.hpp"


int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  ::math::random::VaLND<double, std::size_t, 2> vap2;
  ::math::random::VaLND<double, std::size_t, 2>::coord_type p2;
  vap2( p2 );
  vap2.next( p2 );
  
  ::math::random::VaLND<double, std::size_t, 12> vap12;
  ::math::random::VaLND<double, std::size_t, 12>::coord_type p12;
  vap12( p12 );
  vap12.next( p12 );

  
  return EXIT_SUCCESS;
 }

