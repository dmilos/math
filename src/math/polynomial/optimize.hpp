#ifndef Dh_DDMRM_math_polynomial_optimize_HPP_
 #define Dh_DDMRM_math_polynomial_optimize_HPP_

// math::polynomial::optimize( result, coefficient, size, epsilon = 1e-8 )
// math::polynomial::optimize( coefficient, size, epsilon = 1e-8 ) //!< in-place
// math::polynomial::optimize( coefficient, epsilon = 1e-8 )

#include <array>

 namespace math
   {
    namespace polynomial
     {


     template< typename scalar_name >
      inline
      void
      optimize( scalar_name* result, scalar_name const* coefficient, std::size_t const& size, scalar_name const& epsilon = 1e-8 )
       {
        for( std::size_t  index=0; index < size; index++ )
         {
          if( fabs( coefficient[index] ) < epsilon )
           {
            result[index] = 0;
           }
          else
           {
            result[index] = coefficient[index];
           }
         }
       }
       
      template< typename scalar_name, unsigned size_number >
      inline
      void
      optimize( std::array< scalar_name, size_number> & result, std::array< scalar_name, size_number> const& coefficient, scalar_name const& epsilon = 1e-8 )
       {
        math::polynomial::optimize( result.data(), coefficient.data(), size_number, epsilon );
       }

     template< typename scalar_name >
      inline
      void
      optimize( scalar_name* coefficient, std::size_t const& size, scalar_name const& epsilon = 1e-8 )
       { //! In place version
        for( std::size_t  index=0; index < size; index++ )
         {
          if( fabs( coefficient[index] ) < epsilon )
           {
            coefficient[index] = 0;
           }
         }
       }

      template< typename scalar_name, ::math::type::size_type size_number >
       inline
       void optimize( std::array< scalar_name, size_number> &coefficient, scalar_name const& epsilon = 1e-6 )
        {
         return math::polynomial::optimize( coefficient.data(), coefficient.size(), epsilon );
        }

    }
  }

#endif
