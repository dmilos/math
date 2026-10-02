#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

#include "math/math.hpp"

#ifdef __clang__
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wmissing-braces"
    #pragma clang diagnostic ignored "-Wunused-local-typedef"
    #pragma clang diagnostic ignored "-Wunused-variable"
    #pragma clang diagnostic ignored "-Wself-assign-overloaded"
#endif


using namespace std;
typedef double scalar_t;

void cubic( std::array<double,4> const& coefficients )
{
  std::cout << "------------" << __FUNCTION__ << endl;
  std::cout << "C: { " << coefficients[0] << ", " << coefficients[1] << ", " << coefficients[2] << ", " << coefficients[3] << "}; " <<  std::endl;
  std::array<double,3>   root;

  std::cout << "# Solutions: " << ::math::polynomial::cubic::solve::general<double>(  root, coefficients ) << std::endl;

  std::cout << "Check 1: P( " << root[0] << ") = " << ::math::polynomial::evaluate( root[0], coefficients ) << std::endl;
  std::cout << "Check 2: P( " << root[1] << ") = " << ::math::polynomial::evaluate( root[1], coefficients ) << std::endl;
  std::cout << "Check 3: P( " << root[2] << ") = " << ::math::polynomial::evaluate( root[2], coefficients ) << std::endl;

  std::array<double,4> d;
  std::cout << "Shift: " <<::math::polynomial::cubic::depressing( d, coefficients ) << std::endl;

  std::cout << "Depressed:" << d[0] << ", " << d[1] << ", " << d[2] << ", " << d[3] << "; " <<  std::endl;
}
double confront_root( std::array<double, 3> const& the_root, std::array<double, 3> const& root )
 {
  double result = 0;
  for( int i = 0; i < the_root.size(); ++i )
   {
    if( true == std::isnan( the_root[i] ) )continue;
    double current = 1000.0;
    for( int j = 0; j < root.size(); ++j )
     {
      if( true == std::isnan( root[j] ) )continue;
      auto delta = fabs( the_root[i] - root[j] );
      current = std::min( delta, current );
     }
    result = std::max( current, result );
   }
  return result;
 }

double root_quality( std::array<double, 3> const& root, std::array<double, 4> coefficient )
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

void competition_general()
 {
  std::cout << "RUN: competition" << std::endl;

  std::size_t counter = 0;
  std::array<double, 3> the_root;
  std::array<double, 3> root_brian, root_cardano, root_viete;
  std::array<double, 4> coefficient;
  std::array<double, 4> quality;

  std::array<std::size_t, 120> distributionIdeal{ 0 };
  std::array<std::size_t, 120> distributionBrian{ 0 };
  std::array<std::size_t, 120> distributionCardano{ 0 };
  std::array<std::size_t, 120> distributionViete{ 0 };

  double bounde_left  = -2;
  double bounde_right = +2;
  double step = (bounde_right - bounde_left ) / 100.0;

  for( double epsilon = 1e-22; epsilon < 1e-07; epsilon *= pow( 10.0, 0.2 ) )
  //double epsilon = 1e-12;
   {
   std::array<std::size_t, 4> winner{ 0,0,0,0 };

    for( the_root[0] = bounde_left; the_root[0] < bounde_right; the_root[0] += step * (rand() / (double)RAND_MAX ) )
     {
      for( the_root[1] = bounde_left; the_root[1] < bounde_right; the_root[1] += step * (rand() / (double)RAND_MAX))
       {
        for( the_root[2] = bounde_left; the_root[2] < bounde_right; the_root[2] += step * (rand() / (double)RAND_MAX) )
         {
          ++counter;

          ::math::polynomial::cubic::construct( coefficient, the_root );

          int solutionsBrian   = ::math::polynomial::cubic::solve::brian(   root_brian,   coefficient, epsilon );
          int solutionsCardano = ::math::polynomial::cubic::solve::cardano( root_cardano, coefficient, epsilon );
          int solutionsViete   = ::math::polynomial::cubic::solve::viete(   root_viete,   coefficient, epsilon );

          quality[0] = root_quality( the_root,     coefficient );
          quality[1] = root_quality( root_brian,   coefficient );
          quality[2] = root_quality( root_cardano, coefficient );
          quality[3] = root_quality( root_viete,   coefficient );

          { auto index = -log2( quality[0] ); if( ( 0 < index ) && ( index < distributionIdeal.size()   ) )   ++distributionIdeal[ index ]; }
          { auto index = -log2( quality[1] ); if( ( 0 < index ) && ( index < distributionBrian.size()   ) )   ++distributionBrian[ index ]; }
          { auto index = -log2( quality[2] ); if( ( 0 < index ) && ( index < distributionCardano.size() ) ) ++distributionCardano[ index ]; }
          { auto index = -log2( quality[3] ); if( ( 0 < index ) && ( index < distributionViete.size()   ) )   ++distributionViete[ index ]; }

          ++winner[ std::min_element( quality.begin(), quality.end() ) - quality.begin() ];

          if( 0.1 < quality[3] )
           {
            quality[3] = quality[3];
           }

         }
       }
     }

    for( int index=0; index < distributionIdeal.size(); ++index )
     {
     
      std::cout << std::setw( 3 ) << index << ". ";
      std::cout         << std::setw(16) << distributionIdeal[index];
      std::cout << "\t" << std::setw(16) << distributionBrian[index];
      std::cout << "\t" << std::setw(16) << distributionCardano[index];
      std::cout << "\t" << std::setw(16) << distributionViete[index];
      std::cout << std::endl;
     }

    auto theWinner = *std::max_element( winner.begin(), winner.end() );

    std::cout << "epsilon: " << std::setw( 12) << epsilon << " *** ";
    std::cout << "  ideal:   " << std::setw( 12 ) << (int)winner[0] - (int)theWinner<< "; ";
    std::cout << "  brian:   " << std::setw( 12 ) << (int)winner[1] - (int)theWinner<< "; ";
    std::cout << "  cardano: " << std::setw( 12 ) << (int)winner[2] - (int)theWinner<< "; ";
    std::cout << "  viete:   " << std::setw( 12 ) << (int)winner[3] - (int)theWinner<< "; ";

    std::cout << std::endl;
   }
 }

int main(int argc, char* argv[])
 {
   // { -0.71702993539099269,  2.4033265470762406,  - 2.6851405377361379,  1.0000000000000000 };
   // { 1.0000000000000000,  60.000000000000000,  1200.0000000000000,  8000.0000000000000 };
   // { 1.0000000000000000,   6.000000000000000,   12.0000000000000,   8.0000000000000 };
   // { 1.0000000000000000,   5.000000000000000,   8.0000000000000,   4.0000000000000 };
   // {-4.0805981627857317,   -0.080598162785731731,   2.9798504593035671,   1.0000000000000000 };

  competition_general();

  extern int main_brian( int argc, char* argv[] ); 
  extern int main_cardano( int argc, char* argv[] ); 
  extern int main_viete(   int argc, char* argv[] ); 

  //main_brian(argc, argv);
  //main_cardano(argc, argv);
  //main_viete(argc, argv);

  return EXIT_SUCCESS;
 }
