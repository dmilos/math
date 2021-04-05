#ifndef Dh_math_polynomial_structure_HPP_
 #define Dh_math_polynomial_structure_HPP_

 // ::math::polynomial::structure::dynamic<scalar_name>
 // ::math::polynomial::structure::fixed<scalar_name,dimension_number>




 namespace math
  {
   namespace polynomial
    {
     namespace structure
      {

       template
        <
          typename scalar_name
        >
        using dynamic = std::vector< scalar_name >;

       template
        <
          typename scalar_name
         ,unsigned dimension_number
        >
        using fixed = std::array< scalar_name, dimension_number >;

      }
    }
  }

#endif
