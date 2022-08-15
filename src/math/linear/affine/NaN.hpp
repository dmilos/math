#ifndef Dh_math_linear_affine_NaN
 #define Dh_math_linear_affine_NaN

 // ::math::linear::affine::NaN<scalar_name,width_number,height_number>

#include <limits>

#include "./structure.hpp"
#include "../matrix/NaN.hpp"
#include "../vector/fill.hpp"

 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name, ::math::type::size_type dimension_number>
        ::math::linear::affine::structure<scalar_name,dimension_number> const&
        NaN( ::math::linear::affine::structure<scalar_name,dimension_number> & a )
         {
          ::math::linear::matrix::NaN( a.matrix() );
          ::math::linear::vector::fill<scalar_name>( a.vector(), std::numeric_limits<scalar_name>::quiet_NaN() );
          return a;
         }


       template< typename scalar_name, ::math::type::size_type dimension_number>
        ::math::linear::affine::structure<scalar_name,dimension_number> const&
        NaN()
         {
          static ::math::linear::affine::structure<scalar_name,dimension_number> N = ::math::linear::affine::NaN( N );
          return N;
         }



      }
    }
  }

#endif
