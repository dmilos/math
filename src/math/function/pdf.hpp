#ifndef math_function_pdf
#define math_function_pdf

 // ::math::function::pdf

#include "../constants.hpp"


namespace math
 {
  namespace function
   {

    template< typename scalar_name >
     inline scalar_name pdf( scalar_name const& x, scalar_name const& variance, scalar_name const& mean )
      { // Probability density function
       return exp(-(x-mean)*(x-mean)/( scalar_name(2)* variance) )/sqrt( scalar_name(2)* ::math::constants::PHI * variance );
      }

    template< typename scalar_name >
     inline scalar_name pdf( scalar_name const& x, scalar_name const& variance )
      { // Probability density function
       return exp(-x*x/( scalar_name(2)* variance) )/sqrt( scalar_name(2) * ::math::constants::PHI * variance );
      }


   }
 }

#endif



