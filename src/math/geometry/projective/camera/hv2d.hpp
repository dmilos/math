#ifndef math_geometry_projective_camera_hv2d
#define math_geometry_projective_camera_hv2d

// ::math::geometry::projective::camera::hv2d( h_alpha, v_alpha )





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
         hv2d
          (
            scalar_name const& h_alpha //!< horizontal angle of view
           ,scalar_name const& v_alpha //!< vertical   angle of view
          )
          {
           scalar_name h_scale = scalar_name(2) * tan( h_alpha / scalar_name(2) );
           scalar_name v_scale = scalar_name(2) * tan( v_alpha / scalar_name(2) );

           scalar_name diagonal = sqrt( h_scale* h_scale  +  v_scale * v_scale );

           return scalar_name(2) * atan( diagonal / scalar_name(2) );
          }

       }
     }
   }
 }

#endif
