#ifndef Dh_math_linear_homography_structure
#define Dh_math_linear_homography_structure

 // ::math::linear::homography::structure<scalar_name,dimension_number>

#include "../matrix/matrix.hpp"









namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template
       <
         typename scalar_name
        ,unsigned dimension_number //! For plane it is 2, for #d space it is 3
       > // Currently limited to square matrix
        using structure = ::math::linear::matrix::structure< scalar_name, dimension_number + 1, dimension_number + 1 >;

     }
   }
 }

#endif
