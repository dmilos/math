#ifndef Dh_math_linear_matrix_flip
 #define Dh_math_linear_matrix_flip

 // ::math::linear::matrix::flip( m, t );

#include "./structure.hpp"


 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name >
        ::math::linear::matrix::structure<scalar_name, 2, 2 >   & 
        flip
         (
           ::math::linear::matrix::structure<scalar_name, 2, 2 >        & m
         )
         {
          m[0][0] =  scalar_name(0);  m[0][1] = scalar_name(1); 
          m[1][0] =  scalar_name(1);  m[1][1] = scalar_name(0); 
          return m;
         }

      }
    }
  }

#endif
