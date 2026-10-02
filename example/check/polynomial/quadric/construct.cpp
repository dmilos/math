#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;
typedef double scalar_t;


int main( int argc, char *argv[] )
 {
  double step = 0.01;

  double epsilon = 1e-10;

  scalar_t dMax = 0;
  std::size_t counter = 0;
  std::array<double, 2> the_root;
  std::array<double, 2> root;
  std::array<double, 3> coefficient;

  for( the_root[0] = -1; the_root[0] < +1; the_root[0] += step )
   for( the_root[1] = -1; the_root[1] < +1; the_root[1] += step )
   {
    ++counter;

    ::math::polynomial::quadric::construct( coefficient, the_root );

    int solutions = ::math::polynomial::quadric::solve::general( root, coefficient );

    switch( solutions )
     {
      case( 0 ): /*std::cout << "x" << std::endl;*/ continue;
      //case( 1 ): /*std::cout << "x" << std::endl;*/ continue;
     }

    for( int i = 0; i < the_root.size(); ++i )
     {
      bool match = false;
      for( int j=0; j < root.size(); ++j )
       {
        auto delta = fabs( the_root[i] - root[j] );
        if( delta < epsilon )
         {
          match = true;
          dMax = std::max( delta, dMax );
          break;
         }
       }
      if( match == false )
       {
        std::cout << "*: " << dMax << std::endl;
       }
     }
   }

  std::cout << "dMax: " << dMax << std::endl;
  return EXIT_SUCCESS;
 }
