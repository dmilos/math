#ifndef math_library_linear_algebra__vector_aritmetic_combine2_HPP_
 #define math_library_linear_algebra__vector_aritmetic_combine2_HPP_

 // ::math::linear::vector::combine( result, leftC, leftV, rightC, rightV )



#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, unsigned dimension_number >
        inline
        void
        combine
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
          ,                                 scalar_name                       const& coefficientL_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& left_param
          ,                                 scalar_name                       const& coefficientR_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& right_param
         )
         {
          scalar_name      * I_result = result_param.data()+ dimension_number;
          scalar_name const* I_left   = left_param.data()  + dimension_number;
          scalar_name const* I_right  = right_param.data() + dimension_number;

          while( I_result != result_param.data() )
           {
            --I_result; --I_left; --I_right;
             *I_result = coefficientL_param * *I_left + coefficientR_param* *I_right;
           }
         }

       template< typename scalar_name >
        inline
        void
        combine
         (
           ::math::linear::vector::structure< scalar_name, 2 >      & result_param
          ,                            scalar_name             const& coefficientL_param
          ,::math::linear::vector::structure< scalar_name, 2 > const& left_param
          ,            scalar_name                             const& coefficientR_param
          ,::math::linear::vector::structure< scalar_name, 2 > const& right_param
         )
         {
          result_param[0] = coefficientL_param*left_param[0] + coefficientR_param*right_param[0];
          result_param[1] = coefficientL_param*left_param[1] + coefficientR_param*right_param[1];
         }

       template< typename scalar_name >
        inline
        void
        combine
         (
           ::math::linear::vector::structure< scalar_name, 3 >      & result_param
          ,                                 scalar_name        const& coefficientL_param
          ,::math::linear::vector::structure< scalar_name, 3 > const& left_param
          ,            scalar_name                             const& coefficientR_param
          ,::math::linear::vector::structure< scalar_name, 3 > const& right_param
         )
         {
          result_param[0] = coefficientL_param*left_param[0] + coefficientR_param * right_param[0];
          result_param[1] = coefficientL_param*left_param[1] + coefficientR_param * right_param[1];
          result_param[2] = coefficientL_param*left_param[2] + coefficientR_param * right_param[2];
         }

       template< typename scalar_name >
        inline
        void
        combine
         (
           ::math::linear::vector::structure< scalar_name, 4 >      & result_param
          ,                                 scalar_name        const& coefficientL_param
          ,::math::linear::vector::structure< scalar_name, 4 > const& left_param
          ,            scalar_name                             const& coefficientR_param
          ,::math::linear::vector::structure< scalar_name, 4 > const& right_param
         )
         {
          result_param[0] = coefficientL_param* left_param[0] + coefficientR_param*right_param[0];
          result_param[1] = coefficientL_param* left_param[1] + coefficientR_param*right_param[1];
          result_param[2] = coefficientL_param* left_param[2] + coefficientR_param*right_param[2];
          result_param[3] = coefficientL_param* left_param[3] + coefficientR_param*right_param[3];
         }

     }
   }
 }

#endif