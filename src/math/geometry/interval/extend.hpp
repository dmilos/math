#ifndef math_geometry_interval_extend_hpp_
 #define math_geometry_interval_extend_hpp_

// ::math::geometry::interval::extend( )

#include "./structure.hpp"

#include "../../linear/vector/max.hpp"
#include "../../linear/vector/min.hpp"

 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template
        <
          typename scalar_name
         ,::math::type::size_type dimension_number
        >
       void extend
        (
                   ::math::geometry::interval::structure<scalar_name,dimension_number>                  & result
         ,         ::math::geometry::interval::structure<scalar_name,dimension_number>             const& original
         ,typename ::math::geometry::interval::structure<scalar_name,dimension_number>::point_type const& point
        )
        {
          result[1] = point;
         ::math::linear::vector::max( result[1], result[1], original[0] );
         ::math::linear::vector::max( result[1], result[1], original[1] );
          result[0] = point;
         ::math::linear::vector::min( result[0], result[0], original[0] );
         ::math::linear::vector::min( result[0], result[0], original[1] );
        }

       template
        <
          typename scalar_name
         ,::math::type::size_type dimension_number
        >
       void extend
        (
                   ::math::geometry::interval::structure<scalar_name,dimension_number>                  & result
         ,typename ::math::geometry::interval::structure<scalar_name,dimension_number>::point_type const& point
        )
        {
         auto minimum = point;
         ::math::linear::vector::min( minimum, minimum, result[0] );
         ::math::linear::vector::min( minimum, minimum, result[1] );
         auto maximum = point;
         ::math::linear::vector::max( maximum, maximum, result[0] );
         ::math::linear::vector::max( maximum, maximum, result[1] );

         result[0] = minimum;
         result[1] = maximum;
        }

       template
        <
          typename scalar_name
         ,::math::type::size_type dimension_number
        >
       void extend
        (
          ::math::geometry::interval::structure<scalar_name,dimension_number>      & result
         ,::math::geometry::interval::structure<scalar_name,dimension_number> const& other
        )
        {
         ::math::geometry::interval::extend( result, other[0] );
         ::math::geometry::interval::extend( result, other[1] );
        }

       template
        <
          typename scalar_name
         ,::math::type::size_type dimension_number
        >
       void extend
        (
          ::math::geometry::interval::structure<scalar_name,dimension_number>      & result
         ,::math::geometry::interval::structure<scalar_name,dimension_number> const& left
         ,::math::geometry::interval::structure<scalar_name,dimension_number> const& right
        )
        {
         result = left;
         ::math::geometry::interval::extend( result, right );
        }

      }
    }
  }

#endif
