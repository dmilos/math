#ifndef math_geometry_interval_distance_hpp_
 #define math_geometry_interval_distance_hpp_

// ::math::geometry::interval::distance_class<double, 20>.process( point, instance )
// ::math::geometry::interval::distance_class<double, 20>.process( point  )
// ::math::geometry::interval::distance<double, 20>( point, instance )
#include <limits>

#include "./structure.hpp"





 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template< typename scalar_name, ::math::type::size_type dimension_number >
        class distance_class
         {
          public:
            typedef  scalar_name                scalar_type;
            typedef  ::math::type::size_type      size_type;
            typedef  ::math::geometry::interval::structure< scalar_name, dimension_number >   instance_type;
            typedef  typename instance_type::point_type    point_type;

          public:
            scalar_type
            process
             (
               point_type      const& point
              ,instance_type   const& instance
             )
             {
              scalar_type outside = 0;
              scalar_type inside = std::numeric_limits<scalar_type>::lowest();

              for( size_type coord = 0; coord < dimension_number; ++coord )
               {
                auto const& C = m_center[coord] = (instance[0][coord] + instance[1][coord]) * scalar_type(0.5);
                auto const& H = m_half[coord]   = (instance[1][coord] - instance[0][coord]) * scalar_type(0.5);

                scalar_type d = std::fabs( point[coord] - C ) - H;
                if( 0 < d )
                 {
                  outside += d * d;
                 }
                else
                 {
                  if( inside < d )
                   {
                    inside = d;
                   }
                 }
               }

              if( inside < 0 )
               {
                return inside;
               }

              outside = std::sqrt( outside );
              return outside;
             }

            scalar_type
            process
             (
               point_type      const& point
             )const
             {
              scalar_type outside = 0;
              scalar_type inside = std::numeric_limits<scalar_type>::lowest();

              for( size_type coord = 0; coord < dimension_number; ++coord )
               {
                auto const& C = m_center[coord];
                auto const& H = m_half[coord]  ;

                scalar_type d = std::fabs( point[coord] - C ) - H;
                if( 0 < d )
                 {
                  outside += d * d;
                 }
                else
                 {
                  if( inside < d )
                   {
                    inside = d;
                   }
                 }
               }

              if( inside < 0 )
               {
                return inside;
               }

              outside = std::sqrt( outside );
              return outside;
             }

          public:
            scalar_type outer( point_type      const& point ) //!< By design give wrong result if point is inside
             {
              scalar_type result = 0;

              for( size_type coord = 0; coord < dimension_number; ++coord )
               {
                auto const& C = m_center[coord];
                auto const& H = m_half[coord]  ;
                scalar_type d = std::fabs( point[coord] - C ) - H;
                result += d * d;
               }

              result = std::sqrt( result );
              return result;
             }

            scalar_type inner( point_type      const& point ) //!< By design give wrong result if point is outside
             {
              scalar_type result = std::numeric_limits<scalar_type>::lowest();

              for( size_type coord = 0; coord < dimension_number; ++coord )
               {
                auto const& C = m_center[coord];
                auto const& H = m_half[coord]  ;

                scalar_type d = std::fabs( point[coord] - C ) - H;

                if( result < d )
                 {
                  result = d;
                 }
               }

              return result;
             }

          private:
            point_type m_center;
            point_type m_half;
         };

       template< typename scalar_name, ::math::type::size_type dimension_number >
        scalar_name distance
         (
                     ::math::geometry::interval::structure< scalar_name, dimension_number >              const&  instance
           ,typename ::math::geometry::interval::structure< scalar_name, dimension_number >::point_type  const&  point
         )
         {
          return ::math::geometry::interval::distance_class<scalar_name, dimension_number>().process( point, instance );
         }
      }
    }
  }

#endif
