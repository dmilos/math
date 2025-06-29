#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;
typedef double scalar_t;

void quadric( std::array<scalar_t,3> const& coefficients )
 {
  std::array<scalar_t,2>   root;
  auto count = ::math::polynomial::quadric::solve::general<scalar_t>(root, coefficients);

  std::array<scalar_t, 2>  eval;
  switch( count )
   {
    case( 2 ): 
        eval[1] = ::math::polynomial::evaluate( root[1], coefficients ); 
        if (1e-6 < fabs(eval[1]))
         {
          std::cout << "root1";
         }
    case( 1 ):
        eval[0] = ::math::polynomial::evaluate( root[0], coefficients ); 
        if (1e-6 < fabs(eval[0]))
         {
          std::cout << "root0";
         }
    case( 0 ): break;
  }

 }

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;
  std::array<scalar_t,3> coeffcient;
  std::array<scalar_t,2>   r2;

  quadric({0,0,1});
  quadric({1,0,1});
  quadric({0,1,1});

  quadric( { 1, 2,1 } );
  quadric( { 1,-2,1 } );

  for( coeffcient[0] = -1; coeffcient[0] < +1; coeffcient[0] += 0.001 )
   for( coeffcient[1] = -1; coeffcient[1] < +1; coeffcient[1] += 0.001 )
    for( coeffcient[2] = -1; coeffcient[2] < +1; coeffcient[2] += 0.001 )
        {
        if( fabs( coeffcient[2] ) < 0.001 ) 
         {
          continue;
         }
         quadric( coeffcient );
       }

  ::math::polynomial::quadric::solve::general( r2, coeffcient );
  ::math::polynomial::quadric::solve::depressed<scalar_t>( r2.data(), 1, 2  );
  ::math::polynomial::quadric::solve::trivial<scalar_t>( r2.data(), 1 );

  ::math::polynomial::quadric::solve::monic( r2.data(), coeffcient.data() );
   ::math::polynomial::quadric::solve::monic<scalar_t>( r2.data(), 123, 234  ) ;

  return EXIT_SUCCESS;
 }

