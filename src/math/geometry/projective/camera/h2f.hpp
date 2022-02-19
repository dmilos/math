#ifndef math_geometry_projective_camera_h2f
#define math_geometry_projective_camera_h2f

// ::math::geometry::projective::camera::h2f( horisontal_alpha )

//#include <utility>



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
         h2f
          (
            scalar_name const& horisontal_alpha  //!< horizontal angle of view
          )//! Display1D [ -1, +1 ] //!< 1D display viewed under horizontal angle
          {  //!< convert angle to focus
           return scalar_name(1) / tan( horisontal_alpha / scalar_name(2) );
          }

       }
     }
   }
 }

#endif
