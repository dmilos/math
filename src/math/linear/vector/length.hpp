#ifndef math_library_linear_algebra__vector_length_HPP_
 #define math_library_linear_algebra__vector_length_HPP_

// ::math::linear::vector::length( vector )
// ::math::linear::vector::length( result, model, length  )
// ::math::linear::vector::length( vector, length )

#include <cmath>

#include "./structure.hpp"

#include "./scale.hpp"
#include "./operator.hpp"
#include "./dot.hpp"

 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name=double, typename number_name, ::math::type::size_type dimension_number >
        inline
        scalar_name
        length
         (
          ::math::linear::vector::structure< number_name, dimension_number > const& vector_param
         )
         {
          return static_cast<scalar_name>( std::sqrt( ::math::linear::vector::dot( vector_param, vector_param ) ) );
         }

       template< typename scalar_name, ::math::type::size_type dimension_number/*, typename N_report */ >
        inline
        scalar_name //!<N_report
        length
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& model_param
          ,scalar_name                                                        const& length_param
          ,scalar_name                                                        const& epsilon_param = 1e-8
         )
         {
          using namespace ::math::linear::vector;

          scalar_name old_length = ::math::linear::vector::length<scalar_name,scalar_name,dimension_number>( model_param );
          if( old_length < epsilon_param ) return old_length;

          ::math::linear::vector::scale( result_param, length_param / old_length, model_param );

          return old_length;
         }

       template< typename scalar_name, ::math::type::size_type dimension_number/*, typename N_report */ >
        inline
        scalar_name
        length
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >    & vector_param
          ,scalar_name                                                      const& length_param
          ,scalar_name                                                      const& epsilon_param = 1e-8
         )
         {
          scalar_name old_length = ::math::linear::vector::length<scalar_name,scalar_name,dimension_number>( vector_param );
          if( old_length < epsilon_param ) return old_length;
          ::math::linear::vector::scale( vector_param, length_param / old_length );
          return old_length;
         }

      }
    }
  }



#endif
