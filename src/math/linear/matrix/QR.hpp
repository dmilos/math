#ifndef Dh_math_linear_matrix_QR
 #define Dh_math_linear_matrix_QR

 // ::math::linear::matrix::QR<scalar_name,width_number,height_number>( Q, R, A )

#include "./structure.hpp"
#include "./gs.hpp"





 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, ::math::type::size_type dimension_number >
        bool QR
         (
           ::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number>      & Q // Gram-Schmidt, orthogonal
          ,::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number>      & R // Upper triangle
          ,::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number> const& A
         ) //!< A = Q * R
         {
          typedef ::math::type::size_type size_type;
          typedef ::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number>  matrix_type;
          matrix_type      T;

          ::math::linear::matrix::transpose( T, A );

          if( false == ::math::linear::matrix::GramSchmidt( Q, T ) )
           {
            return false;
           }

          ::math::linear::matrix::zero( R );
          for( size_type i=0; i < dimension_number; ++i )
           for( size_type j=i; j < dimension_number; ++j )
            {
             R[i][j] = ::math::linear::vector::dot( Q[i], T[j] );
            }

          ::math::linear::matrix::transpose( Q );
          return true;
         }

      }
    }
  }

#endif
