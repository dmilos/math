#ifndef math_function_power
#define math_function_power

 // ::math::function::factorial<N>

namespace math
 {
  namespace function
   {

    namespace _internal
     {

      template < unsigned Base, unsigned Exponent >
       struct Power
        {
         enum { value = Power< Base, Exponent/2 >::value * Power< Base, Exponent/2 >::value * ( Base %2 ? 1: Base ) };
        };

      template <> struct Power<0,0> { enum { value = 0 }; };
      template <> struct Power<0,1> { enum { value = 0 }; };
      template <> struct Power<1,0> { enum { value = 1 }; };
      template <> struct Power<1,1> { enum { value = 1 }; };

      template < unsigned Exponent > struct Power<0,Exponent> { enum { value = 0 }; };
      template < unsigned Exponent > struct Power<1,Exponent> { enum { value = 1 }; };

      template < unsigned Base > struct Power<Base,0> { enum { value = 1 }; };
      template < unsigned Base > struct Power<Base,1> { enum { value = Base }; };
      template < unsigned Base > struct Power<Base,2> { enum { value = Base * Base }; };
      template < unsigned Base > struct Power<Base,3> { enum { value = Base * Base * Base }; };
      template < unsigned Base > struct Power<Base,4> { enum { value = Power<Base,2>::value * Power<Base,2>::value }; };
      template < unsigned Base > struct Power<Base,5> { enum { value = Power<Base,4>::value * Base }; };
      template < unsigned Base > struct Power<Base,6> { enum { value = Power<Base,3>::value * Power<Base,3>::value }; };

     }

    template < unsigned Base, unsigned Exponent >
     constexpr unsigned power()
      {
       return ::math::function::_internal::Power<Base,Exponent>::value;
      }

   }
 }

#endif
