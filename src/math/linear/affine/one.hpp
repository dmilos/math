#ifndef Dh_math_linear_affine_one
 #define Dh_math_linear_affine_one

 // ::math::linear::affine::one<scalar_name,dimension_number>

#include "./structure.hpp"
#include "../matrix/one.hpp"
#include "../vector/fill.hpp"



 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name, unsigned dimension_number>
        ::math::linear::affine::structure<scalar_name,dimension_number> &
        one( ::math::linear::affine::structure<scalar_name,dimension_number> & a )
         {
          ::math::linear::matrix::one( a.matrix() );
          ::math::linear::vector::fill<scalar_name>( a.vector(), 0 );
          return a;
         }

       template< typename scalar_name, unsigned dimension_number>
        ::math::linear::affine::structure<scalar_name,dimension_number> const&
        one()
         {
          static ::math::linear::affine::structure<scalar_name,dimension_number> identical = ::math::linear::affine::one( identical );
          return identical;
         }

       template< typename scalar_name, unsigned dimension_number>
        ::math::linear::affine::structure<scalar_name,dimension_number> const &
        one( ::math::linear::affine::structure<scalar_name,dimension_number> const& dummy )
         {
          return ::math::linear::affine::one<scalar_name, dimension_number>( );
         }

      }
    }
  }

#endif
