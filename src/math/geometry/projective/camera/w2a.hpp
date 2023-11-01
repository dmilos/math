#ifndef math_geometry_projective_camera_w2a
#define math_geometry_projective_camera_w2a

// ::math::geometry::projective::camera::w2a( window )





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
         w2a
          (
            scalar_name const& window  //!< window of view
          )
          {  //!< convert window to angle
           return scalar_name(2) * atan( window );
          }

       }
     }
   }
 }

#endif
