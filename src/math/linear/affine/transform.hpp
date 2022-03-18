#ifndef Dh_math_linear_affine_transform
 #define Dh_math_linear_affine_transform

 // ::math::linear::affine::transform<scalar_name,dimension_number>

#include "../vector/structure.hpp"
#include "../matrix/transform.hpp"
#include "./structure.hpp"

 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name, unsigned dimension_number >
        ::math::linear::vector::structure<scalar_name,dimension_number>       &
        transform
         (
           ::math::linear::vector::structure<scalar_name,dimension_number>       & result
          ,::math::linear::affine::structure<scalar_name,dimension_number>  const& left
          ,::math::linear::vector::structure<scalar_name,dimension_number>  const& point
         )
         {
          ::math::linear::matrix::transform( result, left.matrix(), point );
          ::math::linear::vector::addition( result, left.vector() );
          return result;
         }

       template< typename scalar_name, unsigned dimension_number >
        ::math::linear::vector::structure<scalar_name,dimension_number>       &
        transform
         (
           ::math::linear::vector::structure<scalar_name,dimension_number>      & result
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& left
         )
         {
          return ::math::linear::affine::transform<scalar_name,dimension_number>( result, left, ::math::linear::vector::structure<scalar_name,dimension_number>( result ) );
         }
      }
    }
  }

#endif