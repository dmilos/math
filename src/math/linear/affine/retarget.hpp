#ifndef Dh_math_linear_affine_retarget
 #define Dh_math_linear_affine_retarget

 // ::math::linear::affine::retarget<scalar_name,dimension_number>(result, A, source, target )

#include <limits>

#include "./structure.hpp"
#include "./structure.hpp"
#include "../../geometry/interval/structure.hpp"




namespace math
 {
  namespace linear
   {
    namespace affine
     {

      template < typename scalar_name, ::math::type::size_type dimension_number  >
       bool retarget
        (
          ::math::linear::affine::structure<scalar_name,dimension_number>            & result //!< operates on @source give result on @target
         ,::math::linear::affine::structure<scalar_name,dimension_number>       const&      A //!< operates on [-1,...,-1] x [ +1, ..., +1 ]
         ,::math::geometry::interval::structure<scalar_name,dimension_number>  const& target
         ,::math::geometry::interval::structure<scalar_name,dimension_number>  const& source
        ) // result = target * A * source
        {
         ::math::linear::affine::structure<scalar_name,dimension_number>  pre;  ::math::linear::affine::one( pre );
         ::math::linear::affine::structure<scalar_name,dimension_number>  post; ::math::linear::affine::one( post );

         for( int index = 0; index < dimension_number; ++index )
          {
           auto const& a = source[0][index];
           auto const& b = source[1][index];

           pre.matrix() [ index ][ index ] = scalar_name(2)/( b - a );  
           pre.vector()[ index ] = -( scalar_name(2)*a/(b-a) + scalar_name(1) );

           auto const& A = target[0][index];
           auto const& B = target[1][index];
           post.matrix()[ index ][ index ] = ( B - A )/scalar_name(2);  
           post.vector()[ index ] = ( B + A ) / scalar_name(2) ;
          }

         ::math::linear::affine::structure<scalar_name,dimension_number>  tmp;
         ::math::linear::affine::compose( tmp, A,  pre );
         ::math::linear::affine::compose( result, post,  tmp );
         return true;
        }

     }
   }
 }

#endif
