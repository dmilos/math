#ifndef math_geometry_projective_camera_h2f
#define math_geometry_projective_camera_h2f

// ::math::geometry::projective::camera::h2f( horisontal_alpha )





namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {

        /*
        |      /     |
        |    /       |
        |  /         | +(window)/2
        |/ angle/2   |
        +------------+------>
        | \     focus|
        |   \        | -(window)/2
        |     \      |
        |       \    |
        */
        template < typename scalar_name >
         scalar_name
         a2f //!< former h2f
          (
            scalar_name const& angle  //!< horizontal angle of view
          )//! Display1D [focus,focus]x[ -1, +1 ] //!< 1D display viewed under horizontal angle
          {  //!< convert angle to focus
           return scalar_name(1) / tan( angle / scalar_name(2) );
          }
          
        template < typename scalar_name >
         scalar_name
         a2f //!< former h2f
          (
            scalar_name const& angle  //!< horizontal angle of view
           ,scalar_name const& window  //!< horizontal angle of view
          )//! Display1D [focus,focus]x[ -window/2, +window/2 ] //!< 1D display viewed under horizontal angle
          {  //!< convert angle&window to focus
           return scalar_name(0.5) * scalar_name(window) / tan( angle / scalar_name(2) );
          }

       }
     }
   }
 }

#endif
