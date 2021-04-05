#ifndef math_function_convex
#define math_function_convex

#include <array>

 // ::math::function::convex

namespace math
 {
  namespace function
   {

    template< typename scalar_name >
     inline scalar_name convex( scalar_name const& x, scalar_name const& lo, scalar_name const& hi )
      {
       return lo + x * ( hi  -lo );
      }

   }
 }

#endif



