#ifndef math_geometry_projective_camera_intrinsic_angle
#define math_geometry_projective_camera_intrinsic_angle

// ::math::geometry::projective::camera::intrinsic::angle( result, angle )

#include "./k.hpp"



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
           void
           angle
            (
              ::math::linear::vector::structure< scalar_name, 2 >     & result  //
             ,scalar_name                                             & angle  //!< horizontal angle matrix
            )
            {
             auto focus = ::math::geometry::projective::camera::a2f( angle );
             ::math::geometry::projective::camera::intrinsic::K<double>()( result, focus );
            }

         }
       }
     }
   }
 }

#endif
