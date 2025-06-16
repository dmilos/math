#ifndef Dh_math_linear_affine_system
#define Dh_math_linear_affine_system

// ::math::linear::affine::system<scalar_name,width_number,height_number>( result, O, X, Y, Z, T )

// Extract base vectors from affine transformation

#include "./structure.hpp"
#include "../vector/structure.hpp"

#include "../matrix/structure.hpp"
#include "../matrix/system.hpp"


 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name >
        void system
         (
           ::math::linear::affine::structure<scalar_name, 1>                & result
          ,::math::linear::vector::structure<scalar_name, 1>           const& vector
          ,::math::linear::vector::structure<scalar_name, 1>           const& x
         )
         {
          ::math::linear::matrix::system( result.matrix(), x );
          result.vector() = vector;
         }

       template< typename scalar_name >
        void system
         (
           ::math::linear::affine::structure<scalar_name, 2>                & result
          ,::math::linear::vector::structure<scalar_name, 2>           const& vector
          ,::math::linear::vector::structure<scalar_name, 2>           const& x
          ,::math::linear::vector::structure<scalar_name, 2>           const& y
         )
         {
          ::math::linear::matrix::system( result.matrix(), x, y );
          result.vector() = vector;
         }

       template< typename scalar_name >
        void system
         (
           ::math::linear::affine::structure<scalar_name, 3>                 & result
          ,::math::linear::vector::structure<scalar_name, 3>            const& vector
          ,::math::linear::vector::structure<scalar_name, 3>            const& x
          ,::math::linear::vector::structure<scalar_name, 3>            const& y
          ,::math::linear::vector::structure<scalar_name, 3>            const& z
         )
         {
          ::math::linear::matrix::system( result.matrix(), x, y, z );
          result.vector() = vector;
         }

       template< typename scalar_name >
        void system
         (
           ::math::linear::affine::structure<scalar_name, 4>                 & result
          ,::math::linear::vector::structure<scalar_name, 4>            const& vector
          ,::math::linear::vector::structure<scalar_name, 4>            const& x
          ,::math::linear::vector::structure<scalar_name, 4>            const& y
          ,::math::linear::vector::structure<scalar_name, 4>            const& z
          ,::math::linear::vector::structure<scalar_name, 4>            const& t
         )
         {
          ::math::linear::matrix::system( result.matrix(), x, y, z, t );
          result.vector() = vector;
         }

       template< typename scalar_name, ::math::type::size_type dimension_number >
        void system
         (
           ::math::linear::affine::structure<scalar_name, dimension_number>                     & result
          ,::math::linear::vector::structure<scalar_name, dimension_number>                const& vector
          ,std::array< ::math::linear::vector::structure<scalar_name, dimension_number>, dimension_number >  const& base
         )
         {
          ::math::linear::matrix::system( result.matrix(), base );
          result.vector() = vector;
         }

      }
    }
  }

#endif
