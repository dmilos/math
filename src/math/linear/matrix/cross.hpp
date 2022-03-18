#ifndef Dh_math_linear_matrix_cross
 #define Dh_math_linear_matrix_cross

 // ::math::linear::matrix::cross( m, t );

#include "./structure.hpp"


 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name >
        ::math::linear::matrix::structure<scalar_name, 3, 3 >   & 
        cross
         (
           ::math::linear::matrix::structure<scalar_name, 3, 3 >        & m
          ,::math::linear::vector::structure<scalar_name, 3 >      const& t
         )
         {
          m[0][0] =     0;  m[0][1] = -t[2];  m[0][2] = +t[1];
          m[1][0] = +t[2];  m[1][1] =     0;  m[1][2] = -t[0];
          m[2][0] = -t[1];  m[2][1] = +t[0];  m[2][2] = 0;
          return m;
         }

      }
    }
  }

#endif
