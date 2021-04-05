#ifndef Dh_math_linear_matrix_scale
 #define Dh_math_linear_matrix_scale

 // ::math::linear::matrix::scale<scalar_name,width_number,height_number>

#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        void scale
         (
           ::math::linear::matrix::structure<scalar_name,width_number,height_number> & result
          ,scalar_name const& scalar
         )
         {
          for( unsigned i=0; i< height_number; i++ )
           for( unsigned j=0; j< width_number; j++ )
            {
             result[i][j] *= scalar;
            }
         }

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        void scale
         (
           ::math::linear::matrix::structure<scalar_name,width_number,height_number>      & result
          ,::math::linear::matrix::structure<scalar_name,width_number,height_number> const& left
          ,scalar_name const& right
         )
         {
          for( unsigned i=0; i< height_number; i++ )
           for( unsigned j=0; j< width_number; j++ )
            {
             result[i][j] = left[i][j] * right;
            }
         }

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        void scale
         (
           ::math::linear::matrix::structure<scalar_name,width_number,height_number>      & result
          ,scalar_name const& left
          ,::math::linear::matrix::structure<scalar_name,width_number,height_number> const& right
         )
         {
          for( unsigned i=0; i< height_number; i++ )
           for( unsigned j=0; j< width_number; j++ )
            {
             result[i][j] = left * right[i][j];
            }
         }

      }
    }
  }

#endif
