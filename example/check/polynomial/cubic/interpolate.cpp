#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;

typedef double scalar_t;

int main(int argc, char* argv[])
 {
  cout << "Hello World" << endl;

  std::array<scalar_t, 4>   c{ 1,2,3,4 };
  scalar_t   x0 = 0, y0 = 1
        , x1 = 1, y1 = 2
        , x2 = 2, y2 = 3
        , x3 = 3, y3 = 4
  ;

  ::math::polynomial::cubic::interpolate( c.data(), x0, y0, x1, y1, x2, y2, x3, y3 );
  cout << ::math::polynomial::cubic::evaluate( x0, c.data() ) << std::endl;
  cout << ::math::polynomial::cubic::evaluate( x1, c.data() ) << std::endl;
  cout << ::math::polynomial::cubic::evaluate( x2, c.data() ) << std::endl;
  cout << ::math::polynomial::cubic::evaluate( x3, c.data() ) << std::endl;

  scalar_t dMax = 0;
  std::size_t count = 0;
  for( y0 = -2; y0 < +2; y0 += 0.01 )
   {
    for( y1 = -2; y1 < +2; y1 += 0.01 )
     {
      for( y2 = -2; y2 < +2; y2 += 0.01 )
       {
        for( y3 = -2; y3 < +2; y3 += 0.01 )
         {
          if( false == ::math::polynomial::cubic::interpolate( c.data(), x0, y0, x1, y1, x2, y2, x3, y3 ) )
           {
            continue;
           }
          ++count;
          scalar_t dPrev = dMax;

          auto v0 = ::math::polynomial::cubic::evaluate( x0, c.data() );
          auto d0 = fabs(v0 - y0); dMax = std::max( dMax, d0 );
          if( 1e-2 < d0 )
           {
            std::cout << "aa0" << std::endl;
           }
          auto v1 = ::math::polynomial::cubic::evaluate( x1, c.data() );
          auto d1 = fabs( v1 - y1 ); dMax = std::max( dMax, d1 );
          if( 1e-2 < d1 )
           {
            std::cout << "aa1" << std::endl;
           }
          auto v2 = ::math::polynomial::cubic::evaluate( x2, c.data() );
          auto d2 = fabs( v2 - y2 ); dMax = std::max( dMax, d2 );
          if( 1e-2 < d2 )
           {
            std::cout << "aa2" << std::endl;
           }
          auto v3 = ::math::polynomial::cubic::evaluate( x3, c.data() );
          auto d3 = fabs( v3 - y3 ); dMax = std::max( dMax, d3 );
          if( 1e-2 < d3 )
           {
            std::cout << "aa3" << std::endl;
           }
          if( dMax != dPrev )
           {
            std::cout << count << ": " << dMax << "; "
                << x0 << ", " << x1 << ", " << x2 << ", " << x3  << "; "
                << y0 << ", " << y1 << ", " << y2 << ", " << y3 << "; "
                << std::endl;
           }

         }
       }
    }
  }

  std::cout << dMax << std::endl;
  std::cout << "...end" << std::endl;
  cin.get();
  return EXIT_SUCCESS;
}

