#ifndef Dh_math_linear_matrix_column
 #define Dh_math_linear_matrix_column

 // ::math::linear::matrix::column<scalar_name,width_number,height_number>

#include "./structure.hpp"


 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        void column
         (
           ::math::linear::vector::structure<scalar_name, height_number>                     & c
          ,::math::linear::matrix::structure<scalar_name, width_number, height_number > const& m
          , std::size_t                                                                 const& index
         )
         {
          for( std::size_t i=0; i < height_number; ++i )
           {
            c[ i ] = m[ i ][ index ];
           }
         }

      }
    }
  }

#endif
