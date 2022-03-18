#ifndef Dh_math_linear_matrix_id
 #define Dh_math_linear_matrix_id

 // ::math::linear::matrix::id<scalar_name,width_number,height_number>()
 // ::math::linear::matrix::id( m )

#include "./one.hpp"


 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        ::math::linear::matrix::structure<scalar_name,width_number,height_number> &
        id( ::math::linear::matrix::structure<scalar_name,width_number,height_number> & m )
         {
          return ::math::linear::matrix::one( m );
         }

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        ::math::linear::matrix::structure<scalar_name,width_number,height_number> const&
        id()
         {
          return ::math::linear::matrix::one<scalar_name,width_number,height_number>();
         }

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        ::math::linear::matrix::structure<scalar_name,width_number,height_number> const&
        id( ::math::linear::matrix::structure<scalar_name,width_number,height_number> const& dummmy )
         {
          return ::math::linear::matrix::one( dummmy );
         }

      }
    }
  }

#endif
