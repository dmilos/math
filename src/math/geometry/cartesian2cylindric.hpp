#ifndef math_geometry_cartesian2cylindric
#define math_geometry_cartesian2cylindric

 // ::math::geometry::cartesian2cylindric( )
 //https://en.wikipedia.org/wiki/Polar_coordinate_system#Converting_between_polar_and_Cartesian_coordinates

#include "../linear/vector/structure.hpp"

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name >
     ::math::linear::vector::point<scalar_name,3>
     cartesian2cylindric( ::math::linear::vector::point<scalar_name,3> const& point )
      {// ( x, y, z ) -> ( r, phi, z )
       ::math::linear::vector::point<scalar_name,3> result;
        result[0] = sqrt( point[0]*point[0] + point[1]*point[1] );
        result[1] = atan2( point[1], point[0]);
        result[2] = point[2];

       return result;
      }

   }
 }

#endif
