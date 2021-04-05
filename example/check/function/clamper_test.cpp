#include <iostream>
#include <iomanip>

#include "math/math.hpp"


void graf( float P_len)
 {
  for(int i=0; i< P_len; i++ )
   std::cout<< " ";
  std::cout<< "*"<< std::endl;

 }

int main( int argc, char *argv[] )
 {
  std::cout << "main_clamper" << std::endl;

  double I_dval;
  for( I_dval=-3;  I_dval< 0.5; I_dval += 0.01)
   {
    std::cout << "ramp( " << I_dval << " ) = " << ::math::function::ramp( I_dval ) << std::endl;
    std::cout << "saw( " << I_dval << " ) = " <<  ::math::function::saw<double>( I_dval, 0.3, 0.8 )  << std::endl;
    std::cout << "wave( " << I_dval << " ) = " << ::math::function::wave<double>( I_dval, 0.3, 0.8 ) << std::endl;
    std::cout << "to_one<double>( " << I_dval << ", -5, 5 ) = " << ::math::function::to_one<double>( I_dval, -5, 5 ) << std::endl;
    std::cout << "sinkhole( " << I_dval << ", -5, 5 ) = " << ::math::function::sinkhole<double>( I_dval, -5, 5 ) << std::endl;
    std::cout << "relu( " << I_dval << ", -5, 5 ) = " << ::math::function::relu<double>( I_dval ) << std::endl;
    std::cout << "stairs( " << I_dval << ", -5, 5 ) = " << ::math::function::stairs<double>( I_dval ) << std::endl;
   }


  float I_fval;
  for( I_fval = float(-5);  I_fval< float(5); I_fval += float( 0.1 ))
   {
    std::cout << "ramp( " << I_fval << " ) = " << ::math::function::ramp( I_fval ) << std::endl;
    std::cout << "saw( " << I_fval << " ) = " << ::math::function::saw( I_fval )  <<std:: endl;
    std::cout << "wave( " << I_fval << " ) = " << ::math::function::wave( I_fval ) << std::endl;
    std::cout << "to_one<float>( " << I_fval << ", -5, 5 ) = " << ::math::function::to_one<float>( I_fval, -5, 5 ) << std::endl;
    std::cout << "sinkhole<float>( " << I_fval << ", -5, 5 ) = " << ::math::function::sinkhole<float>( I_fval, -5, 5 ) << std::endl;
    std::cout << "relu<float>( " << I_fval << ", -5, 5 ) = " << ::math::function::relu<float>( I_fval ) << std::endl;
   }

   ::math::function::to_one<float>( 5, 1, 10 ); 
   ::math::function::to_any<float>( 0.5, 1, 10 ); 
   ::math::function::any_to_any<float>( 0.5, 1, 10, 2 , 6 ); 

  //

  return 0;
 }

