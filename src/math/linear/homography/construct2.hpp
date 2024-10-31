#ifndef Dh_math_linear_homography_construct2
#define Dh_math_linear_homography_construct2

 // ::math::linear::homography::construct( result, T )
 // ::math::linear::homography::construct_invert( result, S )
 // ::math::linear::homography::construct( result, T, S )

 // ::math::linear::homography::construct( result, b0, b1, b2, b3 )
 // ::math::linear::homography::constructA( result, O, X, Y, T )
 // ::math::linear::homography::constructBB( result, S0, Sx, Sy, Sz, T0, Tx, Ty, Tz )
 // ::math::linear::homography::constructPH( result, b0, b1, b2, b3 )



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
         auto const&  X = T[0];
         auto const&  Y = T[1];

         result[0][0] =       X;  result[0][1] =    zero;  result[0][2] = zero;
         result[1][0] =    zero;  result[1][1] =       Y;  result[1][2] = zero;
         result[2][0] = one - Y;  result[2][1] = one - X;  result[2][2] = X + Y - one;
        }

      template<  typename scalar_name >
       void construct_invert //!< This is always true :D
        (
          ::math::linear::homography::structure< scalar_name, 2 >        & result
         ,::math::linear::vector::structure< scalar_name, 2 >       const& S
        )//!<  S -> ( 1, 1 )
        {
         static scalar_name one = 1;
         static scalar_name zero = 0;
         auto const& X = S[0];
         auto const& Y = S[1];
         scalar_name A = X + Y - one;

         result[0][0] =       Y * A;  result[0][1] =        zero;  result[0][2] = zero;
         result[1][0] =        zero;  result[1][1] =       X * A;  result[1][2] = zero;
         result[2][0] = Y*(Y - one);  result[2][1] = X*(X - one);  result[2][2] = X*Y;
        }

      template<  typename scalar_name >
       void construct //!< This is always true :D
        (
          ::math::linear::homography::structure< scalar_name, 2 >        & result
         ,::math::linear::vector::structure< scalar_name, 2 >       const& T
         ,::math::linear::vector::structure< scalar_name, 2 >       const& S
        ) //!< S -> T
        {
         ::math::linear::homography::structure< scalar_name, 2 >  toOne, fromOne;
         ::math::linear::homography::construct( toOne, fromOne );
         ::math::linear::homography::construct_invert( fromOne, T );

         ::math::linear::matrix::multiply( result, fromOne, toOne );
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

      template<  typename scalar_name >
       bool constructBB
        (
          ::math::linear::homography::structure<scalar_name,2> & result
         ,::math::linear::vector::structure< scalar_name, 2 >    const& S0, ::math::linear::vector::structure< scalar_name, 2 >    const& T0
         ,::math::linear::vector::structure< scalar_name, 2 >    const& Sx, ::math::linear::vector::structure< scalar_name, 2 >    const& Tx
         ,::math::linear::vector::structure< scalar_name, 2 >    const& Sy, ::math::linear::vector::structure< scalar_name, 2 >    const& Ty
         ,::math::linear::vector::structure< scalar_name, 2 >    const& Sz, ::math::linear::vector::structure< scalar_name, 2 >    const& Tz
        ) //!< construct by according the paper
        {
         ::math::linear::vector::structure<scalar_name,3> temp;

         ::math::linear::homography::structure<scalar_name,2> Ts;
         Ts[0][0] = 1;   Ts[0][1] = 0; Ts[0][2] = -S0[0];
         Ts[1][0] = 0;   Ts[1][1] = 1; Ts[1][2] = -S0[1];
         Ts[2][0] = 0;   Ts[2][1] = 0; Ts[2][2] = 1;

         ::math::linear::homography::structure<scalar_name,2> Ls;

         ::math::linear::vector::structure<scalar_name,3> a_x;
         ::math::linear::matrix::transform( a_x, Ts, {Sx[0],Sx[1],1} );
         ::math::linear::vector::structure<scalar_name,3> a_y;
         ::math::linear::matrix::transform( a_y, Ts, { Sy[0],Sy[1],1} );

         Ls[0][0] =  a_y[1];  Ls[0][1] = -a_y[0]; Ls[0][2] = 0;
         Ls[1][0] = -a_x[1];  Ls[1][1] =  a_x[0]; Ls[1][2] = 0;
         Ls[2][0] =       0;  Ls[2][1] =       0; Ls[2][2] = a_x[0] * a_y[1] - a_x[1] * a_y[0];

         ::math::linear::homography::structure<scalar_name,2> Ps;
         ::math::linear::vector::structure<scalar_name,3> a_z;
         ::math::linear::matrix::transform( temp, Ts, {Sz[0],Sz[1],1} );
         ::math::linear::matrix::transform( a_z, Ls, temp );

         auto X = a_z[0];
         auto Y = a_z[1];
         Ps[0][0] =   Y*( X+Y-1); Ps[0][1] =          0; Ps[0][2] = 0;
         Ps[1][0] =   0;          Ps[1][1] = X*( X+Y-1); Ps[1][2] = 0;
         Ps[2][0] = Y*(Y-1);      Ps[2][1] = X*(X-1);    Ps[2][2] = X*Y;

         ::math::linear::homography::structure<scalar_name,2> Tti;
         Tti[0][0] = 1;   Tti[0][1] = 0; Tti[0][2] = +T0[0];
         Tti[1][0] = 0;   Tti[1][1] = 1; Tti[1][2] = +T0[1];
         Tti[2][0] = 0;   Tti[2][1] = 0; Tti[2][2] = 1;

         ::math::linear::homography::structure<scalar_name,2> Tt;
         Tt[0][0] = 1;   Tt[0][1] = 0; Tt[0][2] = -T0[0];
         Tt[1][0] = 0;   Tt[1][1] = 1; Tt[1][2] = -T0[1];
         Tt[2][0] = 0;   Tt[2][1] = 0; Tt[2][2] = 1;

         ::math::linear::vector::structure<scalar_name,3> b_x;
         ::math::linear::matrix::transform( b_x, Ts, { Tx[0], Tx[1], 1 } );
         ::math::linear::vector::structure<scalar_name,3> b_y;
         ::math::linear::matrix::transform( b_y, Ts, { Ty[0], Ty[1], 1 } );

         ::math::linear::homography::structure<scalar_name,2> Lti;
         Lti[0][0] = b_x[0];   Lti[0][1] = b_y[0]; Lti[0][2] = 0;
         Lti[1][0] = b_x[1];   Lti[1][1] = b_y[1]; Lti[1][2] = 0;
         Lti[2][0] =      0;   Lti[2][1] =      0; Lti[2][2] = 1;

         ::math::linear::homography::structure<scalar_name,2> Lt;
         Lt[0][0] =  b_y[1];  Lt[0][1] = -b_y[0]; Lt[0][2] = 0;
         Lt[1][0] = -b_x[1];  Lt[1][1] =  b_x[0]; Lt[1][2] = 0;
         Lt[2][0] =       0;  Lt[2][1] =       0; Lt[2][2] = b_x[0] * b_y[1] - b_x[1] * b_y[0];

         ::math::linear::homography::structure<scalar_name,2> Pti;
         ::math::linear::vector::structure<scalar_name,3> b_z;
         ::math::linear::matrix::transform( temp, Tt, { Tz[0], Tz[1], 1 } );
         ::math::linear::matrix::transform( b_z, Lt, temp );

         auto const & A = Lt[2][2];
         X = b_z[0];
         Y = b_z[1];
         Pti[0][0] =     X;  Pti[0][1] = 0;      Pti[0][2] = 0;
         Pti[1][0] =     0;  Pti[1][1] = Y;      Pti[1][2] = 0;
         Pti[2][0] =   A-Y;  Pti[2][1] = A-X;    Pti[2][2] = X+Y-A;

         ::math::linear::homography::structure<scalar_name,2> S;
         ::math::linear::homography::structure<scalar_name,2> T;

         ::math::linear::matrix::multiply( S, Ps,  Ls,  Ts  );
         ::math::linear::matrix::multiply( T, Tti, Lti, Pti );

         ::math::linear::matrix::multiply( result, T, S );

         return true;
        }


      template<  typename scalar_name >
       bool constructPH //!
        (
          ::math::linear::homography::structure<scalar_name,2>        & result
         ,::math::linear::vector::structure< scalar_name, 2 >    const& b1 //!< { 0, 0 } -> b1
         ,::math::linear::vector::structure< scalar_name, 2 >    const& b2 //!< { 1, 0 } -> b2
         ,::math::linear::vector::structure< scalar_name, 2 >    const& b4 //!< { 1, 1 } -> b4
         ,::math::linear::vector::structure< scalar_name, 2 >    const& b3 //!< { 0, 1 } -> b3
        ) //!< construct Paul Heckbert case 1b
        {
         auto const& x0 = b1[0];
         auto const& y0 = b1[1];
         auto const& x1 = b2[0];
         auto const& y1 = b2[1];
         auto const& x2 = b3[0];
         auto const& y2 = b3[1];
         auto const& x3 = b4[0];
         auto const& y3 = b4[1];

         auto Dx1 = x1 - x2; auto Dx2 = x3 - x2;  auto Sx = x0 - x1 + x2 - x3;
         auto Dy1 = y1 - y2; auto Dy2 = y3 - y2;  auto Sy = y0 - y1 + y2 - y3;

         auto div = Dx1*Dy2 - Dx2*Dy1;

         auto & a = result[0][0]; auto & b = result[0][1]; auto & c = result[0][2];
         auto & d = result[1][0]; auto & e = result[1][1]; auto & f = result[1][2];
         auto & g = result[2][0]; auto & h = result[2][1]; auto & i = result[2][2];

         g = Sx*Dy2 - Dx2*Sy; //g /= div;
         h = Dx1*Sy - Sx*Dy1; //h /= div;

         a = div*( x1 - x0 ) + g * x1;
         b = div*( x3 - x0 ) + h * x3;
         c = div*x0;
         d = div*(y1 - y0) + g*y1;
         e = div*(y3 - y0) + h*y3;
         f = div*y0;

         i = div*1;

         return true;
        }

      template<  typename scalar_name >
       bool constructPH
        (
          ::math::linear::homography::structure<scalar_name,2> & result
         ,::math::linear::vector::structure< scalar_name, 2 >    const& S0, ::math::linear::vector::structure< scalar_name, 2 >    const& T0
         ,::math::linear::vector::structure< scalar_name, 2 >    const& Sx, ::math::linear::vector::structure< scalar_name, 2 >    const& Tx
         ,::math::linear::vector::structure< scalar_name, 2 >    const& Sy, ::math::linear::vector::structure< scalar_name, 2 >    const& Ty
         ,::math::linear::vector::structure< scalar_name, 2 >    const& Sz, ::math::linear::vector::structure< scalar_name, 2 >    const& Tz
        )
        {
         ::math::linear::homography::structure<scalar_name,2>  case2;
         ::math::linear::homography::structure<scalar_name,2>  case2i;
         ::math::linear::homography::constructPH( case2i, S0, Sx, Sy, Sz );
         if( false == ::math::linear::matrix::invert( case2, case2i ) )
          {
           return false;
          }
 
         ::math::linear::homography::structure<scalar_name,2>  case1;
         ::math::linear::homography::constructPH( case1,  T0, Tx, Ty, Tz );
 
         ::math::linear::matrix::multiply( result, case1, case2 );
         return true;
        }

     }
   }
 }

#endif
