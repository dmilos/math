#ifndef math_polynomial_cubic_solve_cardano_HPP_
 #define math_polynomial_cubic_solve_cardano_HPP_

 // ::math::polynomial::cubic::solve::cardano<scalar_name>( result, q, p, epsilon = 1e-9 )
 // ::math::polynomial::cubic::solve::cardano<scalar_name>( result, coefficient, epsilon = 1e-14 );

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
          > // q + p*t + t^3 = 0
          int cardano( scalar_name * result, scalar_name const& q, scalar_name const& p, scalar_name const& epsilon = 1e-12 )
           {
            scalar_name d = (q * q) / 4.0 + (p * p * p) / 27.0;

            if( d < -epsilon  )
             {
              scalar_name u = 2.0 * std::sqrt( -p / 3.0);

              scalar_name cos_theta = -q / (2.0 * std::sqrt(-(p * p * p) / 27.0));
              if (cos_theta > 1.0) cos_theta = 1.0;
              if (cos_theta < -1.0) cos_theta = -1.0;

              scalar_name theta = std::acos(cos_theta);

              result[0] = u * std::cos( theta / 3.0 );
              result[1] = u * std::cos( ( theta + 2.0 * math::constants::PHI ) / 3.0 );
              result[2] = u * std::cos( ( theta + 4.0 * math::constants::PHI ) / 3.0 );
              return 3;
             }

            if( d < epsilon )
             {
              if( ( -epsilon < p ) &&  ( p < epsilon ) )
               {
                result[0] = ::math::function::cbrt( -q );
                result[1] = NAN;
                result[2] = NAN;
                return 1;
               }

              if( ( -epsilon < q ) &&  ( q < epsilon ) )
               {
                result[0] = 0;
                if( p < -epsilon )
                 {
                  result[0] = - sqrt( - p);
                  result[1] = 0;
                  result[2] =   sqrt( - p);
                  return 3;
                 }
                result[1] = NAN;
                result[2] = NAN;
                return 1;
               }

              result[0] = (  3.0 * q ) / p;
              result[1] = ( -3.0 * q ) / (2.0 * p);
              result[2] = NAN;
              return 2;
             }

            if( epsilon < d )
             {
              scalar_name sqrt_disc = std::sqrt( d );
              scalar_name u = -q / 2.0 + sqrt_disc;
              scalar_name v = -q / 2.0 - sqrt_disc;

              u = ::math::function::cbrt( u );
              v = ::math::function::cbrt( v );

              result[0] = u + v;
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
          int cardano( scalar_name result[3], scalar_name const coefficient[4], scalar_name const& epsilon = 1e-12 )
           {
            std::array<scalar_name,4> monic;
            ::math::polynomial::monicing( monic.data(), coefficient, 4, epsilon );
            auto shift = ::math::polynomial::cubic::depressing( monic.data(), monic.data(), epsilon );
            //::math::polynomial::optimize( monic.data(), epsilon );

            int count = ::math::polynomial::cubic::solve::cardano<scalar_name>( result, monic[0], monic[1], epsilon );

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
          int cardano( std::array<scalar_name,3> & result, std::array<scalar_name,4> const coefficient, scalar_name const& epsilon = 1e-12 )
           {
            return ::math::polynomial::cubic::solve::cardano<scalar_name>( result.data(), coefficient.data(), epsilon );
           }

        }
      }
    }
  }

#endif
