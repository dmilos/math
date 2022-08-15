#ifndef Dh_math_linear_matrix_row
 #define Dh_math_linear_matrix_row

 // ::math::linear::matrix::row<scalar_name,width_number,height_number>( r, m, index )
 // ::math::linear::matrix::row<scalar_name,width_number,height_number>( m, index, r )

#include "./structure.hpp"



 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, ::math::type::size_type width_number, ::math::type::size_type height_number >
        void row
         (
           ::math::linear::vector::structure<scalar_name, width_number>                      & r
          ,::math::linear::matrix::structure<scalar_name, width_number, height_number > const& m
          , ::math::type::size_type                                                     const& index
         )
         {
          // for( std::size_t i=0; i < width_number; ++i )
          //  {
          //   r[ i ] = m[ index ][ i ];
          //  }

          r = m[index];
         }

       template< typename scalar_name, ::math::type::size_type width_number, ::math::type::size_type height_number >
        void row
         (
           ::math::linear::matrix::structure<scalar_name, width_number, height_number >     & m
          ,std::size_t                                                                 const& index
          ,::math::linear::vector::structure<scalar_name, width_number>                const& r
         )
         {
          // for( std::size_t i=0; i < width_number; ++i )
          //  {
          //   m[ index ][ i ] = r[ i ];
          //  }

          m[index] = r;
         }

      }
    }
  }

#endif
