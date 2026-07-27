#ifndef math_function_gen_z
#define math_function_gen_z

#include <array>
#include "../../linear/vector/structure.hpp"

 // ::math::function::gen_z

namespace math
 {
  namespace function
   {

    template < typename scalar_name, ::math::type::size_type dimension_number, typename size_name = ::math::type::size_type >
     inline void gen_z( std::array<scalar_name, dimension_number > & result, scalar_name value, size_name const& iteration = 16, scalar_name const& base = 10.0 )
      { // Some kind of generalized Z function
       scalar_name  shift = 1;
       ::math::linear::vector::fill<scalar_name>( result, 0 );

       for( size_name level = 0; level < iteration; ++level )
        {
         shift *= base;
         for( size_name coord = 0; coord < dimension_number; ++coord )
          {
           value *= base;
           result[coord] += int(value)/shift;
           value = fmod( value, scalar_name( 1 ) );
          }
        }
      }

    template < typename scalar_name, typename size_name = ::math::type::size_type >
     void  gen_z( scalar_name & x, scalar_name &y, scalar_name value, size_name iteration=16 )
      {
       std::array<scalar_name, 2 > c;
       ::math::function::gen_z( c, value, iteration );
       x = c[0];
       y = c[1];
      }


   }
 }

#endif
