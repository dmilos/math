#ifndef math_function_lcm
#define math_function_lcm

 // ::math::function::lcm

#include "./gcd.hpp"

namespace math
 {
  namespace function
   {

    template< typename size_name >
     inline size_name lcm( size_name const& a, size_name const& b )
      {  // Least Common Multiple (LCM)
       return  a*b / ::math::function::gcd( a,b );
      }

   }
 }

#endif
