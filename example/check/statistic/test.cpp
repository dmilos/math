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

  ::math::statistic::histogram< >     hist; hist.push( 123  );

  ::math::statistic::histogram<>   hC;
  hC.resize( 20 );
  hC.size();
  hC.push( 1.25 );
  hC.push( 350 );
  hC.push( - 50 );

  ::math::statistic::histogram<::math::statistic::average<math::type::scalar_t>>   hA;

  hA.resize(20);
  hA.size();
  hA.push(1.25);
  hA.push(350);
  hA.push(-50);

  ::math::statistic::histogramNd< >   hX_1;
  hX_1.resize( { 20 } );
  hX_1.size();
  hX_1.push({ 1.25} ); hX_1.push({ 5.25} );
  hX_1.push({ 350 } );
  hX_1.push({ -50 } );

  ::math::statistic::histogramNd< 2 >   hX_2;
  hX_2.resize( { 5, 5 } );
  hX_2.size();
  hX_2.push({   1.25,    1.25 } ); hX_2.push({   2.25,    2.25 } );
  hX_2.push({ 350   ,  350    } );
  hX_2.push({ -50   ,  -50    } );

  ::math::statistic::histogramNd<2,::math::statistic::average<math::type::scalar_t,2> >   h1A;
  h1A.resize( {20,20} );
  h1A.size();
  h1A.push({   1.25,    1.25 } ); h1A.push({   2.25,    2.25 } );
  h1A.push({ 350 ,  350 } );
  h1A.push({ -50 ,  -50 } );

  ::math::statistic::histogramNd<5,::math::statistic::average<math::type::scalar_t, 5> >   h2A;
  h2A.resize( {20,20,20,20,20} );
  h2A.size();
  h2A.push({ 1.25, 1.25,  1.25,  1.25,  1.25} );
  h2A.push({ 350 , 350 ,  350 ,  350 ,  350 } );
  h2A.push({ -50 , -50 ,  -50 ,  -50 ,  -50 } );
  return EXIT_SUCCESS;
 }
