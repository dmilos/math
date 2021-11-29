#ifndef math_geometry_projective_camera_focus_focus3D
#define math_geometry_projective_camera_focus_focus3D

// ::math::geometry::projective::camera::focus::focus3D( result, base, depth )

//#include <utility>



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

          /************** image on display
   (-1,+1,f)+---------2---------+(+1,+1,f)
            |\ near   |        /|
            | \       |       / |
            |  +---------Z---+  |
            |  |      |      |  |
            |  |far   |      |  |
            |  |------0------|  |
            |  |      |      |  |
            |  |far   |      |  |
            |  +---------Z---+  |
            | /       |       \ |
            |/ near   |        \|
  (-1,-1,f) +-------------------+ (+1,-1,f)
          **************/

           template < typename scalar_name >
           scalar_name
           unit3d
            (
             scalar_name const& Z 
            )
            { //! box =[ ( -1, -1, focus ), ( +1, +1, focus + 1 ) ]
             scalar_name focus = Z / ( scalar_name(1) - Z );
             return focus;
            }

         }
       }
     }
   }
 }

#endif
