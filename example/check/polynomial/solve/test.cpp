#include <iostream>
#include <iomanip>
#include <string>
#include <array>

#include "math/math.hpp"


using namespace std;



void quartic( std::array<double,5> const& coefficients )
{
  std::cout << "------------" << __FUNCTION__ << endl;
  std::cout << "C: { " << coefficients[0] << ", " << coefficients[1] << ", " << coefficients[2] << ", " << coefficients[3] << ", "<< coefficients[4] << " }; " <<  std::endl;
  std::array<double,4>   r4;

  std::array<double,5> monic;
  double scale;
  std::cout << "Scale: " << ( scale = ::math::polynomial::monicing( monic.data(), coefficients.data(), monic.size() ) ) << " - ";
  //::math::polynomial::optimize( monic );
  std::cout << "Monic: " << monic[0] << ", " << monic[1] << ", " << monic[2] << ", " << monic[3] << ", "<< monic[4] << "; " <<  std::endl;

  std::array<double,5> depressed;
  double shift;
  std::cout << "Shift: " << ( shift = ::math::polynomial::quartic::depressing( depressed.data(), monic.data() ) ) << " - ";
  //::math::polynomial::optimize( depressed );
  std::cout << "Depressed: " << depressed[0] << ", " << depressed[1] << ", " << depressed[2] << ", " << depressed[3] << ", "<< depressed[4] << "; " <<  std::endl;

  std::cout << "# Ferrari: " << ::math::polynomial::quartic::solve::ferrari<double>( r4.data(), depressed.data() ) << std::endl;
  std::cout << "Check 1: P( " << r4[0]+shift << ") = " << ::math::polynomial::evaluate( r4[0]+shift, coefficients ) << std::endl;
  std::cout << "Check 2: P( " << r4[1]+shift << ") = " << ::math::polynomial::evaluate( r4[1]+shift, coefficients ) << std::endl;
  std::cout << "Check 3: P( " << r4[2]+shift << ") = " << ::math::polynomial::evaluate( r4[2]+shift, coefficients ) << std::endl;
  std::cout << "Check 4: P( " << r4[3]+shift << ") = " << ::math::polynomial::evaluate( r4[3]+shift, coefficients ) << std::endl;

  std::cout << "# shmakov: " << ::math::polynomial::quartic::solve::shmakov<double>( r4.data(), depressed.data() ) << " - "<< std::endl;
  std::cout << "Check 1: P(" <<  r4[0]+shift << ") = " << ::math::polynomial::evaluate( r4[0]+shift, coefficients ) << std::endl;
  std::cout << "Check 2: P(" <<  r4[1]+shift << ") = " << ::math::polynomial::evaluate( r4[1]+shift, coefficients ) << std::endl;
  std::cout << "Check 3: P(" <<  r4[2]+shift << ") = " << ::math::polynomial::evaluate( r4[2]+shift, coefficients ) << std::endl;
  std::cout << "Check 4: P(" <<  r4[3]+shift << ") = " << ::math::polynomial::evaluate( r4[3]+shift, coefficients ) << std::endl;

  std::cout << "# descartes: " << ::math::polynomial::quartic::solve::descartes<double>( r4.data(), depressed.data(), 1e-8 ) << " - "<< std::endl;
  std::cout << "Check 1: P(" <<  r4[0]+shift << ") = " << ::math::polynomial::evaluate( r4[0]+shift, coefficients ) << std::endl;
  std::cout << "Check 2: P(" <<  r4[1]+shift << ") = " << ::math::polynomial::evaluate( r4[1]+shift, coefficients ) << std::endl;
  std::cout << "Check 3: P(" <<  r4[2]+shift << ") = " << ::math::polynomial::evaluate( r4[2]+shift, coefficients ) << std::endl;
  std::cout << "Check 4: P(" <<  r4[3]+shift << ") = " << ::math::polynomial::evaluate( r4[3]+shift, coefficients ) << std::endl;
}

static double errorF = 0;
static double errorD = 0;
//static double errorS = 0;

void quartic2( std::array<double,5> const& coefficients )
{
  std::array<double,4>   rF4,rD4;

  std::array<double,5> depressed;
  double shift = ::math::polynomial::quartic::depressing( depressed.data(), coefficients.data() );
  std::array<double,5> monic;
  double scale = ::math::polynomial::monicing( monic.data(), depressed.data(), monic.size() );
  ::math::polynomial::optimize( monic );

  auto countF = ::math::polynomial::quartic::solve::ferrari<double>( rF4.data(), monic.data() );
  auto eF = errorF; 
  switch( countF )
   {
    case( 4 ): eF = std::max( eF, fabs( ::math::polynomial::evaluate( rF4[3]+shift, coefficients ) ) );
    case( 3 ): eF = std::max( eF, fabs( ::math::polynomial::evaluate( rF4[2]+shift, coefficients ) ) );
    case( 2 ): eF = std::max( eF, fabs( ::math::polynomial::evaluate( rF4[1]+shift, coefficients ) ) );
    case( 1 ): eF = std::max( eF, fabs( ::math::polynomial::evaluate( rF4[0]+shift, coefficients ) ) );
    case( 0 ): ;
   }
  if( errorF < eF )
   {
    errorF = eF;
    std::cout << "ferrari E: " << errorF << "; C: " << coefficients[0] << ", " << coefficients[1] << ", " << coefficients[2] << ", " << coefficients[3] << ", "<< coefficients[4] << "; " <<  std::endl;
   }

  //auto countS = ::math::polynomial::quartic::solve::shmakov<double>( rS4.data(), monic.data() );
  //switch( countS )
  // {
  //  case( 4 ): errorS = std::max( errorS, fabs( ::math::polynomial::evaluate( rS4[3], monic ) ) );
  //  case( 3 ): errorS = std::max( errorS, fabs( ::math::polynomial::evaluate( rS4[2], monic ) ) );
  //  case( 2 ): errorS = std::max( errorS, fabs( ::math::polynomial::evaluate( rS4[1], monic ) ) );
  //  case( 1 ): errorS = std::max( errorS, fabs( ::math::polynomial::evaluate( rS4[0], monic ) ) );
  //  case( 0 ): ;
  // }
  //if( 0.1 < errorS )
  // {
  //  errorS = errorS;
  // }

  auto countD = ::math::polynomial::quartic::solve::descartes<double>( rD4.data(), monic.data(), 1e-8 );
  auto eD = errorD; 
  switch( countD )
   {
    case( 4 ): eD = std::max( eD, fabs( ::math::polynomial::evaluate( rD4[3]+shift, coefficients ) ) );
    case( 3 ): eD = std::max( eD, fabs( ::math::polynomial::evaluate( rD4[2]+shift, coefficients ) ) );
    case( 2 ): eD = std::max( eD, fabs( ::math::polynomial::evaluate( rD4[1]+shift, coefficients ) ) );
    case( 1 ): eD = std::max( eD, fabs( ::math::polynomial::evaluate( rD4[0]+shift, coefficients ) ) );
    case( 0 ): ;
   }
  if( errorD < eD )
   {
    errorD = eD;
    std::cout<< "descartes E: " << errorD << "; C: " << coefficients[0] << ", " << coefficients[1] << ", " << coefficients[2] << ", " << coefficients[3] << ", "<< coefficients[4] << "; " <<  std::endl;
   }

 //if( countF != countS )
 // {
 //  countF = countF; 
 // }

 if( countF != countD )
  {
   countD = countD;
  }
 //if( countS != countD )
 // {
 //  countD = countD; 
 // }
}


int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  errorF = 0;
  errorD = 0;
  // errorS = 0;
  quartic( { -117.1875, 125,-37.5,0.00000000000000000,1.0000000000000000 } );

  quartic( { -0.999, -0.001, -0.993, 0, 1 } );
  quartic( { -1, 0, -1, 0, 1 } );
  quartic( { -0.988, -0.001, 0.994, 0, 1 } );
  quartic( {  0, -0.001, -0.019, 0, 1 } );

  std::size_t counter = 0;
  std::array<double,5> coeffcient;
  coeffcient[4] = 1;
  coeffcient[3] = 0;

  for( coeffcient[0] = -1; coeffcient[0] < +1; coeffcient[0] += 0.001 )
   for( coeffcient[1] = -1; coeffcient[1] < +1; coeffcient[1] += 0.001 )
    for( coeffcient[2] = -1; coeffcient[2] < +1; coeffcient[2] += 0.001 )
     //for( coeffcient[3] = -1; coeffcient[3] < +1; coeffcient[3] += 0.04 )
     // for( coeffcient[4] = -1; coeffcient[4] < +1; coeffcient[4] += 0.04 )
       {
        if( fabs( coeffcient[4] ) < 0.001 ) 
         {
          continue;
         }
         quartic2( coeffcient );
       }

  std::cout << "ferrari: " << errorF << std::endl;
  std::cout << "descartes: " << errorD << std::endl;



  quartic( {-1, -0.05, -0.8, 0.1, 0.8});
  quartic( { 0.9, 3.19189e-16, 3.19189e-16, -0.05, -1});

  quartic( { 0.13184331895789603, -1.0798101783837666e-05, -0.33551814137939084, 0,1 } );
  quartic( { 0.71597682739321855, 6.7936244862454309e-06, -1.8718255810654663, 0, 1 } );
  quartic( { -0.14904909202608607, 5.9777239123093295e-05, 0.20869256442874118, 0, 1 } );
  quartic( { 22.118401942608603, -45.312002784954387, 32.480001234708830, -9.6000001714873360, 1 } );
  quartic( { 22.118401942608617, -40.561962142994950, 27.902657841788098, -8.5936356725752745, 1 } );
  quartic( { 22.118399999999994, -40.561960010761254, 27.902657099041214, -8.5936355955002668, 1 } );
  quartic( { 22.1184, -40.561960010761254, 27.902657099041214,-8.5936355955002668, 1 } );

  quartic( { -1, -1, 0.05, 0.1, -0.01 } );

  quartic({ 1,0,-2,0,1});
  quartic({24,-50,35,-10,1});

  quartic({-1/5.0,-2/5.0,-3/5.0,4/5.0,5/5.0});
  quartic({ -0.15767074955840688, 6.2751997042642671e-05, -0.095080148369023565, 0,1 } );
  quartic({ -0.15767074955840688,                      0, -0.095080148369023565, 0,1 } );

  quartic({ 4*sqrt(30)-28, 2*sqrt(30)-16, 12 ,8, 1}); //! Probem for smakov
  quartic({ 1,0,2,0,1});

  quartic({ 2, -3, 3, -3, 1 });
  quartic({ 1,0,0,0,1});
  quartic({0,0,0,0,1});
  quartic({4,0,-5,0,1});
  quartic( {-1.0,-1.0,-1.0,-1.0, 0.32 } );
  quartic( { -1.0, -1.0, -0.05, 0.1,-0.01 } );


//std::array<float,10>   r;
  std::array<float,1>   r1;
  std::array<float,4>   r4;

//std::array<float,10>   c;
  std::array<float,2>   c2{1,2};
  std::array<float,3>   c3{1,2,3};
  std::array<float,5>   c5{1,2,3,4,5}, c5b;

  // TODO math_polynomial_solve_quadric


  ::math::polynomial::solve::linear<float>( r1, c2 );
  ::math::polynomial::solve::linear<float>( r1.data(), c2.data() );


  ::math::polynomial::quartic::solve::bi<float>(        r4.data(), c5.data() );
  ::math::polynomial::quartic::depressing<float>( c5b.data(), c5.data() );
  ::math::polynomial::quartic::solve::general<float>(      r4.data(), c5.data() );

  std::cin.get();
  return EXIT_SUCCESS;
 }

