#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int g_calc = 0;
#include "math/math.hpp"

#define USE_PNM 0

#if USE_PNM
#include "pnm/pnm.hpp"
#endif



int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  std::vector< std::uint8_t> image;
  auto height = 600;
  auto width  = 600;

  for( double t=0; t < 0;  t+= 0.000001 )
   {
    long double x,y;
    ::math::function::lebesgue2D<long double>( x, y, t, 15 );
    std::array<double,2> point;
    ::math::function::lebesgueND<double>( point, t, 15 );

    x = x - point[0];
    y = y - point[1];
    if( 0.00001 < fabs( x ) )
      {
       x = x;
      }
    if( 0.00001 < fabs( y ) )
      {
       y = y;
      }
   }

  for( int iteration = 10; iteration < 10; ++iteration )
   {
    image.clear(); image.resize( height * width, 0 );
    for( double t=0; t< 0.9999999999;  t+= 0.0000001 )
     {
      long double x,y;
      ::math::function::lebesgue2D<long double>( x, y, t, iteration );

      double xr = ( x*width);
      double yr = ( y*height);

      std::size_t  index = std::size_t( width*int( height - int(yr) - 1)+int( xr ) );
      if( image.size() <= index ) continue;
      image[ index +0 ] //= //std::uint8_t( int( 256*t ) );
      //image[ index +1 ] = //0*std::uint8_t( int( 4*256*t ) );
      //image[ index +2 ] 
      = std::uint8_t( int( 256*t ) );
     }

#if USE_PNM
    { std::ofstream( std::string( "lebesgue2D-")+ (iteration < 10?"0":"") +std::to_string( iteration )+"-Rotate-256.pgm" ) << PNM::save( image, width, height, PNM::P2 ); }
#endif
   }

   image.clear(); image.resize( 3 * height * width, 0 );

   //for( g_calc = 0; g_calc < 10; ++g_calc )           
    {
   for( double t=0; t< 1;  t+= 0.000001 )
    {
     std::array<double,2> point;
    ::math::function::hilbert2D( point, t, 10 );

     int xr = ( point[0]*width);
     int yr = ( point[1]*height);
     std::size_t  index = 3*std::size_t( width*( height - yr - 1 )+  xr );

      if( 3*image.size() <= index ) continue;
      image[ index +2 ] = //std::uint8_t(  int( 256*::math::function::ramp<double>( 4*(t-0.5 ) ) ) );
      image[ index +1 ] = // std::uint8_t(  int( 256*::math::function::ramp<double>( 4*(t-0.25 ) ) ) );
      image[ index +0 ] = //std::uint8_t(  int( 256*::math::function::ramp<double>( 4*t ) ) );
                         std::uint8_t(  int( 256*::math::function::saw<double>( 4 * 4 * t ) ) );
    }
#if USE_PNM
   { 
    std::string time =  __TIME__; std::replace( time.begin(), time.end(), ':', '-');
    std::ofstream( "hilbertND_" + time+"_" + std::to_string(g_calc) + ".pgm" ) << PNM::save( image, width, height, PNM::P3 ); 
   }
#endif
        }
  std::cout << "End." << std::endl;
  //
  return EXIT_SUCCESS;
 }

