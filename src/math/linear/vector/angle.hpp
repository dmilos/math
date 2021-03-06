#ifndef math_library_linear_algebra__vector_angle_HPP_
 #define math_library_linear_algebra__vector_angle_HPP_

 // ::math::linear::vector::angle( left, right )



#include "./structure.hpp"

 #include "./dot.hpp"
 #include "./length.hpp"


 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, unsigned dimension_number >
        inline
        scalar_name
        angle
         (
           ::math::linear::vector::structure< scalar_name, dimension_number > const& left_param
         , ::math::linear::vector::structure< scalar_name, dimension_number > const& right_param
         )
         {
          scalar_name left_len  = ::math::linear::vector::length( left_param );
          scalar_name right_len = ::math::linear::vector::length( right_param );
          scalar_name dot       = ::math::linear::vector::dot( left_param, right_param );
          scalar_name   cosinus =  dot / left_len / right_len;
                        cosinus =  ( ( cosinus < scalar_name(-1) ) ? scalar_name(-1) : ( ( scalar_name(+1) < cosinus ) ? scalar_name(+1) : cosinus ) );
          return std::acos( cosinus );
         }

      }
    }
  }



#endif
