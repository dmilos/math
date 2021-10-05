#ifndef math_function_epsilon
#define math_function_epsilon


 // ::math::function::signum

namespace math
 {
  namespace function
   {

    template< typename scalar_name >
     inline int signum( scalar_name const& x, scalar_name const& epsilon = 0 )
      {
       if( x < - epsilon )
        {
         return -1;
        }

       if( epsilon < x )
        {
         return +1;
        }

       return 0;
      }

   }
 }

#endif




