#ifndef math_function_ricker
#define math_function_ricker

// ::math::function::ricker( x , standard_deviation_param )
// ::math::function::ricker( {x,y} , standard_deviation_param )

#include <array>
#include "../constants.hpp"


namespace math
 {
  namespace function
   {

      template< typename scalar_name >
       inline scalar_name ricker
        (
          scalar_name const& x
         ,scalar_name const& standard_deviation_param
         )
        {
         static const scalar_name A = scalar_name(2) / ( math::constants::SQRT3 * sqrt(sqrt( math::constants::PHI ) ) );

         scalar_name power  =  x / standard_deviation_param;
                     power *= power;

         scalar_name coefficient = A / sqrt( standard_deviation_param );

         scalar_name result    = coefficient * ( scalar_name(1) - power ) * exp( - power * scalar_name(0.5) );

         return result;
        }

      template< typename scalar_name >
       inline scalar_name ricker
        (
          std::array<scalar_name,2> const& p
         ,scalar_name const& standard_deviation_param /* = 0.245965851859991*/ 
         )
        {
         static const scalar_name A = scalar_name(1) / ( math::constants::PHI );

         scalar_name s2  =  standard_deviation_param * standard_deviation_param;
         scalar_name t  =  p[0]*p[0] +  p[1] * p[1];

         scalar_name C = A / ( s2 * s2 );
         scalar_name P = - scalar_name(0.5)* t / s2;

         scalar_name result = C * ( scalar_name(1) + P ) * exp( P );

         return result;
        }

   }
 }

#endif
