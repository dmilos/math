#ifndef math_polynomial_cubic_solve_viete_HPP_
 #define math_polynomial_cubic_solve_viete_HPP_

 // ::math::polynomial::cubic::solve::viete<scalar_name>( result, q, p, epsilon = 1e-9 )
 // ::math::polynomial::cubic::solve::viete<scalar_name>( result, coefficient, epsilon = 1e-14 );

#include <cmath>
#include "../quadric/solve.hpp"
#include "./depressing.hpp"
#include "../optimize.hpp"
#include "../monicize.hpp"




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
          > // x^3 + P*x + Q = 0
          int viete( scalar_name *result, scalar_name const& q, scalar_name const& p, scalar_name const& epsilon = 1e-15 )
           {
            scalar_name discriminant = q * q  +  ( p * p * p ) * ( 4.0/ 27.0 );

            if( fabs( q ) < epsilon )
             {
              result[0] = 0;
              if( p  < - epsilon )
               {
                result[1] = - sqrt( -p );
                result[2] = + sqrt( -p );
                return 3;
               }
              result[1] = NAN;
              result[2] = NAN;
              return 1;
             }

            if( discriminant < -epsilon )
             {
              scalar_name n = std::sqrt( p * (-4.0 / 3.0 ) );
              scalar_name arg = (3.0 * q) / (p * n);
              arg = ::math::function::ramp<scalar_name>( arg, -1, 1 );
              scalar_name theta = std::acos( arg ) / 3.0;

              result[0] = n * std::cos( theta );
              result[1] = n * std::cos( theta + (2.0 * math::constants::PHI / 3.0) );
              result[2] = n * std::cos( theta + (4.0 * math::constants::PHI / 3.0) );
              return 3;
             }

            if( discriminant < +epsilon )
             {
              scalar_name w = math::function::cbrt( -q / 2.0 );
              result[0] =  2 * w;
              result[1] =  - w;
              result[2] = NAN;
              return 2;
             }

            //if( epsilon <= discriminant)
            {
             discriminant = sqrt( discriminant );
             scalar_name w0 = ( -q - discriminant ) / 2.0;
             scalar_name w1 = ( -q + discriminant ) / 2.0;
             w0 = math::function::cbrt( w0 );
             w1 = math::function::cbrt( w1 );

             scalar_name wX; // = ( fabs( w0 ) < fabs( w1 ) ? w1 : w0 );
             if( fabs( w0 ) < fabs( w1 ) )
              {
               wX = w1;
              }
             else
              {
               wX = w0;
              }
             result[0] = wX - p /( 3 * wX);
             result[1] = NAN;
             result[2] = NAN;
             return 1;
            }

           return 0;
          }

         template
          <
            typename scalar_name
          >
          int viete( scalar_name result[3], scalar_name const coefficient[4], scalar_name const& epsilon = 1e-14 )
           {
            std::array<scalar_name,4> monic;
            ::math::polynomial::monicing( monic.data(), coefficient, 4, epsilon );
            auto shift = ::math::polynomial::cubic::depressing( monic.data(), monic.data(), epsilon );
            //::math::polynomial::optimize( monic.data(), epsilon );

            int count = ::math::polynomial::cubic::solve::viete<scalar_name>( result, monic[0], monic[1], epsilon );

            switch( count )
             {
              case( 3 ): result[2] += shift;
              case( 2 ): result[1] += shift;
              case( 1 ): result[0] += shift;
              case( 0 ): break;
             }

            return count;
           }

         template
          <
            typename scalar_name
          >
         int viete( std::array<scalar_name, 3>& result, std::array<scalar_name, 4> const& coefficient, scalar_name const& epsilon = 1e-14 )
          {
           return ::math::polynomial::cubic::solve::viete<scalar_name>( result.data(), coefficient.data(), epsilon );
          }

        }
      }
    }
  }

#endif
