#ifndef math_geometry_direction_vanish
#define math_geometry_direction_vanish

 // ::math::geometry::direction::vanish<scalar_name,dimension_number>


#include "../../linear/affine/transform.hpp"
#include "./two.hpp"
#include "./parametric.hpp"


namespace math
 {
  namespace geometry
   {
    namespace direction
     {

       template< typename scalar_name >
        bool vanish
         (
           ::math::linear::vector::structure<scalar_name,3>              & result    //!< in homography cordinates
          ,::math::geometry::direction::parametric<scalar_name,3>  const & direction
         ) //!< vanis point regarding planeX=((1,0,0),(1,0,0)) or planeY=((0,1,0),(0,1,0)) or planeZ=((0,0,1),(0,0,1))
         {
          result = direction.direction();
          return true;
         }

      }
    }
  }

#endif