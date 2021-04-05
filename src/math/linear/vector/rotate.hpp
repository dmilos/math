#ifndef math_library_linear_algebra__vector_rotate_HPP_
 #define math_library_linear_algebra__vector_rotate_HPP_

// math::linear::vector::rotate(  r, alpha, point )
// math::linear::vector::rotate(  r, alpha, point, pivot )
// math::linear::vector::rotateX( r, alpha, point )
// math::linear::vector::rotateY( r, alpha, point )
// math::linear::vector::rotateZ( r, alpha, point )


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
          ,       value_name                       const& angle_param
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
          ,       value_name                       const& angle_param
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

      }
    }
  }

#endif
