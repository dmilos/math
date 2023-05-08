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
            scalar_name const& horizontal_alpha //!< horizontal angle of view
           ,scalar_name const& vertical_alpha   //!< vertical   angle of view
          )
          {
           scalar_name h_scale = scalar_name(2) * tan( horizontal_alpha / scalar_name(2) );
           scalar_name v_scale = scalar_name(2) * tan( vertical_alpha   / scalar_name(2) );

           scalar_name diagonal = sqrt( h_scale* h_scale  +  v_scale * v_scale );

           return scalar_name(2) * atan( diagonal / scalar_name(2) );
          }

        template < typename scalar_name >
         scalar_name
         hv2d
          (
            std::array<scalar_name,2 > const& angles
          )
          {
           return ::math::geometry::projective::camera::hv2d( angles[0], angles[1] );
          }

       }
     }
   }
 }

#endif
