#ifndef Dh_math_linear_homography_retarget
 #define Dh_math_linear_homography_retarget

 // ::math::linear::homography::retarget<scalar_name,dimension_number>( result, H, target, source )
 // ::math::linear::homography::retarget<scalar_name,dimension_number>( result, H, target, domain, source )
 // ::math::linear::homography::retarget<scalar_name,dimension_number>( result, H, target, codomain, domain, source )

#include <limits>

#include "./structure.hpp"
#include "../matrix/zero.hpp"
#include "../matrix/multiply.hpp"





namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template < typename scalar_name, ::math::type::size_type dimension_number  >
       bool retarget
        (
          ::math::linear::homography::structure<scalar_name,dimension_number>        & result //!<  operates on source give result on target
         ,::math::linear::homography::structure<scalar_name,dimension_number>   const& H      //!< operates on [-1,...,-1] x [ +1, ..., +1 ]
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& target
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& source
        ) // result = target * H * source
        {
         ::math::linear::homography::structure<scalar_name,dimension_number>  pre;  ::math::linear::matrix::zero( pre );
         ::math::linear::homography::structure<scalar_name,dimension_number>  post; ::math::linear::matrix::zero( post );

         for( int index =0; index < dimension_number; ++index  )
          {
           auto const& a = source[0][index];
           auto const& b = source[1][index];

           pre[ index ][ index ] = scalar_name(2)/( b - a );
           pre[ index ][ dimension_number ] = -( scalar_name(2)*a/(b-a) + scalar_name(1) );

           auto const& A = target[0][index];
           auto const& B = target[1][index];
           post[ index ][ index ] = ( B - A )/scalar_name(2);
           post[ index ][ dimension_number ] = ( B + A ) / scalar_name(2) ;
          }
         pre  [ dimension_number ][ dimension_number ] = 1;
         post [ dimension_number ][ dimension_number ] = 1;

         ::math::linear::homography::structure<scalar_name,dimension_number>  tmp;
         ::math::linear::matrix::multiply( tmp, H,  pre );
         ::math::linear::matrix::multiply( result, post, tmp );
         return true;
        }

      template < typename scalar_name, ::math::type::size_type dimension_number  >
       bool retarget
        (
          ::math::linear::homography::structure<scalar_name,dimension_number>        & result //!< operates on source give result on target
         ,::math::linear::homography::structure<scalar_name,dimension_number>   const& H      //!< operates on domain == codomain
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& target
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& domain
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& source
        ) // target = ( result(source) == domain2target H * source2domain ( source )
        {
         typedef ::math::linear::homography::structure<scalar_name,dimension_number>  homography_type;
         homography_type source2domain; ::math::linear::matrix::zero( source2domain );
         homography_type domain2target; ::math::linear::matrix::zero( domain2target );

         for( int index =0; index < dimension_number; ++index  )
          {

           auto const& A = domain[0][index];
           auto const& B = domain[1][index];
           {
            auto const& a = source[0][index];
            auto const& b = source[1][index];

            source2domain[ index ][ index ] = ( B - A )/( b - a );
            source2domain[ index ][ dimension_number ] = ( -a/ ( b - a ) ) * ( B - A ) + A;
           }

           {
            auto const& a = target[0][index];
            auto const& b = target[1][index];
            domain2target[ index ][ index ] = ( b - a )/( B - A );
            domain2target[ index ][ dimension_number ] = ( -A / ( B - A )) * ( b - a ) + a;
           }
          }
         source2domain [ dimension_number ][ dimension_number ] = 1;
         domain2target [ dimension_number ][ dimension_number ] = 1;

         homography_type  tmp;
         ::math::linear::matrix::multiply( tmp, H,  source2domain );
         ::math::linear::matrix::multiply( result, domain2target,  tmp );
         return true;
        }

      template < typename scalar_name, ::math::type::size_type dimension_number  >
       bool retarget
        (
          ::math::linear::homography::structure<scalar_name,dimension_number>        & result //!< operates on source give result on target
         ,::math::linear::homography::structure<scalar_name,dimension_number>   const& H      //!< operates on domain, result on codomain
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& target
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& codomain
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& domain
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& source
        ) // target = ( result(source) == codomain2target * H * source2domain ( source )
        {
         typedef ::math::linear::homography::structure<scalar_name,dimension_number>  homography_type;
         homography_type source2domain;    ::math::linear::matrix::zero( source2domain );
         homography_type codomain2target;  ::math::linear::matrix::zero( codomain2target );

         for( int index =0; index < dimension_number; ++index  )
          {

           {
            auto const& A = domain[0][index];
            auto const& B = domain[1][index];
            auto const& a = source[0][index];
            auto const& b = source[1][index];

            source2domain[ index ][ index ] = ( B - A )/( b - a );
            source2domain[ index ][ dimension_number ] = (-a/ ( b - a ) ) * ( B - A ) + A;
           }

           {
            auto const& A =   target[0][index];
            auto const& B =   target[1][index];
            auto const& a = codomain[0][index];
            auto const& b = codomain[1][index];

            codomain2target[ index ][ index ] = ( B - A )/( b - a );
            codomain2target[ index ][ dimension_number ] = (-a/ ( b - a ) ) * ( B - A ) + A;
           }

          }
         source2domain   [ dimension_number ][ dimension_number ] = 1;
         codomain2target [ dimension_number ][ dimension_number ] = 1;

         homography_type  tmp;
         ::math::linear::matrix::multiply( tmp, H,  source2domain );
         ::math::linear::matrix::multiply( result, codomain2target,  tmp );
         return true;
        }


     }
   }
 }

#endif
