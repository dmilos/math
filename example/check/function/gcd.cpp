#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


#include "math/math.hpp"

#if USE_PNM
#include "pnm/pnm.hpp"
#endif

#include <iostream>
#include <iomanip>
#include <string>

 void putPixel( std::vector< std::uint8_t> & image, std::array<std::size_t,2> const& size, std::array<std::size_t,2> const& location, std::uint8_t const& color )
 {
  if( size[0] < location[0] + 1 ) return;
  if( size[1] < location[1] + 1 ) return;
  auto index = size[0] * location[1] + location[0];
  if( image.size() < index ) return;
  image[ index ] = color;
 }

int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  std::size_t resolution = 1000;
  std::vector< std::uint8_t>  image; image.resize( resolution * resolution, 0 );

  for( std::size_t x=1; x < resolution; ++x )
   {
    for( std::size_t y=1; y < resolution; ++y )
     {
      auto gcd = ::math::function::gcd( x, y );
      double c = gcd/  (double)std::max( x,y );

      putPixel( image, {resolution,resolution}, {x,y}, std::uint8_t ( 255 * c  ) );
     }
   }

#if defined(Portable_Anymap_Format_E84FDB3F_0BF3_447F_821D_B9480766CC13)
  { std::ofstream( "gcd.pgm" ) << PNM::save( image, resolution, resolution, PNM::P2 ); }
#endif
  std::cout << "done" << std::endl;
  std::cin.get();
  return EXIT_SUCCESS;
 }

