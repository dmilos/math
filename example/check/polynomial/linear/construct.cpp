#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

#ifdef __clang__
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wmissing-braces"
    #pragma clang diagnostic ignored "-Wunused-local-typedef"
    #pragma clang diagnostic ignored "-Wunused-variable"
    #pragma clang diagnostic ignored "-Wself-assign-overloaded"
#endif


using namespace std;
typedef double scalar_t;


int main( int argc, char *argv[] )
 {
  double step = 0.01;

  scalar_t dMax = 0;
  std::size_t counter = 0;
  std::array<double, 1> the_root;
  std::array<double, 1> root;
  std::array<double, 2> coefficient;

  for( the_root[0] = -1; the_root[0] < +1; the_root[0] += step )
   {
    ++counter;

    ::math::polynomial::linear::construct( coefficient, the_root );

    int solutions = ::math::polynomial::solve::linear( root, coefficient );

    if( 0 == solutions )
     {
      continue;
     }

    for( int i=0; i < 1; ++i )
     {
      auto delta = fabs(the_root[i] - root[i]);
      if( dMax  < delta )
       {
        dMax = delta;
        std::cout << "*" << std::endl;
       }
     }

   }

  std::cout << "dMax: " << dMax << std::endl;
  return EXIT_SUCCESS;
 }
