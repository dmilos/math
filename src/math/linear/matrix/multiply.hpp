#ifndef Dh_math_linear_matrix_multiply
 #define Dh_math_linear_matrix_multiply

 // ::math::linear::matrix::multiply<scalar_name,width_number,height_number>

#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, unsigned width_number, unsigned height_number, unsigned common_number >
        void multiply
         (
           ::math::linear::matrix::structure<scalar_name,width_number,height_number>      & result
          ,::math::linear::matrix::structure<scalar_name,common_number,height_number> const& left
          ,::math::linear::matrix::structure<scalar_name,width_number,common_number> const& right
         )
         {
          for( unsigned i=0; i< height_number; i++ )
           for( unsigned j=0; j< width_number; j++ )
            {
             result[i][j] = 0;

             for( unsigned k=0; k < common_number; k++ )
              {
               result[i][j] += left[i][k] * right[k][j];
              }
            }
         }

      }
    }
  }

#endif
