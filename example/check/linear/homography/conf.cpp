#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <string>

#include <iostream>
#include <iomanip>


#include "math/math.hpp"

#if defined( HAVE_COUNTER )
#include "counter/counter.hpp"
typedef ::counter::number<double> double_type;
#endif

typedef double double_type;


#if defined( HAVE_COUNTER )
void print( ::counter::statistics const& stat )
 {
  int index=0;
  for( auto const& c : stat.container() )
  {
   ++index;
   if( 0 == c )
    continue;

   std::cout << "    ";
   std::cout << ::counter::constant::to_string( index-1 ) << " = ";
   std::cout << c;
   std::cout << std::endl;
  }

   std::cout << "--- --- ---" << std::endl;
 }
#endif


typedef ::math::linear::vector::structure<double_type,2> C2T;
typedef ::math::linear::vector::structure<double_type,3> C3T;
typedef ::math::linear::vector::structure<double_type,2> coord2d_type;
typedef ::math::linear::vector::structure<double_type,3> coord3d_type;
typedef ::math::linear::homography::structure<double_type,2> homograph_type;

template < typename scalar_name >
 void print( ::math::linear::homography::structure<scalar_name,2> const& H )
  {
   scalar_name div = 1;
   if( 1e-6 < fabs( H[2][2] ) ) div = H[2][2];

   for( auto const& row : H )
    {
     for( auto const& v : row )
      {
       std::cout <<  std::setw(12) << v / div << "; ";
      }
     std::cout << std::endl;
    }
  }

template < typename scalar_name, unsigned dimension >
 void print( ::math::linear::vector::structure<scalar_name,dimension> const& C )
  {
   for( auto const& v : C )
    {
     std::cout << std::setw( 12 ) << v << "; ";
    }
  }



int evaluate 
  (
   homograph_type const& H,
   C2T const& S, C2T const& T,
   double_type const& epsilon = 1e-6
 )
 {
   coord2d_type  t;

   auto dot = ::math::linear::vector::dot(  H[2], {S[0],S[1],1} );

  ::math::linear::homography::transform( t, H, S );
   auto distance =  ::math::linear::vector::distance( t, T );
  if( ( epsilon < distance ) && ( epsilon < fabs( dot ) ) )
   {
    //::math::linear::homography::transform( t, H, S );
    //std::cout << "\x1b[31m";
    //std::cout << "(  "; print( S );  std::cout << " )";
    //std::cout << " -> ";
    //std::cout << "(  "; print( T );  std::cout << " )";
    //std::cout << " - ";
    //std::cout << "(  "; print( t );  std::cout << " )";
    //std::cout << distance << std::endl;
    //std::cout << "\x1b[0m";
    return 0;
   }
  return 1;
 }

int evaluate 
  (
   homograph_type const& H,
   C2T const& S0, C2T const& T0,
   C2T const& Sx, C2T const& Tx,
   C2T const& Sy, C2T const& Ty,
   C2T const& Sz, C2T const& Tz,
   double_type const& epsilon = 1e-6
 )
 {
  int result = 0;
  result += (int)evaluate( H, S0, T0, epsilon );
  result += (int)evaluate( H, Sx, Tx, epsilon );
  result += (int)evaluate( H, Sy, Ty, epsilon );
  result += (int)evaluate( H, Sz, Tz, epsilon );
  return result;
 }


int all_test
 (
   C2T const& S0, C2T const& T0,
   C2T const& Sx, C2T const& Tx,
   C2T const& Sy, C2T const& Ty,
   C2T const& Sz, C2T const& Tz
 )
 {
  homograph_type  heq;
  homograph_type  A;
  homograph_type  BB;
  homograph_type  ph;

   //print( double_type::statistics() ); double_type::statistics().reset();

   if(false){
    C3T   pR, pA;
    homograph_type  test;
    ::math::linear::matrix::transform( pR, test, pA );
    //print( double_type::statistics() ); double_type::statistics().reset();
   }

   // //double_type::statistics().reset();
   // auto rHE = ::math::linear::homography::construct(   heq,  S0, T0, Sx, Tx, Sy, Ty, Sz, Tz );  //::math::linear::matrix::scale<double_type>( heq, 1/heq[2][2] );
   // //print( double_type::statistics() ); double_type::statistics().reset();
   // auto eHE = evaluate( heq,  S0, T0, Sx, Tx, Sy, Ty, Sz, Tz );

   //double_type::statistics().reset();
   auto rA = ::math::linear::homography::constructA(    A,  S0, T0, Sx, Tx, Sy, Ty, Sz, Tz );  //::math::linear::matrix::scale<double_type>(   A, 1/  A[2][2] );
   //print( double_type::statistics() ); double_type::statistics().reset();
   auto eA = evaluate( A,  S0, T0, Sx, Tx, Sy, Ty, Sz, Tz );

   //double_type::statistics().reset();
   auto rBB =::math::linear::homography::constructBB(  BB,  S0, T0, Sx, Tx, Sy, Ty, Sz, Tz );  //::math::linear::matrix::scale<double_type>(  BB, 1/ BB[2][2] );
   //print( double_type::statistics() ); double_type::statistics().reset();
   auto eBB = evaluate( BB,  S0, T0, Sx, Tx, Sy, Ty, Sz, Tz );

   //double_type::statistics().reset();
   auto rPH = ::math::linear::homography::constructPH( ph, S0, T0, Sx, Tx, Sy, Ty, Sz, Tz ); // ::math::linear::matrix::scale<double_type>(  ph, 1/ ph[2][2] );
   //print( double_type::statistics() ); double_type::statistics().reset();
   auto ePH = evaluate( ph,  S0, T0, Sx, Tx, Sy, Ty, Sz, Tz );

   int tC = 0;  tC = (int)rA + (int)rBB + ( int)rPH;

   bool debug = false;

   if ( true == debug ) if( ( 3 != tC ) || ( ( rA == true) && ( 4 != eA ) ) || (( rBB == true)&&( 4 != eBB ) ) || ( ( rPH == true)&&( 4 != ePH ) ) )
    {
     std::cout << "--- PH ---" << ePH << " - " << rPH << std::endl;
     print( ph );     std::cout << std::endl;
     //std::cout << "--- heq ---" << eHE << std::endl;
     //print( heq ); std::cout << std::endl;
     std::cout << "--- BB ---" << eBB << " - " << rBB << std::endl;
     print( BB ); std::cout << std::endl;
     std::cout << "--- A ---" << eA << " - " << rA << std::endl;
     print( A ); std::cout << std::endl;
    }
  return tC;
 }

int main()
 {
  homograph_type  heq;
  homograph_type  A;
  homograph_type  BB;
  homograph_type  ph;
/* */
  all_test
   (
     { 0.0, 0.0 },  { 0.0, 0.0 },
     { 1.0, 0.0 },  { 1.0, 0.0 },
     { 0.0, 1.0 },  { 0.0, 1.0 },
     { 1.0, 1.0 },  { 1.0, 1.0 }
   );

  all_test
   (
     { 0.1, 0.1 },  { 0.1, 0.1 },
     { 1.1, 0.1 },  { 1.1, 0.1 },
     { 0.1, 1.1 },  { 0.1, 1.1 },
     { 1.1, 1.1 },  { 1.1, 1.1 }
   );

  all_test
   (
     { 0.0, 0.0 },  { 0.0, 0.0 },
     { 1.0, 0.0 },  { 1.0, 0.0 },
     { 0.0, 1.0 },  { 0.0, 1.0 },
     { 1.0, 1.0 },  { 1.0, 1.1 }
   );

  all_test
   (
     { 0.0, 0.0 },  { 0.0, 0.0 },
     { 1.0, 0.0 },  { 1.0, 0.0 },
     { 0.0, 1.0 },  { 0.0, 1.0 },
     { 1.1, 1.0 },  { 1.0, 1.0 }
   );
 
  all_test
   (
     { 0.0, 0.0 },  { 0.0, 0.0 },
     { 1.0, 0.0 },  { 1.0, 0.0 },
     { 0.0, 1.0 },  { 0.0, 1.0 },
     { 1.1, 1.0 },  { 1.0, 1.1 }
   );
 
  all_test
   (
     { 0.0, 0.0 },  { 0.0, 0.0 },
     { 1.0, 0.0 },  { 1.0, 0.0 },
     { 0.0, 1.0 },  { 0.0, 1.0 },
     { 1.1, 1.0 },  { 1.0, 1.1 }
   );

  all_test
   (
     { 0.0, 0.0 },  { 0.0, 0.0 },
     { 1.0, 0.0 },  { 1.0, 0.0 },
     { 0.0, 1.0 },  { 0.0, 1.0 },
     { 1.0, 1.0 },  { 2.0/3.0, 2.0/3.0 }
   );

  all_test
   (
     { 0.0, 0.0 },  { 0.0, 0.0 },
     { 1.0, 0.0 },  { 1.0, 0.0 },
     { 0.0, 1.0 },  { 0.0, 1.0 },
     { 1.0, 1.0 },  { 0.5, 0.5 }
   );

  all_test
   (
     { 0.0, 0.0 },  { 0.0, 0.0 },
     { 1.0, 0.0 },  { 1.0, 0.0 },
     { 0.0, 1.0 },  { 0.0, 1.0 },
     { -1.5, 0.0 },  { -1.5, -1.5 }
   );

  all_test
   (
     { 0.0, 0.0 },  { 0.0, 0.0 },
     { 1.0, 0.0 },  { 1.0, 0.0 },
     { 0.0, 1.0 },  { 0.0, 1.0 },
     { 1.0, 1.0 },  { -0.4, 1.4 }
   );

  all_test
   (
     { 0.0, 0.0 },  { 0.0, 0.0 },
     { 1.0, 0.0 },  { 1.0, 0.0 },
     { 0.0, 1.0 },  { 0.0, 1.0 },
     { 0.5, 0.5 },  { 1.0, 1.0 }
   );

 
    std::cout << " -----"<< std::endl;
  for( double x= 0 ; x < 1.0; x += 0.1 )
   {
    for( double y= 0 ; y < 1.0; y += 0.1 )
     {
       std::cout << all_test
        (
          { 0.0, 0.0 },  { 0.0, 0.0 },
          { 1.0, 0.0 },  { 1.0, 0.0 },
          { 0.0, 1.0 },  { 0.0, 1.0 },
          { x, y },  { 1.0, 1.0 }
        );
    }
    std::cout << std::endl;
   }
/**/
  return 0;
}
