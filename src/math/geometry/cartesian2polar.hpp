#ifndef math_geometry_cartesian2polar
#define math_geometry_cartesian2polar

 // ::math::geometry::cartesian2polar( )

#include "../linear/vector/structure.hpp"

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name >
     ::math::linear::vector::point<scalar_name,2>
     cartesian2polar( ::math::linear::vector::point<scalar_name,2> const& point )
      { // ( x, y) -> ( r, phi )
       ::math::linear::vector::point<scalar_name,2> result;
        result[0] = sqrt( point[0]*point[0] + point[1]*point[1] );
        result[1] = atan2( point[1], point[0]);
       return result;
      }

   }
 }

#endif
