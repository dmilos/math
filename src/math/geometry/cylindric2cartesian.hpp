#ifndef math_geometry_cylindric2cartesian
#define math_geometry_cylindric2cartesian

 // ::math::geometry::cylindric2cartesian( )
 //https://en.wikipedia.org/wiki/Polar_coordinate_system#Converting_between_polar_and_Cartesian_coordinates

#include "../linear/vector/structure.hpp"

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name >
     ::math::linear::vector::point<scalar_name,3>
     cylindric2cartesian( ::math::linear::vector::point<scalar_name,3> const& point )
      { // ( r, phi, z ) -> ( x, y, z ) 
       ::math::linear::vector::point<scalar_name,3> result;
        result[0] = point[0] * cos( point[1] );
        result[1] = point[0] * sin( point[1] );
        result[2] = point[2];
       return result;
      }

   }
 }

#endif
