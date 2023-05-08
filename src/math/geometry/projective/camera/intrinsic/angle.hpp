#ifndef math_geometry_projective_camera_intrinsic_angle
#define math_geometry_projective_camera_intrinsic_angle

// ::math::geometry::projective::camera::intrinsic::angle( h_alpha, aspect )





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
           void
           angle
            (
              ::math::linear::vector::structure< scalar_name, 2 > & result  // [0] = horizontal angle, [1] = vertical angle
             ,::math::linear::matrix::structure< scalar_name, 3 > & matrix  //!< intrinsic matrix
             ,::math::linear::vector::structure< scalar_name, 3 > & point   //!< point in space
            )
            {
             ::math::linear::vector::structure< scalar_name, 3 > display;
             ::math::linear::matrix::transform( display, matrix, point );
             ::math::linear::vector::homogenize( display );
             // TODO result[0] = ::math::linear::vector::angle( {}, display );
             // TODO result[1] = ::math::linear::vector::angle( {}, display );
             return ;
            }

       }
     }
   }
 }

#endif
