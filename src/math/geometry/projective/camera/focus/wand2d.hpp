#ifndef math_geometry_projective_camera_focus_wand2d
#define math_geometry_projective_camera_focus_wand2d

// ::math::geometry::projective::camera::focus::wand2d( focus, A,  distance0, distanceA, lengthW );
// ::math::geometry::projective::camera::focus::wand2d( focus, A, B, distanceA, distanceB, lengthW );

#include "../../../../polynomial/quadric/solve.hpp"
#include "../../../triangle/angle.hpp"

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

          /**************
                +------------0---wand----A-+--  NOT parallel to focal plane
                |            |          /
                d            |         /
                i            |        distanceA
                s            |       /
                t            |      /
            ----a----------- f-----B---
                n            o    /
                c            c   /
                e            u  /
                A            s /
                |            |/
                +            0
         **************/
          template < typename scalar_name >
           bool
           wand2d
            (
              scalar_name          & focus
             ,scalar_name     const& A            //!< projection of second point,
             ,scalar_name     const& distance0    //!< distance to 0,
             ,scalar_name     const& distanceA    //!< distance to B,
             ,scalar_name     const& lengthW      //!< length of wand,
            )
            {
             scalar_name gamma;
             if( false == ::math::geometry::triangle::angle_gamma( gamma, distance0, distanceA, lengthW ) ) return false;

             focus = A / tan( gamma );
             return true;
            }


          /**************
            *------------0---wand----*----  NOT parallel to focal plane
             \           |          /
              \          |         /
              distanceA  |        distanceB
                \        |       /
                 \       |      /
              ----A----- f-----B---
                   \     o    /
                    \    c   /
                     \   u  /
                      \  s /
                       \ |/
                         0
         **************/
          template < typename scalar_name >
           bool
           wand2d
            (
              scalar_name          & focus
             ,scalar_name     const& A            //!< projection of first point on left side,
             ,scalar_name     const& B            //!< projection of second point on right side,
             ,scalar_name     const& distanceA    //!< distance to A,
             ,scalar_name     const& distanceB    //!< distance to B,
             ,scalar_name     const& lengthW      //!< length of wand,
            )
            {
             scalar_name epsilon = 1e-6;
             scalar_name gamma;
             if( false == ::math::geometry::triangle::angle_gamma( gamma, distanceA, distanceB, lengthW ) ) return false;

             scalar_name r = (fabs(A)+B)/( scalar_name(2) * sin( gamma ));
             scalar_name y = sqrt( r*r - (fabs(A)-B)*(fabs(A)-B)/scalar_name(2*2));
             scalar_name h = ((fabs(A)+B)/scalar_name(2) ) /tan( gamma );
             focus = y + h;
             return true;
            }

         }
       }
     }
   }
 }

#endif
