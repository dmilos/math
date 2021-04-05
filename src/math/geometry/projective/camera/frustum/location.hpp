#ifndef math_geometry_projective_camera_frustum_location
#define math_geometry_projective_camera_frustum_location

// ::math::geometry::projective::camera::frustum::locator( point, window, depth, 0.01 )
// ::math::geometry::projective::camera::frustum::location( point, window, depth )

#include "../pinhole.hpp"







namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {
        namespace frustum
         {

          template < typename scalar_name >
            struct locator
             {
              public:
                typedef scalar_name                                             scalar_type;
                typedef ::math::linear::vector::point< scalar_name, 2 >             uv_type;
                typedef ::math::linear::vector::point< scalar_name, 3 >         vector_type;
                typedef ::math::geometry::interval::structure<scalar_name, 1 >   depth_type;
                typedef ::math::geometry::interval::structure<scalar_name, 2>   window_type;
                typedef ::math::geometry::projective::camera::pinhole< scalar_name > pinhole_type;

                int process( vector_type const& point, window_type   const& window, depth_type const& depth, scalar_type const& zero = scalar_name(0) )
                 {
                  int result;

                  auto const& y = point[ pinhole_type::forward() ];

                  if( y < zero ) return result = 0;

                  auto const& near  = depth[0];
                  auto const& far = depth[1];
                  if( y < near )  result = 4 + 0;
                  else
                  if( y < far  )  result = 4 + 1;
                  else            result = 4 + 2;

                  m_fly = pinhole_type::project( point );

                  auto const& x = m_fly[0];
                  auto const& left  = window[0][0];
                  auto const& right = window[1][0];
                  if( x < left  ) result += 0 + 0;
                  else
                  if( x < right ) result += 0 + 1;
                  else            result += 0 + 2;

                  auto const& z = m_fly[1];
                  auto const& down = window[0][1];
                  auto const& up   = window[1][1];
                  if( z < down )  result += 7 + 0;
                  else
                  if( z < up   )  result += 7 + 1;
                  else            result += 7 + 2;
                  return result;
                 }

              public:
                 uv_type m_fly;
             };

          template < typename scalar_name >
            int location
             (
               ::math::linear::vector::point< scalar_name, 3 >         const& point
              ,::math::geometry::interval::structure<scalar_name, 2>   const& window
              ,::math::geometry::interval::structure<scalar_name, 1 >  const& depth
              ,scalar_name                                             const& zero = scalar_name(0)
             )
             {
              typedef ::math::geometry::projective::camera::frustum::locator<scalar_name> locator_type;

              locator_type locator;

              return locator.process( point, window,depth, zero  );
             }

         }
       }
     }
   }
 }

#endif
