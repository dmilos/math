#ifndef math_function_bais
#define math_function_bais


 // ::math::function::bais( x, factor ) //!< ( factor = 0.5 == identical )

namespace math
 {
  namespace function
   {

    template< typename scalar_name >
     inline scalar_name bais( scalar_name const& x, scalar_name const& factor )
      {
       return pow( x, log( factor ) / log( scalar_name( 0.5 ) ) );
      }

   }
 }

#endif




