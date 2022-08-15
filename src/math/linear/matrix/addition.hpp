#ifndef Dh_math_linear_matrix_addition
 #define Dh_math_linear_matrix_addition

 // ::math::linear::matrix::addition<scalar_name,width_number,height_number>

#include "./structure.hpp"


 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, ::math::type::size_type width_number, ::math::type::size_type height_number >
        void addition
         (
           ::math::linear::matrix::structure<scalar_name,width_number,height_number>      & result
          ,::math::linear::matrix::structure<scalar_name,width_number,height_number> const& left
          ,::math::linear::matrix::structure<scalar_name,width_number,height_number> const& right
         )
         {
          for( ::math::type::size_type i=0; i< height_number; i++ )
           for( ::math::type::size_type j=0; j< width_number; j++ )
            {
             result[i][j] = left[i][j] + right[i][j];
            }
         }

       template< typename scalar_name, ::math::type::size_type width_number, ::math::type::size_type height_number >
        void addition
         (
           ::math::linear::matrix::structure<scalar_name,width_number,height_number>      & result
          ,::math::linear::matrix::structure<scalar_name,width_number,height_number> const& right
         )
         {
          for( ::math::type::size_type i=0; i< height_number; i++ )
           for( ::math::type::size_type j=0; j< width_number; j++ )
            {
             result[i][j] += right[i][j];
            }
         }
         
       template< typename scalar_name >
        void addition
         (
           ::math::linear::matrix::structure<scalar_name,2,2>      & result
          ,::math::linear::matrix::structure<scalar_name,2,2> const& right
         )
         {
          result[0][0] += right[0][0]; result[0][1] += right[0][1];
          result[1][0] += right[1][0]; result[1][1] += right[1][1];
         }

       template< typename scalar_name >
        void addition
         (
           ::math::linear::matrix::structure<scalar_name,3,3>      & result
          ,::math::linear::matrix::structure<scalar_name,3,3> const& right
         )
         {
          result[0][0] += right[0][0]; result[0][1] += right[0][1]; result[0][2] += right[0][2];
          result[1][0] += right[1][0]; result[1][1] += right[1][1]; result[1][2] += right[1][2];
          result[2][0] += right[2][0]; result[2][1] += right[2][1]; result[2][2] += right[2][2];
         }

       template< typename scalar_name >
        void addition
         (
           ::math::linear::matrix::structure<scalar_name,4,4>      & result
          ,::math::linear::matrix::structure<scalar_name,4,4> const& right
         )
         {
          result[0][0] += right[0][0]; result[0][1] += right[0][1]; result[0][2] += right[0][2]; result[0][3] += right[0][3];
          result[1][0] += right[1][0]; result[1][1] += right[1][1]; result[1][2] += right[1][2]; result[1][3] += right[1][3];
          result[2][0] += right[2][0]; result[2][1] += right[2][1]; result[2][2] += right[2][2]; result[2][3] += right[2][3];
          result[3][0] += right[3][0]; result[3][1] += right[3][1]; result[3][2] += right[3][2]; result[3][3] += right[3][3];
         }

      }
    }
  }

#endif
