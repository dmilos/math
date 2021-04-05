#ifndef Dh_math_geometry_circle_inside
 #define Dh_math_geometry_circle_inside

// ::math::geometry::circle::inside<scalar_name>( unit, point )
// ::math::geometry::circle::inside<scalar_name>( simple, point )

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
        bool inside
         (
           ::math::geometry::circle::unit<scalar_name,dimension_number>  const& circle
          ,::math::linear::vector::point<scalar_name,dimension_number>        const& point
         )
         {
          return ::math::linear::vector::length<scalar_name>( point ) < scalar_name( 1 );
         }

       template
        <
          typename scalar_name
         ,unsigned dimension_number
        >
        bool inside
         (
           ::math::geometry::circle::simple<scalar_name,dimension_number>  const& circle
          ,::math::linear::vector::point<scalar_name,dimension_number>          const& point
         )
         {
          ::math::linear::vector::point<scalar_name,dimension_number>          p;

          ::math::linear::vector::subtraction( p, point, circle.center() );
          return ::math::linear::vector::length<scalar_name>( p ) < circle.radius();
         }


      }
    }
  }

#endif
