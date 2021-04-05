#ifndef math_library_linear_make_HPP_
 #define math_library_linear_make_HPP_

 // ::math::linear::vector::make( result, left, right )
 // ::math::linear::vector::make( result, left, right )
 // ::math::linear::vector::make( result, left, right )



#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 2 >
        make
         (
            value_name const& x
          , value_name const& y
         )
         {
          ::math::linear::vector::structure< scalar_name, 2 >       result;
          result[0] = x;
          result[1] = y;
          return result;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 3 >
        make
         (
            value_name   const& x
          , value_name   const& y
          , value_name   const& z
         )
         {
          ::math::linear::vector::structure< scalar_name, 3 >       result;
          result[0] = x;
          result[1] = y;
          result[2] = z;
          return result;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 4 >
        make
         (
            value_name   const& x
          , value_name   const& y
          , value_name   const& z
          , value_name   const& t
         )
         {
          ::math::linear::vector::structure< scalar_name, 4 >       result;
          result[0] = x;
          result[1] = y;
          result[2] = z;
          result[2] = t;
          return result;
         }

     }
   }
 }

#endif