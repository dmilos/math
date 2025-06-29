#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;
typedef double scalar_t;

void cubic( std::array<double,4> const& coefficients )
{
  std::cout << "------------" << __FUNCTION__ << endl;
  std::cout << "C: { " << coefficients[0] << ", " << coefficients[1] << ", " << coefficients[2] << ", " << coefficients[3] << "}; " <<  std::endl;
  std::array<double,3>   root;

  std::cout << "# Solutions: " << ::math::polynomial::cubic::solve::general<double>(  root, coefficients ) << std::endl;

  std::cout << "Check 1: P( " << root[0] << ") = " << ::math::polynomial::evaluate( root[0], coefficients ) << std::endl;
  std::cout << "Check 2: P( " << root[1] << ") = " << ::math::polynomial::evaluate( root[1], coefficients ) << std::endl;
  std::cout << "Check 3: P( " << root[2] << ") = " << ::math::polynomial::evaluate( root[2], coefficients ) << std::endl;

  std::array<double,4> d;
  std::cout << "Shift: " <<::math::polynomial::cubic::depressing( d, coefficients ) << std::endl;

  std::cout << "Depressed:" << d[0] << ", " << d[1] << ", " << d[2] << ", " << d[3] << "; " <<  std::endl;
}

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;
  std::array<scalar_t, 4> coeffcient{-0.51,2,3,4};
  std::array<scalar_t,3>   root;

  cubic({-350,162,-30,2});
  cubic({1,2,3,4});
  cubic({0,0,0,1});

  //::math::polynomial::cubic::solve::depressed<scalar_t>( r2.data(), 1, 2  );
  ::math::polynomial::cubic::solve::trivial<scalar_t>( root.data(), -0.51 );

  //::math::polynomial::cubic::solve::monic( r2.data(), coeffcient.data() );
  //::math::polynomial::cubic::solve::monic<scalar_t>( r2.data(), 123, 234  ) ;
  ::math::polynomial::cubic::solve::general( root , coeffcient );
  std::array<scalar_t,4>   c4{1,2,3,4};

  ::math::polynomial::cubic::solve::general<scalar_t>( root, c4 );
  auto shift = ::math::polynomial::cubic::depressing<scalar_t>( c4, c4 );
  ::math::polynomial::cubic::shift<scalar_t>( c4, shift, c4 );

  scalar_t dMax = 0;
  std::size_t counter = 0;
  for( coeffcient[0] = -1; coeffcient[0] < +1; coeffcient[0] += 0.01 )
   for( coeffcient[1] = -1; coeffcient[1] < +1; coeffcient[1] += 0.01 )
    for( coeffcient[2] = -1; coeffcient[2] < +1; coeffcient[2] += 0.01 )
     for( coeffcient[3] = -1; coeffcient[3] < +1; coeffcient[3] += 0.01 )
      {
       if( fabs( coeffcient[3] ) < 0.001 ) 
        {
         continue;
        }
       ++counter;
       int solutions = ::math::polynomial::cubic::solve::general( root, coeffcient );

       for( int i=0; i< solutions; ++i )
        {
         auto zero = ::math::polynomial::cubic::evaluate( root[ i ], coeffcient );
         if( dMax < fabs( zero ) )
          {
           std::cout << std::setw(15) << counter << ": " << std::setw(15) << dMax << "; ";
           for (int i = 0; i < coeffcient.size(); ++i)
            {
               std::cout << std::setw(6) << coeffcient[i] << "; ";
            }
           std::cout << std::endl;
          }
         dMax = std::max( dMax, fabs( zero ) );
        }
      }
  std::cout << "dMax: " << dMax << std::endl;
  return EXIT_SUCCESS;
 }

