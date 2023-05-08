#ifndef Dh_math_linear_affine_recodomain
 #define Dh_math_linear_affine_recodomain

 // ::math::linear::affine::recodomain<scalar_name,dimension_number>( result, A, target  )
 // ::math::linear::affine::recodomain<scalar_name,dimension_number>( result, A, target, codomain)

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
       bool recodomain
        (
          ::math::linear::affine::structure<scalar_name,dimension_number>           & result //!< operates on @source give result on @target
         ,::math::linear::affine::structure<scalar_name,dimension_number>      const&      A //!< codomain is [-1,...,-1] x [ +1, ..., +1 ]
         ,::math::geometry::interval::structure<scalar_name,dimension_number>  const& target
        ) // result = target * A
        {
         typedef  ::math::linear::affine::structure<scalar_name,dimension_number>  affine_type;
         affine_type  post; ::math::linear::affine::one( post );

         for( int index = 0; index < dimension_number; ++index )
          {
           auto const& L = target[0][index];
           auto const& R = target[1][index];
           post.matrix()[ index ][ index ] = ( R - L )/scalar_name(2);
           post.vector()[ index ] = ( R + L ) / scalar_name(2) ;
          }

         ::math::linear::affine::compose( result, post, A );
         return true;
        }


      template < typename scalar_name, ::math::type::size_type dimension_number  >
       bool recodomain
        (
          ::math::linear::affine::structure<scalar_name,dimension_number>            & result //!< operates on source give result on target
         ,::math::linear::affine::structure<scalar_name,dimension_number>       const& A
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& target
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& codomain
        ) // target = ( result(source) == codomain2target * A
        {
         typedef  ::math::linear::affine::structure<scalar_name,dimension_number>  affine_type;
         affine_type codomain2target; ::math::linear::affine::one( codomain2target );

         for( int index =0; index < dimension_number; ++index  )
          {
           auto const& R =   target[0][index];
           auto const& L =   target[1][index];
           auto const& r = codomain[0][index];
           auto const& l = codomain[1][index];

           codomain2target.matrix()[ index ][ index ] = ( R - L )/( r - l );
           codomain2target.vector()[ index ]          = (-l/ ( r - l ) ) * ( R - L ) + L;
          }

         ::math::linear::affine::compose( result, codomain2target, A );
         return true;
        }
     }
   }
 }

#endif
