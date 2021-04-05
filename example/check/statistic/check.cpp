#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

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
