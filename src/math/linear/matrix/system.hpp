#ifndef Dh_math_linear_matrix_system
#define Dh_math_linear_matrix_system

 // ::math::linear::matrix::system(m,x,y)
 // ::math::linear::matrix::system(m,x,y,z)
 // ::math::linear::matrix::system(m,x,y,z,t)

 // ::math::linear::matrix::system(x,y, m )
 // ::math::linear::matrix::system(x,y,z, m)
 // ::math::linear::matrix::system(x,y,z,t, m )

#include "../vector/vector.hpp"
#include "./structure.hpp"


 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name >
        void system
         (
           ::math::linear::matrix::structure<scalar_name,1,1>          & result
          ,::math::linear::vector::structure<scalar_name,1>      const & x
         )
         {
          result[0][0] = x[0];
         }

       template< typename scalar_name >
        void system
         (
           ::math::linear::vector::structure<scalar_name,1>                 & x
          ,::math::linear::matrix::structure<scalar_name,1,1>    const      & m
         )
         {
          x[0] = m[0][0];
         }


       template< typename scalar_name >
        void system
         (
           ::math::linear::matrix::structure<scalar_name,2,2>          & result
          ,::math::linear::vector::structure<scalar_name,2>      const & x
          ,::math::linear::vector::structure<scalar_name,2>      const & y
         )
         {
          result[0][0] = x[0]; result[0][1] = y[0];
          result[1][0] = x[1]; result[1][1] = y[1];
         }


       template< typename scalar_name >
        void system
         (
           ::math::linear::vector::structure<scalar_name,2>            & x
          ,::math::linear::vector::structure<scalar_name,2>            & y
          ,::math::linear::matrix::structure<scalar_name,2,2>    const & m
         )
         {
          x[0] = m[0][0]; y[0] = m[0][1];
          x[1] = m[1][0]; y[1] = m[1][1];
         }

       template< typename scalar_name >
        void system
         (
           ::math::linear::matrix::structure<scalar_name,3,3>          & result
          ,::math::linear::vector::structure<scalar_name,3>      const & x
          ,::math::linear::vector::structure<scalar_name,3>      const & y
          ,::math::linear::vector::structure<scalar_name,3>      const & z
         )
         {
          result[0][0] = x[0]; result[0][1] = y[0]; result[0][2] = z[0];
          result[1][0] = x[1]; result[1][1] = y[1]; result[1][2] = z[1];
          result[2][0] = x[2]; result[2][1] = y[2]; result[2][2] = z[2];
         }

       template< typename scalar_name >
        void system
         (
           ::math::linear::vector::structure<scalar_name,3>           & x
          ,::math::linear::vector::structure<scalar_name,3>           & y
          ,::math::linear::vector::structure<scalar_name,3>           & z
          ,::math::linear::matrix::structure<scalar_name,3,3>  const  & m
         )
         {
          x[0] = m[0][0]; y[0] = m[0][1]; z[0] = m[0][2];
          x[1] = m[1][0]; y[1] = m[1][1]; z[1] = m[1][2];
          x[2] = m[2][0]; y[2] = m[2][1]; z[2] = m[2][2];
         }

       template< typename scalar_name >
        void system
         (
           ::math::linear::matrix::structure<scalar_name,4,4>          & result
          ,::math::linear::vector::structure<scalar_name,4>      const & x
          ,::math::linear::vector::structure<scalar_name,4>      const & y
          ,::math::linear::vector::structure<scalar_name,4>      const & z
          ,::math::linear::vector::structure<scalar_name,4>      const & t
         )
         {
          result[0][0] = x[0]; result[0][1] = y[0]; result[0][2] = z[0]; result[0][3] = t[0];
          result[1][0] = x[1]; result[1][1] = y[1]; result[1][2] = z[1]; result[1][3] = t[1];
          result[2][0] = x[2]; result[2][1] = y[2]; result[2][2] = z[2]; result[2][3] = t[2];
          result[3][0] = x[3]; result[3][1] = y[3]; result[3][2] = z[3]; result[3][3] = t[3];
         }

       template< typename scalar_name >
        void system
         (
           ::math::linear::vector::structure<scalar_name,4>           & x
          ,::math::linear::vector::structure<scalar_name,4>           & y
          ,::math::linear::vector::structure<scalar_name,4>           & z
          ,::math::linear::vector::structure<scalar_name,4>           & t
          ,::math::linear::matrix::structure<scalar_name,4,4>  const  & m
         )
         {
          x[0] = m[0][0]; y[0] = m[0][1]; z[0] = m[0][2]; t[0] = m[0][3];
          x[1] = m[1][0]; y[1] = m[1][1]; z[1] = m[1][2]; t[1] = m[1][3];
          x[2] = m[2][0]; y[2] = m[2][1]; z[2] = m[2][2]; t[2] = m[2][3];
          x[3] = m[3][0]; y[3] = m[3][1]; z[3] = m[3][2]; t[3] = m[3][3];
         }


       template< typename scalar_name, unsigned dimension_number >
        void system
         (
           ::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number>                           & result
          ,std::array< ::math::linear::vector::structure<scalar_name,dimension_number>, dimension_number >      const & base
         )
         {
          for( unsigned i = 0; i < dimension_number; ++i )
           for( unsigned j = 0; j < dimension_number; ++j )
            {
             result[i][j] = base[j][i];
            }
         }


      }
    }
  }

#endif
