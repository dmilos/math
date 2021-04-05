#ifndef Dh_math_linear_matrix_zero
 #define Dh_math_linear_matrix_zero

 // ::math::linear::matrix::zero<scalar_name,width_number,height_number>

#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        void zero( ::math::linear::matrix::structure<scalar_name,width_number,height_number> & m )
         {

          for( unsigned i=0; i< height_number; i++ )
           for( unsigned j=0; j< width_number; j++ )
            {
             m[i][j] = scalar_name( 0 );
            }

         }

      }
    }
  }

#endif
