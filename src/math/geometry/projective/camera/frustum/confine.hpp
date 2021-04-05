#ifndef math_geometry_projective_camera_frustum_confine
#define math_geometry_projective_camera_frustum_confine

// ::math::geometry::projective::camera::frustum::confine( two, window, depth )

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
           struct guard
            {
             public:
              typedef ::math::linear::vector::structure< scalar_name, 3 >           vector_type;
              typedef ::math::geometry::direction::parametric< scalar_name, 3 > parametric_type;
              typedef ::math::geometry::direction::parametric< scalar_name, 2 >       line_type;
              typedef ::math::geometry::interval::structure< scalar_name, 2>        window_type;
              typedef ::math::geometry::interval::structure< scalar_name, 1 >        depth_type;

              typedef ::math::geometry::projective::camera::pinhole< scalar_name > pinhole_type;

             public:
               bool process( parametric_type & output, parametric_type const& input, window_type const& window, depth_type const& depth )
                {
                 m_line.origin() = pinhole_type::project( input.origin() );
                 ::math::linear::vector::addition( m_tip, input.origin(), input.direction() );
                 m_line.direction() = pinhole_type::project( m_tip );
                 ::math::linear::vector::subtraction( m_line.direction(), m_line.direction(),  m_line.origin() );

                 if( false == ::math::geometry::interval::intersect( m_bound, window, m_line ) )
                  {
                   return false;
                  }

                 ::math::linear::vector::combine( output.origin(), input.origin(), std::get<1>(m_bound), input.direction() );
                 ::math::linear::vector::scale(   output.direction(), std::get<3>(m_bound) - std::get<1>(m_bound), input.direction() );

                 return true;
                }

             public:
               line_type m_line;
               vector_type m_tip;
               std::tuple< unsigned, scalar_name, unsigned, scalar_name > m_bound;
            };

          template < typename scalar_name >
            bool confine
             (
               ::math::geometry::direction::parametric< scalar_name, 3 >       & output
              ,::math::geometry::direction::parametric< scalar_name, 3 >  const& input
              ,::math::geometry::interval::structure<scalar_name, 2>      const& window
              ,::math::geometry::interval::structure<scalar_name, 1 >     const& depth
             )
             {
              ::math::geometry::projective::camera::frustum::guard<scalar_name> guard;
              return guard.process( output, input, window, depth );
             }

          template < typename scalar_name >
            bool confine
             (
               ::math::geometry::direction::parametric<      scalar_name, 3 >      & parametric
              ,::math::geometry::interval::structure<scalar_name, 2>   const& window
              ,::math::geometry::interval::structure<scalar_name, 1 >  const& depth
             )
             {
              ::math::geometry::projective::camera::frustum::guard<scalar_name> guard;
              return guard.process( parametric, parametric, window, depth );
             }

         }
       }
     }
   }
 }

#endif
