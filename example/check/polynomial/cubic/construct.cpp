#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

typedef double scalar_t;

double root_quality( std::array<double, 3> const& root, std::array<double, 4> coefficient)
 {
  double result = 0;
  for( int i=0; i< root.size(); ++i )
   {
    if( true == std::isnan( root[i] ) )continue;
    auto value = ::math::polynomial::cubic::evaluate( root[i], coefficient );
    result  = std::max( result, fabs(value) );
   }
  return result;
 }

double single_test( std::array<double, 3> const& the_root )
 {
  std::array<double, 4> coefficient;
  ::math::polynomial::cubic::construct( coefficient, the_root );
  auto testRealRoot = root_quality( the_root, coefficient );
  std::array<double, 3> root;
  int solutions = ::math::polynomial::cubic::solve::general( root, coefficient, 1e-9 );
  auto testDetectedRoot = root_quality( root, coefficient );

  return std::max<double>( testRealRoot, testDetectedRoot );
 }

int counter( std::array<double, 3> const& root )
 {
  return 0;
 }

double confront_root( std::array<double, 3> const& the_root, std::array<double, 3> const& root )
 {
  double result = 0;
  for( int i = 0; i < the_root.size(); ++i )
   {
    if( true == std::isnan( the_root[i] ) )continue;
    double current = 1000.0;
    for (int j = 0; j < root.size(); ++j)
     {
      if( true == std::isnan( root[j] ) )continue;
      auto delta = fabs( the_root[i] - root[j] );
      current = std::min( delta, current );
     }
    result = std::max( current, result );
   }
  return result;
 }

void test()
 {
  double step = 0.005;

  std::array<double, 3> the_root;
  std::array<double, 4> coefficient;

  double theError    = 0;

  for( the_root[0] = -2; the_root[0] < +2; the_root[0] += step * (rand() / (double)RAND_MAX ) )
   for( the_root[1] = -2; the_root[1] < +2; the_root[1] += step * (rand() / (double)RAND_MAX) )
    for( the_root[2] = -2; the_root[2] < +2; the_root[2] += step * (rand() / (double)RAND_MAX) )
     {
      ::math::polynomial::cubic::construct( coefficient, the_root );
      theError = std::max( theError, root_quality( the_root, coefficient ) );
     }

  std::cout << "  theError: " << theError << std::endl;
 }

int main( int argc, char *argv[] )
 {
  //test();

  double step = 0.025;

  std::size_t counter = 0;
  std::array<double, 3> the_root;
  std::array<double, 3> root;
  std::array<double, 4> coefficient;

  for( double epsilon = 1e-14; epsilon < 1e-13; epsilon *= pow( 10.0, 0.01 ) )
   {
    double realError   = 0;
    double epilogError = 0;

    for( the_root[0] = -2; the_root[0] < +2; the_root[0] += step * (rand() / (double)RAND_MAX ) )
     for( the_root[1] = -2; the_root[1] < +2; the_root[1] += step * (rand() / (double)RAND_MAX))
      for( the_root[2] = -2; the_root[2] < +2; the_root[2] += step * (rand() / (double)RAND_MAX) )
     {
      the_root[0] = -2.0000000000000000;
      the_root[1] = -1.9899754325998718;
      the_root[2] = -1.9878315073091830;

      ++counter;

      ::math::polynomial::cubic::construct( coefficient, the_root );

      //root[0] = root[1] = root[2] = NAN;
      int solutions = ::math::polynomial::cubic::solve::general( root, coefficient, epsilon );
     
       {
        auto currentError = root_quality( root, coefficient );
        realError = std::max( realError, currentError );
        if( 1 < currentError )
         {
          realError = realError;
         }
       }

      switch( solutions )
       {
        //case( 0 ): std::cout << "x" << std::endl; continue;
        //case( 1 ): std::cout << "x" << std::endl; continue;
        //case( 2 ): std::cout << "x" << std::endl; continue;
       }

      auto epilog = confront_root( the_root, root );
      if( epilogError < epilog )
       {
        epilogError = epilog;
        std::cout << "E*: " << std::setw(12) << std::setprecision(8) << epilogError << "; ";
        std::cout << "R*: " << std::setw(12) << std::setprecision(8) << realError << std::endl;
        std::cout << "    C:"; for (int i = 0; i < coefficient.size(); ++i) std::cout << std::setw(12) << coefficient[i] << "; "; std::cout << std::endl;
        std::cout << "   dR:"; for (int i = 0; i <    the_root.size(); ++i) std::cout << std::setw(16) << std::setprecision(12) <<the_root[i] << "; "; std::cout << std::endl;
        std::cout << "    R:"; for (int i = 0; i <        root.size(); ++i) std::cout << std::setw(16) << std::setprecision(12) <<    root[i] << "; "; std::cout << std::endl;
       }
     }

    std::cout << "epsilon: " << std::setw(12) << epsilon << " *** ";
    std::cout << "  realError: " << std::setw(12) << realError ;
    std::cout << "  epilogError: " << std::setw(12) << epilogError;
    std::cout << std::endl;
   }
  return EXIT_SUCCESS;
 }

//epsilon:  5.62341e-15 ***   epilogError:   0.00694793
//epsilon:  3.98107e-15 * **realError : 2.50582e-07  epilogError : 0.00686247
//epsilon:  4.57088e-15 * **realError : 2.69081e-07  epilogError : 0.00655593
//epsilon:        1e-14 * **realError : 3.96869e-07  epilogError : 0.0079989