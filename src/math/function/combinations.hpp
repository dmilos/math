#ifndef math_function_combinations
#define math_function_combinations

 // ::math::function::combinations( n,k)

namespace math
 {
  namespace function
   {

    inline unsigned combinations( unsigned n, unsigned k )
     { // copy/paste from stackoverflow. it is not possible to make it better
      if( k > n ) return 0;
      if( k * 2 > n) k = n-k;
      if( k == 0 ) return 1;

      unsigned result = n;
      for( unsigned i = 2; i <= k; ++i ) 
       {
        result *= (n-i+1);
        result /= i;
       }
      return result;
     }

   }
 }

#endif
