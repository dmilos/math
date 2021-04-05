#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

   ::math::linear::vector::structure<double,1>   p0_1, p1_1, p2_1;
   ::math::linear::vector::structure<double,2>   p0_2, p1_2, p2_2;
   ::math::linear::vector::structure<double,3>   p0_3, p1_3, p2_3;
   ::math::linear::vector::structure<double,4>   p0_4, p1_4, p2_4;
   ::math::linear::vector::structure<double,5>   p0_5, p1_5, p2_5;


  ::math::linear::vector::symmetric( p0_1, p1_1, p2_1 );
  ::math::linear::vector::symmetric( p0_2, p1_2, p2_2 );
  ::math::linear::vector::symmetric( p0_3, p1_3, p2_3 );
  ::math::linear::vector::symmetric( p0_4, p1_4, p2_4 );
  ::math::linear::vector::symmetric( p0_5, p1_5, p2_5 );


  ::math::linear::vector::subtraction( p0_1, p1_1, p2_1 );
  ::math::linear::vector::subtraction( p0_2, p1_2, p2_2 );
  ::math::linear::vector::subtraction( p0_3, p1_3, p2_3 );
  ::math::linear::vector::subtraction( p0_4, p1_4, p2_4 );
  ::math::linear::vector::subtraction( p0_5, p1_5, p2_5 );


  ::math::linear::vector::scale( p1_1, 234234, p2_1 );
  ::math::linear::vector::scale( p1_2, 234234, p2_2 );
  ::math::linear::vector::scale( p1_3, 234234, p2_3 );
  ::math::linear::vector::scale( p1_4, 234234, p2_4 );
  ::math::linear::vector::scale( p1_5, 234234, p2_5 );


  ::math::linear::vector::fill( p2_1, 123123 );
  ::math::linear::vector::fill( p2_2, 123123 );
  ::math::linear::vector::fill( p2_3, 123123 );
  ::math::linear::vector::fill( p2_4, 123123 );
  ::math::linear::vector::fill( p2_5, 123123 );


  math::linear::vector::rotate(  p2_2, 123, p2_2 );
  math::linear::vector::rotate(  p2_2, 123, p2_2, p2_2 );
  math::linear::vector::rotateX( p2_3, 123, p2_3 );
  math::linear::vector::rotateY( p2_3, 123, p2_3 );
  math::linear::vector::rotateZ( p2_3, 123, p2_3 );


  ::math::linear::vector::reflect(  p0_1, p1_1, p2_1 );
  ::math::linear::vector::reflect(  p0_2, p1_2, p2_2 );
  ::math::linear::vector::reflect(  p0_3, p1_3, p2_3 );
  ::math::linear::vector::reflect(  p0_4, p1_4, p2_4 );
  ::math::linear::vector::reflect(  p0_5, p1_5, p2_5 );


::math::linear::vector::negate( p0_1, p1_1 );
::math::linear::vector::negate( p0_2, p1_2 );
::math::linear::vector::negate( p0_3, p1_3 );
::math::linear::vector::negate( p0_4, p1_4 );
::math::linear::vector::negate( p0_5, p1_5 );


::math::linear::vector::negate( p1_1 );
::math::linear::vector::negate( p1_2 );
::math::linear::vector::negate( p1_3 );
::math::linear::vector::negate( p1_4 );
::math::linear::vector::negate( p1_5 );

 ::math::linear::vector::project( p0_1, p1_1, p2_1 );
 ::math::linear::vector::project( p0_2, p1_2, p2_2 );
 ::math::linear::vector::project( p0_3, p1_3, p2_3 );
 ::math::linear::vector::project( p0_4, p1_4, p2_4 );
 ::math::linear::vector::project( p0_5, p1_5, p2_5 );


  ::math::linear::vector::multiply( p0_1, p1_1, p2_1 );
  ::math::linear::vector::multiply( p0_2, p1_2, p2_2 );
  ::math::linear::vector::multiply( p0_3, p1_3, p2_3 );
  ::math::linear::vector::multiply( p0_4, p1_4, p2_4 );
  ::math::linear::vector::multiply( p0_5, p1_5, p2_5 );

 ::math::linear::vector::multiply( p0_1, p1_1 );
 ::math::linear::vector::multiply( p0_2, p1_2 );
 ::math::linear::vector::multiply( p0_3, p1_3 );
 ::math::linear::vector::multiply( p0_4, p1_4 );
 ::math::linear::vector::multiply( p0_5, p1_5 );


  ::math::linear::vector::min( p0_1, p1_1, p2_1 );
  ::math::linear::vector::min( p0_2, p1_2, p2_2 );
  ::math::linear::vector::min( p0_3, p1_3, p2_3 );
  ::math::linear::vector::min( p0_4, p1_4, p2_4 );
  ::math::linear::vector::min( p0_5, p1_5, p2_5 );

 ::math::linear::vector::min( p0_1, p1_1 );
 ::math::linear::vector::min( p0_2, p1_2 );
 ::math::linear::vector::min( p0_3, p1_3 );
 ::math::linear::vector::min( p0_4, p1_4 );
 ::math::linear::vector::min( p0_5, p1_5 );


  ::math::linear::vector::max( p0_1, p1_1, p2_1 );
  ::math::linear::vector::max( p0_2, p1_2, p2_2 );
  ::math::linear::vector::max( p0_3, p1_3, p2_3 );
  ::math::linear::vector::max( p0_4, p1_4, p2_4 );
  ::math::linear::vector::max( p0_5, p1_5, p2_5 );

 ::math::linear::vector::max( p0_1, p1_1 );
 ::math::linear::vector::max( p0_2, p1_2 );
 ::math::linear::vector::max( p0_3, p1_3 );
 ::math::linear::vector::max( p0_4, p1_4 );
 ::math::linear::vector::max( p0_5, p1_5 );

  ::math::linear::vector::length( p1_1 ); ::math::linear::vector::length( p1_1, p1_1, 12.0  ); ::math::linear::vector::length( p1_1, 433.0 );
  ::math::linear::vector::length( p1_2 ); ::math::linear::vector::length( p1_2, p1_2, 12.0  ); ::math::linear::vector::length( p1_2, 433.0 );
  ::math::linear::vector::length( p1_3 ); ::math::linear::vector::length( p1_3, p1_3, 12.0  ); ::math::linear::vector::length( p1_3, 433.0 );
  ::math::linear::vector::length( p1_4 ); ::math::linear::vector::length( p1_4, p1_4, 12.0  ); ::math::linear::vector::length( p1_4, 433.0 );
  ::math::linear::vector::length( p1_5 ); ::math::linear::vector::length( p1_5, p1_5, 12.0  ); ::math::linear::vector::length( p1_5, 433.0 );

  ::math::linear::vector::invert( p1_1, p1_1 ); ::math::linear::vector::invert( p1_1 );
  ::math::linear::vector::invert( p1_2, p1_2 ); ::math::linear::vector::invert( p1_2 );
  ::math::linear::vector::invert( p1_3, p1_3 ); ::math::linear::vector::invert( p1_3 );
  ::math::linear::vector::invert( p1_4, p1_4 ); ::math::linear::vector::invert( p1_4 );
  ::math::linear::vector::invert( p1_5, p1_5 ); ::math::linear::vector::invert( p1_5 );

   ::math::linear::vector::homogenize( p1_1, p1_1 ); ::math::linear::vector::homogenize( p1_1 );
   ::math::linear::vector::homogenize( p1_2, p1_2 ); ::math::linear::vector::homogenize( p1_2 );
   ::math::linear::vector::homogenize( p1_3, p1_3 ); ::math::linear::vector::homogenize( p1_3 );
   ::math::linear::vector::homogenize( p1_4, p1_4 ); ::math::linear::vector::homogenize( p1_4 );
   ::math::linear::vector::homogenize( p1_5, p1_5 ); ::math::linear::vector::homogenize( p1_5 );

    ::math::linear::vector::dot( p1_1, p1_1 );
    ::math::linear::vector::dot( p1_2, p1_2 );
    ::math::linear::vector::dot( p1_3, p1_3 );
    ::math::linear::vector::dot( p1_4, p1_4 );
    ::math::linear::vector::dot( p1_5, p1_5 );


     ::math::linear::vector::divide( p0_1, p1_1, p2_1 ); ::math::linear::vector::divide( p0_1, p1_1 );
     ::math::linear::vector::divide( p0_2, p1_2, p2_2 ); ::math::linear::vector::divide( p0_2, p1_2 );
     ::math::linear::vector::divide( p0_3, p1_3, p2_3 ); ::math::linear::vector::divide( p0_3, p1_3 );
     ::math::linear::vector::divide( p0_4, p1_4, p2_4 ); ::math::linear::vector::divide( p0_4, p1_4 );
     ::math::linear::vector::divide( p0_5, p1_5, p2_5 ); ::math::linear::vector::divide( p0_5, p1_5 );

     ::math::linear::vector::distance( p0_1, p1_1 );
     ::math::linear::vector::distance( p0_2, p1_2 );
     ::math::linear::vector::distance( p0_3, p1_3 );
     ::math::linear::vector::distance( p0_4, p1_4 );
     ::math::linear::vector::distance( p0_5, p1_5 );

   ::math::linear::vector::cross( p0_2, p1_2  );
   ::math::linear::vector::cross( p0_3, p1_3, p2_3 );
   ::math::linear::vector::cross( p0_4, p1_4, p2_4, p2_4  );

  ::math::linear::vector::convex( p0_1, 322.0, p0_1, p0_1 );
  ::math::linear::vector::convex( p0_2, 322.0, p0_2, p0_2 );
  ::math::linear::vector::convex( p0_3, 322.0, p0_3, p0_3 );
  ::math::linear::vector::convex( p0_4, 322.0, p0_4, p0_4 );
  ::math::linear::vector::convex( p0_5, 322.0, p0_5, p0_5 );

  ::math::linear::vector::angle( p0_1, p0_1 );
  ::math::linear::vector::angle( p0_2, p0_2 );
  ::math::linear::vector::angle( p0_3, p0_3 );
  ::math::linear::vector::angle( p0_4, p0_4 );
  ::math::linear::vector::angle( p0_5, p0_5 );

   ::math::linear::vector::addition( p0_1, p1_1, p2_1 );   ::math::linear::vector::addition( p0_1, p0_1 );
   ::math::linear::vector::addition( p0_2, p1_2, p2_2 );   ::math::linear::vector::addition( p0_2, p0_2 );
   ::math::linear::vector::addition( p0_3, p1_3, p2_3 );   ::math::linear::vector::addition( p0_3, p0_3 );
   ::math::linear::vector::addition( p0_4, p1_4, p2_4 );   ::math::linear::vector::addition( p0_4, p0_4 );
   ::math::linear::vector::addition( p0_5, p1_5, p2_5 );   ::math::linear::vector::addition( p0_5, p0_5 );

   //::math::linear::vector::make( TODO );
   //::math::linear::vector::fill(  TODO );
   //::math::linear::vector::init( TODO );

  return EXIT_SUCCESS;
 }
