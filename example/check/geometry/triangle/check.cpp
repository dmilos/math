#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"
#include "math/geometry/triangle/circumcenter.hpp"
#include "math/geometry/triangle/orthocenter.hpp"

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


void circumcenter()
 {
  std::cout << __func__ << " - start" << std::endl;
  ::math::linear::vector::structure< double, 2 >     center;
  ::math::geometry::triangle::structure<double,2>  triangle;

   triangle[0] = { 0, 0 };
   triangle[1] = { 1, 0 };
   triangle[2] = { 0, 1 };
  ::math::geometry::triangle::circumcenter( center, triangle );

  for( int i=0; i< 100; i++)
   {
    triangle[0] = { ::math::function::any_to_any<double>( rand()/(double)RAND_MAX, 0, 1, -1, 1 ), ::math::function::any_to_any<double>( rand()/(double)RAND_MAX, 0, 1, -1, 1 ) };
    triangle[1] = { ::math::function::any_to_any<double>( rand()/(double)RAND_MAX, 0, 1, -1, 1 ), ::math::function::any_to_any<double>( rand()/(double)RAND_MAX, 0, 1, -1, 1 ) };
    triangle[2] = { ::math::function::any_to_any<double>( rand()/(double)RAND_MAX, 0, 1, -1, 1 ), ::math::function::any_to_any<double>( rand()/(double)RAND_MAX, 0, 1, -1, 1 ) };

    ::math::geometry::triangle::circumcenter( center, triangle );

    auto r0 = ::math::linear::vector::distance( center, triangle[0] );
    auto r1 = ::math::linear::vector::distance( center, triangle[1] );
    auto r2 = ::math::linear::vector::distance( center, triangle[2] );

    if( 0.00001 < fabs( r0-r1 ) ) { std::cout << "*"; }
    if( 0.00001 < fabs( r0-r2 ) ) { std::cout << "*"; }
    if( 0.00001 < fabs( r1-r2 ) ) { std::cout << "*"; }
   }

  std::cout << __func__ << " - end" << std::endl;
 }

void orthocenter
 ( 
   ::math::linear::vector::structure< double, 2 > & oO
  ,::math::linear::vector::structure< double, 2 > & oF
  ,::math::geometry::triangle::structure<double,2> const& triangle 
)
 {
  ::math::geometry::direction::ABC2D<double>  a; a = ::math::geometry::direction::two<double,2>{ triangle[0], triangle[1] };
  ::math::geometry::direction::ABC2D<double>  b; b = ::math::geometry::direction::two<double,2>{ triangle[0], triangle[2] };
  ::math::geometry::direction::ABC2D<double>  c; c = ::math::geometry::direction::two<double,2>{ triangle[1], triangle[2] };

   ::math::linear::vector::structure< double, 2 > oO1, oO2;
   auto r0 = ::math::geometry::triangle::orthocenter<double>().process( oO1, a, b, c );
   auto r1 = ::math::geometry::triangle::orthocenter<double>().process( oO2, triangle );

   if( 0.000001 < ::math::linear::vector::distance( oO1, oO2 ) )
    {
     std::cout << "*";
    }

  ::math::linear::vector::structure< double, 2 > circum;
  ::math::geometry::triangle::circumcenter( circum, triangle );

  ::math::geometry::triangle::structure<double,2>  fix;
     ::math::linear::vector::subtraction( fix[0], triangle[0] , circum );
     ::math::linear::vector::subtraction( fix[1], triangle[1] , circum );
     ::math::linear::vector::subtraction( fix[2], triangle[2] , circum );

  ::math::linear::vector::addition( oF, fix[0], fix[1] );
  ::math::linear::vector::addition( oF, fix[2] );
  ::math::linear::vector::addition( oF, circum );
 }

void orthocenter()
 {
  ::math::geometry::triangle::structure<double,2>  triangle;
   ::math::linear::vector::structure< double, 2 >   oO, oF;

   triangle[0] = { 0, 0 };
   triangle[1] = { 1, 0 };
   triangle[2] = { 0, 1 };
   orthocenter( oO,  oF, triangle );

   triangle[0] = { cos( ::math::geometry::deg2rad(   0 + 0 ) ), sin( ::math::geometry::deg2rad(   0 + 0 ) ) };
   triangle[1] = { cos( ::math::geometry::deg2rad( 120 + 0 ) ), sin( ::math::geometry::deg2rad( 120 + 0 ) ) };
   triangle[2] = { cos( ::math::geometry::deg2rad( 240 + 0 ) ), sin( ::math::geometry::deg2rad( 240 + 0 ) ) };
   orthocenter( oO,  oF, triangle );

  for( int i=0; i< 100; i++)
   {
    triangle[0] = { ::math::function::any_to_any<double>( rand()/(double)RAND_MAX, 0, 1, -1, 1 ), ::math::function::any_to_any<double>( rand()/(double)RAND_MAX, 0, 1, -1, 1 ) };
    triangle[1] = { ::math::function::any_to_any<double>( rand()/(double)RAND_MAX, 0, 1, -1, 1 ), ::math::function::any_to_any<double>( rand()/(double)RAND_MAX, 0, 1, -1, 1 ) };
    triangle[2] = { ::math::function::any_to_any<double>( rand()/(double)RAND_MAX, 0, 1, -1, 1 ), ::math::function::any_to_any<double>( rand()/(double)RAND_MAX, 0, 1, -1, 1 ) };

    orthocenter( oO,  oF, triangle );

    std::cout << "*";
   }

 }

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  triangle_angle();

   circumcenter();

   orthocenter();

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
