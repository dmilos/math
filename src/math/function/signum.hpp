#ifndef math_function_signum
#define math_function_signum


 // ::math::function::signum

namespace math
 {
  namespace function
   {

    template< typename scalar_name , typename integer_name = int >
     inline integer_name signum( scalar_name const& x, scalar_name const& epsilon = scalar_name(0) )
      {
       if( x < -epsilon )
        {
         return integer_name(-1);
        }

       if( epsilon < x )
        {
         return integer_name(+1);
        }

       return integer_name(0);
      }

   }
 }

#endif




