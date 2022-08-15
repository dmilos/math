#ifndef _DDMRM_math_random_VanDerCorputAndPeano_HPP_
 #define _DDMRM_math_random_VanDerCorputAndPeano_HPP_

 // ::math::random::VaPND<scalar_name, size_type, dimension_number>

#include "./vdc.hpp"
#include "../function/peanoND.hpp"
#include "../linear/vector/structure.hpp"

namespace math
 {
  namespace random
   {

    template< typename scalar_name, typename size_name, ::math::type::size_type dimension_number >
     class VaPND  // Combined VanDerCorput and Peano
      {
       public:
         typedef scalar_name            scalar_type;
         typedef size_name              size_type;
         typedef ::math::linear::vector::point< scalar_type, dimension_number > coord_type;

         typedef ::math::random::vdc< scalar_type, size_type, 2 > T_vdc2;

         void next( coord_type & coord_result )
          {
           return this->operator()( coord_result );
          }

         void operator()( coord_type & coord_result )
          {
           auto I_value = M2_vdc.next();
           ::math::function::peanoND( coord_result, I_value );
          }

       private:
         mutable T_vdc2 M2_vdc;
      };

   }
 }

#endif
