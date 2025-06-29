#ifndef math_polynomial_quartic_shift_HPP_
 #define math_polynomial_quartic_shift_HPP_

 // ::math::polynomial::quartic::shift<scalar_name>( result, factor, coefficient, epsilon = 1e-6 )

#include <cmath>



 namespace math
  {
   namespace polynomial
    {
     namespace quartic
      {
 
       template
        <
          typename scalar_name
        >    //    [0] + [1] *x + [2] * x^2 + [3] * x^3 + [4] * x^4  = 0, x = t + shift;
         void shift( std::array<scalar_name,5> & result, scalar_name const & factor, std::array<scalar_name,5> const& coefficient, scalar_name const& epsilon = 1e-12 )
         {
          auto A  = coefficient[4];
          auto B  = coefficient[3];
          auto C  = coefficient[2];
          auto D  = coefficient[1];
          auto E  = coefficient[0];

          result[4] = A;
          result[3] =  scalar_name(4)* A * factor + B;
          result[2] = (scalar_name(6)* A * factor + scalar_name(3) * B ) * factor + C;
          
          result[1] = ((scalar_name(4)*A*factor+scalar_name(3)*B )*factor + scalar_name(2)*C) * factor + D;
          result[0] = (((A*factor+B )*factor +C) * factor+D)*factor + E;
         }

      }
    }
  }

#endif
