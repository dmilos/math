#ifndef math_polynomial_cubic_depressing_HPP_
 #define math_polynomial_cubic_depressing_HPP_

 // ::math::polynomial::cubic::depressing<scalar_name>( result, coefficient, epsilon = 1e-6 )

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
        >    //    [0] + [1] *x + [2] * x^2+ [3] * x^3  = 0
         scalar_name depressing( std::array<scalar_name,4> & result, std::array<scalar_name,4> const coefficient, scalar_name const& epsilon = 1e-12 )
         {
          scalar_name shift = NAN;

          auto A  = coefficient[3];
          auto B  = coefficient[2];
          auto C  = coefficient[1];
          auto D  = coefficient[0];

          shift =   -B/( 3 * A );

          if( ( -epsilon < shift ) && ( shift < epsilon ) ) return shift;

                     result[3] = coefficient[3];
                     result[2] = 0;
          auto &p  = result[1];
          auto &q  = result[0];

          p = C + B * shift ;
          q = D + (scalar_name(2)/scalar_name(3))* B * shift*shift   + C * shift ;

          return -shift;
         }

      }
    }
  }

#endif
