#ifndef Dh_math_linear_homography_constructN
#define Dh_math_linear_homography_constructN

 // ::math::linear::homography::construct( result, T );
 // ::math::linear::homography::construct_invert( result, T );

#include "../vector/vector.hpp"
#include "../matrix/invert.hpp"
#include "../matrix/transform.hpp"
#include "./structure.hpp"
#include "./convert.hpp"


namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template<  typename scalar_name, ::math::type::size_type dimension_number >
       void construct //!< This is always true :D
        (
          ::math::linear::homography::structure<scalar_name, dimension_number >        & result
         ,::math::linear::vector::structure< scalar_name, dimension_number >      const& T
         , scalar_name const& epsilon = 1e-8
        ) //!< ( 1, ... ) -> T
        {
         ::math::linear::matrix::zero( result );

         for( ::math::type::size_type i=0; i< dimension_number; ++i )
          {
           result[i][i] = (dimension_number-1)*T[i];
          }

         result[dimension_number][dimension_number] = -1;

         for( ::math::type::size_type i=0; i< dimension_number; ++i )
          {
           result[dimension_number][dimension_number] += T[i];

           result[dimension_number][i] = 1;
           for( ::math::type::size_type j=0; j< dimension_number; ++j )
            {
             if( i == j )
              {
               result[dimension_number][i] += (dimension_number-2)*T[j];
              }
             else
              {
               result[dimension_number][i] -= T[j];
              }
            }
          }
         return;
        }

      template<  typename scalar_name, ::math::type::size_type dimension_number >
       void construct_invert //!< This is always true :D
        (
          ::math::linear::homography::structure<scalar_name, dimension_number>        & result
         ,::math::linear::vector::structure< scalar_name, dimension_number >     const& T
         , scalar_name const& epsilon = 1e-8
        ) //!< T -> ( 1, ... )
        {
         ::math::linear::matrix::zero( result );

         result[dimension_number][dimension_number] = dimension_number-1;
         for( ::math::type::size_type i=0; i < dimension_number; ++i )
          {
           result[dimension_number][dimension_number] *= T[i];
          }

         scalar_name summae = -1;
         for( ::math::type::size_type i=0; i < dimension_number; ++i )
          {
           summae += T[i];
          }

         for( ::math::type::size_type i=0; i < dimension_number; ++i )
          {
           result[i][i] = summae;
           for( ::math::type::size_type j=0; j < dimension_number; ++j )
            {
             if( i == j ) continue;
             result[i][i] *= T[j];
            }
          }

         for( ::math::type::size_type i=0; i < dimension_number; ++i )
          {
           result[dimension_number][i] = summae - (dimension_number-1)*T[i];
           for( ::math::type::size_type j=0; j < dimension_number; ++j )
            {
             if( i == j ) continue;
             result[dimension_number][i] *= T[j];
            }
          }
        }

      template<  typename scalar_name, ::math::type::size_type dimension_number >
       void construct //!< This is always true :D
        (
          ::math::linear::homography::structure<scalar_name, dimension_number>        & result
         ,::math::linear::vector::structure< scalar_name, dimension_number >     const& T
         ,::math::linear::vector::structure< scalar_name, dimension_number >     const& S
         , scalar_name const& epsilon = 1e-8
        ) //!< S -> T
        {
         ::math::linear::matrix::zero( result );

         scalar_name summae_S = -1;
         scalar_name summae_T = -1;
         for( ::math::type::size_type i=0; i < dimension_number; ++i )
          {
           summae_S += S[ i ];
           summae_T += T[ i ];
          }

         result[dimension_number][dimension_number] = 1;
         for( ::math::type::size_type i=0; i < dimension_number; ++i )
          {
           result[dimension_number][dimension_number] *= S[i];
          }
         result[dimension_number][dimension_number] *= summae_T;

         for( ::math::type::size_type i=0; i < dimension_number; ++i )
          {
           result[i][i] = summae_S * T[i];
           for( ::math::type::size_type j=0; j < dimension_number; ++j )
            {
             if( i == j ) continue;
             result[i][i] *= S[j];
            }
          }

         for( ::math::type::size_type i=0; i < dimension_number; ++i )
          {
           result[dimension_number][i] = 0;
           result[dimension_number][i] += T[i] * ( summae_S - S[i]  );
           result[dimension_number][i] -= S[i] * ( summae_T - T[i]  );
           for( ::math::type::size_type j=0; j < dimension_number; ++j )
            {
             if( i == j ) continue;
             result[dimension_number][i] *= S[j];
            }
          }

        }

     }
   }
 }

#endif
