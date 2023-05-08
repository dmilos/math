#ifndef Dh_math_linear_homography_recodomain
 #define Dh_math_linear_homography_recodomain

 // ::math::linear::homography::recodomain<scalar_name,dimension_number>( result, H, target)
 // ::math::linear::homography::recodomain<scalar_name,dimension_number>( result, H, target, codomain )


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
       bool recodomain
        (
          ::math::linear::homography::structure<scalar_name,dimension_number>        & result //!<
         ,::math::linear::homography::structure<scalar_name,dimension_number>   const& H      //!< codomain is [-1,...,-1] x [ +1, ..., +1 ]
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& target
        ) // result = target * H
        {
         ::math::linear::homography::structure<scalar_name,dimension_number>  codomain2target; ::math::linear::matrix::zero( codomain2target );

         for( int index =0; index < dimension_number; ++index  )
          {
           auto const& A = target[0][index];
           auto const& B = target[1][index];
           codomain2target[ index ][ index ] = ( B - A )/scalar_name(2);
           codomain2target[ index ][ dimension_number ] = ( B + A ) / scalar_name(2) ;
          }
         codomain2target [ dimension_number ][ dimension_number ] = 1;

         ::math::linear::matrix::multiply( result, codomain2target, H );
         return true;
        }

      template < typename scalar_name, ::math::type::size_type dimension_number  >
       bool recodomain
        (
          ::math::linear::homography::structure<scalar_name,dimension_number>        & result //!< operates on source give result on target
         ,::math::linear::homography::structure<scalar_name,dimension_number>   const& H      //!< result on target
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& target
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& codomain
        ) // target = ( result(source) == codomain2target * H
        {
         typedef ::math::linear::homography::structure<scalar_name,dimension_number>  homography_type;
         homography_type codomain2target;  ::math::linear::matrix::zero( codomain2target );

         for( int index =0; index < dimension_number; ++index  )
          {
           auto const& A =   target[0][index];
           auto const& B =   target[1][index];
           auto const& a = codomain[0][index];
           auto const& b = codomain[1][index];

           codomain2target[ index ][ index ] = ( B - A )/( b - a );
           codomain2target[ index ][ dimension_number ] = (-a/ ( b - a ) ) * ( B - A ) + A;
          }
         codomain2target [ dimension_number ][ dimension_number ] = 1;

         ::math::linear::matrix::multiply( result, codomain2target,  H );
         return true;
        }


     }
   }
 }

#endif
