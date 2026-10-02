#ifndef math_polynomial_linear_construct1_HPP_
 #define math_polynomial_linear_construct1_HPP_

 // ::math::polynomial::linear::construct<scalar_name>( result, zero )

#include <cmath>



 namespace math
  {
   namespace polynomial
    {
     namespace linear
      {

       template
        <
          typename scalar_name
        >   //    [0] + 1 * x   = 0;
        void construct( std::array<scalar_name,2> & result, std::array<scalar_name,1> const& zero )
         {
          auto & A  = result[1];
          auto & B  = result[0];

          A = 1;
          B = -zero[0];
         }

      }
    }
  }

#endif
