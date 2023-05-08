#ifndef math_geometry_projective_camera_focus_focus3D
#define math_geometry_projective_camera_focus_focus3D

// ::math::geometry::projective::camera::focus::focus3D( result, base, depth )





namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {
        namespace focus
         {

          /*** image on display
         (-1,f+1)-----1--------(+1,f++1)-
                |             /|
                |            / |
                |           /  |
            ----+------0-Z-+---+-
               -1      |  /   +1
                       f /
                       |
          */
          template < typename scalar_name >
           scalar_name
           unit2d
            (
             scalar_name const& Z   //!< position on y = focus display
            )
            { //! box =[ ( -1, focus ), ( +1, focus + 1 ) ]
             scalar_name focus = Z / ( scalar_name(1) - Z );
             return focus;
            }

         }
       }
     }
   }
 }

#endif
