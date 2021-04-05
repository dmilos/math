#ifndef Dh_math_linear_matrix_row
 #define Dh_math_linear_matrix_row

 // ::math::linear::matrix::row<scalar_name,width_number,height_number>

#include "./structure.hpp"



 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        void row
         (
           ::math::linear::vector::structure<scalar_name, width_number>                      & r
          ,::math::linear::matrix::structure<scalar_name, width_number, height_number > const& m
          , std::size_t                                                                 const& index
         )
         {

          // for( std::size_t i=0; i < width_number; ++i )
          //  {
          //   c[ i ] = m[ index ][ i ];
          //  }

          r = m[index];
         }

      }
    }
  }

#endif
