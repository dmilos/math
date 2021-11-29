#ifndef math_geometry_projective_camera_va2h
#define math_geometry_projective_camera_va2h

// ::math::geometry::projective::camera::va2h( v_alpha, aspect )

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
         va2h
          (
            scalar_name const& vertical_alpha //!< vertical angle of view
           ,scalar_name const& aspect  //!< Aspect ration width::height .e.g. 16:9
          )
          {
           scalar_name vertical_scale   = scalar_name(2) * tan( vertical_alpha / scalar_name(2) );
           scalar_name horizontal_scale = vertical_scale * aspect;

           return scalar_name(2) * atan( horizontal_scale / scalar_name(2) );
          }

       }
     }
   }
 }

#endif
