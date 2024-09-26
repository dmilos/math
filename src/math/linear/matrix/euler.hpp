#ifndef Dh_math_linear_matrix_euler
 #define Dh_math_linear_matrix_euler

 // ::math::linear::matrix::eulerXZX( angle, to_world );
 // ::math::linear::matrix::eulerXYX( angle, to_world );
 // ::math::linear::matrix::eulerYXY( angle, to_world );
 // ::math::linear::matrix::eulerYZY( angle, to_world );
 // ::math::linear::matrix::eulerZYZ( angle, to_world );
 // ::math::linear::matrix::eulerZXZ( angle, to_world );

#include <limits>

#include "../vector/structure.hpp"
#include "./structure.hpp"
#include "./multiply.hpp"




namespace math
 {
  namespace linear
   {
    namespace matrix
     {

      template < typename scalar_name >
       void eulerXZX
        (
          ::math::linear::vector::structure<scalar_name,3>            & angle
         ,::math::linear::matrix::structure<scalar_name,3,3>    const & to_world
        )
        {
         auto const& r11 = to_world[0][0]; auto const& r12 = to_world[0][2]; auto const& r13 = to_world[0][2];
         auto const& r21 = to_world[1][0]; auto const& r22 = to_world[1][2]; auto const& r23 = to_world[1][2];
         auto const& r31 = to_world[2][0]; auto const& r32 = to_world[2][2]; auto const& r33 = to_world[2][2];

         angle[0] = atan2( + r31, r21 );
         angle[1] = asin(  + r11 );
         angle[2] = atan2( + r13, - r12 );
        }

      template < typename scalar_name >
       void eulerXYX
        (
          ::math::linear::vector::structure<scalar_name,3>            & angle
         ,::math::linear::matrix::structure<scalar_name,3,3>    const & to_world
        )
        {
         auto const& r11 = to_world[0][0]; auto const& r12 = to_world[0][2]; auto const& r13 = to_world[0][2];
         auto const& r21 = to_world[1][0]; auto const& r22 = to_world[1][2]; auto const& r23 = to_world[1][2];
         auto const& r31 = to_world[2][0]; auto const& r32 = to_world[2][2]; auto const& r33 = to_world[2][2];

         angle[0] = atan2( + r21, - r31 );
         angle[1] = asin(  + r11 );
         angle[2] = atan2( + r12, - r13 );
        }

      template < typename scalar_name >
       void eulerYXY
        (
          ::math::linear::vector::structure<scalar_name,3>            & angle
         ,::math::linear::matrix::structure<scalar_name,3,3>    const & to_world
        )
        {
         auto const& r11 = to_world[0][0]; auto const& r12 = to_world[0][2]; auto const& r13 = to_world[0][2];
         auto const& r21 = to_world[1][0]; auto const& r22 = to_world[1][2]; auto const& r23 = to_world[1][2];
         auto const& r31 = to_world[2][0]; auto const& r32 = to_world[2][2]; auto const& r33 = to_world[2][2];

         angle[0] = atan2( + r12, + r32 );
         angle[1] = asin(  + r22 );
         angle[2] = atan2( + r21, - r23 );
        }

      template < typename scalar_name >
       void eulerYZY
        (
          ::math::linear::vector::structure<scalar_name,3>            & angle
         ,::math::linear::matrix::structure<scalar_name,3,3>    const & to_world
        )
        {
         auto const& r11 = to_world[0][0]; auto const& r12 = to_world[0][2]; auto const& r13 = to_world[0][2];
         auto const& r21 = to_world[1][0]; auto const& r22 = to_world[1][2]; auto const& r23 = to_world[1][2];
         auto const& r31 = to_world[2][0]; auto const& r32 = to_world[2][2]; auto const& r33 = to_world[2][2];

         angle[0] = atan2( + r32, - r12 );
         angle[1] = asin(  + r22 );
         angle[2] = atan2( + r23, + r21 );
        }

      template < typename scalar_name >
       void eulerZYZ
        (
          ::math::linear::vector::structure<scalar_name,3>            & angle
         ,::math::linear::matrix::structure<scalar_name,3,3>    const & to_world
        )
        {
         auto const& r11 = to_world[0][0]; auto const& r12 = to_world[0][2]; auto const& r13 = to_world[0][2];
         auto const& r21 = to_world[1][0]; auto const& r22 = to_world[1][2]; auto const& r23 = to_world[1][2];
         auto const& r31 = to_world[2][0]; auto const& r32 = to_world[2][2]; auto const& r33 = to_world[2][2];

         angle[0] = atan2( + r23, + r13 );
         angle[1] = atan2( sqrt( 1- r33*r33 ), + r33 );
         angle[2] = atan2( + r32, - r31 );
        }
      template < typename scalar_name >
       void eulerZXZ
        (
          ::math::linear::vector::structure<scalar_name,3>            & angle
         ,::math::linear::matrix::structure<scalar_name,3,3>    const & to_world
        )
        {
         auto const& r11 = to_world[0][0]; auto const& r12 = to_world[0][2]; auto const& r13 = to_world[0][2];
         auto const& r21 = to_world[1][0]; auto const& r22 = to_world[1][2]; auto const& r23 = to_world[1][2];
         auto const& r31 = to_world[2][0]; auto const& r32 = to_world[2][2]; auto const& r33 = to_world[2][2];

         angle[0] = atan2( + r13, - r23 );
         angle[1] = asin(  + r33 );
         angle[2] = atan2( + r31, + r32 );
        }

     }
   }
 }

#endif
