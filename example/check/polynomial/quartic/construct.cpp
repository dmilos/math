#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;
typedef double scalar_t;


int main( int argc, char *argv[] )
 {
  double step = 0.01;

  scalar_t dMax = 0;
  std::size_t counter = 0;

  //for( root[0] = -1; root[0] < +1; root[0] += step )
  // for( root[1] = -1; root[1] < +1; root[1] += step )
  //  for( root[2] = -1; root[2] < +1; root[2] += step )
  //   for( root[3] = -1; root[3] < +1; root[3] += step )
      {
       ++counter;

       // construct

       // solve
       //int solutions = ::math::polynomial::cubic::solve::general( root, coeffcient );

       // compare

      }
  std::cout << "dMax: " << dMax << std::endl;
  return EXIT_SUCCESS;
 }

