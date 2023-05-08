#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

using namespace std;

void f()
 {
  ::math::statistic::gauss::V1< double, unsigned >   g1;
  ::math::statistic::gauss::V2< double, unsigned >   g2;
  ::math::statistic::gauss::V3< double, unsigned >   g3;

  ::math::statistic::gauss::V3< double, unsigned >::vector_type  vect;

  int count = 200;
  for( int i=0; i < count; i++)
   {
    g1.push( i );
    g2.push( i );
    vect.push_back( i );
   }

   double mean;
   double deviation;
   g3.process( mean, deviation, vect );

  std::cout << mean      << " - " << deviation << std::endl;
  std::cout << g1.mean() << " - " << sqrt( g1.deviation() ) << std::endl;
  std::cout << g2.mean() << " - " << sqrt( g2.deviation() ) << std::endl;
 }

void skew()
 {
  ::math::statistic::skewness<double>   skewness;
  std::vector<double> data0=  
   { 
    2.5, 3.7, 6.6, 9.1,
    9.5, 10.7, 11.9, 21.5,
    22.6, 25.2 
   }; //!< 0.77701
  std::cout << skewness.b1( data0 ) << std::endl;
  std::cout << skewness.g1( data0 ) << std::endl;
  std::cout << skewness.G1( data0 ) << std::endl;

  std::vector<double> data1={5, 20, 40, 80, 100}; //!< 0.0980392
  std::cout << skewness.b1( data1 ) << std::endl;
  std::cout << skewness.g1( data1 ) << std::endl;
  std::cout << skewness.G1( data1 ) << std::endl;

  std::vector<double> data2 = {3.4 , 7.1 , 1.5 , 8.6 , 4.9}; //!< -0.0107687
  std::cout << skewness.b1( data2 ) << std::endl;
  std::cout << skewness.g1( data2 ) << std::endl;
  std::cout << skewness.G1( data2 ) << std::endl;
 }

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  f();
  skew();
  ::math::statistic::minimum<float,3>            aa1; aa1.push( {1,2,3}  ); aa1.value( );
  ::math::statistic::maximum<float,3>            aa2; aa2.push( {1,2,3}  ); aa2.value( );
  ::math::statistic::count<int>                  aa3; aa3.push(   );        aa3.value( );
  ::math::statistic::average<float,3,int>        aa4; aa4.push( {1,2,3}  ); aa4.value( );
  ::math::statistic::minimum<float,3>            aa5; aa5.push( {1,2,3}  ); aa5.value( );

  ::math::statistic::minimum<float,1>            aa6; aa6.push( 1  ); aa6.value( );
  ::math::statistic::maximum<float,1>            aa7; aa7.push( 1  ); aa7.value( );
  ::math::statistic::count<int>                  aa8; aa8.push(   );        aa8.value( );
  ::math::statistic::average<float,1,int>        aa9; aa9.push( 1 ); aa9.value( );
  ::math::statistic::minimum<float,1>            aaA; aaA.push( 1 ); aaA.value( );

  ::math::statistic::gauss::vector< double, unsigned, 3 > aaGV; aaGV.push( {1,2,3}  );
  ::math::statistic::gauss::V1< double, unsigned  >     aaG1; aaG1.push( 123  );
  ::math::statistic::gauss::V2< double, unsigned  >     aaG2; aaG2.push( 123  );

   ::math::statistic::interval<double, 3 > aaI; aaI.push( {1,2,3}  );

   ::math::statistic::gauss::vector< double, unsigned, 2 >  g2; g2.push( {1,1} );   g2.mean(  ); g2.deviation(  ); g2.reset();
   ::math::statistic::gauss::vector< double, unsigned, 3 >  g3; g3.push( {1,1,1} ); g3.mean(  ); g3.deviation(  ); g3.reset();

  return EXIT_SUCCESS;
 }
