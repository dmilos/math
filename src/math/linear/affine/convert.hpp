#ifndef Dh_math_linear_affine_convert
 #define Dh_math_linear_affine_convert

 // ::math::linear::affine::convert<scalar_name,dimension_number>

#include "./structure.hpp"
#include "../matrix/structure.hpp"
#include "../vector/fill.hpp"



 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name, ::math::type::size_type dimension_number>
        void
        convert
         (
           ::math::linear::affine::structure<scalar_name,dimension_number> & a
          ,::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number> & m 
         )
         {
          a.matrix() = m;
          ::math::linear::vector::fill(  a.vector, scalar_name(0) );
         }

      }
    }
  }

#endif
