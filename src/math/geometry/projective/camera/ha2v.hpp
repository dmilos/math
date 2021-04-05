#ifndef math_geometry_projective_camera_ha2v
#define math_geometry_projective_camera_ha2v

// ::math::geometry::projective::camera::ha2v( h_alpha, aspect )

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
         ha2v
          (
            scalar_name const& h_alpha  //!< horizontal angle of view
           ,scalar_name const& aspect   //!< Aspect ration width::height .e.g. 16:9
          )
          {
           scalar_name h_scale = scalar_name(2) * tan( h_alpha / scalar_name(2) );
           scalar_name v_scale = h_scale / aspect;

           return scalar_name(2) * atan( v_scale / scalar_name(2) );
          }

       }
     }
   }
 }

#endif
