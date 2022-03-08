#ifndef Dh_math_linear_homography_compose
#define Dh_math_linear_homography_compose

 // ::math::linear::homography::compose<scalar_name,width_number,height_number>

#include "./structure.hpp"
#include "../matrix/multiply.hpp"








namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template< typename scalar_name, unsigned dimension_number >
       void compose
        (
          ::math::linear::homography::structure<scalar_name,dimension_number>      & result
         ,::math::linear::homography::structure<scalar_name,dimension_number> const& left
         ,::math::linear::homography::structure<scalar_name,dimension_number> const& right
        )
        {
         return ::math::linear::matrix::multiply( result, left, right );
        }

     }
   }
 }

#endif
