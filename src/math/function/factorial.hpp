#ifndef math_function_factorial
#define math_function_factorial

 // ::math::function::factorial<N>
 // ::math::function::factorial( value )

namespace math
 {
  namespace function
   {

    namespace _internal
     {
      template < unsigned N >
       struct Factorial
        {
         enum { value = N * Factorial<N - 1>::value };
        };

      template < >
       struct Factorial<0>
        {
         enum { value = 1 };
        };
     }

    template < unsigned N >
     constexpr unsigned factorial()
      {
       return ::math::function::_internal::Factorial<N>::value;
      }

    template < typename size_name >
    size_name factorial( size_name const& value )
      {
       size_name result = 1;
       for( size_name number = 1; number < value;  )
        {
         result *= ++number;
        }
       return result;
      }

   }
 }

#endif
