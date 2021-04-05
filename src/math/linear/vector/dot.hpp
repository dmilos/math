#ifndef math_library_linear_algebra__vector_dot_HPP_
 #define math_library_linear_algebra__vector_dot_HPP_

 // ::math::linear::vector::dot( left, right )



#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, unsigned dimension_number >
        inline
        scalar_name
        dot
         (
           ::math::linear::vector::structure< scalar_name, dimension_number > const& left_param
         , ::math::linear::vector::structure< scalar_name, dimension_number > const& right_param
         )
         {
          auto I_projection = dimension_number;
          scalar_name const *I_left  = &left_param[0];
          scalar_name const *I_right = &right_param[0];
          scalar_name Ir_result(0);

          while( I_projection-- )
           {
            Ir_result += *I_left * *I_right;
            ++I_left; ++I_right;
           }

          return Ir_result;
         }

       template< typename scalar_name >
        inline
        scalar_name
        dot
         (
           ::math::linear::vector::structure< scalar_name, 2> const& left_param
         , ::math::linear::vector::structure< scalar_name, 2> const& right_param
         )
         {
          return   left_param[0]*right_param[0]
                +  left_param[1]*right_param[1];
         }

       template< typename scalar_name >
        inline
        scalar_name
        dot
         (
           ::math::linear::vector::structure< scalar_name, 3 > const& left_param
         , ::math::linear::vector::structure< scalar_name, 3 > const& right_param
         )
         {
          return  left_param[0]*right_param[0]
                + left_param[1]*right_param[1]
                + left_param[2]*right_param[2];
         }

       template< typename scalar_name >
        inline
        scalar_name
        dot
         (
           ::math::linear::vector::structure< scalar_name, 4 > const& left_param
         , ::math::linear::vector::structure< scalar_name, 4 > const& right_param
         )
         {
          return  left_param[0]*right_param[0]
                + left_param[1]*right_param[1]
                + left_param[2]*right_param[2]
                + left_param[3]*right_param[3];
         }
      }
    }
  }

#endif
