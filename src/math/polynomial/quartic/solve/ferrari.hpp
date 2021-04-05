#ifndef math_polynomial_quartic_solve_ferrari_HPP_
 #define math_polynomial_quartic_solve_ferrari_HPP_

 // ::math::polynomial::quartic::solve::ferrari( root, coefficient, epsilon = 1e-12 )

#include "./bi.hpp"

#include "../../quadric/solve.hpp"
#include "../../cubic/solve.hpp"


 namespace math
  {
   namespace polynomial
    {
     namespace quartic
      {
       namespace solve
        {

         template
          <
            typename scalar_name
          > // Expect Monic and depressed
          unsigned ferrari( scalar_name root[4], scalar_name const coefficient[5], scalar_name const& epsilon = 1e-12 )
           {  // [0] + [1] * x + [2] * x ^2 + 0.0. * x^3 +  1.0 * x^4
            scalar_name const& p = coefficient[2];
            scalar_name const& q = coefficient[1];
            scalar_name const& r = coefficient[0];

            if( q * q < epsilon )
             {
              scalar_name biC[3]={ r, p, 1 };
              return math::polynomial::quartic::solve::bi( root, biC, epsilon );
             }

            scalar_name resolventC[ 4 ]={ -q*q, 2*p*p-scalar_name(8)*r, scalar_name(8)*p, scalar_name(8) };
            scalar_name resultC[ 3 ];
            unsigned countC = ::math::polynomial::cubic::solve::general( resultC, resolventC, epsilon );
            if( 0 == countC )
             { // Impossible!!!
              return 0;
             }

            scalar_name const& m = resultC[countC-1];
            if( m < - epsilon  )
             {
              return 0;
             }

            if( m < epsilon  )
             {
              scalar_name biC[3]={ r, p, 1 };
              return math::polynomial::quartic::solve::bi( root, biC, epsilon );
             }

            unsigned count=0;

            scalar_name quadCa[2]={ scalar_name( p/2 + m - q/( 2 * sqrt( 2*m ) ) ), scalar_name( +sqrt( 2 * m ) ) }; count += ::math::polynomial::quadric::solve::monic( root+count, quadCa, epsilon );
            scalar_name quadCb[2]={ scalar_name( p/2 + m + q/( 2 * sqrt( 2*m ) ) ), scalar_name( -sqrt( 2 * m ) ) }; count += ::math::polynomial::quadric::solve::monic( root+count, quadCb, epsilon );

            return count;
           }

        }
      }
    }
  }

#endif
