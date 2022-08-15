#ifndef _math_polynomial_monicing_HPP_
 #define _math_polynomial_monicing_HPP_

// math::polynomial::monicing( coefficient, size, epsilon = 1e-6 )
// math::polynomial::monicing( coefficient, size, epsilon = 1e-6 )

#include <vector>

#include "./structure.hpp"

 namespace math
   {
    namespace polynomial
     {

      template< typename scalar_name >
       inline
       scalar_name monicing( scalar_name* output, scalar_name const* input, std::size_t const& size, scalar_name const& epsilon = 1e-9 )
        {
         std::size_t  index;
         scalar_name  leader = input[size-1];

         if( ( - epsilon < leader ) && ( leader < epsilon ) )
          {
           return NAN;
          }

         for( index=0; index < size; index++ )
          {
           output[index] = input[index] / leader;
          }

         return leader;
        }

      template< typename scalar_name >
       inline
       scalar_name monicing( scalar_name* coefficient, std::size_t const& size, scalar_name const& epsilon = 1e-9 )
        {
         std::size_t  index;
         scalar_name  leader = coefficient[size-1];

         if( ( - epsilon < leader ) && ( leader < epsilon ) )
          {
           return NAN;
          }

         for( index=0; index < size; index++ )
          {
           coefficient[index] /= leader;
          }

         return leader;
        }

      template< typename scalar_name >
       inline
       scalar_name monicing( ::math::polynomial::structure::dynamic< scalar_name > &coefficient, scalar_name const& epsilon = 1e-6 )
        {
         return math::polynomial::monicing( coefficient.data(), coefficient.size(), epsilon );
        }
        
      template< typename scalar_name, ::math::type::size_type size_number >
       inline
       scalar_name monicing( ::math::polynomial::structure::fixed< scalar_name, size_number > &coefficient, scalar_name const& epsilon = 1e-6 )
        {
         return math::polynomial::monicing( coefficient.data(), coefficient.size(), epsilon );
        }

    }
  }
#endif
