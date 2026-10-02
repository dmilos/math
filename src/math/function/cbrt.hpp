#ifndef math_function_cbrt
#define math_function_cbrt


 // ::math::function::cbrt

namespace math
 {
  namespace function
   {

    template< typename scalar_name >
     inline scalar_name cbrt( scalar_name const& value )
      {
       if( value < 0 ) return - pow( -value, scalar_name(1)/scalar_name(3) );
       if( 0 == value ) return 0;
       return pow( value, scalar_name(1)/scalar_name(3) );
      }

   }
 }

#endif



