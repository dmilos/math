#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


#include "math/math.hpp"


#if USE_PNM
#include "pnm/pnm.hpp"
#endif



void normal()
 {

  double epsilon = 0;

  for( double x=-10; x< 10; x += 0.001 )
   {
    auto a = ::math::function::distribution::normal<double>( x );
    auto b = ::math::function::distribution::normal<double>( x, 1 );
    auto c = ::math::function::distribution::normal<double>( x, 1, 0 );

    if( epsilon < fabs( a-b ) ) { std::cout << "Error for X: " << x << std::endl; }
    if( epsilon < fabs( a-c ) ) { std::cout << "Error for X: " << x << std::endl; }
    if( epsilon < fabs( b-c ) ) { std::cout << "Error for X: " << x << std::endl; }
   }

 }

void putPixel( std::vector< std::uint8_t> & image, std::array<std::size_t,2> const& size, std::array<std::size_t,2> const& location )
 {
  if( size[0] < location[0] + 1 ) return;
  if( size[1] < location[1] + 1 ) return;
  auto index = size[0] * location[1] + location[0];
  if( image.size() < index ) return;
  image[ index ] = 255;
 }

void putPixel( std::vector< std::uint8_t> & image, std::array<std::size_t,2> const& size, std::array<std::array<double,2>,2> const& window , std::array<double,2> const& location )
 {
  std::size_t x = (std::size_t)(::math::function::any_to_any<double>( (double)location[0], window[0][0], window[1][0], (double)      0, (double)size[0] ) + 0.5);
  std::size_t y = (std::size_t)(::math::function::any_to_any<double>( (double)location[1], window[0][1], window[1][1], (double)size[1], (double)      0 ) + 0.5);

  putPixel( image, size, { x,y } );
 }

int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;
  normal();
  std::cout << "normal(-1):     "            << ::math::function::distribution::normal<double>(-1)     << std::endl;
  std::cout << "normal(-1,1):   "            << ::math::function::distribution::normal<double>(-1,1)   << std::endl;
  std::cout << "normal(-1,1,0): "            << ::math::function::distribution::normal<double>(-1,1,0) << std::endl<< std::endl;

  std::cout << "normal(0):     "             << ::math::function::distribution::normal<double>(0)     << std::endl;
  std::cout << "normal(0,1):   "             << ::math::function::distribution::normal<double>(0,1)   << std::endl;
  std::cout << "normal(0,1,0): "             << ::math::function::distribution::normal<double>(0,1,0) << std::endl<< std::endl;

  std::cout << "normal(1):     "             << ::math::function::distribution::normal<double>(1)     << std::endl;
  std::cout << "normal(1,1):   "             << ::math::function::distribution::normal<double>(1,1)   << std::endl;
  std::cout << "normal(1,1,0): "             << ::math::function::distribution::normal<double>(1,1,0) << std::endl<< std::endl;

  std::cout << "normal_invert(1,1,0): "      << ::math::function::distribution::normal_invert<double>(1,1,0) << std::endl;
  std::cout << "normal_cumulative(0.99,1): " << ::math::function::distribution::normal_cumulative<double>(0.99,1.0) << std::endl;

  std::vector< std::uint8_t> image;
  auto width  = 1500;
  auto height = 1500;
  image.resize( height * width, 0 );
  double lo_x = -4;
  double hi_x = +4;
  double lo_y = -2;
  double hi_y = +2;

    double y;
  for( int i=0; i< width; ++i)
   {
    double x = ::math::function::any_to_any<double>( i, 0, width, lo_x, hi_x );

    y=0;
    putPixel( image, {(std::size_t)width,(std::size_t)height}, { lo_x, lo_y, hi_x, hi_y }, {x,y} );

    y = 0.5;
    putPixel( image, {(std::size_t)width,(std::size_t)height}, { lo_x, lo_y, hi_x, hi_y }, {x,y} );

    y = 1;
    putPixel( image, {(std::size_t)width,(std::size_t)height}, { lo_x, lo_y, hi_x, hi_y }, {x,y} );

    y = ::math::function::distribution::normal<double>( x );
    putPixel( image, {(std::size_t)width,(std::size_t)height}, { lo_x, lo_y, hi_x, hi_y }, {x,y} );

    y = ::math::function::distribution::normal<double>( x, sqrt(2*3.141),0);
    putPixel( image, {(std::size_t)width,(std::size_t)height}, { lo_x, lo_y, hi_x, hi_y }, {x,y} );
    
    y = ::math::function::distribution::normal<double>( x, 0.9,     0 );
    putPixel( image, {(std::size_t)width,(std::size_t)height}, { lo_x, lo_y, hi_x, hi_y }, {x,y} );
    
    y = ::math::function::distribution::normal<double>( x, 0.8, 0 );
    putPixel( image, {(std::size_t)width,(std::size_t)height}, { lo_x, lo_y, hi_x, hi_y }, {x,y} );
    
    y = ::math::function::distribution::normal<double>( x, 0.7, -0.1 );
    putPixel( image, {(std::size_t)width,(std::size_t)height}, { lo_x, lo_y, hi_x, hi_y }, {x,y} );
    
    y = ::math::function::distribution::normal<double>( x, 0.6, 0.1 );
    putPixel( image, {(std::size_t)width,(std::size_t)height}, { lo_x, lo_y, hi_x, hi_y }, {x,y} );
    
    y   = -1*::math::function::distribution::normal_cumulative<double>( x, 0.8 ) + ::math::function::distribution::normal_cumulative_ZS<double>( x, 0.8 );  
    putPixel( image, {(std::size_t)width,(std::size_t)height}, { lo_x, lo_y, hi_x,hi_y},{x,y});
                    
y=-1*::math::function::distribution::normal_cumulative<double>(x,0.7)+::math::function::distribution::normal_cumulative_ZS<double>(x,0.7);
    putPixel( image, {(std::size_t)width,(std::size_t)height}, { lo_x, lo_y, hi_x, hi_y }, {x,y} );

    y = -1*::math::function::distribution::normal_cumulative<double>( x, 0.6 ) + ::math::function::distribution::normal_cumulative_ZS<double>( x, 0.6 );
    putPixel( image, {(std::size_t)width,(std::size_t)height}, { lo_x, lo_y, hi_x, hi_y }, {x,y} );
   }

#if defined(Portable_Anymap_Format_E84FDB3F_0BF3_447F_821D_B9480766CC13)
  { std::ofstream( "image2_" + std::to_string(width) +".pgm" ) << PNM::save( image, width, height, PNM::P2 ); }
#endif
   std::cout << "Done" << std::endl;

  return EXIT_SUCCESS;
 }

