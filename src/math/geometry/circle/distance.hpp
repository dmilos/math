#ifndef Dh_math_geometry_circle_distance
 #define Dh_math_geometry_circle_distance

// ::math::geometry::circle::distance<scalar_name>( unit, point )
// ::math::geometry::circle::distance<scalar_name>( simple, point )

#include "../../linear/vector/length.hpp"
#include "../../linear/vector/subtraction.hpp"
#include  "./unit.hpp"
#include  "./simple.hpp"

 namespace math
  {
   namespace geometry
    {
     namespace circle
      {

       template
        <
          typename scalar_name
         ,unsigned dimension_number
        >
        scalar_name distance
         (
           ::math::geometry::circle::unit<scalar_name,dimension_number>  const& dummy
          ,::math::linear::vector::point<scalar_name,dimension_number>   const& point_param
         )
         { // positive for out, negative for in
          return ::math::linear::vector::length( point_param ) - scalar_name( 1 );
         }

       template
        <
          typename scalar_name
         ,unsigned dimension_number
        >
        scalar_name distance
         (
           ::math::geometry::circle::simple<scalar_name,dimension_number>  const& circle
          ,::math::linear::vector::point<scalar_name,dimension_number>     const& point_param
         )
         {
          ::math::linear::vector::point<scalar_name,dimension_number>          point_local;

          ::math::linear::vector::subtraction( point_local, point_param, circle.center() );
          return ::math::linear::vector::length( point_local ) - circle.radius();
         }

      }
    }
  }

#endif
