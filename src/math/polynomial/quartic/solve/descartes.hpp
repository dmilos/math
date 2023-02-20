#ifndef math_polynomial_quartic_solve_descartes_HPP_
 #define math_polynomial_quartic_solve_descartes_HPP_

 // ::math::polynomial::quartic::solve::descartes(       root, coefficient, epsilon = 1e-12 )

#include <array>

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
          >   // Monic and depressed
          unsigned descartes( scalar_name root[4], scalar_name const coefficient[5], scalar_name const& epsilon = 1e-12 ) //!< Monic and depressed
           {    // [0] + [1] * x + [2] * x ^2 + 0 * x^3 + 1 * x^4. Monic and depressed !!!
            root[3]=root[2]=root[1]=root[0]=NAN;

           scalar_name const& p = coefficient[2];
           scalar_name const& q = coefficient[1];
           scalar_name const& r = coefficient[0];

           scalar_name Q = q * q;
           if( q * q < epsilon)
            {
             scalar_name biC[3]={ r, p, 1 };
             return math::polynomial::quartic::solve::bi( root, biC, epsilon );
            }

            scalar_name D = p*p - 4 * r;
            scalar_name resolventC[ 4 ]={ - Q, D, scalar_name(2)*p, scalar_name(1) };
            scalar_name resultC[ 3 ];
            unsigned countC = ::math::polynomial::cubic::solve::general( resultC, resolventC, epsilon );
            if( 0 == countC )
             { // Impossible!!!
              return 0;
             }

            scalar_name const& U = resultC[countC-1];
            if( U < - epsilon  )
             {
              return 0;
             }

            scalar_name u, s, t, v;

            unsigned count=0;
            if( U < epsilon  )
             {               // bi( root+count,{ tv, t+v, 1 }, epsilon )
              u = 0;
              s = 0;

              if( D < -epsilon )
               {
                return 0;
               }

              if( D < epsilon )
               {
                t = p / 2;

                count += ::math::polynomial::quadric::solve::trivial( root+count, t, epsilon );
                return count;
               }

              t = ( p - sqrt( D ) ) / 2;
              v = ( p + sqrt( D ) ) / 2;

              count += ::math::polynomial::quadric::solve::trivial( root+count, t, epsilon );
              count += ::math::polynomial::quadric::solve::trivial( root+count, v, epsilon );
              return count;
             }
            else
             {
              u = sqrt( U );
              s = -u;
              t = ( p + U + q/u )/2;
              v = ( p + U - q/u )/2;
              scalar_name quadCa[2]={ t, s }; count += ::math::polynomial::quadric::solve::monic( root+count, quadCa, epsilon );
              scalar_name quadCb[2]={ v, u }; count += ::math::polynomial::quadric::solve::monic( root+count, quadCb, epsilon );
             }

            return count;
           }

        }
      }
    }
  }

#endif
