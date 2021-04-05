#ifndef math_geometry_polar2cartesian
#define math_geometry_polar2cartesian

 // ::math::geometry::polar2cartesian( )

#include "../linear/vector/structure.hpp"

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name >
     ::math::linear::vector::point<scalar_name,2>
     polar2cartesian( ::math::linear::vector::point<scalar_name,2> const& point )
      { // ( r, phi ) -> (  x, y )
       ::math::linear::vector::point<scalar_name,2> result;
        result[0] = point[0] * cos( point[1] );
        result[1] = point[0] * sin( point[1] );
       return result;
      }

   }
 }

#endif
