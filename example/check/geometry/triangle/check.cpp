#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

using namespace std;

void triangle_angle()
 {
  double a;

  ::math::geometry::triangle::angle_alpha<double>( a, 1.5, 2, 3 );
  ::math::geometry::triangle::angle_beta<double>(  a, 1.5, 2, 3 );
  ::math::geometry::triangle::angle_gamma<double>( a, 1.5, 2, 3 );

  ::math::geometry::triangle::height_a<double>( a, 1.5, 2, 3 );
  ::math::geometry::triangle::height_b<double>(  a, 1.5, 2, 3 );
  ::math::geometry::triangle::height_c<double>( a, 1.5, 2, 3 );

    double alpha, beta, gamma;
  ::math::geometry::triangle::angle_beta <double>(  beta, 3, 4, 5 ); std::cout << std::setw( 12 ) << math::geometry::rad2deg(  beta ) << "+";
  ::math::geometry::triangle::angle_alpha<double>( alpha, 3, 4, 5 ); std::cout << std::setw( 12 ) << math::geometry::rad2deg( alpha ) << "+";
  ::math::geometry::triangle::angle_gamma<double>( gamma, 3, 4, 5 ); std::cout << std::setw( 12 ) << math::geometry::rad2deg( gamma ) << "=";

  std::cout <<  math::geometry::rad2deg( alpha  )
              + math::geometry::rad2deg(  beta  )
              + math::geometry::rad2deg(  gamma )
        << std::endl;

  for( int i=0; i< 100; ++i )
   {
    double a = rand()/(double)RAND_MAX;
    double b = rand()/(double)RAND_MAX;
    double c = rand()/(double)RAND_MAX;

    if( false == ::math::geometry::triangle::valid( a,b,c ) )
     {
      continue;
     }

    ::math::geometry::triangle::angle_alpha<double>( alpha, a, b, c ); std::cout << std::setw( 12 ) <<math::geometry::rad2deg( alpha ) << "+";
    ::math::geometry::triangle::angle_beta <double>(  beta, a, b, c ); std::cout << std::setw( 12 ) <<math::geometry::rad2deg(  beta ) << "+";
    ::math::geometry::triangle::angle_gamma<double>( gamma, a, b, c ); std::cout << std::setw( 12 ) <<math::geometry::rad2deg( gamma ) << "=";

     std::cout <<  math::geometry::rad2deg( alpha  )
                 + math::geometry::rad2deg(  beta  )
                 + math::geometry::rad2deg(  gamma )
           << std::endl;
   }

 }


int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  triangle_angle();

  ::math::geometry::triangle::structure<double, 10>   a10{0}; a10 = a10;
  ::math::geometry::triangle::structure<double, 3>   a3;
  ::math::geometry::triangle::structure<double, 2>   a2;

  ::math::linear::vector::structure< double, 2 >  vC, vA0, vA1, vA2;
  ::math::linear::vector::structure< double, 3 >  v3;

  ::math::geometry::triangle::area( a2[0], a2[1], a2[2] );
  ::math::geometry::triangle::area( a3 );
  ::math::geometry::triangle::centroid( vC , vA0, vA1, vA2 );

  ::math::geometry::triangle::inradius( a3 );
  ::math::geometry::triangle::circumradius( a3 );
  ::math::geometry::triangle::barycentric( v3, vC, a2 );



  return EXIT_SUCCESS;
 }
