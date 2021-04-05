#ifndef Dh_math_linear_affine_id
 #define Dh_math_linear_affine_id

 // ::math::linear::affine::id<scalar_name,dimension_number>

#include "./one.hpp"

 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name, unsigned dimension_number>
        ::math::linear::affine::structure<scalar_name,dimension_number> &
        id( ::math::linear::affine::structure<scalar_name,dimension_number> & a )
         {
          return ::math::linear::affine::one<scalar_name,dimension_number>( a );
         }

       template< typename scalar_name, unsigned dimension_number>
        ::math::linear::affine::structure<scalar_name,dimension_number> const&
        id()
         {
          return ::math::linear::affine::one<scalar_name,dimension_number>();
         }

       template< typename scalar_name, unsigned dimension_number>
        ::math::linear::affine::structure<scalar_name,dimension_number> const&
        id( ::math::linear::affine::structure<scalar_name,dimension_number> const& dummy )
         {
          return ::math::linear::affine::one<scalar_name,dimension_number>( dummy );
         }

      }
    }
  }

#endif
