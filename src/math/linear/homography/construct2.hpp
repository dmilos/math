#ifndef Dh_math_linear_homography_construct2
#define Dh_math_linear_homography_construct2

 // ::math::linear::homography::construct2( )

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
          ::math::linear::homography::structure< scalar_name, 2 >        & result
         ,::math::linear::vector::structure< scalar_name, 2 >       const& T 
        ) //!< ( 1, 1 ) -> T
        {
         static scalar_name one = 1;
         static scalar_name zero = 0;
         scalar_name X = T[0];
         scalar_name Y = T[1];

         result[0][0] =       X;  result[0][1] =    zero;  result[0][2] = zero;
         result[1][0] =    zero;  result[1][1] =       Y;  result[1][2] = zero;
         result[2][0] = one - Y;  result[2][1] = one - X;  result[2][2] = X + Y - one;
        }

      template<  typename scalar_name >
       void construct_invert //!< This is always true :D
        (
          ::math::linear::homography::structure< scalar_name, 2 >        & result
         ,::math::linear::vector::structure< scalar_name, 2 >       const& T 
        )//!<  T -> ( 1, 1 )
        {
         static scalar_name one = 1;
         static scalar_name zero = 0;
         scalar_name X = T[0];
         scalar_name Y = T[1];
         scalar_name A = X + Y - one;

         result[0][0] =       Y * A;  result[0][1] =        zero;  result[0][2] = zero;
         result[1][0] =        zero;  result[1][1] =       X * A;  result[1][2] = zero;
         result[2][0] = Y*(Y - one);  result[2][1] = X*(X - one);  result[2][2] = X*Y;
        }

      template<  typename scalar_name >
       bool construct
        (
          ::math::linear::homography::structure<scalar_name,2> & result
         ,::math::linear::vector::structure< scalar_name, 2 >    const& a0, ::math::linear::vector::structure< scalar_name, 2 >    const& b0
         ,::math::linear::vector::structure< scalar_name, 2 >    const& a1, ::math::linear::vector::structure< scalar_name, 2 >    const& b1
         ,::math::linear::vector::structure< scalar_name, 2 >    const& a2, ::math::linear::vector::structure< scalar_name, 2 >    const& b2
         ,::math::linear::vector::structure< scalar_name, 2 >    const& a3, ::math::linear::vector::structure< scalar_name, 2 >    const& b3
        )
        { // a = source; b = target
         ::math::linear::matrix::structure< scalar_name, 8, 8 > m;

         m[0][0] = a0[0]; m[0][1] = a0[1]; m[0][2] = 1;  m[0][3] =     0; m[0][4] =     0; m[0][5] = 0;  m[0][6] = -a0[0]*b0[0]; m[0][7] = -a0[1]*b0[0];
         m[1][0] =     0; m[1][1] =     0; m[1][2] = 0;  m[1][3] = a0[0]; m[1][4] = a0[1]; m[1][5] = 1;  m[1][6] = -a0[0]*b0[1]; m[1][7] = -a0[1]*b0[1];

         m[2][0] = a1[0]; m[2][1] = a1[1]; m[2][2] = 1;  m[2][3] =     0; m[2][4] =     0; m[2][5] = 0;  m[2][6] = -a1[0]*b1[0]; m[2][7] = -a1[1]*b1[0];
         m[3][0] =     0; m[3][1] =     0; m[3][2] = 0;  m[3][3] = a1[0]; m[3][4] = a1[1]; m[3][5] = 1;  m[3][6] = -a1[0]*b1[1]; m[3][7] = -a1[1]*b1[1];

         m[4][0] = a2[0]; m[4][1] = a2[1]; m[4][2] = 1;  m[4][3] =     0; m[4][4] =     0; m[4][5] = 0;  m[4][6] = -a2[0]*b2[0]; m[4][7] = -a2[1]*b2[0];
         m[5][0] =     0; m[5][1] =     0; m[5][2] = 0;  m[5][3] = a2[0]; m[5][4] = a2[1]; m[5][5] = 1;  m[5][6] = -a2[0]*b2[1]; m[5][7] = -a2[1]*b2[1];

         m[6][0] = a3[0]; m[6][1] = a3[1]; m[6][2] = 1;  m[6][3] =     0; m[6][4] =     0; m[6][5] = 0;  m[6][6] = -a3[0]*b3[0]; m[6][7] = -a3[1]*b3[0];
         m[7][0] =     0; m[7][1] =     0; m[7][2] = 0;  m[7][3] = a3[0]; m[7][4] = a3[1]; m[7][5] = 1;  m[7][6] = -a3[0]*b3[1]; m[7][7] = -a3[1]*b3[1];

         ::math::linear::matrix::structure<scalar_name,8,8> i;
         if( false == ::math::linear::matrix::invert( i, m ) )
          {
           return false;
          }

         ::math::linear::vector::structure< scalar_name, 8 > coefficient;
         ::math::linear::vector::structure< scalar_name, 8 > free;
         free[0]=  b0[0];
         free[1]=  b0[1];
         free[2]=  b1[0];
         free[3]=  b1[1];
         free[4]=  b2[0];
         free[5]=  b2[1];
         free[6]=  b3[0];
         free[7]=  b3[1];

         ::math::linear::matrix::transform( coefficient, i, free );

         result[0][0] = coefficient[0];
         result[0][1] = coefficient[1];
         result[0][2] = coefficient[2];
         result[1][0] = coefficient[3];
         result[1][1] = coefficient[4];
         result[1][2] = coefficient[5];
         result[2][0] = coefficient[6];
         result[2][1] = coefficient[7];
         result[2][2] = 1; // TODO dislike

         return true;
        }

      template<  typename scalar_name >
       bool construct
        (
          ::math::linear::homography::structure<scalar_name,2> & result
         ,::math::linear::vector::structure< scalar_name, 2 >    const& b0 //!< ( 0,0 ) -> b0
         ,::math::linear::vector::structure< scalar_name, 2 >    const& b1 //!< ( 1,0 ) -> b1
         ,::math::linear::vector::structure< scalar_name, 2 >    const& b2 //!< ( 0,1 ) -> b2
         ,::math::linear::vector::structure< scalar_name, 2 >    const& b3 //!< ( 1,1 ) -> b3
        ) //!< construct by using matrix
        {
         ::math::linear::matrix::structure< scalar_name, 8, 8 > m;

         m[0][0] =     0; m[0][1] =     0; m[0][2] = 1;  m[0][3] =     0; m[0][4] =     0; m[0][5] = 0;  m[0][6] = -    0*b0[0]; m[0][7] = -    0*b0[0];
         m[1][0] =     0; m[1][1] =     0; m[1][2] = 0;  m[1][3] =     0; m[1][4] =     0; m[1][5] = 1;  m[1][6] = -    0*b0[1]; m[1][7] = -    0*b0[1];

         m[2][0] =     1; m[2][1] =     0; m[2][2] = 1;  m[2][3] =     0; m[2][4] =     0; m[2][5] = 0;  m[2][6] = -    1*b1[0]; m[2][7] = -    0*b1[0];
         m[3][0] =     0; m[3][1] =     0; m[3][2] = 0;  m[3][3] =     1; m[3][4] =     0; m[3][5] = 1;  m[3][6] = -    1*b1[1]; m[3][7] = -    0*b1[1];

         m[4][0] =     0; m[4][1] =     1; m[4][2] = 1;  m[4][3] =     0; m[4][4] =     0; m[4][5] = 0;  m[4][6] = -    0*b2[0]; m[4][7] = -    1*b2[0];
         m[5][0] =     0; m[5][1] =     0; m[5][2] = 0;  m[5][3] =     0; m[5][4] =     1; m[5][5] = 1;  m[5][6] = -    0*b2[1]; m[5][7] = -    1*b2[1];

         m[6][0] =     1; m[6][1] =     1; m[6][2] = 1;  m[6][3] =     0; m[6][4] =     0; m[6][5] = 0;  m[6][6] = -    1*b3[0]; m[6][7] = -    1*b3[0];
         m[7][0] =     0; m[7][1] =     0; m[7][2] = 0;  m[7][3] =     1; m[7][4] =     1; m[7][5] = 1;  m[7][6] = -    1*b3[1]; m[7][7] = -    1*b3[1];

         ::math::linear::matrix::structure<scalar_name,8,8> i;
         if( false == ::math::linear::matrix::invert( i, m ) )
          {
           return false;
          }

         ::math::linear::vector::structure< scalar_name, 8 > coefficient;
         ::math::linear::vector::structure< scalar_name, 8 > free;
         free[0] = b0[0];
         free[1] = b0[1];
         free[2] = b1[0];
         free[3] = b1[1];
         free[4] = b2[0];
         free[5] = b2[1];
         free[6] = b3[0];
         free[7] = b3[1];

         ::math::linear::matrix::transform( coefficient, i, free );

         result[0][0] = coefficient[0];
         result[0][1] = coefficient[1];
         result[0][2] = coefficient[2];
         result[1][0] = coefficient[3];
         result[1][1] = coefficient[4];
         result[1][2] = coefficient[5];
         result[2][0] = coefficient[6];
         result[2][1] = coefficient[7];
         result[2][2] = 1; // TODO dislike

         return true;
        }

      template<  typename scalar_name >
       bool constructA
        (
          ::math::linear::homography::structure<scalar_name,2>        & result
         ,::math::linear::vector::structure< scalar_name, 2 >    const& O //!< { 0, 0 } -> O
         ,::math::linear::vector::structure< scalar_name, 2 >    const& X //!< { 1, 0 } -> X
         ,::math::linear::vector::structure< scalar_name, 2 >    const& Y //!< { 0, 1 } -> Y
         ,::math::linear::vector::structure< scalar_name, 2 >    const& T //!< { 1, 1 } -> T
        ) //!< construct by using affine
        {
         ::math::linear::affine::structure<scalar_name,2>  aa;
         ::math::linear::affine::construct( aa, { O, X, Y } ); //!< ideally find triplet with abs(highest) determinant and form system from them

         ::math::linear::homography::structure<scalar_name,2> hh;
         {
          ::math::linear::affine::structure<scalar_name,2>  ai;
          if( false == ::math::linear::affine::invert( ai, aa ) )
           {
            return false;
           }
          ::math::linear::vector::structure< scalar_name, 2 > t;
          ::math::linear::affine::transform( t, ai, T );
          ::math::linear::homography::construct( hh, t );
         }

         ::math::linear::homography::structure<scalar_name,2> ha;
         ::math::linear::homography::convert( ha, aa );
         ::math::linear::matrix::multiply( result, ha, hh );

         return true;
        }

      template<  typename scalar_name >
       bool constructA
        (
          ::math::linear::homography::structure<scalar_name,2> & result
         ,::math::linear::vector::structure< scalar_name, 2 >    const& a0, ::math::linear::vector::structure< scalar_name, 2 >    const& b0
         ,::math::linear::vector::structure< scalar_name, 2 >    const& a1, ::math::linear::vector::structure< scalar_name, 2 >    const& b1
         ,::math::linear::vector::structure< scalar_name, 2 >    const& a2, ::math::linear::vector::structure< scalar_name, 2 >    const& b2
         ,::math::linear::vector::structure< scalar_name, 2 >    const& a3, ::math::linear::vector::structure< scalar_name, 2 >    const& b3
        ) //!< construct by using affine // a= source; b = target
        {
          ::math::linear::homography::structure<scalar_name,2> hSd;
          if( false == ::math::linear::homography::constructA( hSd, a0, a1, a2, a3  ) )
           {
            return false;
           }

          ::math::linear::homography::structure<scalar_name,2> hSi;
          if( false == ::math::linear::matrix::invert( hSi, hSd ) )
           {
            return false;
           }

          ::math::linear::homography::structure<scalar_name,2> hT;
          if( false == ::math::linear::homography::constructA( hT, b0, b1, b2, b3 ) )
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
