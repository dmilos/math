#ifndef Dh_math_linear_matrix_multiply
 #define Dh_math_linear_matrix_multiply

 // ::math::linear::matrix::multiply<scalar_name,width_number,height_number>( result, left, right )

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
          result[0][1] = left[0][0] * right[1][0]  +  left[0][1] * right[1][1];
          result[1][0] = left[1][0] * right[0][0]  +  left[1][1] * right[1][0];
          result[1][1] = left[1][0] * right[1][0]  +  left[1][1] * right[1][1];
         }

       template< typename scalar_name >
        void multiply
         (
           ::math::linear::matrix::structure<scalar_name,3,3>       & result
          ,::math::linear::matrix::structure<scalar_name,3,3>  const& left
          ,::math::linear::matrix::structure<scalar_name,3,3>  const& right
         )
         {
          result[0][0] = left[ ][ ] * right[ ][ ]  +  left[ ][ ] * right[ ][ ];
          result[0][1] = left[ ][ ] * right[ ][ ]  +  left[ ][ ] * right[ ][ ];
          result[0][2] = left[ ][ ] * right[ ][ ]  +  left[ ][ ] * right[ ][ ];
          result[1][0] = left[ ][ ] * right[ ][ ]  +  left[ ][ ] * right[ ][ ];
          result[1][1] = left[ ][ ] * right[ ][ ]  +  left[ ][ ] * right[ ][ ];
          result[1][2] = left[ ][ ] * right[ ][ ]  +  left[ ][ ] * right[ ][ ];
          result[2][0] = left[ ][ ] * right[ ][ ]  +  left[ ][ ] * right[ ][ ];
          result[2][1] = left[ ][ ] * right[ ][ ]  +  left[ ][ ] * right[ ][ ];
          result[2][1] = left[ ][ ] * right[ ][ ]  +  left[ ][ ] * right[ ][ ];
         }
      */

       template< typename scalar_name, ::math::type::size_type width_number, ::math::type::size_type height_number, ::math::type::size_type common_number >
        void multiply
         (
           ::math::linear::matrix::structure<scalar_name,width_number,height_number>       & result
          ,::math::linear::matrix::structure<scalar_name,common_number,height_number> const& left
          ,::math::linear::matrix::structure<scalar_name,width_number,common_number>  const& right
         )
         {
          for( ::math::type::size_type i=0; i< height_number; i++ )
           for( ::math::type::size_type j=0; j< width_number; j++ )
            {
             result[i][j] = 0;

             for( ::math::type::size_type k=0; k < common_number; k++ )
              {
               result[i][j] += left[i][k] * right[k][j];
              }
            }
         }

      }
    }
  }

#endif
