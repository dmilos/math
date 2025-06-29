#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


#include "math/math.hpp"

#if USE_PNM
#include "pnm/pnm.hpp"
#endif


void putPixel( std::vector< std::uint8_t> & image, std::array<std::size_t,2> const& size, std::array<std::size_t,2> const& location, std::uint8_t const& color )
 {
  if( size[0] < location[0] + 1 ) return;
  if( size[1] < location[1] + 1 ) return;
  auto index = size[0] * location[1] + location[0];
  if( image.size() < index ) return;
  image[ index ] = color;
 }

void putPixel( std::vector< std::uint8_t> & image, std::array<std::size_t,2> const& size, std::array<std::array<double,2>,2> const& window , std::array<double,2> const& location, std::uint8_t const& color )
 {
  std::size_t x = (std::size_t)(::math::function::any_to_any<double>( (double)location[0], window[0][0], window[1][0], (double)      0, (double)size[0] ) + 0.5);
  std::size_t y = (std::size_t)(::math::function::any_to_any<double>( (double)location[1], window[0][1], window[1][1], (double)size[1], (double)      0 ) + 0.5);

  putPixel( image, size, { x,y }, color );
 }

int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  std::vector< std::uint8_t> image;
  auto height = 1000;
  auto width  = 1000;
  image.resize( height * width, 0 );

  for( double x=-1; x< 1; x += 1.0/width)
  for( double y=-1; y< 1; y += 1.0/height )
   {
    putPixel( image, {(std::size_t)width,(std::size_t)height}, { -1, -1, 1, 1 }, {x,y}, (std::uint8_t)( 127+127*::math::function::gabor2D<double>()( {x,y} ) ) );
   }

  int a=0;
  for( double x=-1; x < 1; x += 1.0/width)
   {
    auto y =  ::math::function::gabor<double,1>()( x );
    putPixel( image, {(std::size_t)width,(std::size_t)height}, { -1, -1, 1, 1 }, {x,y}, 255 );

    if( 0 ==( ++a%2 ))
     {
          y =  ::math::function::gabor<double,1>( math::constants::PHI_invSQRT2, 0.5, 0  )( x );
      putPixel( image, {(std::size_t)width,(std::size_t)height}, { -1, -1, 1, 1 }, {x,y}, 255 );
     }
    else
     {
           y = ::math::function::gabor2D<double>()( {x,0} );
      putPixel( image, {(std::size_t)width,(std::size_t)height}, { -1, -1, 1, 1 }, {x,y}, 0 );
     }

   }


#if defined(Portable_Anymap_Format_E84FDB3F_0BF3_447F_821D_B9480766CC13)
  { std::ofstream( "gabor.pgm" ) << PNM::save( image, width, height, PNM::P2 ); }
#endif
  return EXIT_SUCCESS;
 }
