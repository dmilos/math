#ifndef math_geometry_projective_camera_intrinsic_focus
#define math_geometry_projective_camera_intrinsic_focus

// ::math::geometry::projective::camera::intrinsic::focus( result, base, depth )

//#include <utility>

#include "../../../../linear/homography/structure.hpp"

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {
        namespace intrinsic
         {

          template < typename scalar_name >
           scalar_name
           focus
            (
              ::math::linear::homography::structure< scalar_name, 1 > & result
             ,scalar_name const& focus
            )
            {
             result[0][0] = focus; result[0][1] = 0;
             result[1][0] = 0;     result[1][1] = 1;

             return focus;
            }

          template < typename scalar_name >
           scalar_name
           focus
            (
              ::math::linear::homography::structure< scalar_name, 2 > & result
             ,scalar_name const& focus
            )
            {
             result[0][0] = focus; result[0][1] = 0;     result[0][2] = 0;
             result[1][0] = 0;     result[1][1] = focus; result[1][2] = 0;
             result[2][0] = 0;     result[2][1] = 0;     result[2][2] = 1;

             return focus;
            }

          template < typename scalar_name >
           ::math::linear::vector::structure< scalar_name, 2 >
           focus
            (
              ::math::linear::homography::structure< scalar_name, 2 >     & result
              ::math::linear::vector::structure< scalar_name, 2 >    const& focus
            )
            {
             result[0][0] = focus[0]; result[0][1] = 0;        result[0][2] = 0;
             result[1][0] = 0;        result[1][1] = focus[1]; result[1][2] = 0;
             result[2][0] = 0;        result[2][1] = 0;        result[2][2] = 1;

             return focus;
            }

         }
       }
     }
   }
 }

#endif
