#ifndef math_geometry_projective_camera_K
#define math_geometry_projective_camera_K

// ::math::geometry::projective::camera::intrinsic::K<double>()( r, focus, center, aspec, skew )

#include "../../../../linear/matrix/structure.hpp"
#include "../../../../linear/vector/structure.hpp"

#include "../optical.hpp"
#include "../classic.hpp"


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
           struct K
            {
             public:
               typedef scalar_name scalar_type;
               typedef  ::math::linear::matrix::structure<scalar_name,3,3>    matrix3x3_type;
               typedef  ::math::linear::vector::structure<scalar_name,2> vector2_type;
               typedef  ::math::geometry::projective::camera::optical<scalar_name > optical_type;
               typedef  ::math::geometry::projective::camera::classic<scalar_name >               classic_type;
             public:
               static void process
                (
                   matrix3x3_type      & result
                  ,scalar_type    const& f      //!< focus
                  ,vector2_type   const& center = { 0, 0 }
                  ,scalar_type    const& a      = 1         //!< this is PIXEL aspect ration width / height
                  ,scalar_type    const& skew   = 0
                 )
                {
                 result[0][0] = a*f;  result[0][1] =  skew; result[0][2] = -center[0];
                 result[1][0] = 0;    result[1][1] =     f; result[1][2] = -center[1];
                 result[2][0] = 0;    result[2][1] =     0; result[2][2] = 1;
                }

               /* in progress
               static void process
                (
                   matrix3x3_type      & result
                  ,optical_type    const& optical
                 )
                {
                 auto focusX = ::math::geometry::projective::camera::a2f( optical.horizontalFV() );
                 auto focusX = ::math::geometry::projective::camera::a2f( optical.verticalFV()   );

                 result[0][0] = focusX; result[0][1] =       0; result[0][2] = -optical.resolution()/scalar_type(2);
                 result[1][0] = 0;      result[1][1] =  focusY; result[1][2] = -optical.resolution()/scalar_type(2);
                 result[2][0] = 0;      result[2][1] =        0; result[2][2] = 1;
                }
               */
               static void process
                (
                   matrix3x3_type       & result
                  ,classic_type    const& classic
                )
                {
                 auto W = classic.resolution()[0];
                 auto H = classic.resolution()[1];
                 auto Lx = classic.window()[1][0] - classic.window()[0][0];
                 auto Ly = classic.window()[1][1] - classic.window()[0][1];

                 auto Cx = classic.window()[0][0];
                 auto Cy = classic.window()[0][1];
                 auto F = classic.focus();
 
                 result[0][0] = F*W/Lx;   result[0][1] =       0;  result[0][2] = +( -Cx )*W/Lx;
                 result[1][0] = 0;        result[1][1] =-F* H/Ly;  result[1][2] = -( -Cy )*H/Ly+H;
                 result[2][0] = 0;        result[2][1] =       0;  result[2][2] = 1;
                }
            };

         }
       }
     }
   }
 }

#endif
