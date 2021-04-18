#ifndef math_library_linear_algebra__vector_orientation_HPP_
 #define math_library_linear_algebra__vector_orientation_HPP_

 // ::math::linear::vector::orientation( left, right )



#include "./structure.hpp"

 #include "./extend.hpp"


 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name >
        inline
        scalar_name
        orientation
         (
           ::math::linear::vector::structure< scalar_name, 2 > const& left_param
          ,::math::linear::vector::structure< scalar_name, 2 > const& right_param
          ,scalar_name const& epsilon = 1e-6
         )
         {
          scalar_name o =   left_param[0] * right_param[1]  -  left_param[1] * right_param[0];

          if( o < -epsilon ) return -1;
          if( +epsilon < o ) return +1;
          return 0;
         }

      }
    }
  }



#endif
