#ifndef math_function_gain
#define math_function_gain

#include "./bais.hpp"

 // ::math::function::gain( x, factor ); x e(0,1); factor e (0,1),  ID( X ) = gain( x, factor = 0.5, center = 0.5 )
 // ::math::function::gain( x, factor, center ); center e(0,1)

namespace math
 {
  namespace function
   {

    template< typename scalar_name >
     inline scalar_name gain( scalar_name const& x, scalar_name const& factor )
      {
       if( x < scalar_name(0.5) )
        {
         return ::math::function::bais( scalar_name(2)*x, factor )/scalar_name(2);
        }
       if( scalar_name(0.5) < x )
        {
         return scalar_name(1) - ::math::function::bais( scalar_name(2) - scalar_name(2)*x, factor )/scalar_name(2);
        }
       return scalar_name(0.5);
      }

    template< typename scalar_name >
     inline scalar_name gain( scalar_name const& x, scalar_name const& factor, scalar_name const& center )
      {
       if( x < center )
        {
         return ::math::function::bais( x / center, factor )*center;
        }
       if( center < x )
        {
         return scalar_name(1) - ::math::function::bais( ( scalar_name(1) - x ) / center, factor )*center;
        }
       return scalar_name(0.5);
      }

   }
 }

#endif
