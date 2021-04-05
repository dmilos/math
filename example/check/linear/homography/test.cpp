#include <iostream>
#include <iomanip>
#include <chrono>

#include "math/math.hpp"

template< typename scalar_name, unsigned width_number, unsigned height_number >
 void print ( ::math::linear::matrix::structure<scalar_name,width_number,height_number> const& m )
  {
   for( unsigned j=0; j< width_number; j++ )
    {
     std::cout << std::endl;
     for( unsigned i=0; i< height_number; i++ )
      {
       std::cout << std::setw(10) << std::fixed << m[j][i] << ", ";
      }
    }
  }

void hg()
 {
    typedef ::math::linear::matrix::structure<double,3,3> matrix3_type;
    matrix3_type h;

    ::math::linear::homography::construct<double>( h, {0,0}, {0,0}, {1,0}, {1,0}, {0,1}, {0,1}, {1,1}, {1,1} );
    print( h );
    ::math::linear::homography::construct<double>( h, {0,0}, {1,0}, {0,1}, {1,1} );
    print( h );

    ::math::linear::homography::construct<double>( h, {1,1} );
    print( h );
    
}
 
int main( int argc, char*argv[] )
 {
  hg();

  
  return 0;
 }