#ifndef math_library_linear_algebra__vector_aritmetic_unit_HPP_
 #define math_library_linear_algebra__vector_aritmetic_unit_HPP_

// ::math::linear::vector::unit( result, right )
// ::math::linear::vector::unit( result )


#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number > const&
        unit
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& right_param
         )
         {
          auto length = ::math::linear::vector::length( right_param );
          ::math::linear::vector::scale( result_param, scalar_name(1)/length, right_param );
          return result_param;
         }

       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number > const&
        unit
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >       & result_param
         )
         {
          auto length = ::math::linear::vector::length( result_param );
          ::math::linear::vector::scale( result_param, scalar_name(1)/length );
          return result_param;
         }

        template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
          ::math::linear::vector::structure< scalar_name, dimension_number > 
          unit
          (
            ::math::linear::vector::structure< scalar_name, dimension_number >  const& right_param
          )
         {
          auto length = ::math::linear::vector::length( right_param );
          ::math::linear::vector::structure< scalar_name, dimension_number >  result_param;
          ::math::linear::vector::scale( result_param, scalar_name(1)/length, right_param );

          return result_param;
         }

     }
   }
 }

#endif
