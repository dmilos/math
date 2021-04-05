#ifndef math_function_hilbert2D
#define math_function_hilbert2D

#include <array>
#include "./factorial.hpp"
#include "./power.hpp"

 // ::math::function::hilbert2D

namespace math
 {
  namespace function
   {

    template < typename scalar_name, typename size_name =unsigned >
     void hilbert2D( scalar_name & x, scalar_name &y, scalar_name value, size_name iteration=16 )
      {
       return; // TODO
      }

    template < typename scalar_name, typename size_name = unsigned >
     void hilbert2D( std::array<scalar_name, 2 > & coord, scalar_name value, size_name const& iteration = 16 )
      {
       return; // TODO
      }

   }
 }

#endif
