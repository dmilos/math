#ifndef math_polynomial_cubic_trivial_HPP_
 #define math_polynomial_cubic_trivial_HPP_

 // ::math::polynomial::cubic::solve::trivial( scalar_name root[2], scalar_name const &C, epsilon );
 // ::math::polynomial::cubic::solve::trivial( scalar_name root[2], coefficient[4], epsilon );

#include <cmath>



 namespace math
  {
   namespace polynomial
    {
     namespace cubic
      {
       namespace solve
        {

         template
          <
            typename scalar_name
          > // C + 0 *x^1+ 0 * x^2 + 1 * x^3 = 0
          int trivial( scalar_name root[2], scalar_name const &C, scalar_name const& epsilon = 1e-6 )
           {
            root[0] = ::math::function::cbrt( C );
            root[1] = NAN;
            root[2] = NAN;
            return 1;
           }

         template
          <
            typename scalar_name
          > // C + 0 *x^1 + 0 * x^2 + c[3] * x^3 = 0
          int trivial( scalar_name root[2], scalar_name coefficient[4], scalar_name const& epsilon = 1e-6 )
           {
            root[0] = ::math::function::cbrt( - coefficient[ 0 ] / coefficient[ 3 ] );
            root[1] = NAN;
            root[2] = NAN;
            return 1;
           }

        }
      }
    }
  }

#endif
