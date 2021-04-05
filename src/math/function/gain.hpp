#ifndef math_function_gain
#define math_function_gain

#include "./bais.hpp"

 // ::math::function::gain

namespace math
 {
  namespace function
   {

    template< typename scalar_name >
     inline scalar_name gain( scalar_name const& x, scalar_name const& g )
      {
       if( x < scalar_name(0.5) )
        {
         return ::math::function::bais( scalar_name(2)*x, g )/scalar_name(2);
        }
       if( scalar_name(0.5) < x )
        {
         return scalar_name(1) - ::math::function::bais( scalar_name(2) - scalar_name(2)*x, g )/scalar_name(2);
        }
       return scalar_name(0.5);
      }

   }
 }

#endif
