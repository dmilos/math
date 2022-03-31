#ifndef Dh_math_linear_homography_invert
#define Dh_math_linear_homography_invert

 // ::math::linear::homography::invert<scalar_name,dimension_number>( result, H )

#include "./structure.hpp"
#include "../matrix/multiply.hpp"








namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template< typename scalar_name >
       void invert // exists always
        (
          ::math::linear::homography::structure<scalar_name,2>      & result
         ,::math::linear::homography::structure<scalar_name,2> const& H
        )
        {
         ::math::linear::vector::structure<scalar_name,3> X;   ::math::linear::matrix::column( X, H, 0 );
         ::math::linear::vector::structure<scalar_name,3> Y;   ::math::linear::matrix::column( Y, H, 1 );
         ::math::linear::vector::structure<scalar_name,3> O;   ::math::linear::matrix::column( O, H, 2 );

         ::math::linear::vector::cross( result[0], Y, O );
         ::math::linear::vector::cross( result[1], O, X );
         ::math::linear::vector::cross( result[2], X, Y );
        }

     }
   }
 }

#endif
