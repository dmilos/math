#ifndef math_geometry_projective_camera_d2hv
#define math_geometry_projective_camera_d2hv

// ::math::geometry::projective::camera::d2hv( alpha, horizontal_scale, v_scale )





namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {

        template < typename scalar_name >
         std::pair<scalar_name,scalar_name>
         d2hv
          (
            scalar_name const& diagonal_alpha    //!< diagonal angle of view
           ,scalar_name const& horizontal_scale  //!< 16
           ,scalar_name const& vertical_scale    //!<  9
          )
          { //! See also http://therandomlab.blogspot.com/2013/03/logitech-c920-and-c910-fields-of-view.html
           scalar_name diagonal = sqrt( horizontal_scale* horizontal_scale + vertical_scale * vertical_scale );
           scalar_name focus = (diagonal/scalar_name(2)) / tan( diagonal_alpha / scalar_name(2) ) ;

           scalar_name horizontal_alpha = scalar_name(2) * atan( (horizontal_scale/scalar_name(2) ) / focus );
           scalar_name vertical_alpha   = scalar_name(2) * atan( (  vertical_scale/scalar_name(2) ) / focus );

           return std::make_pair( horizontal_alpha, vertical_alpha );
          }

       }
     }
   }
 }

#endif
