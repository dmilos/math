#ifndef math_function_peano2D
#define math_function_peano2D

#include <array>

 // ::math::function::peano2D

namespace math
 {
  namespace function
   {

    /*
      7|8|9
      -+-+
      4|5|6
      -+-+
      1|2|3
     */
    template< typename scalar_name, typename size_name = unsigned >
     inline void peano2D( scalar_name & x, scalar_name &y, scalar_name P_value, size_name iteration = 16 )
      {
       // TODO
      }

    template < typename scalar_name, typename size_name = unsigned >
     void peano2D( std::array<scalar_name, 2 > & coord, scalar_name const& value, size_name iteration = 16 )
      {
       ::math::function::peano2D( coord[0], coord[1], value, iteration );
      }

   }
 }

#endif



