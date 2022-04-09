#ifndef math_geometry_projective_camera_f2h
#define math_geometry_projective_camera_f2h

// ::math::geometry::projective::camera::f2h( focus )





namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {

        template < typename scalar_name >
         scalar_name
         f2h
          (
            scalar_name const& focus    //!< focus
          )//! Display1D [ -1, +1 ] //!< 1D display viewed under horizontal angle
          { //!< convert focus to angle
           return scalar_name(2) * atan( scalar_name(1) / focus );
          }

       }
     }
   }
 }

#endif
