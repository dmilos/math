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
         //::math::linear::vector::structure< scalar_name, 3 > X; ::math::linear::matrix::column( X, left, 0 );
         //::math::linear::vector::structure< scalar_name, 3 > Y; ::math::linear::matrix::column( Y, left, 1 );
         //::math::linear::vector::structure< scalar_name, 3 > Z; ::math::linear::vector::cross( Z, X, Y );
         //auto value = ::math::linear::vector::length( Z );

         scalar_name X =    left[1][0]*left[2][1] - left[2][0]*left[1][1];
         scalar_name Y = -( left[0][0]*left[2][1] - left[2][0]*left[0][1] );
         scalar_name Z =    left[0][0]*left[1][1] - left[1][0]*left[0][1];

         scalar_name value = sqrt( X*X + Y*Y + Z*Z );
       //scalar_name value = sqrt( left[2][0]*left[2][0] + left[2][1]*left[2][1] + left[2][2]*left[2][2] );
         ::math::linear::matrix::scale( right, scalar_name(1) / value, left );
        }

      template<  typename scalar_name >
       void normalize
        (
          ::math::linear::homography::structure<  scalar_name, 2 >    & H
        )
        {
         //::math::linear::vector::structure< scalar_name, 3 > X; ::math::linear::matrix::column( X, left, 0 );
         //::math::linear::vector::structure< scalar_name, 3 > Y; ::math::linear::matrix::column( Y, left, 1 );
         //::math::linear::vector::structure< scalar_name, 3 > Z; ::math::linear::vector::cross( Z, X, Y );
         //auto value = ::math::linear::vector::length( Z );

         scalar_name X =    H[1][0]*H[2][1] - H[2][0]*H[1][1];
         scalar_name Y = -( H[0][0]*H[2][1] - H[2][0]*H[0][1] );
         scalar_name Z =    H[0][0]*H[1][1] - H[1][0]*H[0][1];

         scalar_name value = sqrt( X*X + Y*Y + Z*Z );
       //scalar_name value = sqrt( H[2][0]*H[2][0] + H[2][1]*H[2][1] + H[2][2]*H[2][2] );
         ::math::linear::matrix::scale( H, scalar_name(1) / value );
        }

     }
   }
 }

#endif