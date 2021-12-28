#ifndef math_geometry_projective_camera_v2f
#define math_geometry_projective_camera_v2f

// ::math::geometry::projective::camera::v2f( vertical_alpha, aspect )

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
         v2f
          (
            scalar_name const& vertical_alpha  //!< vertical angle of view
          )//! Display [ -aspect/2, +aspect/2 ] x [ -1, +1 ] //!< aspect is irrelevant
          {
           return scalar_name(1) / tan( vertical_alpha / scalar_name(2) );
          }

       }
     }
   }
 }

#endif
