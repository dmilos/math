#ifndef math_geometry_projective_camera_frustum_out
#define math_geometry_projective_camera_frustum_out

// ::math::geometry::projective::camera::frustum::out( point, window, depth )

#include "../pinhole.hpp"
#include "../../../interval/out.hpp"






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

          // TODO out_struct::m_fly

          template < typename scalar_name >
           bool out
            (
              ::math::linear::vector::point< scalar_name, 3 >         const& point
             ,::math::geometry::interval::structure<scalar_name, 2>   const& window
             ,::math::geometry::interval::structure<scalar_name, 1 >  const& depth
            )
            {
             typedef ::math::geometry::projective::camera::pinhole< scalar_name > pinhole_type;

             if( point[ pinhole_type::forward() ] < depth[0] ) return true;
             if( depth[1] < point[ pinhole_type::forward() ] ) return true;
             auto fly = pinhole_type::project( point );
             return ::math::geometry::interval::out( window, fly );
            }

         }
       }
     }
   }
 }

#endif
