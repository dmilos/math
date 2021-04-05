#ifndef Dh_math_complex_quaternion_multiply_HPP_
 #define Dh_math_complex_quaternion_multiply_HPP_

 // ::math::complex::quaternion::multiply<scalar_name>

#include <array>

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
        multiply
         (
           ::math::complex::quaternion::structure< scalar_name >      & result_param
          ,::math::complex::quaternion::structure< scalar_name > const& l
          ,::math::complex::quaternion::structure< scalar_name > const& r
         )
         {
          result_param[0] = l[0]*r[0] - l[1]*r[1] - l[2]*r[2] - l[3]*r[3];
          result_param[1] = l[1]*r[0] + l[0]*r[1] + l[2]*r[3] - l[3]*r[2];
          result_param[2] = l[0]*r[2] - l[1]*r[3] + l[2]*r[0] + l[3]*r[1];
          result_param[3] = l[0]*r[3] + l[1]*r[2] - l[2]*r[1] + l[3]*r[0];
         }

      }
    }
  }

#endif
