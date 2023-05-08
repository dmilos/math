#ifndef Dh_math_linear_affine_retarget
 #define Dh_math_linear_affine_retarget

 // ::math::linear::affine::retarget<scalar_name,dimension_number>( result, A, target, source )
 // ::math::linear::affine::retarget<scalar_name,dimension_number>( result, A, target, domain, source )
 // ::math::linear::affine::retarget<scalar_name,dimension_number>( result, A, target, codomain, domain, source )

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
         typedef  ::math::linear::affine::structure<scalar_name,dimension_number>  affine_type;
         affine_type  pre;  ::math::linear::affine::one( pre );
         affine_type  post; ::math::linear::affine::one( post );

         for( int index = 0; index < dimension_number; ++index )
          {
           auto const& l = source[0][index];
           auto const& r = source[1][index];

           pre.matrix() [ index ][ index ] = scalar_name(2)/( r - l );
           pre.vector()[ index ] = -( scalar_name(2)*l/(r-l) + scalar_name(1) );

           auto const& L = target[0][index];
           auto const& R = target[1][index];
           post.matrix()[ index ][ index ] = ( R - L )/scalar_name(2);
           post.vector()[ index ] = ( R + L ) / scalar_name(2) ;
          }

         affine_type  tmp;
         ::math::linear::affine::compose( tmp, A,  pre );
         ::math::linear::affine::compose( result, post,  tmp );
         return true;
        }


      template < typename scalar_name, ::math::type::size_type dimension_number  >
       bool retarget
        (
          ::math::linear::affine::structure<scalar_name,dimension_number>        & result //!< operates on source give result on target
         ,::math::linear::affine::structure<scalar_name,dimension_number>   const& A      //!< operates on domain == codomain
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& target
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& domain
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& source
        ) // target = ( result(source) == domain2target H * source2domain ( source )
        {
         typedef  ::math::linear::affine::structure<scalar_name,dimension_number>  affine_type;
         affine_type source2domain; ::math::linear::affine::one( source2domain );
         affine_type domain2target; ::math::linear::affine::one( domain2target );

         for( int index =0; index < dimension_number; ++index  )
          {
           auto const& L = domain[0][index];
           auto const& R = domain[1][index];
           {
            auto const& l = source[0][index];
            auto const& r = source[1][index];

            source2domain.matrix()[ index ][ index ] = ( R - L )/( r - l );
            source2domain.vector()[ index ] = ( -l/ ( r - l ) ) * ( R - L ) + L;
           }

           {
            auto const& l = target[0][index];
            auto const& r = target[1][index];
            domain2target.matrix()[ index ][ index ] = ( r - l )/( R - L );
            domain2target.vector()[ index ] = ( -L / ( R - L )) * ( r - l ) + l;
           }
          }

         affine_type  tmp;
         ::math::linear::affine::compose( tmp, A,  source2domain );
         ::math::linear::affine::compose( result, domain2target,  tmp );
         return true;

         return true;
        }


      template < typename scalar_name, ::math::type::size_type dimension_number  >
       bool retarget
        (
          ::math::linear::affine::structure<scalar_name,dimension_number>        & result //!< operates on source give result on target
         ,::math::linear::affine::structure<scalar_name,dimension_number>   const& A      //!< operates on domain, result on codomain
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& target
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& codomain
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& domain
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& source
        ) // target = ( result(source) == codomain2target * H * source2domain ( source )
        {
         typedef  ::math::linear::affine::structure<scalar_name,dimension_number>  affine_type;
         affine_type source2domain; ::math::linear::affine::one( source2domain );
         affine_type codomain2target; ::math::linear::affine::one( codomain2target );

         for( int index =0; index < dimension_number; ++index  )
          {

           {
            auto const& L = domain[0][index];
            auto const& R = domain[1][index];
            auto const& l = source[0][index];
            auto const& r = source[1][index];

            source2domain.matrix()[ index ][ index ] = ( R - L )/( r - l );
            source2domain.vector()[ index ]          = (-l/ ( r - l ) ) * ( R - L ) + L;
           }

           {
            auto const& R =   target[0][index];
            auto const& L =   target[1][index];
            auto const& r = codomain[0][index];
            auto const& l = codomain[1][index];

            codomain2target.matrix()[ index ][ index ] = ( R - L )/( r - l );
            codomain2target.vector()[ index ]          = (-l/ ( r - l ) ) * ( R - L ) + L;
           }
          }

         affine_type  tmp;
         ::math::linear::affine::compose( tmp, A,  source2domain );
         ::math::linear::affine::compose( result, codomain2target, tmp );
         return true;
        }
     }
   }
 }

#endif
