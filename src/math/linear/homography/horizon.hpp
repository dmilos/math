#ifndef Dh_math_linear_homography_horizon
#define Dh_math_linear_homography_horizon

 // ::math::linear::homography::horizon<scalar_name>( result, display2space )

#include "./structure.hpp"
#include "../matrix/row.hpp"
#include "../vector/cross.hpp"
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
          ::math::geometry::direction::ABC2D<>                             & result_in_display
         ,::math::linear::homography::structure<  scalar_name, 2 >    const& display2plane
        )
        {  //! display = N(0,0,1) + O(0,0,0)
         ::math::linear::matrix::row( result_in_display.array(), display2plane, 2 );
         return result_in_display;
        }

      template<  typename scalar_name >
       void horizon_invert
        (
          ::math::geometry::direction::ABC2D<>                             & result_in_display
         ,::math::linear::homography::structure<  scalar_name, 2 >    const& plane2display
        )
        {   //! display = N(0,0,1) + O(0,0,0)
         ::math::linear::vector::structure<  scalar_name, 3 > X; ::math::linear::matrix::column( X, plane2display, 0 );
         ::math::linear::vector::structure<  scalar_name, 3 > Y; ::math::linear::matrix::column( Y, plane2display, 1 );
         ::math::linear::vector::cross( result_in_display.array(), X, Y );
        }

     }
   }
 }

#endif
