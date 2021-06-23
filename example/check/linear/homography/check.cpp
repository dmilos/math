#include <iostream>
#include <iomanip>
#include <chrono>

#include "math/math.hpp"

template< typename scalar_name, unsigned width_number, unsigned height_number >
 void print ( ::math::linear::matrix::structure<scalar_name,width_number,height_number> const& m )
  {
   std::cout << "{" << std::endl;
   for( unsigned j=0; j< width_number; j++ )
    {
     std::cout << std::endl << "    ";
     for( unsigned i=0; i< height_number; i++ )
      {
       std::cout << "" << std::setw(10) << std::fixed << m[j][i] << ", ";
      }
    }
   std::cout << std::endl;
   std::cout << "}" << std::endl;

  }

void hg1()
 {
  typedef ::math::linear::homography::structure<double,1>  homography1_type;

  homography1_type h1;

  ::math::linear::homography::construct<double>( h1, 0.5, 1.0 );
  print( h1 );

  ::math::linear::homography::construct<double>( h1, 0.4, 0.6 );
  print( h1 );

  ::math::linear::homography::construct<double>( h1, 0.6, 0.4 );
  print( h1 );

  ::math::linear::homography::construct<double>( h1, 0.5, 0.5 );
  print( h1 );
 }

void hg2()
 {
  typedef ::math::linear::homography::structure<double,2>  homography2_type;

  homography2_type h2;

  ::math::linear::homography::construct<double>( h2, {0,0}, {1,0}, {0,1}, {1,1} );
  print( h2 );

  ::math::linear::homography::construct<double>( h2, {1,1} );
  print( h2 );

  ::math::linear::homography::construct<double>( h2, {1,2}  );
  print( h2 );

  ::math::linear::homography::construct<double>( h2, {2,1}  );
  print( h2 );

  ::math::linear::homography::construct<double>( h2, {0,0}, {0,0}, {1,0}, {1,0}, {0,1}, {0,1}, {1,1}, {1,1} );
  print( h2 );

  ::math::linear::homography::construct<double>( h2, {0,0}, {0,0}, {1,0}, {1,0}, {0,1}, {0,1}, {1,1}, {1,2} );
  print( h2 );

  ::math::linear::homography::construct<double>( h2, {0,0}, {0,0}, {1,0}, {1,0}, {0,1}, {0,1}, {1,1}, {2,1} );
  print( h2 );

 }

void hg3()
 {
  typedef ::math::linear::homography::structure<double,3>  homography3_type;

  homography3_type h3;

  ::math::linear::homography::construct( h3, { 1, 1, 1 } );
  print( h3 );

  ::math::linear::homography::construct( h3, { 1, 2, 3 } );
  print( h3 );

  ::math::linear::homography::construct(
    h3
         ,{ 0, 0, 0 }
         ,{ 1, 0, 0 }
         ,{ 0, 1, 0 }
         ,{ 0, 0, 1 }
         ,{ 1, 1, 1 }
        );
  print( h3 );
  
  ::math::linear::homography::construct(
    h3
         ,{ 0, 0, 0 }
         ,{ 1, 0, 0 }
         ,{ 0, 1, 0 }
         ,{ 0, 0, 1 }
         ,{ 1, 2, 3 }
        );
  print( h3 );

  typedef  ::math::linear::vector::point<double,3> point3_type;

  ::math::linear::homography::construct<double>(
    h3, { 0, 0, 0,  1, 0, 0,  0, 1, 0,  0, 0, 1,  1, 2, 3 }
      , { 0, 0, 0,  1, 0, 0,  0, 1, 0,  0, 0, 1,  1, 2, 3 }
        );
  print( h3 );

 }

int main( int argc, char*argv[] )
 {
  hg1();
  hg2();
  hg3();

  return 0;
 }