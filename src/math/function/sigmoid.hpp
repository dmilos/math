#ifndef math_function_sigmoid
#define math_function_sigmoid


 // ::math::function::signum

namespace math
 {
  namespace function
   {

    template< typename scalar_name >
     inline int sigmoid( scalar_name const& x )
      {
       return scalar_name(1)/( scalar_name(1) + exp(-x) );
      }

   }
 }

#endif




