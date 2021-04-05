#ifndef math_function_bais
#define math_function_bais


 // ::math::function::bais

namespace math
 {
  namespace function
   {

    template< typename scalar_name >
     inline scalar_name bais( scalar_name const& x, scalar_name const& b )
      {
       return pow( x, log( b ) / log( scalar_name( 0.5 ) ) );
      }

   }
 }

#endif




