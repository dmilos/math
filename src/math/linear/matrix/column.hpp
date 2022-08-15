#ifndef Dh_math_linear_matrix_column
 #define Dh_math_linear_matrix_column

 // ::math::linear::matrix::column/*<scalar_name,width_number,height_number>*/( column , matrix, index );
 // ::math::linear::matrix::column/*<scalar_name,width_number,height_number>*/(  matrix, index, column );

#include "./structure.hpp"


 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, ::math::type::size_type width_number, ::math::type::size_type height_number >
        void column
         (
           ::math::linear::vector::structure<scalar_name, height_number>                     & c
          ,::math::linear::matrix::structure<scalar_name, width_number, height_number > const& m
          , ::math::type::size_type                                                     const& index
         )
         {
          for( ::math::type::size_type i=0; i < height_number; ++i )
           {
            c[ i ] = m[ i ][ index ];
           }
         }

       template< typename scalar_name, ::math::type::size_type width_number, ::math::type::size_type height_number >
        void column
         (
           ::math::linear::matrix::structure<scalar_name, width_number, height_number >      & m
          , ::math::type::size_type                                                                 const& index
          ,::math::linear::vector::structure<scalar_name, height_number>                const& c
         )
         {
          for( ::math::type::size_type i=0; i < height_number; ++i )
           {
            m[ i ][ index ] = c[ i ];
           }
         }

      }
    }
  }

#endif

