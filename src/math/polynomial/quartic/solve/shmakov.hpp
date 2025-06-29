#ifndef math_polynomial_quartic_solve_shmakov_HPP_
 #define math_polynomial_quartic_solve_shmakov_HPP_

 // ::math::polynomial::quartic::solve::shmakov(         root, coefficient, epsilon = 1e-12 )

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
          > // expect monic polynomial
          unsigned shmakov( scalar_name root[4], scalar_name const coefficient[5], scalar_name const& epsilon = 1e-12 )
           {   // TODO have some bug
            root[0] = root[1] = root[2] = root[3] = NAN;
            scalar_name const& A = coefficient[3];
            scalar_name const& B = coefficient[2];
            scalar_name const& C = coefficient[1];
            scalar_name const& D = coefficient[0];

            scalar_name y;
             {
              std::array<scalar_name,4> resolventC={ -A*A*D - C*C + 4*B*D, A * C - 4 * D, scalar_name(-1)*B, scalar_name(1) };
              std::array<scalar_name,3> resultC;
              unsigned countC = ::math::polynomial::cubic::solve::general( resultC.data(), resolventC.data(), epsilon );
              y = resultC[ 0 ];
             }

            unsigned count=0;
            unsigned count_real=0;
            std::array<scalar_name,2> g;
            switch( ::math::polynomial::quadric::solve::monic( g.data(),  B-y, -A, epsilon ) )
             {
              case(0) : return 0;
              case(1) : g[1] = g[0]; count = 2; count_real += 1; break;
              case(2) :              count = 2; count_real += 2; break;
             }

            std::array<scalar_name,2> h;
            switch( ::math::polynomial::quadric::solve::monic( h.data(),    D, -y, epsilon ) )
             {
              case(0) : return 0;
              case(1) : h[1] = h[0]; count = 4; count_real +=1;  break;
              case(2) :              count = 4; count_real +=2;  break;
             }

            if( 4 != count )
             {
              return 0;
             }

            count = ::math::polynomial::quadric::solve::monic(  root,       h[0], g[0] );
            if( 2 == count_real )
             {
              return count;
             }

            count += ::math::polynomial::quadric::solve::monic( root+count, h[1], g[1] );

            return count;
           }

        }
      }
    }
  }

#endif
