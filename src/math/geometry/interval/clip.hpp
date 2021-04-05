#ifndef math_geometry_interval_clip_hpp_
 #define math_geometry_interval_clip_hpp_

// ::math::geometry::interval::scissors< scalar_name, dimension_number >
// ::math::geometry::interval::scissors.process( two, window )
// ::math::geometry::interval::scissors.process( output, input, window )

// ::math::geometry::interval::clip( two, window )
// ::math::geometry::interval::clip( output, input, window )


#include "./structure.hpp"


 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template < typename scalar_name, unsigned dimension_number >
        struct scissors
         {
          public:
            typedef scalar_name scalar_type;
            typedef ::math::geometry::direction::two<        scalar_name, dimension_number >         two_type;
            typedef ::math::geometry::interval::structure<   scalar_name, dimension_number >    interval_type;
            typedef ::math::geometry::direction::parametric< scalar_name, dimension_number >  parametric_type;
            typedef std::tuple< unsigned, scalar_name, unsigned, scalar_name >                 intersect_type;

          public:
            scissors():m_near( std::get<1>( m_intersect )), m_far( std::get<3>( m_intersect ) ){}

          public:
            int process( two_type &output, two_type const&input, interval_type const& interval )
             {
              m_parametric = input;
              if( false == ::math::geometry::interval::intersect( m_intersect, interval, m_parametric ) )
               {
                return 0; // No intersection with interval
               }

              if(    ( scalar_name( 1 )  < m_near )
                  || ( m_far             < scalar_name( 0 ) )
                )
               {
                return -1; // both points are outside of interval
               }

              if( scalar_name( 0 ) < m_near )
               {
                ::math::linear::vector::combine( output.first(), m_parametric.origin(), m_near, m_parametric.direction() );
               }
              else
               {
                output.first() = m_parametric.origin();
               }

              if( m_far < scalar_name( 1 ) )
               {
                ::math::linear::vector::combine( output.second(), m_parametric.origin(), m_far, m_parametric.direction() );
               }
              else
               {
                ::math::linear::vector::addition( output.second(), m_parametric.origin(), m_parametric.direction() );
               }

              return +1; // we have intersection of line and interval
             }

            int process( two_type &two, interval_type const& interval )
             {
              auto result = process( m_output, two, interval );
              two = m_output;
              return result;
             }

          public:
              two_type           m_output;
              intersect_type     m_intersect;
              scalar_type const& m_near;
              scalar_type const& m_far;
              parametric_type    m_parametric;
         };

       template < typename scalar_name, unsigned dimension_number >
        int
        clip
         (
           ::math::geometry::direction::two<      scalar_name, dimension_number >        & two
          ,::math::geometry::interval::structure< scalar_name, dimension_number >  const& interval
         )
         {
          ::math::geometry::interval::scissors<scalar_name,dimension_number> scissors;

          return scissors.process( two, interval );
         }

       template < typename scalar_name, unsigned dimension_number >
        int
        clip
         (
           ::math::geometry::direction::two<      scalar_name, dimension_number >       & output
          ,::math::geometry::direction::two<      scalar_name, dimension_number >       & input
          ,::math::geometry::interval::structure< scalar_name, dimension_number >  const& interval
         )
         {
          ::math::geometry::interval::scissors<scalar_name,dimension_number> scissors;

          return scissors.process( output, input, interval );
         }

      }
    }
  }

#endif
