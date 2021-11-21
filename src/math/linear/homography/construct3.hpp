#ifndef math_geometry_homography_construct3
#define math_geometry_homography_construct3

 // ::math::linear::homography::construct( result, T );
 // ::math::linear::homography::construct_invert( result, T );
 // ::math::linear::homography::construct_invert( result, O, X, Y, Z );
 // ::math::linear::homography::construct_invert( result, source, target );

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

      template<  typename scalar_name >
       void construct //!< This is always true :D
        (
          ::math::linear::homography::structure<scalar_name,3>        & result
         ,::math::linear::vector::structure< scalar_name, 3 >    const& T 
         , scalar_name const& epsilon = 1e-8
        ) //!< ( 1, 1, 1 ) -> T
        {
         scalar_name X = T[0];
         scalar_name Y = T[1];
         scalar_name Z = T[2];

         scalar_name A =                      Y * Z * ( Z + Y - X - scalar_name(1) );
         scalar_name B =                  X *     Z * ( X - Y + Z - scalar_name(1) );
         scalar_name C =                  X * Y *     ( X + Y - Z - scalar_name(1) );
         scalar_name D = scalar_name(2) * X * Y * Z;

         scalar_name M = std::max< scalar_name > ( std::max< scalar_name >( fabs(A), fabs(B) ), std::max< scalar_name >( fabs(C), fabs(D) ) );
         if( epsilon < M ) 
          {
           A /= M; B /= M; C /= M; D /= M;
          }
         result[0][0] = D*(B+D)*(C+D);  result[1][0] = 0;              result[2][0] = 0;              result[3][0] = - A *             ( B + D ) * ( C + D ); 
         result[0][1] = 0;              result[1][1] = D*(A+D)*(C+D);  result[2][1] = 0;              result[3][1] = - B * ( A + D ) *             ( C + D ); 
         result[0][2] = 0;              result[1][2] = 0;              result[2][2] = D*(A+D)*(B+D);  result[3][2] = - C * ( A + D ) * ( B + D )            ;
         result[0][3] = 0;              result[1][3] = 0;              result[2][3] = 0;              result[3][3] =       ( A + D ) * ( B + D ) * ( C + D );
        }

      template<  typename scalar_name >
       void construct_invert //!< This is always true :D
        (
          ::math::linear::homography::structure<scalar_name,3>        & result
         ,::math::linear::vector::structure< scalar_name, 3 >    const& T 
         , scalar_name const& epsilon = 1e-8
        ) //!< T -> ( 1, 1, 1 )
        {
         scalar_name X = T[0];
         scalar_name Y = T[1];
         scalar_name Z = T[2];

         scalar_name A =                  Y * Z * ( Z + Y - X - scalar_name(1) );
         scalar_name B =                  X * Z * ( X - Y + Z - scalar_name(1) );
         scalar_name C =                  X * Y * ( X + Y - Z - scalar_name(1) );
         scalar_name D = scalar_name(2) * X * Y * Z;

         scalar_name M = std::max< scalar_name > ( std::max< scalar_name >( fabs(A), fabs(B) ), std::max< scalar_name >( fabs(C), fabs(D) ) );
         if( epsilon < M ) 
          {
           A /= M; B /= M; C /= M; D /= M;
          }

         result[0][0] = A + D;  result[1][0] = 0;     result[2][0] = 0;      result[3][0] = A;
         result[0][1] = 0;      result[1][1] = B + D; result[2][1] = 0;      result[3][1] = B;
         result[0][2] = 0;      result[1][2] = 0;     result[2][2] = C + D;  result[3][2] = C;
         result[0][3] = 0;      result[1][3] = 0;     result[2][3] = 0;      result[3][3] = D;
        }


      template<  typename scalar_name >
       bool construct
        (
          ::math::linear::homography::structure<scalar_name,3>        & result
         ,::math::linear::vector::structure< scalar_name, 3 >    const& O //!< { 0, 0, 0 } -> O
         ,::math::linear::vector::structure< scalar_name, 3 >    const& X //!< { 1, 0, 0 } -> X
         ,::math::linear::vector::structure< scalar_name, 3 >    const& Y //!< { 0, 1, 0 } -> Y
         ,::math::linear::vector::structure< scalar_name, 3 >    const& Z //!< { 0, 0, 1 } -> Z
         ,::math::linear::vector::structure< scalar_name, 3 >    const& T //!< { 1, 1, 1 } -> T
        )
        {
         ::math::linear::affine::structure<scalar_name,3>  aa;
         ::math::linear::affine::construct( aa, { O, X, Y, Z } );

         ::math::linear::homography::structure<scalar_name,3> hh;
         {
          ::math::linear::affine::structure<scalar_name,3>  ai;
          if( false == ::math::linear::affine::invert( ai, aa ) )
           {
            return false;
           }
          ::math::linear::vector::structure< scalar_name, 3 > t;
          ::math::linear::affine::transform( t, ai, T );
          ::math::linear::homography::construct( hh, t );
         }

         ::math::linear::homography::structure<scalar_name,3> ha;
         ::math::linear::homography::convert( ha, aa );
         ::math::linear::matrix::multiply( result, ha, hh );

         return true;
        }

      template<  typename scalar_name >
        bool construct
         (
           ::math::linear::homography::structure<scalar_name,3>               & result
          ,std::array< ::math::linear::vector::point<scalar_name,3>, 5 > const& target
          ,std::array< ::math::linear::vector::point<scalar_name,3>, 5 > const& source
         )
         {
          ::math::linear::homography::structure<scalar_name,3> hSd;
          if( false == ::math::linear::homography::construct( hSd, source[0], source[1], source[2], source[3], source[4] ) )
           {
            return false;
           }

          ::math::linear::homography::structure<scalar_name,3> hSi;
          if( false == ::math::linear::matrix::invert( hSi, hSd ) )
           {
            return false;
           }

          ::math::linear::homography::structure<scalar_name,3> hT;
          if( false == ::math::linear::homography::construct( hT, target[0], target[1], target[2], target[3], target[4] ) )
           {
            return false;
           }

          ::math::linear::matrix::multiply( result, hT, hSi );

          return true;
         }

     }
   }
 }

#endif
