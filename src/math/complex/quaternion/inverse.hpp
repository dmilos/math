#ifndef Dh_math_complex_quaternion_inverse_HPP_
 #define Dh_math_complex_quaternion_inverse_HPP_

// ::math::complex::quaternion::inverse<scalar_name>( result, model )
// ::math::complex::quaternion::inverse<scalar_name>( value )

#include <array>

#include "./structure.hpp"
#include "./scale.hpp"
#include "./length.hpp"


 namespace math
  {
   namespace complex
    {
     namespace quaternion
      {

       template< typename scalar_name >
        inline
        bool
        inverse
         (
           ::math::complex::quaternion::structure< scalar_name >       & value_param
          ,scalar_name                                            const& epsilon_param = 1e-8
         )
         {
          auto len = ::math::complex::quaternion::length( value_param );
          if( ( epsilon_param < len ) && ( len < epsilon_param ) )
           {
            return false;
           }
          ::math::complex::quaternion::scale( value_param, scalar_name(1) / len );
          return true;
         }

       template< typename scalar_name >
        inline
        bool
        inverse
         (
           ::math::complex::quaternion::structure< scalar_name >      & result_param
          ,::math::complex::quaternion::structure< scalar_name > const& value_param
          ,scalar_name                                           const& epsilon_param = 1e-8
         )
         {
          auto len = ::math::complex::quaternion::length( value_param );
          if( ( epsilon_param < len ) && ( len < epsilon_param ) )
           {
            return false;
           }
          ::math::complex::quaternion::scale( result_param, scalar_name(1) / len, value_param );
          return true;
         }

      }
    }
  }

#endif
