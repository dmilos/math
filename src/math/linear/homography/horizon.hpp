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
         return ::math::geometry::direction::ABC2D<>( display2space[2][0], display2space[2][1], display2space[2][2] );
        }

      template<  typename scalar_name >
       ::math::geometry::direction::ABC2D<scalar_name> horizon_invert
        (
          ::math::linear::vector::structure<      scalar_name, 3 >         & result_in_display
         ,::math::linear::homography::structure<  scalar_name, 2 >    const& space2display
        )
        {
         //::math::linear::vector::structure< scalar_name, 3 > X;
         //::math::linear::vector::structure< scalar_name, 3 > Y;
         //::math::linear::vector::load( X, space2display[0][0], space2display[0][1], space2display[0][2] );
         //::math::linear::vector::load( Y, space2display[1][0], space2display[1][1], space2display[1][2] );
         //::math::geometry::direction::ABC2D<scalar_name> result;
         //
         //::math::linear::vector::cross( result.vector(), X, Y );
         //return result;

         ::math::linear::homography::structure<  scalar_name, 2 > display2space;
         ::math::linear::matrix::invert( display2space, space2display );
         return ::math::linear::homography::horizon( result_in_display, display2space );
       }

     }
   }
 }

#endif
