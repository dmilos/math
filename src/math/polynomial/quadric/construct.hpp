#ifndef math_polynomial_quadric_construct2_HPP_
 #define math_polynomial_quadric_construct2_HPP_

 // ::math::polynomial::quadric::construct<scalar_name>( result, zero )

#include <cmath>



 namespace math
  {
   namespace polynomial
    {
     namespace quadric
      {

       template
        <
          typename scalar_name
        >
        void construct( std::array<scalar_name,3> & result, std::array<scalar_name,2> const& zero )
         {
          auto & A  = result[2];
          auto & B  = result[1];
          auto & C  = result[0];

          A = scalar_name(1);
          B = -( zero[0] + zero[1] );
          C = zero[0] * zero[1];

         }

      }
    }
  }

#endif
