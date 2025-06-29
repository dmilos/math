#ifndef math_polynomial_cubic_shift_HPP_
 #define math_polynomial_cubic_shift_HPP_

 // ::math::polynomial::cubic::shift<scalar_name>( result, factor, coefficient, epsilon = 1e-6 )

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
        >    //    [0] + [1] *x + [2] * x^2+ [3] * x^3  = 0, x = t + shift;
         void shift( std::array<scalar_name,4> & result, scalar_name const & factor, std::array<scalar_name,4> const& coefficient, scalar_name const& epsilon = 1e-12 )
         {
          auto A  = coefficient[3];
          auto B  = coefficient[2];
          auto C  = coefficient[1];
          auto D  = coefficient[0];

          result[3] = A;
          result[2] = scalar_name(3)*A * factor + B ;
          result[1] = (scalar_name(3)*A * factor + scalar_name(2)*B )*factor  + C;
          result[0] = ((A*factor+B )*factor +C) * factor+D;
         }

      }
    }
  }

#endif
