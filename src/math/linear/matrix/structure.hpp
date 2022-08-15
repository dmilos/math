#ifndef Dh_math_linear_matrix_structure
 #define Dh_math_linear_matrix_structure

 // ::math::linear::matrix::structure<scalar_name,height_number,width_number>

#include <array>
#include "../../type/size.hpp"




 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template
        <
          typename scalar_name
         ,::math::type::size_type width_number
         ,::math::type::size_type height_number
        > // AKA SOLID, Orientation: row by row
        using structure = std::array< std::array< scalar_name, width_number >, height_number >;

       //template
       // <
       //   typename scalar_name
       // > // Orientation: row by row
       // using dynamic = std::vector< std::vector< scalar_name > >;

      }
    }
  }

#endif
