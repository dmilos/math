#ifndef Dh_math_linear_affine_compose
 #define Dh_math_linear_affine_compose

 // ::math::linear::affine::compose<scalar_name,dimension_number>

#include "./structure.hpp"
#include "../matrix/multiply.hpp"
#include "../matrix/transform.hpp"
#include "../vector/addition.hpp"

 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name, ::math::type::size_type dimension_number >
        void compose
         (
           ::math::linear::affine::structure<scalar_name,dimension_number>      & result
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& left
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& right
         )
         {
          ::math::linear::matrix::multiply( result.matrix(), left.matrix(), right.matrix() );
          ::math::linear::matrix::transform( result.vector(), left.matrix(), right.vector() );
          ::math::linear::vector::addition( result.vector(), left.vector() );
         }

       template< typename scalar_name, ::math::type::size_type dimension_number >
        void compose
         (
           ::math::linear::affine::structure<scalar_name,dimension_number>      & result
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& a0
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& a1
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& a2
         )
         {
          ::math::linear::affine::structure<scalar_name,dimension_number> t;
          ::math::linear::affine::compose<scalar_name,dimension_number>( t, a1, a2 );
          ::math::linear::affine::compose<scalar_name,dimension_number>( result, a0, t );
         }

      }
    }
  }

#endif