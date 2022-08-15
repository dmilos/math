#ifndef Dh_math_linear_homography_retarget
 #define Dh_math_linear_homography_retarget

 // ::math::linear::homography::retarget<scalar_name,dimension_number>( result, H, target, source )

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

           pre [ index ][ index ] = scalar_name(2)/( b - a );  
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
         ::math::linear::matrix::multiply( result, post,  tmp );
         return true;
        }

     }
   }
 }

#endif
