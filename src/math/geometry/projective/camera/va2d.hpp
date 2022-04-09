#ifndef math_geometry_projective_camera_va2d
#define math_geometry_projective_camera_va2d

// ::math::geometry::projective::camera::va2d( h_alpha, aspect )





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
         va2d
          (
            scalar_name const& vertical_alpha  //!< vertical angle of view
           ,scalar_name const& aspect          //!< Aspect ration width::height .e.g. 16:9
          )
          {
           scalar_name vertical_scale   = scalar_name(2) * tan( vertical_alpha / scalar_name(2) );
           scalar_name horizontal_scale = vertical_scale * aspect;

           scalar_name diagonal = sqrt( horizontal_scale* horizontal_scale + vertical_scale * vertical_scale );

           return scalar_name(2) * atan( diagonal / scalar_name(2) );
          }

       }
     }
   }
 }

#endif
