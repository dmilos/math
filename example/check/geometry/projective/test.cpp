#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

using namespace std;


void anharmonic( )
 {
  std::cout <<   ::math::geometry::projective::anharmonic::value( 0, 1, 2, 3 ) << std::endl;

  std::cout << "coefficient: " << ::math::geometry::projective::anharmonic::value<double>( 0, 1, 2, 3 ) << std::endl;
  std::cout << "coefficient: " << ::math::geometry::projective::anharmonic::value<double>( 1, 1, 1 ) << std::endl;

  std::cout << "a: " << ::math::geometry::projective::anharmonic::a<double>( 1, 1, ::math::geometry::projective::anharmonic::value<double>( 1, 1, 1 ) ) << std::endl; 
  std::cout << "b: " << ::math::geometry::projective::anharmonic::b<double>( 1, 1, ::math::geometry::projective::anharmonic::value<double>( 1, 1, 1 ) ) << std::endl; 
  std::cout << "c: " << ::math::geometry::projective::anharmonic::c<double>( 1, 1, ::math::geometry::projective::anharmonic::value<double>( 1, 1, 1 ) ) << std::endl; 

  std::cout << "A: " << ::math::geometry::projective::anharmonic::A<double>(    1, 2, 3, ::math::geometry::projective::anharmonic::value<double>( 0, 1, 2, 3 ) ) << std::endl; 
  std::cout << "B: " << ::math::geometry::projective::anharmonic::B<double>( 0,    2, 3, ::math::geometry::projective::anharmonic::value<double>( 0, 1, 2, 3 ) ) << std::endl; 
  std::cout << "C: " << ::math::geometry::projective::anharmonic::C<double>( 0, 1, 3,    ::math::geometry::projective::anharmonic::value<double>( 0, 1, 2, 3 ) ) << std::endl; 
  std::cout << "D: " << ::math::geometry::projective::anharmonic::D<double>( 0, 1, 2,    ::math::geometry::projective::anharmonic::value<double>( 0, 1, 2, 3 ) ) << std::endl; 

  std::cout << "coefficient: " << ::math::geometry::projective::anharmonic::value<double>( 0, 30, 50, 60 ) << std::endl;
  std::cout << "coefficient: " << ::math::geometry::projective::anharmonic::value<double>( 30, 20, 10 ) << std::endl;
  std::cout << "a: " << ::math::geometry::projective::anharmonic::a<double>( 20, 10, ::math::geometry::projective::anharmonic::value<double>( 30, 20, 10 ) ) << std::endl; 
  std::cout << "b: " << ::math::geometry::projective::anharmonic::b<double>( 30, 10, ::math::geometry::projective::anharmonic::value<double>( 30, 20, 10 ) ) << std::endl; 
  std::cout << "c: " << ::math::geometry::projective::anharmonic::c<double>( 30, 20, ::math::geometry::projective::anharmonic::value<double>( 30, 20, 10 ) ) << std::endl; 

  std::cout << "A: " << ::math::geometry::projective::anharmonic::A<double>(    30, 50, 60,  ::math::geometry::projective::anharmonic::value<double>( 0, 30, 50, 60 ) ) << std::endl; 
  std::cout << "B: " << ::math::geometry::projective::anharmonic::B<double>( 0,     50, 60,  ::math::geometry::projective::anharmonic::value<double>( 0, 30, 50, 60 ) ) << std::endl; 
  std::cout << "C: " << ::math::geometry::projective::anharmonic::C<double>( 0, 30,  60,     ::math::geometry::projective::anharmonic::value<double>( 0, 30, 50, 60 ) ) << std::endl; 
  std::cout << "D: " << ::math::geometry::projective::anharmonic::D<double>( 0, 30, 50,      ::math::geometry::projective::anharmonic::value<double>( 0, 30, 50, 60 ) ) << std::endl; 


  std::cout << "coefficient: " << ::math::geometry::projective::anharmonic::value<double>( 7, 8, 6 ) << std::endl;
  std::cout << "a: " << ::math::geometry::projective::anharmonic::a<double>(    8, 6, ::math::geometry::projective::anharmonic::value<double>( 7, 8, 6 ) ) << std::endl; 
  std::cout << "b: " << ::math::geometry::projective::anharmonic::b<double>( 7,    6, ::math::geometry::projective::anharmonic::value<double>( 7, 8, 6  ) ) << std::endl; 
  std::cout << "c: " << ::math::geometry::projective::anharmonic::c<double>( 7, 8,    ::math::geometry::projective::anharmonic::value<double>( 7, 8, 6  ) ) << std::endl; 

 }

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  anharmonic( );

  return EXIT_SUCCESS;
 }
