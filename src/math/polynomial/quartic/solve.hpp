#ifndef math_polynomial_quartic_solve_HPP_
 #define math_polynomial_quartic_solve_HPP_

#include <array>

#include "../quadric/solve.hpp"
#include "../cubic/solve.hpp"
#include "../evaluate.hpp"

 // ::math::polynomial::quartic::solve::general(         root, coefficient, epsilon = 1e-12 )


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
          >
          unsigned general( scalar_name root[4], scalar_name const coefficient[5], scalar_name const& epsilon = 1e-12 )
           {
            if( ( -epsilon < coefficient[4] ) && ( coefficient[4] < epsilon ) )
             {
              return math::polynomial::cubic::solve::general( root, coefficient, epsilon );
             }

            if( ( -epsilon < coefficient[0] ) && ( coefficient[0] < epsilon ) )
             {
              root[ 0 ] = 0;
              return 1 + ::math::polynomial::cubic::solve::general( root+1, coefficient+1, epsilon );
             }

            if(    ( ( -epsilon < coefficient[1] ) && ( coefficient[1] < epsilon ) )
                && ( ( -epsilon < coefficient[3] ) && ( coefficient[3] < epsilon ) )
              )
             {
              scalar_name c2[3]={coefficient[0], coefficient[2], coefficient[4] };
              return ::math::polynomial::quartic::solve::bi( root, c2, epsilon );
             }


            // TODO scalar_name shift = ::math::polynomial::quartic::depressing( depressedC, coefficient, epsilon );
            // TODO scalar_name shift = ::math::polynomial::quartic::monic( depressedC, depressedC, epsilon );

            scalar_name const& a4 = coefficient[4];
            scalar_name const& a3 = coefficient[3];
            scalar_name const& a2 = coefficient[2];
            scalar_name const& a1 = coefficient[1];
            scalar_name const& a0 = coefficient[0];

            scalar_name r = (-3*a3*a3*a3*a3 +256*a0*a4*a4*a4 - 64*a1*a3*a4*a4 + 16*a2*a3*a3*a4)/(256*a4*a4*a4*a4);
            scalar_name q = (a3*a3*a3 - 4*a2*a3*a4+8*a1*a4*a4)/(8*a4*a4*a4 );
            scalar_name p = ( 8*a2*a4-3*a3*a3)/( 8*a4*a4  );
            scalar_name depressedC[3]={ r, q, p };

            //std:: cout << "p:" << p << "; q: " << q << "; r: " << r << std::endl;

            scalar_name substitution = -a3/(4*a4);
            unsigned count;
            switch( count = ::math::polynomial::quartic::solve::ferrari( root, depressedC, epsilon ) )
             {
              case( 4 ): root[3] += substitution;
              case( 3 ): root[2] += substitution;
              case( 2 ): root[1] += substitution;
              case( 1 ): root[0] += substitution;
             }
            return count;
           }

         template
          <
            typename scalar_name
          >
          unsigned general( std::array<scalar_name,4> & root, std::array<scalar_name,5> const& coefficient, scalar_name const& epsilon = 1e-12 )
           {
            return ::math::polynomial::quartic::solve::general<scalar_name>( root.data(), coefficient.data(), epsilon );
           }

        }
      }
    }
  }

#endif
