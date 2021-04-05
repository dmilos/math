#ifndef math_geometry_projective_camera_va2d
#define math_geometry_projective_camera_va2d

// ::math::geometry::projective::camera::va2d( h_alpha, aspect )

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
         va2d
          (
            scalar_name const& v_alpha //!< vertical angle of view
           ,scalar_name const& aspect  //!< Aspect ration width::height .e.g. 16:9
          )
          {
           scalar_name v_scale = scalar_name(2) * tan( v_alpha / scalar_name(2) );
           scalar_name h_scale = v_scale * aspect;

           scalar_name diagonal = sqrt( h_scale* h_scale + v_scale * v_scale );

           return scalar_name(2) * atan( diagonal / scalar_name(2) );
          }

       }
     }
   }
 }

#endif
