#ifndef Dh_math_linear_matrix_negate
 #define Dh_math_linear_matrix_negate

 // ::math::linear::matrix::negate<scalar_name,width_number,height_number>

#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        void negate
         (
           ::math::linear::matrix::structure<scalar_name,width_number,height_number> & result
          ,scalar_name const& scalar
         )
         {
          for( unsigned i=0; i< height_number; i++ )
           for( unsigned j=0; j< width_number; j++ )
            {
             result[i][j] = - result[i][j];
            }
         }

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        void negate
         (
           ::math::linear::matrix::structure<scalar_name,width_number,height_number>      & result
          ,::math::linear::matrix::structure<scalar_name,width_number,height_number> const& left
          ,scalar_name const& right
         )
         {
          for( unsigned i=0; i< height_number; i++ )
           for( unsigned j=0; j< width_number; j++ )
            {
             result[i][j] = - left[i][j];
            }
         }

      }
    }
  }

#endif
