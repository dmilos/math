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

       template< typename scalar_name, ::math::type::size_type width_number, ::math::type::size_type height_number >
        ::math::linear::matrix::structure<scalar_name,width_number,height_number> &
        fill( ::math::linear::matrix::structure<scalar_name,width_number,height_number> & m, scalar_name const& value )
         {
          for( ::math::type::size_type i=0; i< height_number; i++ )
           for( ::math::type::size_type j=0; j< width_number; j++ )
            {
             m[i][j] = value;
            }
          return m;
         }

      }
    }
  }

#endif
