#ifndef math_linear_matrix_rotate
 #define math_linear_matrix_rotate

// math::linear::matrix::rotate( result, angle )
// math::linear::matrix::rotate( result, direction, angle, epsilon )

#include "../vector/structure.hpp"
#include "./structure.hpp"


 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name>
        inline
        void
        rotate
         (
           ::math::linear::matrix::structure<scalar_name,2,2>      & result
          ,scalar_name                                        const& angle_param
         )
         {
          result[0][0] = cos( angle_param ); result[ 0 ][ 1 ] = -sin( angle_param );
          result[1][0] = sin( angle_param ); result[ 1 ][ 1 ] =  cos( angle_param );
         }

       template< typename scalar_name>
        inline
        void
        rotateX
         (
           ::math::linear::matrix::structure<scalar_name, 3, 3 >          & result
          ,                                   scalar_name            const& angle_param
         )
         {
          result[0][0] = 1;  result[0][1] =                  0 ; result[0][2] =  +                  0 ;
          result[1][0] = 0;  result[1][1] =  cos( angle_param ); result[1][2] =  - sin( angle_param ) ;
          result[2][0] = 0;  result[2][1] =  sin( angle_param ); result[2][2] =  + cos( angle_param ) ;
         }

       template< typename scalar_name>
        inline
        void
        rotateY
         (
           ::math::linear::matrix::structure<scalar_name, 3, 3 >          & result
          ,                                   scalar_name            const& angle_param
         )
         {
          result[0][0] = + cos( angle_param ); result[0][1] = 0; result[0][2] = + sin( angle_param );
          result[1][0] =                    0; result[1][1] = 1; result[1][2] =                   0 ;
          result[2][0] = - sin( angle_param ); result[2][1] = 0; result[2][2] = + cos( angle_param );
         }


       template< typename scalar_name>
        inline
        void
        rotateZ
         (
           ::math::linear::matrix::structure<scalar_name, 3, 3 >          & result
          ,                                   scalar_name            const& angle_param
         )
         {
          result[0][0] = + cos( angle_param ); result[0][1] = - sin( angle_param ); result[0][2] = + 0;
          result[1][0] = + sin( angle_param ); result[1][1] = + cos( angle_param ); result[1][2] = + 0;
          result[2][0] =                    0; result[2][1] = +                  0; result[2][2] = + 1;
         }

       template< typename scalar_name>
        inline
        bool
        rotate
         (
           ::math::linear::matrix::structure<scalar_name, 3, 3 >          & result
          ,::math::linear::vector::structure< scalar_name, 3 >       const& direction
          ,                                   scalar_name            const& angle_param
          ,                                   scalar_name            const& epsilon = 1e-12
         )
         {
          scalar_name ca, sa, jmca, vx2, vy2, vz2, vxvy, vxvz, vyvz;

          vx2 = direction[0] * direction[0];
          vy2 = direction[1] * direction[1];
          vz2 = direction[2] * direction[2];

          scalar_name I_len = std::sqrt( vx2 + vy2 + vz2 );
          if( ( -epsilon < I_len  ) && ( I_len < epsilon ) )
           {
            return false;
           }

          ::math::linear::vector::structure< scalar_name, 3 > I_dir( direction );
          ::math::linear::vector::scale( I_dir,  scalar_name(1)/I_len );

          ca = cos ( angle_param );
          sa = sin ( angle_param );
          jmca = 1 - ca;

          vxvy = I_dir[0] * I_dir[1];
          vxvz = I_dir[0] * I_dir[2];
          vyvz = I_dir[1] * I_dir[2];

          result[ 0 ][ 0 ] = vx2  + ( 1   -  vx2 ) * ca;
          result[ 0 ][ 1 ] = vxvy * jmca  -  I_dir[2] * sa;
          result[ 0 ][ 2 ] = vxvz * jmca  +  I_dir[1] * sa;
          result[ 1 ][ 0 ] = vxvy * jmca  +  I_dir[2] * sa;
          result[ 1 ][ 1 ] = vy2  + ( 1  -  vy2 ) * ca;
          result[ 1 ][ 2 ] = vyvz * jmca  -  I_dir[0] * sa;
          result[ 2 ][ 0 ] = vxvz * jmca  -  I_dir[1] * sa;
          result[ 2 ][ 1 ] = vyvz * jmca  +  I_dir[0] * sa;
          result[ 2 ][ 2 ] = vz2  + ( 1  -  vz2 ) * ca;

          return  true;
         }

     }
   }
 }

#endif