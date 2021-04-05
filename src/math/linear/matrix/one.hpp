#ifndef Dh_math_linear_matrix_one
 #define Dh_math_linear_matrix_one

 // ::math::linear::matrix::one<scalar_name,width_number,height_number>

#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        ::math::linear::matrix::structure<scalar_name,width_number,height_number> &
        one( ::math::linear::matrix::structure<scalar_name,width_number,height_number> & m )
         {
          for( unsigned i=0; i< height_number; i++ )
           for( unsigned j=0; j< width_number; j++ )
            {
             m[i][j] = scalar_name( 0 );
             if( i == j ) m[i][j] = scalar_name( 1 );
            }
          return m;
         }

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        ::math::linear::matrix::structure<scalar_name,width_number,height_number> const&
        one()
         {
          static ::math::linear::matrix::structure<scalar_name,width_number,height_number> identical = ::math::linear::matrix::one( identical );
          return identical;
         }

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        ::math::linear::matrix::structure<scalar_name,width_number,height_number> const&
        one( ::math::linear::matrix::structure<scalar_name,width_number,height_number> const& dummmy )
         {
          return ::math::linear::matrix::one<scalar_name,width_number,height_number>();
         }

      }
    }
  }

#endif
