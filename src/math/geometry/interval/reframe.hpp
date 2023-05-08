#ifndef math_geometry_interval_reframe_hpp_
 #define math_geometry_interval_reframe_hpp_

// ::math::geometry::interval::reframe( result, frame )
// ::math::geometry::interval::reframe( result, original, frame )

#include "./structure.hpp"
#include "../../linear/vector/structure.hpp"
#include "../../linear/vector/subtraction.hpp"
#include "../../linear/vector/addition.hpp"



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
       void reframe
        (
          ::math::geometry::interval::structure<scalar_name,dimension_number>       & result
         ,::math::linear::vector::structure<scalar_name,dimension_number>      const& frame
        )
        {
         ::math::linear::vector::subtraction( result[0], frame );
         ::math::linear::vector::addition(   result[1], frame );
        }

       template
        <
          typename scalar_name
         ,::math::type::size_type dimension_number
        >
       void reframe
        (
          ::math::geometry::interval::structure<scalar_name,dimension_number>       & result
         ,::math::geometry::interval::structure<scalar_name,dimension_number>  const& original
         ,::math::linear::vector::structure<scalar_name,dimension_number>      const& frame
        )
        {
         ::math::linear::vector::subtraction( result[0], original[0], frame );
         ::math::linear::vector::addition(   result[1], original[1], frame );
        }

      }
    }
  }

#endif
