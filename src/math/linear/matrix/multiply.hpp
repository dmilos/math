#ifndef Dh_math_linear_matrix_multiply
 #define Dh_math_linear_matrix_multiply

 // ::math::linear::matrix::multiply<scalar_name,width_number,height_number>( result, left, right )
 // ::math::linear::matrix::multiply<scalar_name,width,A,B,height>( result, left, middle, right )

#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

      /*
       template< typename scalar_name >
        void multiply
         (
           ::math::linear::matrix::structure<scalar_name,2,2>       & result
          ,::math::linear::matrix::structure<scalar_name,2,2>  const& left
          ,::math::linear::matrix::structure<scalar_name,2,2>  const& right
         )
         {
          result[0][0] = left[0][0] * right[0][0]  +  left[0][1] * right[1][0];
          result[0][1] = left[0][0] * right[0][1]  +  left[0][1] * right[1][1];
          result[1][0] = left[1][0] * right[0][0]  +  left[1][1] * right[1][0];
          result[1][1] = left[1][0] * right[0][1]  +  left[1][1] * right[1][1];
         }

       template< typename scalar_name >
        void multiply
         (
           ::math::linear::matrix::structure<scalar_name,3,3>       & result
          ,::math::linear::matrix::structure<scalar_name,3,3>  const& left
          ,::math::linear::matrix::structure<scalar_name,3,3>  const& right
         )
         {
          result[0][0] = left[0][0] * right[0][0]  +  left[0][1] * right[1][0]  +  left[0][2] * right[2][0];
          result[0][1] = left[0][0] * right[0][1]  +  left[0][1] * right[1][1]  +  left[0][2] * right[2][1];
          result[0][2] = left[0][0] * right[0][2]  +  left[0][1] * right[1][2]  +  left[0][2] * right[2][2];
          result[1][0] = left[1][0] * right[0][0]  +  left[1][1] * right[1][0]  +  left[1][2] * right[2][0];
          result[1][1] = left[1][0] * right[0][1]  +  left[1][1] * right[1][1]  +  left[1][2] * right[2][1];
          result[1][2] = left[1][0] * right[0][2]  +  left[1][1] * right[1][2]  +  left[1][2] * right[2][2];
          result[2][0] = left[2][0] * right[0][0]  +  left[2][1] * right[1][0]  +  left[2][2] * right[2][0];
          result[2][1] = left[2][0] * right[0][1]  +  left[2][1] * right[1][1]  +  left[2][2] * right[2][1];
          result[2][2] = left[2][0] * right[0][2]  +  left[2][1] * right[1][2]  +  left[2][2] * right[2][2];
         }
      */

       template< typename scalar_name, ::math::type::size_type width_number, ::math::type::size_type height_number, ::math::type::size_type common_number >
        void multiply
         (
           ::math::linear::matrix::structure<scalar_name,width_number,height_number>       & result
          ,::math::linear::matrix::structure<scalar_name,common_number,height_number> const& left
          ,::math::linear::matrix::structure<scalar_name,width_number,common_number>  const& right
         ) // ( a, H )*( W, a ) = ( H, W )
         {
          for( ::math::type::size_type i=0; i< height_number; i++ )
           for( ::math::type::size_type j=0; j< width_number; j++ )
            {
             result[i][j] = 0;

             for( ::math::type::size_type k=0; k < common_number; k++ )
              {
               result[i][j] += left[i][k] * right[k][j];
               // std::cout << "result[" << i << "][" << j << "] += left[" << i << "][" << k << "] * right[" << k << "][" << j << "]; " ;
              }
              //std::cout << std::endl;
            }
         }

       template
        <   typename scalar_name
         , ::math::type::size_type width_number
         , ::math::type::size_type A_number
         , ::math::type::size_type C_number
         , ::math::type::size_type height_number
        >
        void multiply
         (
           ::math::linear::matrix::structure<scalar_name,width_number,height_number>       & result
          ,::math::linear::matrix::structure<scalar_name,A_number,height_number>      const& left
          ,::math::linear::matrix::structure<scalar_name,C_number,A_number>           const& middle
          ,::math::linear::matrix::structure<scalar_name,width_number,C_number>       const& right
         )
         {
          ::math::linear::vector::structure<scalar_name,C_number>    temp;

          for( ::math::type::size_type i=0; i< height_number; i++ )
           for( ::math::type::size_type j=0; j< width_number; j++ )
            {

             for( ::math::type::size_type k=0; k < C_number; k++ )
              {
               temp[k] = 0;
               for( ::math::type::size_type l=0; l < A_number; l++ )
                {
                 temp[k] += left[i][l] * middle[l][k];
                }
              }

             result[i][j] = 0;
             for( ::math::type::size_type k=0; k < C_number; k++ )
              {
               result[i][j] += temp[k] * right[k][j];
              }
            }
         }

      }
    }
  }

#endif
