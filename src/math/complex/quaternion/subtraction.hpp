#ifndef Dh_math_complex_quaternion_subtraction_HPP_
 #define Dh_math_complex_quaternion_subtraction_HPP_

 // ::math::complex::quaternion::subtraction<scalar_name>

//#include <array>

#include "./structure.hpp"


 namespace math
  {
   namespace complex
    {
     namespace quaternion
      {

       template< typename scalar_name >
        inline
        void
        subtraction
         (
           ::math::complex::quaternion::structure< scalar_name >      & result_param
          ,::math::complex::quaternion::structure< scalar_name > const& left_param
          ,::math::complex::quaternion::structure< scalar_name > const& right_param
         )
         {
          result_param[0] = left_param[0] - right_param[0];
          result_param[1] = left_param[1] - right_param[1];
          result_param[2] = left_param[2] - right_param[2];
          result_param[3] = left_param[3] - right_param[3];
         }


       template< typename scalar_name >
        inline
        void
        subtraction
         (
           ::math::complex::quaternion::structure< scalar_name >      & result_param
          ,::math::complex::quaternion::structure< scalar_name > const& left_param
         )
         {
          result_param[0] -= left_param[0];
          result_param[1] -= left_param[1];
          result_param[2] -= left_param[2];
          result_param[3] -= left_param[3];
         }
      }
    }
  }

#endif
