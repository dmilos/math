#ifndef math_geometry_projective_camera_ha2f
#define math_geometry_projective_camera_ha2f

// ::math::geometry::projective::camera::ha2f( h_alpha, aspect )





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
         ha2f
          (
            scalar_name const& horiszontal_alpha  //!< horizontal angle of view
           ,scalar_name const& aspect             //!< Aspect ration width::height .e.g. 16:9
          )//! Display [ -aspect/2, +aspect/2 ] x [ -1, +1 ]
          {
           return aspect / tan( ( horiszontal_alpha / scalar_name(2) ) );
          }

       }
     }
   }
 }

#endif
