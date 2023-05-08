

#include <iostream>
#include <iomanip>
#include <chrono>

#include "math/math.hpp"


int main( int argc, char*argv[] )
 {
  std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
  ::math::geometry::projective::camera::focus::semi1D<double> semi;
  typedef ::math::linear::vector::structure< double, 2 >  point_type;
  const double focus = 5.51;
  int width = 800;
  int height = 600;
  for( int index=1; index < 52; ++index )
   {
    point_type P;
    double A = math::geometry::deg2rad(rand()%360 );
    P[0] = (int)( width*( 0.9*cos( A ) ) );
    P[1] = (int)( width*( 0.9*sin( A ) ) );

    auto S1 = sqrt( ( P[0] )*( P[0] ) + (focus)*(focus) + ( P[1] )*( P[1] ) );
    auto D1 = sqrt( P[0]*P[0] + P[1]*P[1] );
    //semi.process( S1, D1 );

    A = math::geometry::deg2rad(rand()%360 );
    P[0] = (int)( width*cos( A ) );
    P[1] = (int)( width*sin( A ) );
    auto S2 = sqrt( ( P[0] )*( P[0] ) + (focus)*(focus) + ( P[1] )*( P[1] ) );
    auto D2 = sqrt( P[0]*P[0] + P[1]*P[1] );
    //semi.process( S2, D2 );

    semi.process( S1, D1, S2, D2 );
    std::cout <<  semi.focus()<< ", ";   //"Focus: " <<
    std::cout  << semi.scale() << std::endl; //<< "Scale: "

     if( 0 == ( index % 2 ) ) 
      {
       //semi.reset( semi.focus(), semi.scale() );
      }
                              
   }

  std::cout << "Focus: " << semi.focus() << std::endl;
  std::cout << "Scale: " << semi.scale() << std::endl;

  return 0;
 }

