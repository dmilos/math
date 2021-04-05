#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


#include "math/math.hpp"
//#include "pnm/pnm.hpp"


int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  std::cout << "normal(1,1)" <<::math::function::distribution::normal<double>(1,1) << std::endl;
  std::cout << "normal(1)" <<::math::function::distribution::normal<double>(1) << std::endl;
  std::cout << "normal_invert(1,1,1)" <<::math::function::distribution::normal_invert<double>(1,1,1) << std::endl;
  std::cout << "normal_cumulative(0.99,1)" << ::math::function::distribution::normal_cumulative<double>(0.99,1.0) << std::endl;

  std::vector< std::uint8_t> image;
  auto height = 1500;
  auto width  = 1500;
  image.resize( height * width, 0 );
  double lo_x = -4; 
  double lo_y = -4;
  double hi_x = +4;
  double hi_y = +4;

  double scale_x = (hi_x-lo_x)/width;  double move_x = lo_x;
  double scale_y = height/( hi_y-lo_y );  double move_y = height/2;

  for( int i=0; i< width; ++i)
   {
    double x = scale_x * i + move_x;

    double v = 0;
    int y= int( (v) * scale_y + move_y ); y = height-y-1; auto index = width *y + i;if( (0<index)&&(index< image.size()))image[ index ] = 255;

    v = 0.5;
    y= int( (v) * scale_y + move_y ); y = height-y-1; index = width *y + i;if( (0<index)&&(index< image.size()))image[ index ] = 255;

    v = 1;
    y= int( (v) * scale_y + move_y ); y = height-y-1; index = width *y + i;if( (0<index)&&(index< image.size()))image[ index ] = 255;

    v = ::math::function::distribution::normal<double>( x );
    y= int( (v) * scale_y + move_y ); y = height-y-1; index = width *y + i;if( (0<index)&&(index< image.size()))image[ index ] = 255;

    v = ::math::function::distribution::normal<double>( x, sqrt( 2 * 3.141 ), 0 );
    y= int( (v) * scale_y + move_y ); y = height-y-1;index = width *y + i; if( (0<index)&&(index< image.size()))image[ index ] = 255;

    v = ::math::function::distribution::normal<double>( x, 0.9, 0 );
    y= int( (v) * scale_y + move_y ); y = height-y-1;index = width *y + i; if( (0<index)&&(index< image.size()))image[ index ] = 255;

    v = ::math::function::distribution::normal<double>( x, 0.8, 0 );
    y= int( (v) * scale_y + move_y ); y = height-y-1;index = width *y + i; if( (0<index)&&(index< image.size()))image[ index ] = 255;

    v = ::math::function::distribution::normal<double>( x, 0.7, -0.1 );
    y= int( (v) * scale_y + move_y ); y = height-y-1;index = width *y + i;  if( (0<index)&&(index< image.size()))image[ index ] = 255;

    v = ::math::function::distribution::normal<double>( x, 0.6, 0.1 );
    y= int( (v) * scale_y + move_y ); y = height-y-1;index = width *y + i; if( (0<index)&&(index< image.size()))image[ index ] = 255;

    v = -1*::math::function::distribution::normal_cumulative<double>( x, 0.8 ) + ::math::function::distribution::normal_cumulative_ZS<double>( x, 0.8 );
    y= int( (v) * scale_y + move_y ); y = height-y-1;index = width *y + i; if( (0<index)&&(index< image.size()))image[ index ] = 255;

    v = -1*::math::function::distribution::normal_cumulative<double>( x, 0.7 ) + ::math::function::distribution::normal_cumulative_ZS<double>( x, 0.7 );
    y= int( (v) * scale_y + move_y ); y = height-y-1;index = width *y + i; if( (0<index)&&(index< image.size()))image[ index ] = 255;

    v = -1*::math::function::distribution::normal_cumulative<double>( x, 0.6 ) + ::math::function::distribution::normal_cumulative_ZS<double>( x, 0.6 );
    y= int( (v) * scale_y + move_y ); y = height-y-1; index = width *y + i; if( (0<index)&&(index< image.size()))image[ index ] = 255;

   }

  //{ std::ofstream( "image2.pgm" ) << PNM::save( image, width, height, PNM::P2 ); }
   std::cout << "Done" << std::endl;
  
  return EXIT_SUCCESS;
 }

