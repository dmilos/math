#ifndef Dh_math_linear_affine_lookAt
 #define Dh_math_linear_affine_lookAt

 // ::math::linear::affine::look_at<scalar_name>( result, eye, view, up )

#include "../vector/vector.hpp"
#include "./structure.hpp"

 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name>
        void look_at
         (
           ::math::linear::affine::structure<scalar_name,3>         & result
          ,::math::linear::vector::structure<scalar_name,3>    const& eye
          ,::math::linear::vector::structure<scalar_name,3>    const& view
          ,::math::linear::vector::structure<scalar_name,3>    const& up
         )
         {
          ::math::linear::vector::structure<scalar_name,3>              direction;
          ::math::linear::vector::subtraction( direction, view, eye );
          ::math::linear::vector::length( direction, scalar_name(1) ) ;

          ::math::linear::vector::structure<scalar_name,3>              right;
          ::math::linear::vector::cross( right, direction, up );
          ::math::linear::vector::length( right, scalar_name(1) ) ;

          ::math::linear::vector::structure<scalar_name,3>              upU;
          ::math::linear::vector::cross( upU, right, direction );
          ::math::linear::vector::length( upU, scalar_name(1) ) ;

          ::math::linear::matrix::column( result.matrix(), 0, right );
          ::math::linear::matrix::column( result.matrix(), 1, direction );
          ::math::linear::matrix::column( result.matrix(), 2, upU );

          result.vector() = eye;
         }

      }
    }
  }

#endif