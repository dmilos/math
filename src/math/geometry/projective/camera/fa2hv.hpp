#ifndef math_geometry_projective_camera_fa2hv
#define math_geometry_projective_camera_fa2hv

// ::math::geometry::projective::camera::fa2hv( focus, aspect )

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
         std::pair<scalar_name,scalar_name>
         fa2hv
          (
            scalar_name const& focus    //!< focus
           ,scalar_name const& aspect   //!< 16:9 = 1.7777777777777777777777777777778
          )//! Display [ -aspect/2, +aspect/2 ] x [ -1, +1 ]
          {
           scalar_name vertical_alpha   = scalar_name(2) * acos( focus / sqrt( scalar_name(1) + focus*focus ) );
           scalar_name horizontal_alpha = ::math::geometry::projective::camera::va2h( vertical_alpha, aspect );

           return std::make_pair( horizontal_alpha, vertical_alpha );
          }

       }
     }
   }
 }

#endif
