#ifndef math_geometry_spherical2cylindric
#define math_geometry_spherical2cylindric

 // ::math::geometry::spherical2cylindric( )

#include "../linear/vector/structure.hpp"

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name >
     ::math::linear::vector::point<scalar_name,3>
     spherical2cylindric( ::math::linear::vector::point<scalar_name,3> const& point )
      {// ( r, phi, theta ) -> ( r, phi, z ) 
       auto cartesian = ::math::geometry::spherical2cartesian( point );
       auto result    = ::math::geometry::cartesian2cylindric( cartesian );
       return result;
      }

   }
 }

#endif
