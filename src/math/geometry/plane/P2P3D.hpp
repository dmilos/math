#ifndef math_geometry_plane_distance_P2P3d
#define math_geometry_plane_distance_P2P3d

// ::math::geometry::plane::distance( point, no3d );
// ::math::geometry::plane::P2P3d< scalar>::process( point, no3d );


#include "../../linear/vector/vector.hpp"
#include "../direction/parametric.hpp"


namespace math
 {
  namespace geometry
   {
    namespace plane
     {

      template<  typename scalar_name >
       struct P2P3d
        {
         public:
          typedef scalar_name scalar_type;
          typedef ::math::linear::vector::point< scalar_type, 3 > point_type;
          typedef ::math::geometry::plane::no3d<scalar_type> no3d_type;

          static scalar_type process( point_type const& point, no3d_type const& no3d )
           {
            auto ya = ::math::linear::vector::dot( point, no3d.normal() );
            auto d  = ::math::linear::vector::dot( no3d.origin(), no3d.normal() );
            auto al = ::math::linear::vector::length( no3d.normal() );

            return fabs( ya - d ) / al;
           }

        };

      template<  typename scalar_name >
        scalar_name distance
         (
           ::math::linear::vector::point<scalar_name,3>               const & point
          ,::math::geometry::plane::no3d <scalar_name>                const & plane
         )
         {
          return ::math::geometry::plane::P2P3d<scalar_name>::process( point, plane );
         }


     }
   }
 }

#endif
