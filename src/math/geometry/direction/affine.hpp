#ifndef math_linear_affine_transform
 #define math_linear_affine_transform

 // ::math::linear::affine::transform<scalar_name,dimension_number>


#include "../../linear/affine/transform.hpp"
#include "./two.hpp"
#include "./parametric.hpp"


 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name, ::math::type::size_type dimension_number >
        void transform
         (
           ::math::geometry::direction::two<scalar_name,dimension_number>       & result
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& left
          ,::math::geometry::direction::two<scalar_name,dimension_number>  const& right
         )
         {
          ::math::linear::affine::transform( result.first() ,  left, right.first() );
          ::math::linear::affine::transform( result.second(), left, right.second() );
         }

       template< typename scalar_name, ::math::type::size_type dimension_number >
        void transform
         (
           ::math::geometry::direction::two<scalar_name,dimension_number>       & result
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& left
         )
         {
          ::math::linear::vector::structure<scalar_name,dimension_number> t;
          ::math::linear::affine::transform( t,  left, result.first()  ); result.first()  = t;
          ::math::linear::affine::transform( t, left, result.second() );  result.second() = t;
         }


       template< typename scalar_name, ::math::type::size_type dimension_number >
        void transform
         (
           ::math::geometry::direction::parametric<scalar_name, dimension_number>       & result
          ,::math::linear::affine::structure<scalar_name,dimension_number>         const& affine
          ,::math::geometry::direction::parametric<scalar_name, dimension_number>  const& right
         )
         {
          typedef ::math::linear::vector::structure<scalar_name,dimension_number> point_type;
          point_type vertex;

          ::math::linear::affine::transform( vertex,  affine, right.origin()  ); result.origin() = vertex;

          ::math::linear::vector::addition( vertex, right.origin(), right.direction() );

          ::math::linear::affine::transform( vertex, affine, point_type( vertex ) );

          ::math::linear::vector::subtraction( result.direction(), vertex, result.origin() );
         }

      }
    }
  }

#endif