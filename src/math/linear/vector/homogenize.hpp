#ifndef math_library_linear_algebra__vector_aritmetic_homogenize_HPP_
 #define math_library_linear_algebra__vector_aritmetic_homogenize_HPP_

 // ::math::linear::vector::homogenize( result, right )
 // ::math::linear::vector::homogenize( result )



#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, unsigned dimension_number>
        inline
        void
        homogenize
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& right_param
         )
         {
          scalar_name      * I_result = result_param.data()+ dimension_number - 1;
          scalar_name const* I_right  = right_param.data() + dimension_number - 1;

          while( I_result != result_param.data() )
           {
            --I_result; --I_right;
            *I_result = *I_right / right_param[dimension_number-1];
           }
          result_param[dimension_number-1] = 1;
         }

       template< typename scalar_name >
        inline
        void
        homogenize
         (
           ::math::linear::vector::structure< scalar_name, 2 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 2 > const& right_param
         )
         {
          result_param[0] = right_param [0]/ right_param[1];
          result_param[1] = 1;
         }

       template< typename scalar_name >
        inline
        void
        homogenize
         (
           ::math::linear::vector::structure< scalar_name, 3 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 3 > const& right_param
         )
         {
          result_param[0] = right_param [0]/ right_param[2];
          result_param[1] = right_param [1]/ right_param[2];
          result_param[2]  = 1;
         }

       template< typename scalar_name >
        inline
        void
        homogenize
         (
           ::math::linear::vector::structure< scalar_name, 4 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 4 > const& right_param
         )
         {
          result_param[0] = right_param [0]/ right_param[3];
          result_param[1] = right_param [1]/ right_param[3];
          result_param[2] = right_param [2]/ right_param[3];
          result_param[3] = 1;
         }

       template< typename scalar_name, unsigned dimension_number >
        inline
        void
        homogenize
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
         )
         {
          scalar_name      * I_result = result_param.data()+ dimension_number - 1;

          while( I_result != result_param.data() )
           {
            --I_result;
            *I_result /= result_param[dimension_number-1];
           }
          result_param[dimension_number-1] = 1;
         }

       template< typename scalar_name >
        inline
        void
        homogenize
         (
           ::math::linear::vector::structure< scalar_name, 2 >      & result_param
         )
         {
          result_param[0] /= result_param[1];
          result_param[1] = 1;
         }

       template< typename scalar_name >
        inline
        void
        homogenize
         (
           ::math::linear::vector::structure< scalar_name, 3 >      & result_param
         )
         {
          result_param[0] /= result_param[2];
          result_param[1] /= result_param[2];
          result_param[2] = 1;
         }

       template< typename scalar_name >
        inline
        void
        homogenize
         (
           ::math::linear::vector::structure< scalar_name, 4 >      & result_param
         )
         {
          result_param[0] /= result_param[3];
          result_param[1] /= result_param[3];
          result_param[2] /= result_param[3];
          result_param[3] = 1;
         }

     }
   }
 }

#endif