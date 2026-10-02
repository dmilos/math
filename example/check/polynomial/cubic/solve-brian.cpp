#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;
typedef double scalar_t;

extern double root_quality(std::array<double, 3> const& root, std::array<double, 4> coefficient);


void brian_specific_check( std::array<double, 4> const& coefficient )
 {
  std::cout << "brian: " << std::endl;
  double epsilon = 1e-15;
  std::array<double, 3> root;
  int solutions = ::math::polynomial::cubic::solve::brian( root, coefficient, epsilon );
  auto quality = root_quality( root, coefficient );
  std::cout << "    quality : " << quality <<  std::endl;
  std::cout << "    Root: " << quality << std::endl;
  for( int i=0; i< 3; ++i )
   {
    if( true == std::isnan( root[i] ))continue;
    std::cout << std::setw(22) << std::setprecision( 18 ) << root[i] << "; ";
   }
  std::cout << std::endl;
  std::cout << "--- " << std::endl;
 }

void brian_general()
 {
  double step = 0.05;
  std::array<double, 3> root;
  std::array<double, 4> coefficient;
  std::size_t counter = 0;

  double bestQuality = 0;

  //for( double epsilon = 1e-20; epsilon < 1e-05; epsilon *= pow( 10.0, 0.1 ) )
      double epsilon = 1e-16;
   {
    double maxQuality = 0;

    for (coefficient[3] = -20; coefficient[3] < +20; coefficient[3] += step * (rand() / (double)RAND_MAX))
     {
      for (coefficient[2] = -20; coefficient[2] < +20; coefficient[2] += step * (rand() / (double)RAND_MAX))
       {
        for( coefficient[1] = -20; coefficient[1] < +20; coefficient[1] += step * (rand() / (double)RAND_MAX))
         {
          for( coefficient[0] = -20; coefficient[0] < +20; coefficient[0] += step * (rand() / (double)RAND_MAX))
           {
            ++counter;
            int solutions = ::math::polynomial::cubic::solve::brian( root, coefficient, epsilon );
            auto quality = root_quality( root, coefficient );

            if( maxQuality < quality )
             {
              maxQuality = quality;
             }

            /*if(1 < quality)*/if( bestQuality < quality )
             {
              bestQuality = quality;
              std::cout << "epsilon: " << std::setw(12) << epsilon << " *** ";
              std::cout << "  maxQuality: " << std::setw(18) << maxQuality << ";"; std::cout << std::endl;
              std::cout << "    coefficient[0]= " << std::setw( 18 ) << std::setprecision( 12 ) << coefficient[0] << ";"; std::cout << std::endl;
              std::cout << "    coefficient[1]= " << std::setw( 18 ) << std::setprecision( 12 ) << coefficient[1] << ";"; std::cout << std::endl;
              std::cout << "    coefficient[2]= " << std::setw( 18 ) << std::setprecision( 12 ) << coefficient[2] << ";"; std::cout << std::endl;
              std::cout << "    coefficient[3]= " << std::setw( 18 ) << std::setprecision( 12 ) << coefficient[3] << ";"; std::cout << std::endl;

              std::cout << "    {" ;
              std::cout << std::setw( 20 ) << std::setprecision( 16 ) << coefficient[0] << ",";
              std::cout << std::setw( 20 ) << std::setprecision( 16 ) << coefficient[1] << ",";
              std::cout << std::setw( 20 ) << std::setprecision( 16 ) << coefficient[2] << ",";
              std::cout << std::setw( 20 ) << std::setprecision( 16 ) << coefficient[3] << ",";
              std::cout << "    }"; std::cout << std::endl;

              std::cout << std::endl;
             }
           }
         }
        //std::cout << "QUOTER-FINALE: epsilon: " << std::setw(12) << epsilon << " *** ";
        //std::cout << "  maxQuality: " << std::setw(12) << maxQuality;
        //std::cout << std::endl;
       }
      std::cout << "SEMI-FINALE: epsilon: " << std::setw(12) << epsilon << " *** ";
      std::cout << "  maxQuality: " << std::setw(12) << maxQuality;
      std::cout << std::endl;
     }
    std::cout << "FINALE: epsilon: " << std::setw(12) << epsilon << " *** ";
    std::cout << "  maxQuality: " << std::setw(12) << maxQuality;

    std::cout << std::endl;
   }
 }



int main_brian( int argc, char *argv[] )
 {
  extern void viete_specific_check( std::array<double, 4> const& coefficient );



  brian_general();


  return EXIT_SUCCESS;
 }

