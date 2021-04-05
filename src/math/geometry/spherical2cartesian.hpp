#ifndef math_geometry_spherical2cartesian
#define math_geometry_spherical2cartesian

 // ::math::geometry::spherical2cartesian( )
 // https://en.wikipedia.org/wiki/Spherical_coordinate_system

#include "../linear/vector/structure.hpp"

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name >
     ::math::linear::vector::point<scalar_name,3>
     spherical2cartesian( ::math::linear::vector::point<scalar_name,3> const& point )
      { // ( r, phi, theta ) -> (x,y,z)
       ::math::linear::vector::point<scalar_name,3> result;
       result[0] = point[0] * cos( point[2] ) * cos( point[1] );
       result[1] = point[0] * cos( point[2] ) * sin( point[1] );
       result[2] = point[0] * sin( point[2] );
       return result;
      }

   }
 }

#endif
