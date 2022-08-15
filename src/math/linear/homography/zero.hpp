#ifndef Dh_math_linear_homography_zero
#define Dh_math_linear_homography_zero

 // ::math::linear::homography::zero<scalar_name,dimension_number>

#include "./structure.hpp"
#include "../matrix/zero.hpp"








namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template< typename scalar_name, ::math::type::size_type dimension_number >
       void zero( ::math::linear::homography::structure<scalar_name,dimension_number> & H )
        {
         //::math::linear::matrix::zero( H );
         H[dimension_number][dimension_number] = scalar_name( 1 );
        }

     }
   }
 }

#endif
