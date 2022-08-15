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

       template< typename scalar_name, ::math::type::size_type width_number, ::math::type::size_type height_number >
        void zero( ::math::linear::matrix::structure<scalar_name,width_number,height_number> & m )
         {

          for( ::math::type::size_type i=0; i< height_number; i++ )
           for( ::math::type::size_type j=0; j< width_number; j++ )
            {
             m[i][j] = scalar_name( 0 );
            }

         }

      }
    }
  }

#endif
