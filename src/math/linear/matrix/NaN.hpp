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

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        void NaN( ::math::linear::matrix::structure<scalar_name,width_number,height_number> & m )
         {

          for( unsigned i=0; i< height_number; i++ )
           for( unsigned j=0; j< width_number; j++ )
            {
             m[i][j] = std::numeric_limits<scalar_name>::quiet_NaN();
            }

         }

      }
    }
  }

#endif
