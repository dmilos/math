#ifndef Dh_math_linear_affine_scale
 #define Dh_math_linear_affine_scale

 // ::math::linear::affine::scale<scalar_name,width_number>

#include "../vector/scale.hpp"
#include "../matrix/scale.hpp"
#include "./structure.hpp"


 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name, unsigned dimension_number >
        void scale
         (
           ::math::linear::affine::structure<scalar_name,dimension_number> & result
          ,scalar_name const& scalar
         )
         {
          ::math::linear::matrix::scale< scalar_name >( result.matrix(), scalar );
          ::math::linear::vector::scale< scalar_name >( result.vector(), scalar );
         }

       template< typename scalar_name, unsigned dimension_number >
        void scale
         (
           ::math::linear::affine::structure<scalar_name,dimension_number>      & result
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& left
          ,scalar_name const& right
         )
         {
          ::math::linear::matrix::scale< scalar_name >(      result.matrix(), left.matrix(), right );
          ::math::linear::vector::scale< scalar_name >( result.vector(), left.vector(), right );
         }

       template< typename scalar_name, unsigned dimension_number >
        void scale
         (
           ::math::linear::affine::structure<scalar_name,dimension_number>      & result
          ,scalar_name const& left
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& right
         )
         {
          ::math::linear::matrix::scale< scalar_name >(      result.matrix(), left, right.matrix() );
          ::math::linear::vector::scale< scalar_name >( result.vector(), left, right.vector() );
         }

      }
    }
  }

#endif
