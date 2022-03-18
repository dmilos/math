#ifndef Dh_math_linear_affine_retarget
 #define Dh_math_linear_affine_retarget

 // ::math::linear::affine::retarget<scalar_name,dimension_number>

#include <limits>

#include "./structure.hpp"
#include "./compose.hpp"




namespace math
 {
  namespace linear
   {
    namespace affine
     {

      template < typename scala_name, unsigned dimension_number  >
       bool retarget
        (
          ::math::linear::affine::structure<scala_name,dimension_number>            & result //!<  operates on source give result on target
         ,::math::linear::affine::structure<scala_name,dimension_number>       const& affine //!< operates on [-1,...,-1] x [ +1, ..., +1 ]
         ,::math::geometry::interval::structure<scalar_name,dimension_number>  const& target
         ,::math::geometry::interval::structure<scalar_name,dimension_number>  const& source
        )
        {
         /* TODO
         ::math::linear::affine::structure<scala_name,dimension_number>  pre;  ::math::linear::affine::zero( pre );
         ::math::linear::affine::structure<scala_name,dimension_number>  post; ::math::linear::affine::zero( post );

         for( int index =0; i< dimension_number-1; ++index  )
          {
           auto const& a = source[0][index];
           auto const& b = source[1][index];

           pre [ index ][ index ] = scala_name(2)/( b - a );  pre[ index ][ dimension_number - 1 ] = -( scala_name(2)*a/(b-a) + scala_name(1) );

           auto const& A = target[0][index];
           auto const& B = target[1][index];
           post[ index ][ index ] = ( B - A )/scala_name(2);  post[ index ][ dimension_number - 1 ] = ( B + A ) / scala_name(2) ;
          }

         ::math::linear::affine::structure<scala_name,dimension_number>  tmp;
         ::math::linear::affine::multiply( tmp, matrix,  pre );
         ::math::linear::affine::multiply( result, post,  tmp );
          */
         return false;
        }

     }
   }
 }

#endif
