#ifndef math_function_gdc
#define math_function_gdc

 // ::math::function::gcd

namespace math
 {
  namespace function
   {

    template< typename size_name >
     inline size_name gcd( size_name const& a, size_name const& b )
      { // Greatest Common Divisor (GCD)
       if( size_name(0) == b )
        {
         return a;
        }
       return ::math::function::gcd<size_name>( b, a % b );
      }

   }
 }

#endif
