#ifndef math_library_linear_algebra__vector_rotate_HPP_
 #define math_library_linear_algebra__vector_rotate_HPP_

// math::linear::vector::rotate(  r, alpha, point ) //!< 2D
// math::linear::vector::rotate(  r, alpha, point, pivot ) //!< 2D
// math::linear::vector::rotate(  r, alpha ) //!< 2D
// math::linear::vector::rotateX( r, alpha, point, pivot ) ( r, alpha, point ) ( r, alpha ) //!< 3D
// math::linear::vector::rotateY( r, alpha, point, pivot ) ( r, alpha, point ) ( r, alpha ) //!< 3D
// math::linear::vector::rotateZ( r, alpha, point, pivot ) ( r, alpha, point ) ( r, alpha ) //!< 3D

// math::linear::vector::rotateA( r, point, axis, alpha )
// math::linear::vector::rotateA( r, point, axis, alpha, pivot )
// math::linear::vector::rotateA( r, axis, alpha )
// math::linear::vector::rotateA( r, axis, alpha, pivot )


#include "./structure.hpp"




 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, typename value_name >
        inline
        void
        rotate
         (
           ::math::linear::vector::structure< scalar_name, 2 >       & result_param
          ,       value_name                                    const& angle_param
          ,::math::linear::vector::structure< scalar_name, 2 >  const& point_param
         )
         {
          result_param[0] = point_param[0] * cos( angle_param ) - point_param[1] * sin( angle_param );
          result_param[1] = point_param[0] * sin( angle_param ) + point_param[1] * cos( angle_param );
         }

       template< typename scalar_name, typename value_name >
        inline
        void
        rotate
         (
           ::math::linear::vector::structure< scalar_name, 2 >       & result_param
          ,       value_name                                    const& angle_param
          ,::math::linear::vector::structure< scalar_name, 2 >  const& point_param
          ,::math::linear::vector::structure< scalar_name, 2 >  const& pivot_param
         )
         {
          result_param[0] = (point_param[0] - pivot_param[0]) * cos( angle_param ) - ( point_param[1] - pivot_param[1] ) * sin( angle_param ) + pivot_param[0];
          result_param[1] = (point_param[0] - pivot_param[0]) * sin( angle_param ) + ( point_param[1] - pivot_param[1] ) * cos( angle_param ) + pivot_param[1];
         }

       template< typename scalar_name, typename value_name >
        inline
        void
        rotate
         (
           ::math::linear::vector::structure< scalar_name, 2 >        & result_param
          ,                  value_name                          const&  angle_param
         )
         {
          ::math::linear::vector::structure< scalar_name, 2 > temp;
          ::math::linear::vector::rotate( temp, angle_param, result_param );
          result_param = temp;
         }

       template< typename scalar_name, typename value_name >
        inline
        void
        rotateX
         (
           ::math::linear::vector::structure< scalar_name, 3 >         & result_param
          ,       value_name                                      const&  angle_param
          ,::math::linear::vector::structure< scalar_name, 3 >    const&  point_param
          ,::math::linear::vector::structure< scalar_name, 3 >    const&  pivot_param
         )
        {
         ::math::linear::vector::structure< scalar_name, 3 > local;
         ::math::linear::vector::subtraction( local, point_param, pivot_param );

         result_param[0] = 1 * local[0] +                 0 * local[1] +                  0 * local[2] + pivot_param[0];
         result_param[1] = 0 * local[0] + cos( angle_param )* local[1] - sin( angle_param ) * local[2] + pivot_param[1];
         result_param[2] = 0 * local[0] + sin( angle_param )* local[1] + cos( angle_param ) * local[2] + pivot_param[2];
        }

       template< typename scalar_name, typename value_name >
        inline
        void
        rotateX
         (
           ::math::linear::vector::structure< scalar_name, 3 >         & result_param
          ,       value_name                                      const&  angle_param
          ,::math::linear::vector::structure< scalar_name, 3 >    const&  point_param
         )
        {
         result_param[0] = 1 * point_param[0] +                 0 * point_param[1] +                  0 * point_param[2];
         result_param[1] = 0 * point_param[0] + cos( angle_param )* point_param[1] - sin( angle_param ) * point_param[2];
         result_param[2] = 0 * point_param[0] + sin( angle_param )* point_param[1] + cos( angle_param ) * point_param[2];
        }

       template< typename scalar_name, typename value_name >
        inline
        void
        rotateX
         (
           ::math::linear::vector::structure< scalar_name, 3 >         & result_param
          ,       value_name                                      const&  angle_param
         )
        {
         ::math::linear::vector::structure< scalar_name, 3 > temp;
         ::math::linear::vector::rotateX( temp, angle_param, result_param );
         result_param = temp;
        }

       template< typename scalar_name, typename value_name >
        inline
        void
        rotateY
         (
           ::math::linear::vector::structure< scalar_name, 3 >         & result_param
          ,       value_name                                      const&  angle_param
          ,::math::linear::vector::structure< scalar_name, 3 >    const&  point_param
          ,::math::linear::vector::structure< scalar_name, 3 >    const&  pivot_param
         )
        {
         ::math::linear::vector::structure< scalar_name, 3 > local;
         ::math::linear::vector::subtraction( local, point_param, pivot_param );

         result_param[0] =  cos( angle_param ) * local[0] + 0 * local[1] + sin( angle_param )* local[2] + pivot_param[0];
         result_param[1] = 0                   * local[0] + 1 * local[1] +                 0 * local[2] + pivot_param[1];
         result_param[2] = -sin( angle_param ) * local[0] + 0 * local[1] + cos( angle_param )* local[2] + pivot_param[2];
        }

       template< typename scalar_name, typename value_name >
        inline
        void
        rotateY
         (
           ::math::linear::vector::structure< scalar_name, 3 >         & result_param
          ,       value_name                                      const&  angle_param
          ,::math::linear::vector::structure< scalar_name, 3 >    const&  point_param
         )
        {
         result_param[0] =  cos( angle_param ) * point_param[0] + 0 * point_param[1] + sin( angle_param )* point_param[2];
         result_param[1] = 0                   * point_param[0] + 1 * point_param[1] +                 0 * point_param[2];
         result_param[2] = -sin( angle_param ) * point_param[0] + 0 * point_param[1] + cos( angle_param )* point_param[2];
        }

       template< typename scalar_name, typename value_name >
        inline
        void
        rotateY
         (
           ::math::linear::vector::structure< scalar_name, 3 >         & result_param
          ,       value_name                         const&  angle_param
         )
        {
         ::math::linear::vector::structure< scalar_name, 3 > temp;
         ::math::linear::vector::rotateY( temp, angle_param, result_param );
         result_param = temp;
        }
       template< typename scalar_name, typename value_name >
        inline
        void
        rotateZ
         (
           ::math::linear::vector::structure< scalar_name, 3 >         & result_param
          ,       value_name                                      const&  angle_param
          ,::math::linear::vector::structure< scalar_name, 3 >    const&  point_param
          ,::math::linear::vector::structure< scalar_name, 3 >    const&  pivot_param
         )
        {
         ::math::linear::vector::structure< scalar_name, 3 > local;
         ::math::linear::vector::subtraction( local, point_param, pivot_param );

         result_param[0] = cos( angle_param ) * local[0] - sin( angle_param ) * local[1] - 0 * local[2] + pivot_param[0];
         result_param[1] = sin( angle_param ) * local[0] + cos( angle_param ) * local[1] + 0 * local[2] + pivot_param[1];
         result_param[2] =                  0 * local[0] +                  0 * local[1] + 1 * local[2] + pivot_param[2];
        }

       template< typename scalar_name, typename value_name >
        inline
        void
        rotateZ
         (
           ::math::linear::vector::structure< scalar_name, 3 >         & result_param
          ,       value_name                                      const&  angle_param,
           ::math::linear::vector::structure< scalar_name, 3 >    const&  point_param
         )
        {
         result_param[0] = cos( angle_param ) * point_param[0] - sin( angle_param ) * point_param[1] + 0 * point_param[2];
         result_param[1] = sin( angle_param ) * point_param[0] + cos( angle_param ) * point_param[1] + 0 * point_param[2];
         result_param[2] =                  0 * point_param[0] +                  0 * point_param[1] + 1 * point_param[2];
        }

       template< typename scalar_name, typename value_name >
        inline
        void
        rotateZ
         (
           ::math::linear::vector::structure< scalar_name, 3 >         & result_param
          ,       value_name                                      const&  angle_param
         )
        {
         ::math::linear::vector::structure< scalar_name, 3 > temp;
         ::math::linear::vector::rotateZ( temp, angle_param, result_param );
         result_param = temp;
        }

       template< typename scalar_name >
        inline
        void
        rotateA
         (
           ::math::linear::vector::structure< scalar_name, 3 >         & result_param
          ,::math::linear::vector::structure< scalar_name, 3 >    const& point_param
          ,::math::linear::vector::structure< scalar_name, 3 >    const& axis_param   //!< expect unit vector
          ,scalar_name                                            const& alpha_param
         )
         {
          scalar_name cosA = cos( alpha_param );
          scalar_name sinA = sin( alpha_param );

          scalar_name const& Ax = axis_param[0];
          scalar_name const& Ay = axis_param[1];
          scalar_name const& Az = axis_param[2];

          scalar_name a11 = Ax*Ax*( 1 - cosA ) +    cosA,  a12 = Ay*Ax*( 1 - cosA) - Az*sinA,  a13 = Az*Ax*( 1 - cosA) + Ay*sinA;
          scalar_name a21 = Ax*Ay*( 1 - cosA ) + Az*sinA,  a22 = Ay*Ay*( 1 - cosA) +    cosA,  a23 = Az*Ay*( 1 - cosA) - Ax*sinA;
          scalar_name a31 = Ax*Az*( 1 - cosA ) - Ay*sinA,  a32 = Ay*Az*( 1 - cosA) + Ax*sinA,  a33 = Az*Az*( 1 - cosA) +    cosA;

          result_param[0] =  a11 * point_param[0] + a12 * point_param[1] + a13 * point_param[2];
          result_param[1] =  a21 * point_param[0] + a22 * point_param[1] + a23 * point_param[2];
          result_param[2] =  a31 * point_param[0] + a32 * point_param[1] + a33 * point_param[2];
         }

       template< typename scalar_name >
        inline
        void
        rotateA
         (
           ::math::linear::vector::structure< scalar_name, 3 >         & result_param
          ,::math::linear::vector::structure< scalar_name, 3 >    const& point_param
          ,::math::linear::vector::structure< scalar_name, 3 >    const& axis_param
          ,scalar_name                                            const& alpha_param   //!< expect unit vector
          ,::math::linear::vector::structure< scalar_name, 3 >    const& pivot_param
         )
         {
          ::math::linear::vector::structure< scalar_name, 3 > ground;
          ::math::linear::vector::subtraction( ground, point_param, pivot_param );

          ::math::linear::vector::rotateA( result_param, ground, axis_param, alpha_param );

          ::math::linear::vector::addition( result_param, pivot_param );
         }

       template< typename scalar_name >
        inline
        void
        rotateA
         (
           ::math::linear::vector::structure< scalar_name, 3 >         & result_param
          ,::math::linear::vector::structure< scalar_name, 3 >    const& axis_param      //!< expect unit vector
          ,scalar_name                                            const& alpha_param
         )
         {
          ::math::linear::vector::structure< scalar_name, 3 > temp;
          ::math::linear::vector::rotateA( temp, result_param, axis_param, alpha_param );
          result_param = temp;
         }
       template< typename scalar_name >
        inline
        void
        rotateA
         (
           ::math::linear::vector::structure< scalar_name, 3 >         & result_param
          ,::math::linear::vector::structure< scalar_name, 3 >    const& axis_param      //!< expect unit vector
          ,scalar_name                                            const& alpha_param
          ,::math::linear::vector::structure< scalar_name, 3 >    const& pivot_param
         )
         {
          ::math::linear::vector::structure< scalar_name, 3 > temp;
          ::math::linear::vector::rotateA( temp, result_param, axis_param, alpha_param, pivot_param );
          result_param = temp;
         }

      }
    }
  }

#endif
