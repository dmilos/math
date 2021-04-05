#ifndef _DDMRM_math_random_VanDerCorputAndLebesgue_HPP_
 #define _DDMRM_math_random_VanDerCorputAndLebesgue_HPP_

 // ::math::random::VaPND<scalar_name, size_type, dimension_number>

#include "./vdc.hpp"
#include "../function/lebesgueND.hpp"
#include "../linear/vector/structure.hpp"

namespace math
 {
  namespace random
   {

    template< typename scalar_name, typename size_name, unsigned dimension_number >
     class VaLND  // Combined VanDerCorput and Lebesgue
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
           ::math::function::lebesgueND( coord_result, I_value );
          }

       private:
         mutable T_vdc2 M2_vdc;
      };

   }
 }

#endif
