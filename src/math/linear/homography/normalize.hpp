#ifndef Dh_math_linear_homography_normalize
#define Dh_math_linear_homography_normalize

// math::linear::homography::normalize( H );
#include "./structure.hpp"
#include "../matrix/scale.hpp"




namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template<  typename scalar_name >
       void normalize
        (
          ::math::linear::homography::structure<  scalar_name, 2 >         & right
         ,::math::linear::homography::structure<  scalar_name, 2 >    const& left
        )
        {
         scalar_name value = sqrt( left[2][0]*left[2][0] + left[2][1]*left[2][1] + left[2][2]*left[2][2] );
         ::math::linear::matrix::scale( right, scalar_name(1) / value, left );
        }

      template<  typename scalar_name >
       void normalize
        (
          ::math::linear::homography::structure<  scalar_name, 2 >    & H
        )
        {
         scalar_name value = sqrt( H[2][0]*H[2][0] + H[2][1]*H[2][1] + H[2][2]*H[2][2] );
         ::math::linear::matrix::scale( H, scalar_name(1) / value );
        }

     }
   }
 }

#endif