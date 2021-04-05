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
  auto height = 1000;
  auto width  = 1000;
  image.resize( height * width, 0 );

  for( int x=0; x< width; ++x)
  for( int y=0; y< height; ++y)
   {
    double xr = ( x/(width/2.0) - 1.0);
    double yr = ( y/(width/2.0) - 1.0);

   image[ width*y+x ] = std::uint8_t( 127*(::math::function::gabor2D<double>{}({xr,yr}) + 1) );
   }

  //{ std::ofstream( "gabor.pgm" ) << PNM::save( image, width, height, PNM::P2 ); }

  //
  return EXIT_SUCCESS;
 }

