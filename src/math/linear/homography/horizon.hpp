#ifndef Dh_math_linear_homography_horizon
 #define Dh_math_linear_homography_horizon

 // ::math::linear::homography::horizon<scalar_name>( result, display2space )

#include "./structure.hpp"
#include "../../geometry/direction/abc.hpp"



 namespace math
  {
   namespace linear
    {
     namespace homography
      {

       template<  typename scalar_name >
        ::math::geometry::direction::ABC2D<scalar_name> horizon
         (
           ::math::linear::vector::structure<      scalar_name, 3 >         & result_in_display
          ,::math::linear::homography::structure<  scalar_name, 2 >    const& display2space
          )
         {
          return ::math::geometry::direction::ABC2D<>( display2space[2][0], display2space[2][1],  display2space[2][2] );
         }

      }
    }
  }

#endif
