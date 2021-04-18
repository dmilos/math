#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int g_calc = 0;
#include "math/math.hpp"

#if USE_PNM
#include "pnm/pnm.hpp"
#endif

#if USE_COLOR
#include "color/color.hpp"
#endif


int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  std::vector< std::uint8_t> image;
  auto height = 1280;
  auto width  = 1280;
  auto channel  = 3;

  for( double t=0; t < 1;  t+= 0.01 )
   {
    long double x,y;
    ::math::function::hilbert2D<long double>( x, y, t, 15 );
    std::array<double,2> point;
    ::math::function::hilbertND<double>( point, t, 15 );

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

  for( int iteration = 1; iteration < 13; ++iteration )
   {
    image.clear(); image.resize( channel*height * width, 0 );
    ::color::rgb<std::uint8_t> rgb;
    double step =pow( 0.25, iteration );
    for( double t=0; t< 0.9999999999;  t+= step )
     {
#if USE_COLOR
      ::color::hsl<double>       hsv{ 360 * t, 100 ,t*90 + 10  };
#endif
      long double x,y;
      ::math::function::hilbert2D<long double>( x, y, t, iteration );

      double xr = ( x*width  );
      double yr = ( y*height );

      std::size_t  index = channel * std::size_t( width*int( height - int(yr) - 1)+int( xr ) );
      if( image.size() <= index ) continue;
#if USE_COLOR
      rgb = hsv;
      image[ index +0 ] = rgb[0]; // std::uint8_t( int( 256*t ) );
      image[ index +1 ] = rgb[1]; // std::uint8_t( int( 256*(t*3) )%256 );
      image[ index +2 ] = rgb[2]; // std::uint8_t( int( 256*(t*9) )%256 );
#endif
      image[ index +0 ] =  std::uint8_t( int( 256*t ) );
     }

    std::cout << "iteration: " << iteration << std::endl;
#if USE_PNM
    { std::ofstream( std::string( "hilbert2D-")+ (iteration < 10?"0":"") +std::to_string( iteration )+"-Rotate-256.pgm", std::ios_base::binary ) << PNM::save( image, width, height, PNM::P6 ); }
#endif
   }

  for( int iteration = 13; iteration < 13; ++iteration )
   {
    image.clear(); image.resize( channel*height * width, 0 );
    double step =pow( 0.25, iteration );
    for( double t=0; t< 0.9999999999;  t+= step )
     {
      std::array<double,2> point;
      ::math::function::hilbertND<double>( point, t, iteration );

      int xr = ( point[0]*width  );
      int yr = ( point[1]*height );
      std::size_t  index = channel * std::size_t( width*int( height - int(yr) - 1)+int( xr ) );

      if( image.size() <= index ) continue;
      image[ index +0 ] = std::uint8_t( int( 256*t ) );
     }

    std::cout << "iteration: " << iteration << std::endl;
#if USE_PNM
   { 
    { std::ofstream( std::string( "hilbertND-")+ (iteration < 10?"0":"") +std::to_string( iteration )+"-Rotate-256.pgm", std::ios_base::binary ) << PNM::save( image, width, height, PNM::P6 ); }
   }
#endif
        }
  std::cout << "End." << std::endl;
  //
  return EXIT_SUCCESS;
 }

