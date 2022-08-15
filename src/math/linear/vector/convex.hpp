#ifndef math_library_linear_algebra__vector_aritmetic_convex_HPP_
 #define math_library_linear_algebra__vector_aritmetic_convex_HPP_

 // ::math::linear::vector::convex( result, coefficient, left, right )

 
 
#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        void
        convex
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
          ,                                            scalar_name            const& coefficient_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& left_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& right_param
         )
         {
          scalar_name      * I_result = result_param.data()+ dimension_number;
          scalar_name const* I_left   = left_param.data()  + dimension_number;
          scalar_name const* I_right  = right_param.data() + dimension_number;

          while( I_result != result_param.data() )
           {
            --I_result; --I_left; --I_right;
             *I_result = *I_left + coefficient_param* ( *I_right - *I_left );
           }
         }

       template< typename scalar_name >
        inline
        void
        convex
         (
           ::math::linear::vector::structure< scalar_name, 2 >      & result_param
          ,            scalar_name                             const& coefficient_param
          ,::math::linear::vector::structure< scalar_name, 2 > const& left_param
          ,::math::linear::vector::structure< scalar_name, 2 > const& right_param
         )
         {
          result_param[0] = left_param[0] + coefficient_param*( right_param[0] - left_param[0] );
          result_param[1] = left_param[1] + coefficient_param*( right_param[1] - left_param[1] );
         }

       template< typename scalar_name >
        inline
        void
        convex
         (
           ::math::linear::vector::structure< scalar_name, 3 >      & result_param
          ,            scalar_name                             const& coefficient_param
          ,::math::linear::vector::structure< scalar_name, 3 > const& left_param
          ,::math::linear::vector::structure< scalar_name, 3 > const& right_param
         )
         {
          result_param[0] = left_param[0] + coefficient_param*( right_param[0] - left_param[0] );
          result_param[1] = left_param[1] + coefficient_param*( right_param[1] - left_param[1] );
          result_param[2] = left_param[2] + coefficient_param*( right_param[2] - left_param[2] );
         }

       template< typename scalar_name >
        inline
        void
        convex
         (
           ::math::linear::vector::structure< scalar_name, 4 >      & result_param
          ,            scalar_name                             const& coefficient_param
          ,::math::linear::vector::structure< scalar_name, 4 > const& left_param
          ,::math::linear::vector::structure< scalar_name, 4 > const& right_param
         )
         {
          result_param[0] = left_param[0] + coefficient_param*( right_param[0] - left_param[0] );
          result_param[1] = left_param[1] + coefficient_param*( right_param[1] - left_param[1] );
          result_param[2] = left_param[2] + coefficient_param*( right_param[2] - left_param[2] );
          result_param[3] = left_param[3] + coefficient_param*( right_param[3] - left_param[3] );
         }

     }
   }
 }

#endif