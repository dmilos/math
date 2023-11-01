#ifndef Dh_math_linear_homography_redomain
 #define Dh_math_linear_homography_redomain

 // ::math::linear::homography::redomain<scalar_name,dimension_number>( result, H, source )
 // ::math::linear::homography::redomain<scalar_name,dimension_number>( result, H, domain, source )


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
       bool redomain
        (
          ::math::linear::homography::structure<scalar_name,dimension_number>        & result //!<  operates on source give result on whatever
         ,::math::linear::homography::structure<scalar_name,dimension_number>   const& H      //!< operates on [-1,...,-1] x [ +1, ..., +1 ] give result on whatever
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& source
        ) // result = H * source
        {
         typedef ::math::linear::homography::structure<scalar_name,dimension_number>  homography_type;
         homography_type source2domain;  ::math::linear::matrix::zero( source2domain );

         for( int index =0; index < dimension_number; ++index  )
          {
           auto const& a = source[0][index];
           auto const& b = source[1][index];

           source2domain[ index ][ index ] = scalar_name(2)/( b - a );
           source2domain[ index ][ dimension_number ] = -( scalar_name(2)*a/(b-a) + scalar_name(1) );
          }
         source2domain  [ dimension_number ][ dimension_number ] = 1;

         ::math::linear::matrix::multiply( result, H, source2domain );
         return true;
        }

      template < typename scalar_name, ::math::type::size_type dimension_number  >
       bool redomain
        (
          ::math::linear::homography::structure<scalar_name,dimension_number>        & result //!< operates on source give result on whatever
         ,::math::linear::homography::structure<scalar_name,dimension_number>   const& H      //!< operates on domain give result on whatever
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& domain
         ,::math::geometry::interval::structure<scalar_name,dimension_number>   const& source
        ) // codomain = ( result(source) == H * source2domain ( source )
        {
         typedef ::math::linear::homography::structure<scalar_name,dimension_number>  homography_type;
         homography_type source2domain; ::math::linear::matrix::zero( source2domain );

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

          }
         source2domain [ dimension_number ][ dimension_number ] = 1;

         ::math::linear::matrix::multiply( result, H,  source2domain );
         return true;
        }

     }
   }
 }

#endif
