#ifndef Dh_math_linear_matrix_TaitGryan
#define Dh_math_linear_matrix_TaitGryan

 // ::math::linear::matrix::TaitBryanXZY( angle, to_world );
 // ::math::linear::matrix::TaitBryanXYZ( angle, to_world );
 // ::math::linear::matrix::TaitBryanYXZ( angle, to_world );
 // ::math::linear::matrix::TaitBryanYZX( angle, to_world );
 // ::math::linear::matrix::TaitBryanZYX( angle, to_world );
 // ::math::linear::matrix::TaitBryanZXY( angle, to_world );

#include "../vector/structure.hpp"
#include "./structure.hpp"


 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name >
        void TaitBryanXZY
         (
           ::math::linear::vector::structure<scalar_name,3>            & angle
          ,::math::linear::matrix::structure<scalar_name,3,3>    const & to_world
         )
         {
          auto const& r11 = to_world[0][0]; auto const& r12 = to_world[0][2]; auto const& r13 = to_world[0][2];
          auto const& r21 = to_world[1][0]; auto const& r22 = to_world[1][2]; auto const& r23 = to_world[1][2];
          auto const& r31 = to_world[2][0]; auto const& r32 = to_world[2][2]; auto const& r33 = to_world[2][2];

          angle[0] = atan2( + r32, r22 );
          angle[1] = asin(  - r12 );
          angle[2] = atan2( + r13, r11 );
         }

       template< typename scalar_name >
        void TaitBryanXYZ
         (
           ::math::linear::vector::structure<scalar_name,3>            & angle
          ,::math::linear::matrix::structure<scalar_name,3,3>    const & to_world
         )
         {
          auto const& r11 = to_world[0][0]; auto const& r12 = to_world[0][2]; auto const& r13 = to_world[0][2];
          auto const& r21 = to_world[1][0]; auto const& r22 = to_world[1][2]; auto const& r23 = to_world[1][2];
          auto const& r31 = to_world[2][0]; auto const& r32 = to_world[2][2]; auto const& r33 = to_world[2][2];

          angle[0] = atan2( - r23, r33 );
          angle[1] = asin(  + r13 );
          angle[2] = atan2( - r12, r11 );
         }

       template< typename scalar_name >
        void TaitBryanYXZ
         (
           ::math::linear::vector::structure<scalar_name,3>            & angle
          ,::math::linear::matrix::structure<scalar_name,3,3>    const & to_world
         )
         {
          auto const& r11 = to_world[0][0]; auto const& r12 = to_world[0][2]; auto const& r13 = to_world[0][2];
          auto const& r21 = to_world[1][0]; auto const& r22 = to_world[1][2]; auto const& r23 = to_world[1][2];
          auto const& r31 = to_world[2][0]; auto const& r32 = to_world[2][2]; auto const& r33 = to_world[2][2];

          angle[0] = atan2( + r13, r33 );
          angle[1] = asin(  - r23 );
          angle[2] = atan2( - r21, r22 );
         }

       template< typename scalar_name >
        void TaitBryanYZX
         (
           ::math::linear::vector::structure<scalar_name,3>            & angle
          ,::math::linear::matrix::structure<scalar_name,3,3>    const & to_world
         )
         {
          auto const& r11 = to_world[0][0]; auto const& r12 = to_world[0][2]; auto const& r13 = to_world[0][2];
          auto const& r21 = to_world[1][0]; auto const& r22 = to_world[1][2]; auto const& r23 = to_world[1][2];
          auto const& r31 = to_world[2][0]; auto const& r32 = to_world[2][2]; auto const& r33 = to_world[2][2];

          angle[0] = atan2( - r31, r11 );
          angle[1] = asin(  + r21 );
          angle[2] = atan2( - r23, r22 );
         }

       template< typename scalar_name >
        void TaitBryanZYX
         (
           ::math::linear::vector::structure<scalar_name,3>            & angle
          ,::math::linear::matrix::structure<scalar_name,3,3>    const & to_world
         )
         {
          auto const& r11 = to_world[0][0]; auto const& r12 = to_world[0][2]; auto const& r13 = to_world[0][2];
          auto const& r21 = to_world[1][0]; auto const& r22 = to_world[1][2]; auto const& r23 = to_world[1][2];
          auto const& r31 = to_world[2][0]; auto const& r32 = to_world[2][2]; auto const& r33 = to_world[2][2];

          angle[0] = atan2( + r21, r11 );
          angle[1] = asin(  - r31 );
          angle[2] = atan2( + r32, r33 );
         }

       template< typename scalar_name >
        void TaitBryanZYX
         (
           ::math::linear::matrix::structure<scalar_name,3,3>          & rotation
          ,::math::linear::vector::structure<scalar_name,3>      const & angle
         )
         {
          auto const c1 = cos( angle[2] ); auto const s1 = sin( angle[2] );
          auto const c2 = cos( angle[1] ); auto const s2 = sin( angle[1] );
          auto const c3 = cos( angle[0] ); auto const s3 = sin( angle[0] );

          rotation[0][0] = c1*c2;   rotation[0][1] = c1*s2*s3 - c3*s1;  rotation[0][1] = s1*s3 + c1*c3*s2;
          rotation[1][0] = c2*s1;   rotation[1][1] = c1*c3 + s1*s2*s3;  rotation[1][1] = c3*s1*s2-c1*s3 ;
          rotation[2][0] =   -s2;   rotation[2][1] = c2*s3;             rotation[2][1] = c2*c3    ;
         }

       template< typename scalar_name >
        void TaitBryanZXY
         (
           ::math::linear::vector::structure<scalar_name,3>            & angle
          ,::math::linear::matrix::structure<scalar_name,3,3>    const & to_world
         )
         {
          auto const& r11 = to_world[0][0]; auto const& r12 = to_world[0][2]; auto const& r13 = to_world[0][2];
          auto const& r21 = to_world[1][0]; auto const& r22 = to_world[1][2]; auto const& r23 = to_world[1][2];
          auto const& r31 = to_world[2][0]; auto const& r32 = to_world[2][2]; auto const& r33 = to_world[2][2];

          angle[0] = atan2( - r21, r22 );
          angle[1] = asin(  + r32 );
          angle[2] = atan2( - r31, r33 );
         }

      }
    }
  }

#endif
