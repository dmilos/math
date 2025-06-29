#ifndef math_polynomial_linear_shift_HPP_
 #define math_polynomial_linear_shift_HPP_

 // ::math::polynomial::linear::shift<scalar_name>( result, factor, coefficient, epsilon = 1e-6 )

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
        >    //    [0] + [1] *x  = 0, x = t + shift;
        void shift( scalar_name result[2], scalar_name const & factor,  scalar_name const coefficient[2], scalar_name const& epsilon = 1e-12 )
         {
          auto A  = coefficient[1];
          auto B  = coefficient[0];

          result[1] = A;
          result[0] = A * factor + B;
          }
         
       template
        <
          typename scalar_name
        >    //    [0] + [1] *x  = 0, x = t + shift;
        void shift( std::array<scalar_name,2> & result, scalar_name const & factor, std::array<scalar_name,2> const& coefficient, scalar_name const& epsilon = 1e-12 )
         {
          return ::math::polynomial::linear::shift<scalar_name>( result.data(), factor, coefficient.data(), epsilon );
         }

      }
    }
  }

#endif
