#ifndef math_geometry_projective_camera_frustum_side
#define math_geometry_projective_camera_frustum_side

// ::math::geometry::projective::camera::frustum::side( point, depth )

#include "../pinhole.hpp"
#include "../../../interval/structure.hpp"
#include "../../../../linear/vector/structure.hpp"







namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {
        namespace frustum
         {
          template < typename scalar_name >
           int side
            (
              ::math::linear::vector::point< scalar_name, 3 >         const& point
             ,::math::geometry::interval::structure<scalar_name, 1 >  const& depth
             ,scalar_name                                             const& zero = scalar_name(0)
            )
            {
             typedef ::math::geometry::projective::camera::pinhole< scalar_name > pinhole_type;

             if( point[pinhole_type::forward() ] < zero ) return 0;

             if( point[pinhole_type::forward() ] < depth[0] ) return 1;
             if( point[pinhole_type::forward() ] < depth[1] ) return 2;

             return 3;
            }

         }
       }
     }
   }
 }

#endif
