#ifndef math_library_linear_algebra__vector_aritmetic_negate_HPP_
 #define math_library_linear_algebra__vector_aritmetic_negate_HPP_

// ::math::linear::vector::negate( result, right )
// ::math::linear::vector::negate( result ) 


#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, ::math::type::size_type dimension_number>
        inline
        void
        negate
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& right_param
         )
         {
          scalar_name      * I_result = result_param.data()+ dimension_number;
          scalar_name const* I_right  = right_param.data() + dimension_number;

          while( I_result != result_param.data() )
           {
            --I_result; --I_right;
             *I_result = - *I_right;
           }
         }

       template< typename scalar_name >
        inline
        void
        negate
         (
           ::math::linear::vector::structure< scalar_name, 2 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 2 > const& right_param
         )
         {
          result_param[0] = - right_param[0];
          result_param[1] = - right_param[1];
         }

       template< typename scalar_name >
        inline
        void
        negate
         (
           ::math::linear::vector::structure< scalar_name, 3 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 3 > const& right_param
         )
         {
          result_param[0] = - right_param[0];
          result_param[1] = - right_param[1];
          result_param[2] = - right_param[2];
         }

       template< typename scalar_name >
        inline
        void
        negate
         (
           ::math::linear::vector::structure< scalar_name, 4 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 4 > const& right_param
         )
         {
          result_param[0] = - right_param[0];
          result_param[1] = - right_param[1];
          result_param[2] = - right_param[2];
          result_param[3] = - right_param[3];
         }

       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number > &
        negate
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
         )
         {
          scalar_name      * I_result = result_param.data()+ dimension_number;

          while( I_result != result_param.data() )
           {
            --I_result;
             *I_result = - *I_result;
           }
          return result_param;
         }

       template< typename scalar_name >
        inline
        ::math::linear::vector::structure< scalar_name, 2 > &
        negate
         (
           ::math::linear::vector::structure< scalar_name, 2 >      & result_param
         )
         {
          result_param[0] = - result_param[0];
          result_param[1] = - result_param[1];
          return result_param;
         }

       template< typename scalar_name >
        inline
        ::math::linear::vector::structure< scalar_name, 3 > &
        negate
         (
           ::math::linear::vector::structure< scalar_name, 3 >      & result_param
         )
         {
          result_param[0] = - result_param[0];
          result_param[1] = - result_param[1];
          result_param[2] = - result_param[2];
          return result_param;
         }

       template< typename scalar_name >
        inline
        ::math::linear::vector::structure< scalar_name, 4 >
        negate
         (
           ::math::linear::vector::structure< scalar_name, 4 >      & result_param
         )
         {
          result_param[0] = - result_param[0];
          result_param[1] = - result_param[1];
          result_param[2] = - result_param[2];
          result_param[3] = - result_param[3];
          return result_param;
         }

     }
   }
 }

#endif