#ifndef Dh_math_linear_matrix_fill
 #define Dh_math_linear_matrix_fill

 // ::math::linear::matrix::fill<scalar_name,width_number,height_number>( m, value )

#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        ::math::linear::matrix::structure<scalar_name,width_number,height_number> &
        fill( ::math::linear::matrix::structure<scalar_name,width_number,height_number> & m, scalar_name const& value )
         {
          for( unsigned i=0; i< height_number; i++ )
           for( unsigned j=0; j< width_number; j++ )
            {
             m[i][j] = value;
            }
          return m;
         }

      }
    }
  }

#endif
