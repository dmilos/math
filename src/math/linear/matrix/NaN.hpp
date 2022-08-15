#ifndef Dh_math_linear_matrix_NaN
 #define Dh_math_linear_matrix_NaN

 // ::math::linear::matrix::NaN<scalar_name,width_number,height_number>

#include <limits>

#include "./structure.hpp"



 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, ::math::type::size_type width_number, ::math::type::size_type height_number >
        void NaN( ::math::linear::matrix::structure<scalar_name,width_number,height_number> & m )
         {

          for( ::math::type::size_type i=0; i< height_number; i++ )
           for( ::math::type::size_type j=0; j< width_number; j++ )
            {
             m[i][j] = std::numeric_limits<scalar_name>::quiet_NaN();
            }

         }

      }
    }
  }

#endif
