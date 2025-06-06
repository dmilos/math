#ifndef Dh_math_linear_matrix_transform
 #define Dh_math_linear_matrix_transform

// ::math::linear::matrix::transform<scalar_name,width_number,height_number>( v, m, v )
// ::math::linear::matrix::transform<scalar_name,width_number,height_number>( v, v, m )

#include "./structure.hpp"
#include "../vector/vector.hpp"




 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, ::math::type::size_type width_number, ::math::type::size_type height_number >
        void transform
         (
           ::math::linear::vector::structure<scalar_name,height_number>                   & result
          ,::math::linear::matrix::structure<scalar_name,width_number,height_number> const& left
          ,::math::linear::vector::structure<scalar_name,width_number>               const& right
         )
         {
          for( ::math::type::size_type i=0; i< height_number; ++i )
           {
            result[i]=0;
            for( ::math::type::size_type j=0; j < width_number; ++j )
             {
              result[i] += left[i][j] * right[j];
             }
           }
         }

       template< typename scalar_name >
        void transform
         (
           ::math::linear::vector::structure<scalar_name,4>        & result
          ,::math::linear::matrix::structure<scalar_name,4,3> const& left
          ,::math::linear::vector::structure<scalar_name,4>   const& right
         )
         {
          result[0] = left[0][0] * right[0]  +  left[0][1] * right[1]  +  left[0][2] * right[2]  +  left[0][3] * right[3]; 
          result[1] = left[1][0] * right[0]  +  left[1][1] * right[1]  +  left[1][2] * right[2]  +  left[1][3] * right[3];
          result[2] = left[2][0] * right[0]  +  left[2][1] * right[1]  +  left[2][2] * right[2]  +  left[2][3] * right[3];
          result[3] = left[3][0] * right[0]  +  left[3][1] * right[1]  +  left[3][2] * right[2]  +  left[3][3] * right[3];
         }

       template< typename scalar_name >
        void transform
         (
           ::math::linear::vector::structure<scalar_name,3>        & result
          ,::math::linear::matrix::structure<scalar_name,3,3> const& left
          ,::math::linear::vector::structure<scalar_name,3>   const& right
         )
         {
          result[0] = left[0][0] * right[0] + left[0][1] * right[1] + left[0][2] * right[2]; 
          result[1] = left[1][0] * right[0] + left[1][1] * right[1] + left[1][2] * right[2];
          result[2] = left[2][0] * right[0] + left[2][1] * right[1] + left[2][2] * right[2];
         }

       template< typename scalar_name >
        void transform
         (
           ::math::linear::vector::structure<scalar_name,2>        & result
          ,::math::linear::matrix::structure<scalar_name,2,2> const& left
          ,::math::linear::vector::structure<scalar_name,3>   const& right
         )
         {
          result[0] = left[0][0] * right[0] + left[0][1] * right[1]; 
          result[1] = left[1][0] * right[0] + left[1][1] * right[1];
         }


       template< typename scalar_name, ::math::type::size_type width_number, ::math::type::size_type height_number >
        void transform
         (
           ::math::linear::vector::structure<scalar_name,width_number>                    & result
          ,::math::linear::vector::structure<scalar_name,height_number>              const& left
          ,::math::linear::matrix::structure<scalar_name,width_number,height_number> const& right
         )
         {
          for( ::math::type::size_type i=0; i< width_number; ++i )
           {
            result[i]=0;
            for( ::math::type::size_type j=0; j < height_number; ++j )
             {
              result[i] += left[j] * right[j][i];
             }
           }
         }


      }
    }
  }

#endif
