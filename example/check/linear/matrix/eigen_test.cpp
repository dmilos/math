#include <iostream>
#include <iomanip>
#include <chrono>

#include "math/math.hpp"



template< typename scalar_name, unsigned width_number, unsigned height_number >
 void print ( ::math::linear::matrix::structure<scalar_name,width_number,height_number> const& m )
  {
   for( unsigned j=0; j< width_number; j++ )
    {
     std::cout << std::endl;
     for( unsigned i=0; i< height_number; i++ )
      {
       std::cout << std::setw(10) << std::fixed << m[j][i] << ", ";
      }
    }
  }

template ::math::linear::matrix::eigen::algoritham<double,2>;
template ::math::linear::matrix::eigen::algoritham<double,3>;

typedef ::math::linear::matrix::eigen::algoritham<double,2> eu2_type;
typedef ::math::linear::matrix::eigen::algoritham<double,3> eu3_type;

void eu2_test()
 {
  eu2_type::matrix_type m;
  eu2_type  aa;

  // -0.3722813232690143:     (-0.8245648401323937, 0.5657674649689923)
  //5.372281323269014:        (0.41597355791928425, 0.9093767091321241)
  m={1,2,3,4}; aa.process( m );


 //-1.4494897427831778: (-0.6324555320336759, 0.7745966692414833)
 //3.449489742783178:   (0.6324555320336759, 0.7745966692414833)
  m={1,2,3,1}; aa.process( m );

 //0:    (-1, 1)
 //2:    (1, 1)

  m={1,1,1,1}; aa.process( m );

  m={2,2,2,3}; aa.process( m );

  m={3,2,4,5}; aa.process( m );

  // -15: (-0.554700196225229, 0.8320502943378437)
  // 0:   ( 0.7071067811865475, 0.7071067811865475)

  m={-6, 6, 9,  -9}; aa.process( m );

  // 1: (0.7071067811865475, 0.7071067811865475)
  m={ -7,  8,  -8,   9 }; aa.process( m );
 }

void eu3_test()
 {
  eu3_type::matrix_type m;
  eu3_type  aa;

  m={ 1, 0, 0,  0, 1, 0, 0, 0, 1 }; aa.process( m );
  m={ 1, 0, 0,  0, 1, 0, 0, 0, -1 }; aa.process( m );

  //m={ 1, 2, 3, 3, 4, 5, 6, 7, 8 }; aa.process( m );
// m={ 1, 2, 3, 4, 5, 6, 7, 8, 9 }; aa.process( m );
// m={ 3, 2, 6, 2, 2, 5, -2, -1, -4 }; aa.process( m );

  //// one real solution
  // m={  4,   2,   7,  -6,  -6,   8,   0,  -8,  -6 }; aa.process( m );

   // one real solution
   //m={  -8,   3,  -1, -6,  -7,  -4, 2,  -6,  -1 }; aa.process( m );

   //// two real solution
   //m={  8,   1,  -2, 2,   7,  -6, -1,  -2,  -5 }; aa.process( m );
   //// tree real solution, all integers
   m={6,   0,  -6,   2,  -2,  -1,   4,   5,   -8 }; aa.process( m );

 }

int main( int argc, char*argv[] )
 {
     eu2_test();
     eu3_test();

  
  return 0;
 }