#ifndef math_polynomial_quartic_depressing_HPP_
 #define math_polynomial_quartic_depressing_HPP_

#include <array>

 // ::math::polynomial::quartic::depressing<scalar_name>( result, coefficient, epsilon = 1e-6 )


 namespace math
  {
   namespace polynomial
    {
     namespace quartic
      {

       template
         <
         typename scalar_name
         >// TODO MONIC variant also
         scalar_name depressing( scalar_name result[5], scalar_name const coefficient[5], scalar_name const& epsilon = 1e-12 )
          {
           scalar_name shift = NAN;

           auto &A  = coefficient[4];
           auto &B  = coefficient[3];
           auto &C  = coefficient[2];
           auto &D  = coefficient[1];
           auto &E  = coefficient[0];

           if( ( -epsilon < A ) && ( A < epsilon ) ) return shift;

           shift = B/( 4 * A );
           result[4] = A*A*A*A;
           result[3] = 0;
           result[2] = A*A*( (-3 * B*B / 8 ) + ( C * A ) );
           result[1] = A*( ( B*B*B/ 8 ) +( - B*C * A /2 ) + ( D * A * A ) ) ;
           result[0] = ( - 3 *B*B*B*B / ( 256 ) ) + ( A *B*B*C /( 16 )) + ( - A*A*B*D/( 4 )) + ( A*A*A*E);

           return -shift;
          }

      }
    }
  }

#endif
