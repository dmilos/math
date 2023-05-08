#ifndef math_geometry_interval_remap_hpp_
 #define math_geometry_interval_remap_hpp_

// ::math::geometry::interval::remap( target, source, value )

#include "./structure.hpp"
#include "../../function/clamper.hpp"




 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template< typename scalar_name >
        inline
        scalar_name
        remap
         (
            scalar_name  const& value
          ,::math::geometry::interval::structure< scalar_name, 1 > const& source
          ,::math::geometry::interval::structure< scalar_name, 1 > const& target
         )
         {
          return ::math::function::any_to_any<scalar_name>( value, source[0], source[1], target[0], target[1] );
         }

       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        typename ::math::geometry::interval::structure< scalar_name, dimension_number >::point_type
        remap
         (
           typename ::math::geometry::interval::structure< scalar_name, dimension_number >::point_type const& point
          ,         ::math::geometry::interval::structure< scalar_name, dimension_number >             const& source
          ,         ::math::geometry::interval::structure< scalar_name, dimension_number >             const& target
         )
         {
          typename ::math::geometry::interval::structure< scalar_name, dimension_number >::point_type result;
          auto index = dimension_number;

          while( index-- )
           {
            result[index] = ::math::function::any_to_any<scalar_name>( point[index], source[0][index], source[1][index], target[0][index], target[1][index] );
           }
          return result;
         }

      }
    }
  }

#endif
