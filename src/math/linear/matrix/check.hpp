#ifndef Dh_math_linear_matrix_check
 #define Dh_math_linear_matrix_check

// ::math::linear::matrix::check( dynamic )

#include "./structure.hpp"



 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template
        <
          typename scalar_name
        >
        bool check( ::math::linear::matrix::fringe<scalar_name> const& m )
         {
          for( auto const& row : m )
           {
            if( m[0].size() != row.size() ) return false;
           }
          return true;
         }

       template
        <
          typename scalar_name
        >
        bool check
         ( 
          ::math::linear::matrix::fringe<scalar_name> const& m
          , ::math::type::size_type                   const&  width_number
          ,::math::type::size_type                    const& height_number 
         )
         {
          return (width_number * height_number) == m.size();
         }

      }
    }
  }

#endif
