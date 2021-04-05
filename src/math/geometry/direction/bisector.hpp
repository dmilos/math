#ifndef math_geometry_direction_bisector
#define math_geometry_direction_bisector

// ::math::geometry::object::direction::redirect<scalar_name>( direction )

#include <cmath>

#include "./parametric.hpp"
#include "../../linear/vector/convex.hpp"
#include "../../linear/vector/subtraction.hpp"


namespace math
 {
  namespace geometry
   {
    namespace direction
     {

      template
       <
         typename scalar_name = double
       >
       ::math::geometry::direction::parametric<scalar_name,2>
       bisector
        (
          ::math::linear::vector::point< scalar_name, 2 > const & first
         ,::math::linear::vector::point< scalar_name, 2 > const & second
        )
        {
         ::math::linear::vector::point< scalar_name, 2>  origin;
         ::math::linear::vector::convex( origin, scalar_name(0.5), first, second );

         ::math::linear::vector::point< scalar_name, 2>  direction;
         ::math::linear::vector::subtraction( direction, second, first );
         std::swap( direction[0], direction[1] );
         direction[0] = -direction[0];

         return ::math::geometry::direction::parametric<scalar_name, 2>( origin, direction );
        }

     }
   }
 }

#endif

