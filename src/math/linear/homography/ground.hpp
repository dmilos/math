#ifndef Dh_math_linear_homography_ground
#define Dh_math_linear_homography_ground

// ::math::linear::homography::ground<double>( point, plane2display );

#include "../vector/scale.hpp"
#include "../homography/structure.hpp"


namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template< typename scalar_name >
       bool ground
        (
          ::math::linear::vector::structure<scalar_name,3>          & point         //!< in homogenious coordinate
         ,::math::linear::homography::structure<scalar_name,2> const& plane2display
         ,scalar_name const& epsilon = 1e-6
        )
        { // display = N(0,0,1) + O(0,0,0)
         ::math::linear::vector::structure<  scalar_name, 3 > X; ::math::linear::matrix::column( X, plane2display, 0 );
         ::math::linear::vector::structure<  scalar_name, 3 > Y; ::math::linear::matrix::column( Y, plane2display, 1 );
         ::math::linear::vector::structure<  scalar_name, 3 > O; ::math::linear::matrix::column( O, plane2display, 2 );

         ::math::linear::vector::structure<  scalar_name, 3 > Z; ::math::linear::vector::cross( Z, X, Y );

         scalar_name dot_down = ::math::linear::vector::dot( Z, Z );
         if( fabs( dot_down ) < epsilon )
          {
           return false;
          }

         scalar_name dot_up = ::math::linear::vector::dot( O, Z );

         ::math::linear::vector::scale( point, dot_up / dot_down, Z );
         return true;
        }
 
     }
   }
 }

#endif
