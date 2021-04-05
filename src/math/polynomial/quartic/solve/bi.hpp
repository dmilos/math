#ifndef math_polynomial_quartic_solve_bi_HPP_
 #define math_polynomial_quartic_solve_bi_HPP_

 // ::math::polynomial::quartic::solve::bi<scalar_name>( root, coefficient, epsilon = 1e-8 )

#include <array>





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
          unsigned bi( scalar_name root[4], scalar_name const coefficient[3], scalar_name const& epsilon = 1e-8 )
           {
            unsigned count = 0;
            scalar_name r2[2];
            root[3]=root[2]=root[1]=root[0]=NAN;
            switch( math::polynomial::quadric::solve::general( r2, coefficient, epsilon ) )
             {
              case( 2 ):
               {
                if( r2[1] < -epsilon ) { goto case_1; }
                if( r2[1] < +epsilon ) { root[count++] = 0; goto case_1; }
              //if( epsilon < r2[1] )
                 {
                  root[count++] = - sqrt( r2[1] );
                  root[count++] = + sqrt( r2[1] );
                 }
               }// break for no one
              case( 1 ):
               {
                case_1:
                if( r2[0] < -epsilon ) { goto case_0; }
                if( r2[0] < +epsilon ) { root[count++] = 0; goto case_0; }
              //if( epsilon < r2[0] )
                 {
                  root[count++] = - sqrt( r2[0] );
                  root[count++] = + sqrt( r2[0] );
                 }
               }// break for no one
              case( 0 ): case_0: ;
             }
            return count;
           }

        }
      }
    }
  }

#endif
