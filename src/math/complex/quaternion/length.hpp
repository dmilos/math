#ifndef Dh_math_complex_quaternion_length_HPP_
 #define Dh_math_complex_quaternion_length_HPP_

// ::math::complex::quaternion::length<scalar_name>( value )

#include <array>

#include "./structure.hpp"
#include "../../linear/vector/length.hpp"


 namespace math
  {
   namespace complex
    {
     namespace quaternion
      {

       template< typename scalar_name=double, typename number_name>
        inline
        scalar_name
        length
         (
          ::math::complex::quaternion::structure< number_name > const& vector_param
         )
         {
          return ::math::linear::vector::length<scalar_name,number_name>( vector_param );
         }

       template< typename scalar_name  >
        inline
        scalar_name //!<N_report
        length
         (
           ::math::complex::quaternion::structure< scalar_name >       & result_param
          ,::math::complex::quaternion::structure< scalar_name >  const& model_param
          ,scalar_name                                            const& length_param
        //,scalar_name                                            const& epsilon_param
         )
         {
          return ::math::linear::vector::length<scalar_name>( result_param, model_param, length_param );
         }

       template< typename scalar_name  >
        inline
        scalar_name
        length
         (
           ::math::complex::quaternion::structure< scalar_name >    & vector_param
          ,scalar_name                                         const& length_param
        //,scalar_name                                         const& epsilon_param
         )
         {
          return ::math::linear::vector::length<scalar_name>( vector_param, length_param );
         }

      }
    }
  }

#endif
