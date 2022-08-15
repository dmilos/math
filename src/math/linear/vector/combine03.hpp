#ifndef math_library_linear_algebra__vector_aritmetic_combine03_HPP_
 #define math_library_linear_algebra__vector_aritmetic_combine03_HPP_

 // ::math::linear::vector::combine( result, leftV, midC, midV, rightC, rightV )



#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number >      &
        combine
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& left_param
          ,                                 scalar_name                       const& coefficientM_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& middle_param
          ,                                 scalar_name                       const& coefficientR_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& right_param
         )
         {
          scalar_name      * I_result = result_param.data()+ dimension_number;
          scalar_name const* I_left   = left_param.data()  + dimension_number;
          scalar_name const* I_middle = middle_param.data()+ dimension_number;
          scalar_name const* I_right  = right_param.data() + dimension_number;

          while( I_result != result_param.data() )
           {
            --I_result; --I_left; --I_middle; --I_right;
             *I_result =                        *I_left
                         + coefficientM_param * *I_middle
                         + coefficientR_param * *I_right;
           }
          return result_param;
         }

       template< typename scalar_name >
        inline
        ::math::linear::vector::structure< scalar_name, 2 > &
        combine
         (
           ::math::linear::vector::structure< scalar_name, 2 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 2 > const& left_param
          ,            scalar_name                             const& coefficientM_param
          ,::math::linear::vector::structure< scalar_name, 2 > const& middle_param
          ,            scalar_name                             const& coefficientR_param
          ,::math::linear::vector::structure< scalar_name, 2 > const& right_param
         )
         {
          result_param[0] = left_param[0] + coefficientM_param*middle_param[0] + coefficientR_param*right_param[0];
          result_param[1] = left_param[1] + coefficientM_param*middle_param[1] + coefficientR_param*right_param[1];
          return result_param;
         }

       template< typename scalar_name >
        inline
        ::math::linear::vector::structure< scalar_name, 3 >      &
        combine
         (
           ::math::linear::vector::structure< scalar_name, 3 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 3 > const& left_param
          ,            scalar_name                             const& coefficientM_param
          ,::math::linear::vector::structure< scalar_name, 3 > const& middle_param
          ,            scalar_name                             const& coefficientR_param
          ,::math::linear::vector::structure< scalar_name, 3 > const& right_param
         )
         {
          result_param[0] = left_param[0] + coefficientM_param*middle_param[0] +coefficientR_param * right_param[0];
          result_param[1] = left_param[1] + coefficientM_param*middle_param[1] +coefficientR_param * right_param[1];
          result_param[2] = left_param[2] + coefficientM_param*middle_param[2] +coefficientR_param * right_param[2];
          return result_param;
         }

       template< typename scalar_name >
        inline
        ::math::linear::vector::structure< scalar_name, 4 >      &
        combine
         (
           ::math::linear::vector::structure< scalar_name, 4 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 4 > const& left_param
          ,            scalar_name                             const& coefficientM_param
          ,::math::linear::vector::structure< scalar_name, 4 > const& middle_param
          ,            scalar_name                             const& coefficientR_param
          ,::math::linear::vector::structure< scalar_name, 4 > const& right_param
         )
         {
          result_param[0] = left_param[0] + coefficientM_param*middle_param[0] +coefficientR_param*right_param[0];
          result_param[1] = left_param[1] + coefficientM_param*middle_param[1] +coefficientR_param*right_param[1];
          result_param[2] = left_param[2] + coefficientM_param*middle_param[2] +coefficientR_param*right_param[2];
          result_param[3] = left_param[3] + coefficientM_param*middle_param[3] +coefficientR_param*right_param[3];
          return result_param;
         }

     }
   }
 }

#endif