#ifndef math_geometry_cartesian2spherical
#define math_geometry_cartesian2spherical

 // ::math::geometry::cartesian2spherical( )
 // https://en.wikipedia.org/wiki/Spherical_coordinate_system

#include "../linear/vector/structure.hpp"

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name >
     ::math::linear::vector::point<scalar_name,3>
     cartesian2spherical( ::math::linear::vector::point<scalar_name,3> const& point )
      { // (x,y,z) -> ( r, phi, theta ) -> (x,y,z)
       ::math::linear::vector::point<scalar_name,3> result;
       result[0] = ::math::linear::vector::length( point );
       result[1] = atan2( point[1], point[2] );
       result[2] = acos( point[2] / result[0] );
       return result;
      }

   }
 }

#endif
