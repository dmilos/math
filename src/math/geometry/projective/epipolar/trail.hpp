#ifndef math_geometry_projective_camera_epipolar_trail
#define math_geometry_projective_camera_epipolar_trail

// ::math::geometry::projective::epipolar::trail( result, uv_left )

#include "../camera/pinhole.hpp"
#include "../camera/frustum/clip.hpp"
#include "../../../geometry/interval/structure.hpp"
#include "../../../linear/affine/structure.hpp"
#include "../../direction/two.hpp"

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {

        template< typename scalar_name >
         bool trail
          (
             ::math::geometry::direction::two< scalar_name, 2 >             & result
            ,::math::linear::vector::structure< scalar_name, 2 >       const& left_uv
            ,::math::geometry::interval::structure< scalar_name, 1 >   const& left_focus
            ,::math::geometry::interval::structure< scalar_name, 1 >   const& right_focus
            ,::math::linear::affine::structure< scalar_name, 3 >       const& to_right
            ,::math::geometry::interval::structure< scalar_name, 2 >   const& right_window
           )
          {
           typedef ::math::geometry::projective::camera::pinhole< scalar_name > pinhole_type;
           auto left_ray = pinhole_type::reproject( left_uv );

           ::math::geometry::direction::two<scalar_name,3> two3D;

           ::math::linear::vector::scale( two3D.first(),  left_focus[0] / left_ray[pinhole_type::forward() ], left_ray );
           ::math::linear::vector::scale( two3D.second(), left_focus[1] / left_ray[pinhole_type::forward() ], left_ray );

           ::math::linear::affine::transform( two3D.first(),  to_right );
           ::math::linear::affine::transform( two3D.second(), to_right );
           typedef ::math::geometry::projective::camera::frustum::scissors<scalar_name>  scissors_type;
           scissors_type   scissors;
           if( false == scissors.process( two3D, two3D, right_window, right_focus ) )
            {
             return false;
            }
           result = scissors.m_trace;
           return true;
          }

       }
     }
   }
 }
#endif
