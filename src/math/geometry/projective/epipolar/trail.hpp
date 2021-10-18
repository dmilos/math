#ifndef math_geometry_projective_camera_epipolar_trail
#define math_geometry_projective_camera_epipolar_trail

// ::math::geometry::projective::epipolar::trail<scalar>.process( left_uv, uv_left )

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
          class dash
            {
             public:
               typedef ::math::linear::vector::structure< scalar_name, 2 >              uv_type;
               typedef ::math::geometry::direction::two<scalar_name,2>           direction_type;
               typedef ::math::geometry::direction::two<scalar_name,3>           trace_type;
               typedef ::math::geometry::interval::structure< scalar_name, 1 >       focus_type;
               typedef ::math::geometry::interval::structure< scalar_name, 2 >      window_type;
               typedef ::math::linear::affine::structure< scalar_name, 3 >          affine_type;

               typedef ::math::geometry::projective::camera::pinhole< scalar_name > pinhole_type;

               typedef ::math::geometry::projective::camera::frustum::scissors<scalar_name>  scissors_type;

             public:
               bool process
                (
                  uv_type      const& left_uv
                 ,focus_type   const& left_focus
                 ,focus_type   const& right_focus
                 ,affine_type  const& to_right
                 ,window_type  const& right_window
                )
                {
                 auto left_ray = pinhole_type::reproject( left_uv );

                 ::math::linear::vector::scale( m_left.first(),  left_focus[0] / left_ray[pinhole_type::forward() ], left_ray );
                 ::math::linear::vector::scale( m_left.second(), left_focus[1] / left_ray[pinhole_type::forward() ], left_ray );

                 ::math::linear::affine::transform( m_right.first(),  to_right, m_left.first()  );
                 ::math::linear::affine::transform( m_right.second(), to_right, m_left.second() );

                 if( false == m_scissors.process( m_trace, m_right, right_window, right_focus ) )
                  {
                   return false;
                  }

                 return true;
                }
             direction_type const& result() 
              {
               return m_scissors.trail();
              }
             trace_type m_left, m_right, m_trace;
             scissors_type m_scissors;
           };


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
           typedef  ::math::geometry::projective::epipolar::dash<scalar_name> dash_type;
           dash_type d;
           if( false == d.process( left_uv, left_focus, right_focus, to_right, right_window ) )
            {
             return false;
            }
            result = d.result();
            return true;
          }
       }
     }
   }
 }
#endif
