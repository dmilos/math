#ifndef math_geometry_plane_affine
 #define math_geometry_plane_affine

 // ::math::linear::affine::transform<scalar_name>


#include "../../linear/affine/transform.hpp"
#include "./no3d.hpp"
#include "./parametric3d.hpp"


 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name >
        void transform
         (
           ::math::geometry::plane::no3d<scalar_name>            & result
          ,::math::linear::affine::structure<scalar_name,3> const& affine
          ,::math::geometry::plane::no3d<scalar_name>       const& right
         )
         {
          ::math::linear::affine::transform( result.origin(),  affine, right.origin() );

          ::math::linear::vector::structure<scalar_name,3> vertex;

          ::math::linear::vector::addition( vertex, right.origin(), right.normal() );
          ::math::linear::affine::transform( vertex, affine );
          ::math::linear::vector::subtraction( result.normal(), vertex, result.origin() );
         }

       template< typename scalar_name >
        void transform
         (
           ::math::geometry::plane::parametric3d<scalar_name>        & result
          ,::math::linear::affine::structure<scalar_name,3>     const& affine
          ,::math::geometry::plane::parametric3d<scalar_name>   const& right
         )
         {
          ::math::linear::affine::transform( result.origin(), affine, right.origin() );

          ::math::linear::vector::structure<scalar_name,3> vertex;

          ::math::linear::vector::addition( vertex, right.origin(), right.x() );
          ::math::linear::affine::transform( vertex, affine );
          ::math::linear::vector::subtraction( result.x(), vertex, result.origin() );

          ::math::linear::vector::addition( vertex, right.origin(), right.y() );
          ::math::linear::affine::transform( vertex, affine );
          ::math::linear::vector::subtraction( result.y(), vertex, result.origin() );
         }

      }
    }
  }

#endif