#include <iostream>
#include <iomanip>
#include <chrono>

#include "math/math.hpp"


template< typename scalar_name, math::type::size_t width_number, math::type::size_t height_number >
 void print ( ::math::linear::matrix::structure<scalar_name,width_number,height_number> const& m )
  {
   for( math::type::size_t j=0; j< width_number; j++ )
    {
     std::cout << std::endl;
     for( math::type::size_t i=0; i< height_number; i++ )
      {
       std::cout << std::setw(10) << std::fixed << m[j][i] << ", ";
      }
    }
  }

void invert5()
 {
  typedef ::math::linear::matrix::structure<double,5,5> matrix5_type;
  matrix5_type m{ 1,0,0,0,1,  0,1,0,0,3, 0,0,1,0,1,  0,2,0,1,0,  0,0,6,0,9   };
  matrix5_type i,i2{ 1.0,   0.0,   2.0,   0.0,  -1/3.0,
                     0.0,   1.0,   6.0,   0.0,  -1.000,
                     0.0,   0.0,   3.0,   0.0,  -1/3.0,
                     0.0,  -2.0, -12.0,   1.0,   2.000,
                     0.0,   0.0,  -2.0,   0.0,   1/3.0, };
  matrix5_type one;

  m={ 1,0,0,0,1,  0,1,0,0,3, 0,0,1,0,1,  0,2,0,1,0,  0,0,6,0,9   };
  ::math::linear::matrix::invert( i, m );  
  ::math::linear::matrix::multiply( one, i, m );  print( one ); std::cout<< std::endl << "-----" <<std::endl;

  m={ (double)(rand()%10),(double)(rand()%10),(double)(rand()%10),(double)(rand()%10),(double)(rand()%10),  0,1,0,0,3, 0,0,1,0,1,  0,2,0,1,0,  (double)(rand()%10),(double)(rand()%10),(double)(rand()%10),(double)(rand()%10),(double)(rand()%10)   };
  ::math::linear::matrix::invert( i, m );  
  ::math::linear::matrix::multiply( one, i, m ); print( one ); std::cout<< std::endl << "-----" <<std::endl;

}

int main( int argc, char*argv[] )
 {
  invert5();

  
  return 0;
 }