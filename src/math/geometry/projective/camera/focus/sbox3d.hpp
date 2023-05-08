#ifndef math_geometry_projective_camera_focus_sbox3D
#define math_geometry_projective_camera_focus_sbox3D

// ::math::geometry::projective::camera::focus::sbox3D( result, base, depth )

#include "./unit3d.hpp"



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

          /************** image on display
            +-------base--------+
            |\ near   |        /|
            | \       |       / |
            |  +---------p---d  |
            b  |      |      |  b
            a  |      |      |  a
            s--|------0------|--s
            e  |      |      |  e
            |  | far  |      |  |
            |  +---------p---+  |
            | /       |       \ |
            |/ near   |        \|
            +-------base--------+
          **************/
          template < typename scalar_name >
           scalar_name
           sbox3D
            (
              scalar_name const& base       //!< length of box base
             ,scalar_name const& depth      //!< depth of box
             ,scalar_name const& p          //!< position on y=focus display
            )
            { //! box =[ ( -base/2, -base/2, focus ), ( +base/2, +base/2, focus + depth  ) ]
             scalar_name focus = ::math::geometry::projective::camera::focus::unit3d( base * sqrt( 2 ), depth, p *  sqrt( 2 ) );
             return focus;
            }

         }
       }
     }
   }
 }

#endif
