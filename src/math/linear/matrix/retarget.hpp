#ifndef Dh_math_linear_matrix_retarget
 #define Dh_math_linear_matrix_retarget

// ::math::linear::matrix::retarget<scalar_name,dimension_number>( result, matrix, target, source )

#include <limits>

#include "../vector/structure.hpp"
#include "./structure.hpp"
#include "./multiply.hpp"




namespace math
 {
  namespace linear
   {
    namespace matrix
     {

      template < typename scalar_name, ::math::type::size_type dimension_number  >
       bool retarget
        (
          ::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number>            & result //!<  operates on source give result on target
         ,::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number>       const& matrix //!< operates on [-1,...,-1] x [ +1, ..., +1 ]
         ,::math::linear::vector::structure<scalar_name,dimension_number>                               const& target
         ,::math::linear::vector::structure<scalar_name,dimension_number>                               const& source
        )
        {
         typedef ::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number> matrix_type;
         matrix_type  pre;  ::math::linear::matrix::zero( pre );
         matrix_type  post; ::math::linear::matrix::zero( post );

         for( int index = 0; index < dimension_number; ++index )
          {
           auto const & a = source[index];

           pre [ index ][ index ] = scalar_name(1)/a;

           auto const & A = target[index];
           post[ index ][ index ] = A;
          }

         matrix_type  tmp;
         ::math::linear::matrix::multiply( tmp, matrix,  pre );
         ::math::linear::matrix::multiply( result, post,  tmp );

         return true;
        }

     }
   }
 }

#endif
