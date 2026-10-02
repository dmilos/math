#ifndef math_polynomial_cubic_brian_HPP_
 #define math_polynomial_cubic_brian_HPP_

 // ::math::polynomial::cubic::solve::brian<scalar_name>( result, coefficient, epsilon  )

#include <cmath>
#include "../quadric/solve.hpp"
#include "../../geometry/deg2rad.hpp"
#include "../../function/cbrt.hpp"


 namespace math
  {
   namespace polynomial
    {
     namespace cubic
      {
       namespace solve
        {

         /*
         - 2 - first two solutions are equal
         - 3 - all solutions are equal
         */
         template
          <
            typename scalar_name
          > // copy paste from gsl_poly_solve_cubic
          int brian( scalar_name result[3], scalar_name const coefficient[4], scalar_name const& epsilon = 1e-12 )
           {
            if( ( -epsilon < coefficient[3] ) && ( coefficient[3] < epsilon ) )
             {
              return ::math::polynomial::quadric::solve::general( result, coefficient, epsilon );
             }

            if( ( -epsilon < coefficient[0] ) && ( coefficient[0] < epsilon ) )
             {
              scalar_name r2[2];
              switch( ::math::polynomial::quadric::solve::general( r2, coefficient+1, epsilon ) )
               {
                case( 0 ):
                  {
                   result[0] = 0; result[1] = result[2] = NAN;
                   return 1;
                  }
                case( 1 ):
                 {
                  result[0] = std::min<scalar_name>( 0, r2[0] );
                  result[1] = std::max<scalar_name>( 0, r2[0] );
                  result[2] = NAN;
                  return 2;
                 }

                case( 2 ):
                 {
                  result[0] = 0;
                  result[1] = r2[0];
                  result[2] = r2[1];
                  if( result[1] < result[0]){ std::swap( result[1] , result[0] ); }
                  if( result[2] < result[1]){ std::swap( result[2] , result[1] ); }
                  if( result[1] < result[0]){ std::swap( result[1] , result[0] ); }
                  return 3;
                 }
               }
              result[0] = result[1] = result[2] = NAN;
              return 0;
             }

            scalar_name a = coefficient[2] /coefficient[3];
            scalar_name b = coefficient[1] /coefficient[3];
            scalar_name c = coefficient[0] /coefficient[3];

            scalar_name q = (a * a - 3 * b);
            scalar_name r = (2 * a * a * a - 9 * a * b + 27 * c);

            scalar_name Q = q / 9;
            scalar_name R = r / 54;

            scalar_name Q3 = Q * Q * Q;
            scalar_name R2 = R * R;

            scalar_name CR2 = 729 * r * r;
            scalar_name CQ3 = 2916 * q * q * q;

            if( ::math::geometry::interval::in( R, -epsilon, epsilon)  && ::math::geometry::interval::in( Q, -epsilon, +epsilon ) )
             {
              result[0] = - a / scalar_name(3);
              result[1] = result[0];
              result[2] = result[0];
              result[1] = result[2] = NAN;
              return 1;
             }

            if( fabs( CR2 - CQ3 ) < epsilon )
             {
              scalar_name sqrtQ = sqrt( Q );

              if( epsilon < R )
               {
                result[0] = -scalar_name(2) * sqrtQ  - a / scalar_name(3);
                result[1] = sqrtQ - a / scalar_name(3);
                result[2] = result[1];
                result[2] = NAN;
                return 2;
               }

              //if( R < -epsilon ) // TODO
               {
                result[0] =   - sqrtQ - a / scalar_name(3);
                result[1] = 2 * sqrtQ - a / scalar_name(3);
                result[2] = NAN;
                return 2;
               }
              // R == 0
              {
               // TODO
              }

             }
            else if( R2 < Q3 )
             {
              scalar_name sgnR = scalar_name(R >= 0 ? 1 : -1);
              scalar_name ratio = sgnR * sqrt (R2 / Q3);
              scalar_name theta = acos (ratio);
              scalar_name norm = -scalar_name(2) * sqrt (Q);
              result[0] =scalar_name( norm * cos (theta / 3) - a / 3 );
              result[1] =scalar_name( norm * cos ((theta + ::math::geometry::deg2rad( 360.0 ) ) / scalar_name(3)) - a / scalar_name(3) );
              result[2] =scalar_name( norm * cos ((theta - ::math::geometry::deg2rad( 360.0 ) ) / scalar_name(3)) - a / scalar_name(3) );

              /* Sort result[x] into increasing order */

              if( result[1] < result[0] )
               {
                std::swap( result[0], result[1] );
               }

              if( result[2] < result[1] )
               {
                std::swap( result[1], result[2] );

                if (result[0] > result[1] )
                 {
                  std::swap( result[0], result[1] );
                 }
               }

              return 3;
             }
            else
             {
              scalar_name sgnR = scalar_name(R >= 0 ? 1 : -1);
              scalar_name A = -sgnR * pow (fabs (R) + sqrt (R2 - Q3), scalar_name(1)/scalar_name(3));
              scalar_name B = Q / A ;
              result[0] = A + B - a / scalar_name(3);
              result[1] = result[2] = NAN;
              return 1;
             }
          }

         template
          <
            typename scalar_name
          >
          int brian( std::array<scalar_name,3> & result, std::array<scalar_name,4> const coefficient, scalar_name const& epsilon = 1e-12 )
           {
            return ::math::polynomial::cubic::solve::brian<scalar_name>( result.data(), coefficient.data(), epsilon );
           }

        }
      }
    }
  }

#endif
