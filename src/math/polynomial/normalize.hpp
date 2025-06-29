#ifndef _math_polynomial_normaliza_HPP_
 #define _math_polynomial_normaliza_HPP_

// math::polynomial::normalize( coefficient, size, epsilon = 1e-6 )
// math::polynomial::normalize( coefficient, epsilon = 1e-6 )

#include <vector>

#include "./structure.hpp"

 namespace math
   {
    namespace polynomial
     {

      template< typename scalar_name >
       inline
       scalar_name normalize( scalar_name* coefficient, ::math::type::size_type const& size, scalar_name const& epsilon = 1e-12 )
        {
         ::math::type::size_type  index;
         scalar_name  biggest_val = coefficient[0];
         scalar_name  biggest_abs = fabs(coefficient[0]);
         ::math::type::size_type  biggest_index = 0;

         for( index=0; index < size; index++ )
          {
           auto const &current_val = coefficient[index];
           auto current_abs = fabs( current_val );
           if( biggest_abs < current_abs )
            {
             biggest_val   = coefficient[index];
             biggest_abs   = current_abs;
             biggest_index = index;
           }
          }

         if( ( - epsilon < biggest_val ) && ( biggest_val < epsilon ) )
          {
           return NAN;
          }
         if( 0 == biggest_index )
          {
           return 1;
          }

         for( index=0; index < size; index++ )
          {
           coefficient[index] /= biggest_val;
          }

         return biggest_val;
        }

      template< typename scalar_name >
       inline
       scalar_name normalize( ::math::polynomial::structure::dynamic< scalar_name > &coefficient, scalar_name const& epsilon = 1e-6 )
        {
         return math::polynomial::normalize( coefficient.data(), coefficient.size(), epsilon );
        }
        
      template< typename scalar_name, ::math::type::size_type size_number >
       inline
       scalar_name normalize( ::math::polynomial::structure::fixed< scalar_name, size_number > &coefficient, scalar_name const& epsilon = 1e-6 )
        {
         return math::polynomial::normalize( coefficient.data(), coefficient.size(), epsilon );
        }

    }
  }
#endif
