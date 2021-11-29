#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"
#include "math\geometry\projective\camera\focus\orto2d.hpp"
#include "math\geometry\projective\camera\focus\gmmb.hpp"


void print( ::math::linear::vector::structure<double,2> const& v )
 {
  std::cout << "[ " << v[0] << "," <<  v[1] << "]"; 
 }

void print( ::math::linear::vector::structure<double,3> const& v )
 {
  std::cout << "[ " << v[0] << "," <<  v[1] << "," <<   v[2] << "]"; 
 }

void test2D( double base, double height, double p )
 {
 }



void test3D( double base, double height, double p )
 {
 }

template < typename scalar_name >
  scalar_name projector( scalar_name const& focus, ::math::linear::vector::structure< double, 2 > const& point  )
   {
    return focus * point[0] / point[1];
   }

void check
 (
   double                                           const& focus_param
  ,::math::linear::vector::structure< double, 2 >   const&  O
  ,::math::linear::vector::structure< double, 2 >   const&  X
  ,::math::linear::vector::structure< double, 2 >   const&  Y
 )
 {
  std::cout << "---------------" << std::endl;
  double Op =  projector( focus_param, O ); std::cout << "Op : "<< Op << std::endl;
  double Xp =  projector( focus_param, X ); std::cout << "Xp : "<< Xp << std::endl;
  double Yp =  projector( focus_param, Y ); std::cout << "Yp : "<< Yp << std::endl;
  double Xl = ::math::linear::vector::distance( O, X ); std::cout << "Xl: " << Xl << std::endl; 
  double Yl = ::math::linear::vector::distance( O, Y ); std::cout << "Yl: " << Yl << std::endl;

  double focus_local;
  ::math::linear::vector::structure< double, 3 > origin{ NAN, NAN, Op };

  ::math::geometry::projective::camera::focus::orto2d( focus_local, origin, { Xp, Xl }, { Yp, Yl } );

  std::cout << "focusP: " << focus_param << std::endl;
  std::cout << "focusL: " << focus_local << std::endl;
  std::cout << "0: "; print( origin );  std::cout<< std::endl;
  std::cout << "O: "; print( O );  std::cout<< std::endl;
  std::cout << "X: "; print( X );  std::cout<< std::endl;
  std::cout << "Y: "; print( Y );  std::cout<< std::endl;
 }


int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;
  ::math::geometry::projective::camera::focus::gmmb<double> gmmb;
  double f;
  gmmb.process(f,{0,0},{0,0},{0,0},{0,0}); 

  check( 1, {1,1}, {2,1}, {1,2} );
  check( 2, {2,2}, {4,2}, {2,4} );

  for(int i=0; i< 10; ++i ){
   double focus = 1 + 5*rand()/(double)RAND_MAX; 
   ::math::linear::vector::structure< double, 2 > O{ 5 - 10 * rand()/(double)RAND_MAX, 5 - 10 * rand()/(double)RAND_MAX    };
   ::math::linear::vector::structure< double, 2 > X{ O[0] + 5 * rand()/(double)RAND_MAX, O[1]  };
   ::math::linear::vector::structure< double, 2 > Y{ O[0] , O[1]+ 5 * rand()/(double)RAND_MAX  };
    check( focus, O, X, Y );
  }


  return EXIT_SUCCESS;
 }
