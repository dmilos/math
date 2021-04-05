#ifndef Dh_math_linear_affine_addition
 #define Dh_math_linear_affine_addition

 // ::math::linear::affine::addition<scalar_name,dimension_number>

#include "./structure.hpp"
#include "../matrix/addition.hpp"
#include "../vector/addition.hpp"


 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name, unsigned dimension_number >
        void addition
         (
           ::math::linear::affine::structure<scalar_name,dimension_number>      & result
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& left
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& right
         )
         {
          ::math::linear::matrix::addition( result.matrix(), left.matrix(), right.matrix() );
          ::math::linear::vector::addition( result.vector(), left.vector(), right.vector() );
         }

       template< typename scalar_name, unsigned dimension_number >
        void addition
         (
           ::math::linear::affine::structure<scalar_name,dimension_number>      & result
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& right
         )
         {
          ::math::linear::matrix::addition( result.matrix(), right.matrix() );
          ::math::linear::vector::addition( result.vector(), right.vector() );
         }

      }
    }
  }

#endif