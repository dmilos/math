#ifndef Dh_math_linear_matrix_quadratic
 #define Dh_math_linear_matrix_quadratic

 // ::math::linear::matrix::quadratic<scalar_name,size_number,size_number>

#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, ::math::type::size_type size_number >
        scalar_name quadratic
         (
           ::math::linear::vector::structure<scalar_name,size_number>             const& point
          ,::math::linear::matrix::structure<scalar_name,size_number,size_number> const& M
         )
         {
          scalar_name result = 0;

          for( ::math::type::size_type i=0; i< size_number; i++ )
           {
            scalar_name partial = 0;
            for( ::math::type::size_type j=0; j< size_number; j++ )
             {
              partial += point[j] * M[i][j];
             }
            result += point[i] * partial;
           }
         }

      }
    }
  }

#endif
