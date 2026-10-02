#ifndef math_polynomial_cubic_construct3_HPP_
 #define math_polynomial_cubic_construct3_HPP_

 // ::math::polynomial::cubic::construct<scalar_name>( result, factor, coefficient, epsilon = 1e-6 )

#include <cmath>



 namespace math
  {
   namespace polynomial
    {
     namespace cubic
      {

       template
        <
          typename scalar_name
        >    //    [0] + [1] *x + [2] * x^2+ 1 * x^3  = 0;
         void construct( std::array<scalar_name,4> & result, std::array<scalar_name,3> const& zero )
         {
          auto & A  = result[3];
          auto & B  = result[2];
          auto & C  = result[1];
          auto & D  = result[0];

          A = scalar_name(1);
          B = -( zero[0] + zero[1]+ zero[2] );
          C = zero[0] * zero[1] + zero[0] * zero[2] + zero[1] * zero[2];
          D = -( zero[0] * zero[1]* zero[2] );
         }

      }
    }
  }

#endif
