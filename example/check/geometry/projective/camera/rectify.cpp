#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"
#include "math/geometry/projective/epipolar/rectify2.hpp"
#include "math/geometry/projective/epipolar/rectify3.hpp"

using namespace std;

template< typename scalar_name, unsigned width_number, unsigned height_number >
 void print ( ::math::linear::matrix::structure<scalar_name,width_number,height_number> const& m, std::string const& comment = "" )
  {
   std::cout << comment << "{" ;
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

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  ::math::linear::homography::structure< double, 1 >   left;
  ::math::linear::homography::structure< double, 1 >   right;

  ::math::linear::affine::structure< double, 2 >       right2left{  { 1,0,0,1}, {0,1} };
  ::math::linear::affine::structure< double, 2 >       left2world;
  ::math::linear::affine::structure< double, 2 >       right2world;

  ::math::geometry::projective::epipolar::rectify( left, right, { { 1, 0, 0, 1 }, {   1,   0 } } );
  print( left, "left" ); print( right, "right" );

  ::math::geometry::projective::epipolar::rectify( left, right, { { 1, 0, 0, 1 }, { 100,   1 } } );
  print( left, "left" ); print( right, "right" );

  ::math::geometry::projective::epipolar::rectify( left, right, { { 1, 0, 0, 1 }, {   0,   1 } } );
  print( left, "left" ); print( right, "right" );

  ::math::geometry::projective::epipolar::rectify( left, right, { { 1, 0, 0, 1 }, {   1,   1 } } );
  print( left, "left" ); print( right, "right" );

  return EXIT_SUCCESS;
 }
