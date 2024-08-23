#ifndef math_geometry_projective_camera_a2w
#define math_geometry_projective_camera_a2w

// ::math::geometry::projective::camera::a2w( angle )





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
         a2w
          (
            scalar_name const& angle  //!< angle of view
          ) //!< angle of view of interval [1,1]x[ -window, +window ]
          {  //!< convert angle to window
           return tan( angle / scalar_name(2) );
          }

       }
     }
   }
 }

#endif
