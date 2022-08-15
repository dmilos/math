#ifndef math_library_linear_algebra__vector_aritmetic_scale_HPP_
 #define math_library_linear_algebra__vector_aritmetic_scale_HPP_

// ::math::linear::vector::scale( result, value, right )
// ::math::linear::vector::scale( result, value )



#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, ::math::type::size_type dimension_number, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number >      &
        scale
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
          ,                   value_name                                      const& value_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& right_param
         )
         {
          scalar_name      * I_result = result_param.data()+ dimension_number;
          scalar_name const* I_right  = right_param.data() + dimension_number;

          while( I_result != result_param.data() )
           {
            --I_result; --I_right;
             *I_result = scalar_name( value_param * *I_right );
           }
          return result_param;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 2 >       &
        scale
         (
           ::math::linear::vector::structure< scalar_name, 2 >       & result_param
          ,              value_name                             const& value_param
          ,::math::linear::vector::structure< scalar_name, 2 >  const& right_param
         )
         {
          result_param[0] = value_param * right_param[0];
          result_param[1] = value_param * right_param[1];
          return result_param;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 3 >       &
        scale
         (
           ::math::linear::vector::structure< scalar_name, 3 >       & result_param
          ,              value_name                             const& value_param
          ,::math::linear::vector::structure< scalar_name, 3 >  const& right_param
         )
         {
          result_param[0] = value_param * right_param[0];
          result_param[1] = value_param * right_param[1];
          result_param[2] = value_param * right_param[2];
          return result_param;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 4 > &
        scale
         (
           ::math::linear::vector::structure< scalar_name, 4 >       & result_param
          ,               value_name                            const& value_param
          ,::math::linear::vector::structure< scalar_name, 4 >  const& right_param
         )
         {
          result_param[0] = value_param * right_param[0];
          result_param[1] = value_param * right_param[1];
          result_param[2] = value_param * right_param[2];
          result_param[3] = value_param * right_param[3];
          return result_param;
         }

       template< typename scalar_name, ::math::type::size_type dimension_number, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number >      &
        scale
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
          ,                  value_name                          const& value_param
         )
         {
          scalar_name      * I_result = result_param.data()+ dimension_number;

          while( I_result != result_param.data() )
           {
            --I_result;
             *I_result *= scalar_name( value_param );
           }
          return result_param;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 2 > &
        scale
         (
           ::math::linear::vector::structure< scalar_name, 2 >        & result_param
          ,              value_name                 const& value_param
         )
         {
          result_param[0] = (scalar_name)( result_param[0] * value_param );
          result_param[1] = (scalar_name)( result_param[1] * value_param );
          return result_param;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 3 > &
        scale
         (
           ::math::linear::vector::structure< scalar_name, 3 >        & result_param
          ,              value_name                 const& value_param
         )
         {
          result_param[0] = (scalar_name)( result_param[0] * value_param );
          result_param[1] = (scalar_name)( result_param[1] * value_param );
          result_param[2] = (scalar_name)( result_param[2] * value_param );
          return result_param;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 4 > &
        scale
         (
           ::math::linear::vector::structure< scalar_name, 4 >        & result_param
          ,                value_name                            const& value_param
         )
         {
          result_param[0] = (scalar_name)( result_param[0] * value_param );
          result_param[1] = (scalar_name)( result_param[1] * value_param );
          result_param[2] = (scalar_name)( result_param[2] * value_param );
          result_param[3] = (scalar_name)( result_param[3] * value_param );
          return result_param;
         }

     }
   }
 }

#endif
