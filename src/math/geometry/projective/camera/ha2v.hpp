#ifndef math_geometry_projective_camera_ha2v
#define math_geometry_projective_camera_ha2v

// ::math::geometry::projective::camera::ha2v( h_alpha, aspect )




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
         ha2v
          (
            scalar_name const& horizontal_alpha  //!< horizontal angle of view
           ,scalar_name const& aspect            //!< Aspect ration width::height .e.g. 16:9
          )
          {
           scalar_name horizontal_scale = scalar_name(2) * tan( horizontal_alpha / scalar_name(2) );
           scalar_name vertical_scale = horizontal_scale / aspect;

           return scalar_name(2) * atan( vertical_scale / scalar_name(2) );
          }

       }
     }
   }
 }

#endif
