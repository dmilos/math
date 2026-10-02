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

int main(int argc, char* argv[])
 {
  cout << "Hello World" << endl;

  std::array<float, 3>   c{ 1,2,3 };
  float   x0 = 0, y0 = 1
        , x1 = 1, y1 = 2
        , x2 = 2, y2 = 3
  ;

  ::math::polynomial::quadric::interpolate( c.data(), x0, y0, x1, y1, x2, y2 );
  cout << ::math::polynomial::quadric::evaluate( x0, c.data() ) << std::endl;
  cout << ::math::polynomial::quadric::evaluate( x1, c.data() ) << std::endl;
  cout << ::math::polynomial::quadric::evaluate( x2, c.data() ) << std::endl;

  for( y0 = -2; y0 < +2; y0 += 0.01 )
   {
    for( y1 = -2; y1 < +2; y1 += 0.01 )
     {
      for( y2 = -2; y2 < +2; y2 += 0.01 )
       {
        if( false == ::math::polynomial::quadric::interpolate( c.data(), x0, y0, x1, y1, x2, y2) )
         {
          continue;
         }
        //math::polynomial::normalize( c );

        auto v0 = ::math::polynomial::quadric::evaluate( x0, c.data() );
        if( 1e-2 <  fabs( v0 - y0 ) )
         {
          std::cout << "aa" << std::endl;
         }
        auto v1 = ::math::polynomial::quadric::evaluate( x1, c.data() );
        if( 1e-2 < fabs( v1 - y1 ) )
         {
          std::cout << "aa" << std::endl;
         }
        auto v2 = ::math::polynomial::quadric::evaluate( x2, c.data() );
        if( 1e-2 < fabs( v2 - y2 ) )
         {
          std::cout << "aa" << std::endl;
         }
       }
     }
    }
  std::cout << "...end" << std::endl;
  cin.get();
  return EXIT_SUCCESS;
}

