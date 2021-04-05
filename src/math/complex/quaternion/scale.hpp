#ifndef Dh_math_complex_quaternion_scale_HPP_
 #define Dh_math_complex_quaternion_scale_HPP_

 // ::math::complex::quaternion::scale<scalar_name>

#include <array>

#include "./structure.hpp"


 namespace math
  {
   namespace complex
    {
     namespace quaternion
      {

       template< typename scalar_name, typename value_name >
        inline
        void
        scale
         (
           ::math::complex::quaternion::structure< scalar_name >       & result_param
          ,               value_name                              const& value_param
          ,::math::complex::quaternion::structure< scalar_name >  const& right_param
         )
         {
          result_param[0] = value_param * right_param[0];
          result_param[1] = value_param * right_param[1];
          result_param[2] = value_param * right_param[2];
          result_param[3] = value_param * right_param[3];
         }


       template< typename scalar_name, typename value_name >
        inline
        void
        scale
         (
           ::math::complex::quaternion::structure< scalar_name >       & result_param
          ,               value_name                              const& value_param
         )
         {
          result_param[0] *= value_param;
          result_param[1] *= value_param;
          result_param[2] *= value_param;
          result_param[3] *= value_param;
         }

      }
    }
  }

#endif
