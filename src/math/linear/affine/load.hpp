#ifndef Dh_math_linear_affine_load
#define Dh_math_linear_affine_load

 // ::math::linear::affine::load(a,m,v)

#include "../vector/vector.hpp"
#include "./structure.hpp"


 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name, unsigned dimension_number>
        ::math::linear::affine::structure<scalar_name,dimension_number> &
        load
         (
           ::math::linear::affine::structure<scalar_name,dimension_number>                             & result
          ,::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number>      const & m
          ,::math::linear::vector::structure<scalar_name,dimension_number>                       const & v
         )
         {
          result.matrix() = m;
          result.vector() = v;
          return result;
         }

       template< typename scalar_name, unsigned dimension_number>
        ::math::linear::affine::structure<scalar_name,dimension_number>
        load
         (
           ::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number>      const & m
          ,::math::linear::vector::structure<scalar_name,dimension_number>                       const & v
         )
         {
           ::math::linear::affine::structure<scalar_name,dimension_number> result;
          result.matrix() = m;
          result.vector() = v;
          return result;
         }

      }
    }
  }

#endif
