#ifndef math_geometry_direction_intersect_common
#define math_geometry_direction_intersect_common

// ::math::geometry::direction::closest().process( point, beam );

#include "../../linear/vector/structure.hpp"
#include "../../linear/vector/addition.hpp"
#include "../../linear/vector/structure.hpp"
#include "./project.hpp"
#include "./parametric.hpp"
#include "./abc.hpp"



namespace math
 {
  namespace geometry
   {
    namespace direction
     {

      template< typename scalar_name >
       struct closest
        {
         public:
           typedef scalar_name scalar_type;
           typedef ::math::type::size_type size_type;

           typedef ::math::linear::vector::point<  scalar_type, 2 > point_type;
           typedef ::math::geometry::direction::ABC2D < scalar_type > direction_type;
           //typedef ::math::geometry::direction::parametric < scalar_type, 2 > direction_type;
           typedef ::std::vector< direction_type > beam_type;

           typedef ::math::geometry::direction::project<scalar_type>  projector_type;

         public:
           closest( size_type const& I = 30, scalar_type const& S = 1.74, scalar_type const& E = 1e-6 )
           : m_max( I )
           , m_scale( 1.8 )
           , m_epsilon( E )
            {
            }

           bool process
            (
              point_type              & point
             ,beam_type         const & beam
            )
            {
             m_effective.resize( beam.size());
             std::fill( m_effective.begin(), m_effective.end(), true );
             //::math::linear::vector::load( point, rand(), rand() );
             ::math::linear::vector::fill( point, 0 );
             m_iteration = 0;
             size_type essential = size_type( 0.8 * beam.size() );
             while( ( essential < beam.size() ) && (m_iteration < m_max ) )
              {
               ++m_iteration;
               point_type next; ::math::linear::vector::fill( next, 0 );
               size_type counter = 0;
               for( size_type index=0; index < beam.size(); ++index )
                {
                 if( false == m_effective[index] ) continue;
                 auto P = m_projector.process( point, beam[index] );
                 ::math::linear::vector::addition( next, P );
                 ++counter;
                }
               ::math::linear::vector::scale( next, scalar_type(1)/scalar_type(counter) );
               auto L = ::math::linear::vector::distance( next, point );
               if( L < m_epsilon )
                {
                 break;
                }

              // move strategy
              //point = next;
               point_type direction;
               ::math::linear::vector::subtraction( direction, next, point );
               ::math::linear::vector::scale( direction, m_scale );
               ::math::linear::vector::addition( point, direction );

              // outlier handling strategy
               purge( point,  beam );
              }
             return true;
            }

         private:
           void purge( point_type const& point, beam_type const& beam )
            {
             if( 0 == m_iteration ) return;
             if( 0 != ( m_iteration % 10 ) ) return;

             auto O = outlier( point, beam );
             if( O != beam.size() )
              {
               m_effective[O] = false;
              }
            }

          size_type outlier( point_type const& point, beam_type         const& beam )
           {
            size_type result     = beam.size();
            scalar_type distance = 0;

            for( size_type index=0; index < beam.size(); ++index )
             {
              if( false == m_effective[index]) continue;
              auto P = m_projector.process( point, beam[index] );
              auto D = ::math::linear::vector::distance( P, point );

              if( beam.size() == result )
               {
                result = index;
                distance = D;
               }

               if( D < distance )
                {
                 continue;
                }

               distance = D;
               result = index;
             }
            return result;
           }

         public:
          size_type m_iteration, m_max;
          scalar_type m_scale;
         private:
          projector_type m_projector;
          scalar_type m_epsilon;
          std::vector<bool> m_effective;
        };

      //template<  typename scalar_name >
      // bool closest
      //  (
      //    ::math::linear::vector::point<  scalar_name, 2 >                 & point
      //   ,beam_type      const & epsilon = 1e-6
      //  )
      //  {
      //   return ::math::geometry::direction::intersectV<scalar_name>( ).process( point, left, right, epsilon );
      //  }

     }
   }
 }

#endif
