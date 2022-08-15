#ifndef math_function_moore2D
#define math_function_moore2D

#include <array>

 // ::math::function::moore2D

namespace math
 {
  namespace function
   {

    template< typename scalar_name, typename size_name = ::math::type::size_type >
     inline void moore2D( scalar_name & x, scalar_name &y, scalar_name P_value, size_name iteration = 16 )
      {
       // TODO
      }

    template < typename scalar_name, typename size_name = ::math::type::size_type >
     void moore2D( std::array<scalar_name, 2 > & coord, scalar_name const& value, size_name iteration = 16 )
      {
       ::math::function::moore2D( coord[0], coord[1], value, iteration );
      }

   }
 }

#endif



