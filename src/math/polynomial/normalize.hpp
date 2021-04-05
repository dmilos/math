#ifndef _math_polynomial_normaliza_HPP_
 #define _math_polynomial_normaliza_HPP_

// math::polynomial::normalize( coefficient, size, epsilon = 1e-6 )
// math::polynomial::normalize( coefficient, size, epsilon = 1e-6 )

#include <vector>

#include "./structure.hpp"

 namespace math
   {
    namespace polynomial
     {

      template< typename scalar_name >
       inline
       scalar_name normalize( scalar_name* coefficient, std::size_t const& size, scalar_name const& epsilon = 1e-12 )
        {
         std::size_t  index;
         scalar_name  biggest= coefficient[0];

         for( index=0; index < size; index++ )
          {
           if( biggest < fabs( coefficient[index] ) )
            {
             biggest = coefficient[index];
            }
          }

         if( ( - epsilon < biggest ) && ( biggest < epsilon ) )
          {
           return NAN;
          }

         for( index=0; index < size; index++ )
          {
           coefficient[index] /= biggest;
          }

         return biggest;
        }

      template< typename scalar_name >
       inline
       scalar_name normalize( ::math::polynomial::structure::dynamic< scalar_name > &coefficient, scalar_name const& epsilon = 1e-6 )
        {
         return math::polynomial::normalize( coefficient.data(), coefficient.size(), epsilon );
        }
        
      template< typename scalar_name, unsigned size_number >
       inline
       scalar_name normalize( ::math::polynomial::structure::fixed< scalar_name, size_number > &coefficient, scalar_name const& epsilon = 1e-6 )
        {
         return math::polynomial::normalize( coefficient.data(), coefficient.size(), epsilon );
        }

    }
  }
#endif
