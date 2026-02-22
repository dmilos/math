#ifndef math_geometry_projective_camera_focus_intrisic
#define math_geometry_projective_camera_focus_intrisic

// ::math::geometry::projective::camera::focus::intrinsic_horisontal( K, width )
// ::math::geometry::projective::camera::focus::intrinsic_vertical( K, height )
// ::math::geometry::projective::camera::focus::intrinsic( K, resolution )
// ::math::geometry::projective::camera::focus::intrinsic( K, resolution , window )


#include "../../../interval/structure.hpp"


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
             ,::math::linear::vector::structure<other_name,2>    const& resolution
            )
            {
             ::math::linear::vector::structure<scalar_name,2> result;
             result[0] = ::math::geometry::projective::camera::focus::intrinsic_horisontal( K,(scalar_name)resolution[0] );
             result[1] = ::math::geometry::projective::camera::focus::intrinsic_vertical(   K,(scalar_name)resolution[1] );
             return result;
            }

          template < typename scalar_name, typename other_name  >
           ::math::linear::vector::structure<scalar_name,2>
           intrinsic
            (
              ::math::linear::matrix::structure<scalar_name,3,3>     const& K
             ,::math::linear::vector::structure<other_name,2>        const& resolution
             ,::math::geometry::interval::structure<scalar_name,2>   const& window
            )
            {
             auto const& W = resolution[0];
             auto const& H = resolution[1];

             auto Lx = window[1][0] - window[0][0];
             auto Ly = window[1][1] - window[0][1];

             auto Cx = window[0][0];
             auto Cy = window[0][1];
             auto A = Lx/ Ly;

             // K[0][0] = F*W/Lx;   K[0][1] =       0;  K[0][2] = +( -Cx )*W/Lx;
             // K[1][0] = 0;        K[1][1] =-F* H/Ly;  K[1][2] = -( -Cy )*H/Ly+H;
             // K[2][0] = 0;        K[2][1] =       0;  K[2][2] = 1;

             ::math::linear::vector::structure<scalar_name,2> result;

             result[0] = scalar_name( 2 ) * atan2( W / Lx,             K[0][0]   );
             result[1] = scalar_name( 2 ) * atan2( ( H / Ly ) / A ,       -K[1][1] );

             return result;
            }

         }
       }
     }
   }
 }

#endif
