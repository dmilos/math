#ifndef math_geometry_plane_project_P2P3d
#define math_geometry_plane_project_P2P3d

// ::math::geometry::plane::project( point, no3d );
// ::math::geometry::plane::P2P3D_project< scalar>::process( point, no3d );


#include "../../linear/vector/vector.hpp"
#include "../direction/parametric.hpp"


namespace math
 {
  namespace geometry
   {
    namespace plane
     {

      template<  typename scalar_name >
       struct P2P3D_project
        {
         public:
          typedef scalar_name scalar_type;
          typedef ::math::linear::vector::point< scalar_type, 3 > point_type;
          typedef ::math::geometry::plane::no3d<scalar_type> no3d_type;

          static scalar_type process( point_type & projection, point_type const& point, no3d_type const& no3d )
           {
            point_type contra_heading;
            ::math::linear::vector::subtraction( contra_heading, no3d.origin(), point );

            auto length2 = ::math::linear::vector::dot( no3d.normal(), no3d.normal() );
            auto lambda = ::math::linear::vector::dot( contra_heading, no3d.normal() );
            lambda /= length2;

            ::math::linear::vector::combine( projection, 1, point, lambda, no3d.normal() );
           }

        };

      template<  typename scalar_name >
        scalar_name project
         (
           ::math::linear::vector::point<scalar_name,3>                     & projection
          ,::math::linear::vector::point<scalar_name,3>               const & point
          ,::math::geometry::plane::no3d <scalar_name>                const & plane
         )
         {
          return ::math::geometry::plane::P2P3D_project<scalar_name>::process( point, plane );
         }


     }
   }
 }

#endif
