#ifndef math_library_linear_algebra__vector_aritmetic_load_HPP_
 #define math_library_linear_algebra__vector_aritmetic_load_HPP_

 // ::math::linear::vector::load( result, value )



#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 2 > &
        load
         (
           ::math::linear::vector::structure< scalar_name, 2 >       & result_param
          ,            value_name                  const& x_param
          ,            value_name                  const& y_param
         )
         {
          result_param[0] = x_param;
          result_param[1] = y_param;
          return result_param;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 2 >
        load
         (
           ::math::linear::vector::structure< scalar_name, 2 >  const& dummy_param
          ,            value_name                               const& x_param
          ,            value_name                               const& y_param
         )
         {
          ::math::linear::vector::structure< scalar_name, 2 > result;
          result[0] = x_param;
          result[1] = y_param;
          return result;
         }


       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 3 > &
        load
         (
           ::math::linear::vector::structure< scalar_name, 3 >       & result_param
          ,            value_name                  const& x_param
          ,            value_name                  const& y_param
          ,            value_name                  const& z_param
         )
         {
          result_param[0] = x_param;
          result_param[1] = y_param;
          result_param[2] = z_param;
          return result_param;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 3 >
        load
         (
           ::math::linear::vector::structure< scalar_name, 3 >   const& dummy_param
          ,            value_name                  const& x_param
          ,            value_name                  const& y_param
          ,            value_name                  const& z_param
         )
         {
          ::math::linear::vector::structure< scalar_name, 3 > result;
          result[0] = scalar_name( x_param );
          result[1] = scalar_name( y_param );
          result[2] = scalar_name( z_param );
          return result;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 4 > &
        load
         (
           ::math::linear::vector::structure< scalar_name, 4 >       & result_param
          ,            value_name                  const& x_param
          ,            value_name                  const& y_param
          ,            value_name                  const& z_param
          ,            value_name                  const& t_param
         )
         {
          result_param[0] = scalar_name( x_param );
          result_param[1] = scalar_name( y_param );
          result_param[2] = scalar_name( z_param );
          result_param[3] = scalar_name( t_param );
          return result_param;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 4 >
        load
         (
           ::math::linear::vector::structure< scalar_name, 4 >   const& dummy_param
          ,            value_name                  const& x_param
          ,            value_name                  const& y_param
          ,            value_name                  const& z_param
          ,            value_name                  const& t_param
         )
         {
          ::math::linear::vector::structure< scalar_name, 3 > result;
          result[0] = x_param;
          result[1] = y_param;
          result[2] = z_param;
          result[3] = t_param;
          return result;
         }



     }
   }
 }

#endif