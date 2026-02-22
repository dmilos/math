#ifndef math_geometry_projective_camera_intrinsic_skew
#define math_geometry_projective_camera_intrinsic_skew

// ::math::geometry::projective::camera::intrinsic::skew( K )





namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {
        namespace intrinsic
         {

          template < typename scalar_name >
           scalar_name
           skew
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
 }

#endif
