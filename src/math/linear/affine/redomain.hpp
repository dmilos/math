#ifndef Dh_math_linear_affine_redomain
 #define Dh_math_linear_affine_redomain

 // ::math::linear::affine::redomain<scalar_name,dimension_number>( result, A, source )
 // ::math::linear::affine::redomain<scalar_name,dimension_number>( result, A, domain, source )

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
       bool redomain
        (
          ::math::linear::affine::structure<scalar_name,dimension_number>           & result //!< operates on @source give result on @target
         ,::math::linear::affine::structure<scalar_name,dimension_number>      const&      A //!< operates on [-1,...,-1] x [ +1, ..., +1 ]
         ,::math::geometry::interval::structure<scalar_name,dimension_number>  const& source
        ) // result = A * source
        {
         typedef  ::math::linear::affine::structure<scalar_name,dimension_number>  affine_type;
         affine_type  pre;  ::math::linear::affine::one( pre );

         for( int index = 0; index < dimension_number; ++index )
          {
           auto const& l = source[0][index];
           auto const& r = source[1][index];

           pre.matrix() [ index ][ index ] = scalar_name(2)/( r - l );
           pre.vector()[ index ] = -( scalar_name(2)*l/(r-l) + scalar_name(1) );

          }

         ::math::linear::affine::compose( result, A,  pre );
         return true;
        }


      template < typename scalar_name, ::math::type::size_type dimension_number  >
       bool redomain
        (
          ::math::linear::affine::structure<scalar_name,dimension_number>            & result //!< operates on source give result on target
         ,::math::linear::affine::structure<scalar_name,dimension_number>       const& A      //!< operates on domain == codomain
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& domain
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& source
        ) // target = ( result(source) == H * source2domain ( source )
        {
         typedef  ::math::linear::affine::structure<scalar_name,dimension_number>  affine_type;
         affine_type source2domain; ::math::linear::affine::one( source2domain );

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

          }

         affine_type  tmp;
         ::math::linear::affine::compose( result, A, source2domain );
         return true;
        }

     }
   }
 }

#endif
