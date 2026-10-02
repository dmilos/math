#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;
typedef double scalar_t;

bool confront(std::array<double, 3> const& the_root, std::array<double, 3> const& root, double const& epsilon )
 {
  return false;
 }

double single_cardano( double const& q, double const& p, double epsilon )
 {
  std::array< double, 4 > depresed;

  depresed[0] = q;
  depresed[1] = p;
  depresed[2] = 0;
  depresed[3] = 1;

  std::array<double, 3> root;
  int solution = ::math::polynomial::cubic::solve::cardano<double>( root.data(), q, p, epsilon );
  double dMaxD = 0;
  for( int i=0; i< solution; ++i )
   {
    auto value = ::math::polynomial::cubic::evaluate( root[i], depresed );
    dMaxD = std::max( fabs( value ), dMaxD);
   }

  return dMaxD;
 }

void test()
 {
  double start = -100;
  double end = +100;
  double step = 1;
  std::array<scalar_t, 4> coefficient;
  std::array<scalar_t, 4> depresed;


  for( double epsilon = 1e-20; epsilon < 1.0; epsilon *= pow(10.0, 0.1) )
   {
    double maxDelta = 0;
    coefficient[3] = 1;

    for( coefficient[0] = start; coefficient[0] < end; coefficient[0] += step * (rand() / (double)RAND_MAX) )
     for( coefficient[1] = start; coefficient[1] < end; coefficient[1] += step * (rand() / (double)RAND_MAX) )
      for( coefficient[2] = start; coefficient[2] < end; coefficient[2] += step * (rand() / (double)RAND_MAX) )
       {
        double shift = ::math::polynomial::cubic::depressing( depresed.data(), coefficient.data(), epsilon );
        ::math::polynomial::cubic::shift( depresed, -shift, depresed );

        for (int i = 0; i < coefficient.size(); ++i)
         {
          auto delta = fabs( coefficient[i] - depresed[i] );
          maxDelta = std::max(maxDelta, delta);
          if( 0.000001 < maxDelta )
           {
            maxDelta = maxDelta;
           }
         }
       }
      std::cout << "epsilon: "  << std::setw(20) << std::setprecision(12) << epsilon << "; ";
      std::cout << "maxDelta: " << std::setw(20) << std::setprecision(12) << maxDelta << "; ";
      std::cout  << std::endl;
   }
 }

void best_epsilon()
 {
  double step = 0.0001;

  double best_epsilon;
  double best_error = 100;

  for( double epsilon = 1e-12; epsilon < 1e-08; epsilon *= 10 )
   {
    double current_error = 0;
    for( double p = -2; p < +2; p += step )
     {
      for( double q = -2; q < +2; q += step )
       {
        auto error = single_cardano( q, p, epsilon );
        if( current_error < error )
         {
          current_error = error;
         }
       }
     }
    std::cout << epsilon << "; " << current_error << std::endl;
  }

 }

bool single( std::array<double, 3> const& the_root )
 {
  double epsilon = 1e-7;
  std::array<double, 3> root;
  std::array<double, 4> coefficient;

  ::math::polynomial::cubic::construct( coefficient, the_root );
  double dMaxC = 0;

  for( int i=0; i< the_root.size(); ++i )
   {
    auto value = ::math::polynomial::cubic::evaluate( the_root[i], coefficient );
    dMaxC = std::max( fabs(value), dMaxC );
    if( epsilon < fabs( value ) )
     {
      return false;
     }
   }

  std::array<double,4> depresed;
  double shift = ::math::polynomial::cubic::depressing<double>( depresed.data(), coefficient.data(), epsilon);

  std::array<double, 4> check; ::math::polynomial::cubic::shift<double>( check, shift, depresed );

  int solution = ::math::polynomial::cubic::solve::cardano<double>( root.data(), depresed[0], depresed[1], epsilon );
  double dMaxD = 0;
  for( int i=0; i< solution; ++i )
   {
    auto value = ::math::polynomial::cubic::evaluate( root[i], depresed );
    dMaxD = std::max( fabs( value ), dMaxD);
    root[i] -= shift;
   }

  double dMaxR = 0;
  for( int i=0; i< solution; ++i )
   {
    auto value = ::math::polynomial::cubic::evaluate( root[i], coefficient);
    dMaxR = std::max( fabs( value ), dMaxR );
   }

  std::array<double, 3> rootC;
  int solutionsC = ::math::polynomial::cubic::solve::general( rootC, coefficient, epsilon );

  return true;
 }


int main( int argc, char *argv[] )
 {
    test(); return 0;
   // best_epsilon(); return 0;
   //
   //if(false){
   // std::array<double, 3> the_root;
   // the_root[0] = 1.5838211814796750;
   // the_root[1] = -0.79191059073983749;
   // the_root[2] = -1.98;
   //
   // single( the_root );
   //}
   //
   //{
   // single_depressed( -0.0020000000001092529, -0.016000000000109260, 0.001 );
   //}

  //return 0;

  double step = 0.001;
  std::array<double, 4> coefficient;
  std::array<double, 3> root;
  double dMax = 0;
  double epsilon = 1e-10;

  int counter = 0;
  for( double p = -2; p < +2; p += step )
   for( double q = -2; q < +2; q += step )
    {
     ++counter;
     coefficient[0] = q;
     coefficient[1] = p;
     coefficient[2] = 0;
     coefficient[3] = 1;
     
     int solutions = ::math::polynomial::cubic::solve::cardano( root.data(), coefficient[0], coefficient[1], epsilon );
     
     switch( solutions )
      {
       case( 0 ): /*std::cout << "x" << std::endl;*/ continue;
       //case( 1 ): /*std::cout << "x" << std::endl;*/ continue;
      }
     
     for( int i = 0; i < solutions; ++i )
      {
       bool fit = false;
     
       auto value = ::math::polynomial::cubic::evaluate( root[i], coefficient );
     
       auto delta = fabs( value );
     
       dMax = std::max( delta, dMax );
     
       if( epsilon < delta )
        {
         std::cout << "*: " << dMax << std::endl;
         std::cout << "    C:"; for (int i = 0; i < coefficient.size(); ++i) std::cout << setw(8) << coefficient[i] << "; "; std::cout << std::endl;
         std::cout << "    R:"; for (int i = 0; i <     root.size(); ++i) std::cout << setw(8) <<     root[i] << "; "; std::cout << std::endl;
        }
      }

   }

  std::cout << "dMax: " << dMax << std::endl;
  return EXIT_SUCCESS;
 }
