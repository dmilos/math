#ifndef math_geometry_projective_camera_focus_chuchc
#define math_geometry_projective_camera_focus_chuchc

// ::math::geometry::projective::camera::focus::chuchc<>().process( value, point, depth )


#include "../../../direction/abc.hpp"

#include "../../../../linear/homography/transform.hpp"
#include "../../../../linear/vector/structure.hpp"
#include "../../../../linear/homography/structure.hpp"
#include "../../../../linear/matrix/transpose.hpp"
#include "../../../../linear/matrix/invert.hpp"
#include "../../../../linear/matrix/multiply.hpp"
#include "../../../../linear/matrix/scale.hpp"

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
           class chuchc
            {
             public:
               typedef ::math::linear::vector::structure< scalar_name, 2 > uv_type;
               typedef ::math::geometry::direction::ABC2D<scalar_name>   ABC2D_type;
               typedef ::math::linear::homography::structure<scalar_name, 2 > homography_type;

              bool process( scalar_name & value, uv_type const& point, ABC2D_type const& princip, homography_type const& H )
               {
                homography_type Ht;  ::math::linear::matrix::transpose( Ht, H );
                homography_type invert_H;  ::math::linear::matrix::invert( invert_H, H );

                homography_type H1r;
                H1r[0][0] =  princip.A();  H1r[0][1] = princip.B(); H1r[0][2] = 0;
                H1r[1][0] = -princip.B();  H1r[1][1] = princip.A(); H1r[1][2] = 0;
                H1r[2][0] =            0;  H1r[2][1] =           0; H1r[2][2] = 1;

                homography_type H1s;
                H1s[0][0] = 1;  H1s[0][1] = 0; H1s[0][2] = -point[0];
                H1s[1][0] = 0;  H1s[1][1] = 1; H1s[1][2] = -point[1];
                H1s[2][0] = 0;  H1s[2][1] = 0; H1s[2][2] = 1;

                ABC2D_type  invert_princip;  ::math::linear::matrix::transform( invert_princip.array(), Ht, princip.array() ); invert_princip.normalize();
                uv_type invert_point;        ::math::linear::homography::transform( invert_point, invert_H, point );

                homography_type H2r;
                H2r[0][0] =  invert_princip.A();  H2r[0][1] = invert_princip.B(); H2r[0][2] = 0;
                H2r[1][0] = -invert_princip.B();  H2r[1][1] = invert_princip.A(); H2r[1][2] = 0;
                H2r[2][0] =                   0;  H2r[2][1] =                  0; H2r[2][2] = 1;

                homography_type H2s;
                H2s[0][0] = 1;  H2s[0][1] = 0; H2s[0][2] = -invert_point[0];
                H2s[1][0] = 0;  H2s[1][1] = 1; H2s[1][2] = -invert_point[1];
                H2s[2][0] = 0;  H2s[2][1] = 0; H2s[2][2] = 1;

                homography_type temp;  
                homography_type right;  
               ::math::linear::matrix::multiply( temp, H2r, H2s );  ::math::linear::matrix::invert( right, temp );

                homography_type left;
               ::math::linear::matrix::multiply( left, H1r, H1s );

                homography_type Hnew; ::math::linear::matrix::multiply( Hnew, left, H, right );

               ::math::linear::matrix::scale( Hnew, 1 / Hnew[2][2] );

                auto cos_gamma =  Hnew[1][1]/Hnew[0][0];
                auto s =  Hnew[2][1]/sqrt( 1 - cos_gamma *cos_gamma );

                value = fabs( Hnew[0][0] / s );
                scalar_name tz = Hnew[2][2] / s;

                return true;
               }

            };

         }
       }
     }
   }
 }

#endif
