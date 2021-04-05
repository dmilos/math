#ifndef math_function_binomial
#define math_function_binomial

 // ::math::function::binomial

namespace math
 {
  namespace function
   {

    template< typename scalar_name >
     inline scalar_name binomial( scalar_name const& n, scalar_name const& k )
      {
       scalar_name result = 1;
       for( scalar_name  i = 0; i < k; ++i )
        {
         result *= (n - i);
         result /= (i + 1);
        }
       return result;
      }

   }
 }

#endif
