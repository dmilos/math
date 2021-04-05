#ifndef math_library_linear_algebra__vector_distance_HPP_
 #define math_library_linear_algebra__vector_distance_HPP_

 // ::math::linear::vector::distance( left, right )



#include "./structure.hpp"

 #include "./length.hpp"
 #include "./operator.hpp"


 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, unsigned dimension_number >
        inline
        scalar_name
        distance
         (
           ::math::linear::vector::structure< scalar_name, dimension_number > const& left_param
          , ::math::linear::vector::structure< scalar_name, dimension_number > const& right_param
         )
         {
          ::math::linear::vector::structure< scalar_name, dimension_number > heading;
          ::math::linear::vector::subtraction( heading, left_param, right_param );
          return ::math::linear::vector::length( heading );
         }

       template< typename scalar_name >
        inline
        scalar_name
        distance
         (
           ::math::linear::vector::structure< scalar_name, 2> const& left_param
         , ::math::linear::vector::structure< scalar_name, 2> const& right_param
         )
         {
          scalar_name Ir_distance, I_value;
          I_value = left_param[0] - right_param[0]; Ir_distance  = I_value * I_value;
          I_value = left_param[1] - right_param[1]; Ir_distance += I_value * I_value;
          return scalar_name( sqrt( Ir_distance ) );
         }

       template< typename scalar_name >
        inline
        scalar_name
        distance
         (
           ::math::linear::vector::structure< scalar_name, 3 > const& left_param
         , ::math::linear::vector::structure< scalar_name, 3 > const& right_param
         )
         {
          scalar_name Ir_distance, I_value;
          I_value = left_param[0] - right_param[0]; Ir_distance  = I_value * I_value;
          I_value = left_param[1] - right_param[1]; Ir_distance += I_value * I_value;
          I_value = left_param[2] - right_param[2]; Ir_distance += I_value * I_value;
          return scalar_name( sqrt( Ir_distance ) );
         }

       template< typename scalar_name >
        inline
        scalar_name
        distance
         (
           ::math::linear::vector::structure< scalar_name, 4 > const& left_param
         , ::math::linear::vector::structure< scalar_name, 4 > const& right_param
         )
         {
          scalar_name Ir_distance, I_value;
          I_value = left_param[0] - right_param[0]; Ir_distance  = I_value * I_value;
          I_value = left_param[1] - right_param[1]; Ir_distance += I_value * I_value;
          I_value = left_param[2] - right_param[2]; Ir_distance += I_value * I_value;
          I_value = left_param[3] - right_param[3]; Ir_distance += I_value * I_value;
          return scalar_name( sqrt( Ir_distance ) );
         }
      }
    }
  }

#endif