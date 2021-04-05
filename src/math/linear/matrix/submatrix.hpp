#ifndef Dh_math_linear_matrix_submatrix
 #define Dh_math_linear_matrix_submatrix

 // ::math::linear::matrix::submatrix<scalar_name,width_number,height_number>

#include "./structure.hpp"


 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        void submatrix
         (
           ::math::linear::matrix::structure<scalar_name, width_number-1, height_number-1>         & result
          ,::math::linear::matrix::structure<scalar_name, width_number, height_number >       const& m
          , std::size_t                                                                       const& column
          , std::size_t                                                                       const& row
         )
         {
          for( std::size_t j=0; j < height_number-1; ++j )
           {
            for( std::size_t i=0; i < width_number-1; ++i )
            {
             result[ i ][ j ] = m[ i + ( i < column ? 0: 1 ) ][  j + ( j < row ? 0: 1 ) ];
            }
           }

         }

      }
    }
  }

#endif
