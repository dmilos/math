#ifndef math_geometry_plane_bisector
#define math_geometry_plane_bisector

// ::math::geometry::object::plane::bisector<scalar_name>( first, second, dimension_number )

#include <cmath>

#include "./noNd.hpp"
#include "../../linear/vector/convex.hpp"
#include "../../linear/vector/subtraction.hpp"


namespace math
 {
  namespace geometry
   {
    namespace plane
     {

      template
       <
         typename scalar_name = double
         ,unsigned dimension_number = 3
       >
       ::math::geometry::plane::noNd<scalar_name,dimension_number>
       bisector
        (
          ::math::linear::vector::point< scalar_name, dimension_number > const & first
         ,::math::linear::vector::point< scalar_name, dimension_number > const & second
        )
        {
         ::math::linear::vector::point< scalar_name, dimension_number>  origin;
         ::math::linear::vector::convex( origin, scalar_name(0.5), first, second );

         ::math::linear::vector::point< scalar_name, dimension_number>  normal;
         ::math::linear::vector::subtraction( normal, second, first );

         return ::math::geometry::plane::noNd<scalar_name, dimension_number>( origin, normal );
        }

     }
   }
 }

#endif

