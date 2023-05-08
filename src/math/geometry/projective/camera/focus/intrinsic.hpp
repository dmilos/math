#ifndef math_geometry_projective_camera_focus_intrisic
#define math_geometry_projective_camera_focus_intrisic

// ::math::geometry::projective::camera::focus::intrinsic_horisontal( K, width )
// ::math::geometry::projective::camera::focus::intrinsic_vertical( K, height )
// ::math::geometry::projective::camera::focus::intrinsic( K, resolution )





namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {
        namespace focus
         {

          template < typename scalar_name >
           scalar_name
           intrinsic_horisontal
            (
              ::math::linear::matrix::structure<scalar_name,3,3> const& K
             ,scalar_name                                        const& width
            )
            {
             auto result = scalar_name(2) * atan2( width/scalar_name(2), fabs( K[0][0] ) );
             return result;
            }

          template < typename scalar_name >
           scalar_name
           intrinsic_vertical
            (
              ::math::linear::matrix::structure<scalar_name,3,3> const& K
             ,scalar_name                                        const& height
            )
            {
             auto result = scalar_name(2) * atan2( height/scalar_name(2), fabs( K[1][1] ) );
             return result;
            }

          template < typename scalar_name, typename other_name  >
           ::math::linear::vector::structure<scalar_name,2>
           intrinsic
            (
              ::math::linear::matrix::structure<scalar_name,3,3> const& K
             ,::math::linear::vector::structure<other_name,2>  const& resolution
            )
            {
             ::math::linear::vector::structure<scalar_name,2> result;
             result[0] = ::math::geometry::projective::camera::focus::intrinsic_horisontal( K,(scalar_name)resolution[0] );
             result[1] = ::math::geometry::projective::camera::focus::intrinsic_vertical(   K,(scalar_name)resolution[1] );
             return result;
            }

         }
       }
     }
   }
 }

#endif
