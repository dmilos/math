#ifndef math_library_linear_algebra__vector_cross_HPP_
 #define math_library_linear_algebra__vector_cross_HPP_

 // ::math::linear::vector::cross( result, left )
 // ::math::linear::vector::cross( result, left, right )


#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name >
        inline
        void
        cross
         (
           ::math::linear::vector::structure< scalar_name, 2 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 2 > const& left_param
         )
         {
          result_param[0] =  left_param[1];
          result_param[1] = -left_param[0];
         }

       template< typename scalar_name >
        inline
        void
        cross
         (
           ::math::linear::vector::structure< scalar_name, 3 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 3 > const& left_param
          ,::math::linear::vector::structure< scalar_name, 3 > const& right_param
         )
         {
          result_param[0] =   left_param[1] * right_param[2]  -  left_param[2] * right_param[1];
          result_param[1] =-( left_param[0] * right_param[2]  -  left_param[2] * right_param[0] );
          result_param[2] =   left_param[0] * right_param[1]  -  left_param[1] * right_param[0];
         }

       template< typename scalar_name >
        inline
        void
        cross
         (
           ::math::linear::vector::structure< scalar_name, 4 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 4 > const& left_param
          ,::math::linear::vector::structure< scalar_name, 4 > const& right_param
          ,::math::linear::vector::structure< scalar_name, 4 > const& P_time
         )
         {
          //result_param[0] =   left_param[1] * right_param[2]  -  left_param[2] * right_param[1] ;
          //result_param[1] =-( left_param[0] * right_param[2]  -  left_param[2] * right_param[0] );
          //result_param[2] =   left_param[0] * right_param[1]  -  left_param[1] * right_param[0];
          //result_param[3] =-( left_param[0] * right_param[1]  -  left_param[1] * right_param[0] );
         }

      }
    }
  }

#endif