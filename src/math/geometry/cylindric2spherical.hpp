#ifndef math_geometry_cylindric2spherical
#define math_geometry_cylindric2spherical

 // ::math::geometry::cylindric2spherical( )

#include "../linear/vector/structure.hpp"

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name >
     ::math::linear::vector::point<scalar_name,3>
     cylindric2spherical( ::math::linear::vector::point<scalar_name,3> const& point )
      {// ( r, phi, z ) -> ( r, phi, theta )
       auto cartesian = ::math::geometry::cylindric2cartesian( point );
       auto result    = ::math::geometry::cartesian2cylindric( cartesian );
       return result;
      }

   }
 }

#endif
