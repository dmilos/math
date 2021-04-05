#ifndef Dh_DDMRM_math_LA_vector_structure_HPP_
 #define Dh_DDMRM_math_LA_vector_structure_HPP_

 // ::math::linear::vector::structure<scalar_name,dimension_number>
 // ::math::linear::vector::vector<scalar_name,dimension_number>
 // ::math::linear::vector::point<scalar_name,dimension_number>

#include <array>


 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template
        <
          typename scalar_name
         ,unsigned dimension_number
        >
         using structure = std::array< scalar_name, dimension_number >;

       template
        <
          typename scalar_name
         ,unsigned dimension_number
        >
         using vector = ::math::linear::vector::structure< scalar_name, dimension_number >;

       template
        <
          typename scalar_name
         ,unsigned dimension_number
        >
         using point = ::math::linear::vector::structure< scalar_name, dimension_number >;

      }
    }
  }

#endif
