#ifndef math_geometry_projective_camera_ha2d
#define math_geometry_projective_camera_ha2d

// ::math::geometry::projective::camera::ha2d( h_alpha, aspect )





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
         ha2d
          (
            scalar_name const& h_alpha //!< horizontal angle of view
           ,scalar_name const& aspect  //!< Aspect ration width : height .e.g. 16:9
          )
          {
           scalar_name h_scale = scalar_name(2) * tan( h_alpha / scalar_name(2) );
           scalar_name v_scale = h_scale / aspect;

           scalar_name diagonal = sqrt( h_scale * h_scale  +  v_scale * v_scale );

           return scalar_name(2) * atan( diagonal / scalar_name(2) );
          }

       }
     }
   }
 }

#endif
