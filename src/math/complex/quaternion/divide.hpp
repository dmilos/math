#ifndef Dh_math_complex_quaternion_divide_HPP_
 #define Dh_math_complex_quaternion_divide_HPP_

 // ::math::complex::quaternion::divide<scalar_name>

#include <array>

#include "./structure.hpp"
#include "./inverse.hpp"
#include "./multiply.hpp"


 namespace math
  {
   namespace complex
    {
     namespace quaternion
      {

       template< typename scalar_name >
        inline
        bool
        divide
         (
           ::math::complex::quaternion::structure< scalar_name >      & result_param
          ,::math::complex::quaternion::structure< scalar_name > const& l
         )
         {
          ::math::complex::quaternion::structure< scalar_name >  t;

          if( false == ::math::complex::quaternion::inverse( t, l ) )
           {
            return false;
           }
          ::math::complex::quaternion::multiply( result_param, t );
          return true;
         }


       template< typename scalar_name >
        inline
        bool
        divide
         (
           ::math::complex::quaternion::structure< scalar_name >      & result_param
          ,::math::complex::quaternion::structure< scalar_name > const& l
          ,::math::complex::quaternion::structure< scalar_name > const& r
         )
         {
          ::math::complex::quaternion::structure< scalar_name >  t;

          if( false == ::math::complex::quaternion::inverse( t, r ) )
           {
            return false;
           }
          ::math::complex::quaternion::multiply( result_param, l, t );
          return true;
         }


      }
    }
  }

#endif
