#ifndef math_geometry_projective_camera_skew
#define math_geometry_projective_camera_skew

// ::math::geometry::projective::camera::skew( K )





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
         intrinsic_horisontal
          (
            ::math::linear::matrix::structure<scalar_name,3,3> const& K
          )
          {
           scalar_name result = atan2( K[0][1], fabs( K[0][0] ) );
           return result;
          }

       }
     }
   }
 }

#endif
