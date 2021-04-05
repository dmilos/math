#ifndef Dh_math_linear_affine_invert
 #define Dh_math_linear_affine_invert

 // ::math::linear::affine::invert<scalar_name,dimension_number>

#include "./structure.hpp"
#include "../matrix/invert.hpp"
#include "../matrix/transform.hpp"
#include "../vector/negate.hpp"

 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name, unsigned dimension_number >
        bool invert
         (
           ::math::linear::affine::structure<scalar_name,dimension_number>      & result
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& right
          ,scalar_name const& epsilon  = 1e-6
         )
         {
          if( false == ::math::linear::matrix::invert( result.matrix(), right.matrix(), epsilon ) )
           {
            return false;
           }
          ::math::linear::matrix::transform( result.vector(), result.matrix(), right.vector() );
          ::math::linear::vector::negate( result.vector() );
          return true;
         }

       template< typename scalar_name, unsigned dimension_number >
        bool invert
         (
           ::math::linear::affine::structure<scalar_name,dimension_number>      & a
          ,scalar_name const& epsilon  = 1e-6
         )
         {
          ::math::linear::affine::structure<scalar_name,dimension_number> tmp = a;
          return ::math::linear::affine::invert( a, tmp );
         }

      }
    }
  }

#endif
