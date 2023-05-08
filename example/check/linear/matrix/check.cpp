#include <iostream>
#include <iomanip>
#include <chrono>

#include "math/math.hpp"


template< typename scalar_name, math::type::size_t dimension_number >
 void print( ::math::linear::vector::structure<scalar_name,dimension_number> const& v )
  {
   for( math::type::size_t i=0; i< dimension_number; i++ )
    {
     std::cout << std::setw( 10 ) << std::fixed << v[i] << ", ";
    }
  }

template< typename scalar_name, math::type::size_t width_number, math::type::size_t height_number >
 void print ( ::math::linear::matrix::structure<scalar_name,width_number,height_number> const& m )
  {
   for( math::type::size_t j=0; j< height_number; j++ )
    {
     for( math::type::size_t i=0; i<width_number ; i++ )
      {
       std::cout << std::setw(10) << std::fixed << m[j][i] << ", ";
      } std::cout << std::endl;
    }
  }

void GS()
 {
  std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
  std::vector< ::math::linear::vector::structure<double,3> >   mResult;

   std::cout << "--{" << std::endl;

   //print( mA );
   std::cout << " --" << std::endl;
  ::math::linear::vector::GramSchmidt( mResult, { { 12, 6, -4 }, {-69,158,30 }, { -58/5.0, 6/5.0, -33 } } );
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[0], mResult[1] )<< " - "; print( mResult[0] ); std::cout << std::endl;
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[0], mResult[2] )<< " - "; print( mResult[1] ); std::cout << std::endl;
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[1], mResult[2] )<< " - "; print( mResult[2] ); std::cout << std::endl;

   std::cout << " --" << std::endl;
  ::math::linear::vector::GramSchmidt( mResult, { { 1, 0,  0 }, {1,1,0 }, { 0,0,1 } } );
   std::cout << std::setw( 10 ) <<::math::linear::vector::dot( mResult[0], mResult[1] ) << " - "; print( mResult[0] ); std::cout << std::endl;
   std::cout << std::setw( 10 ) <<::math::linear::vector::dot( mResult[0], mResult[2] ) << " - "; print( mResult[1] ); std::cout << std::endl;
   std::cout << std::setw( 10 ) <<::math::linear::vector::dot( mResult[1], mResult[2] ) << " - "; print( mResult[2] ); std::cout << std::endl;

   std::cout << " --" << std::endl;
  ::math::linear::vector::GramSchmidt( mResult, { { 12, -69, -58/5.0 }, {6,158,6/5.0 }, {  -4, 30, -33 } } );
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[0], mResult[1] ) << " - "; print( mResult[0] ); std::cout << std::endl;
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[0], mResult[2] ) << " - "; print( mResult[1] ); std::cout << std::endl;
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[1], mResult[2] ) << " - "; print( mResult[2] ); std::cout << std::endl;

   std::cout << " --" << std::endl;
  ::math::linear::vector::GramSchmidt( mResult, { { 2, 2, 1 }, { -2, 1, 2 }, {  18, 0, 0 } } );
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[0], mResult[1] ) << " - "; print( mResult[0] ); std::cout << std::endl;
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[0], mResult[2] ) << " - "; print( mResult[1] ); std::cout << std::endl;
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[1], mResult[2] ) << " - "; print( mResult[2] ); std::cout << std::endl;

   std::cout << " --" << std::endl;

   std::cout << "}--" << std::endl;
 }

void GS2()
 {
  std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
  ::math::linear::matrix::structure<double,3,3>  mResult;

   std::cout << " --" << std::endl;
  ::math::linear::matrix::GramSchmidt( mResult, {  12, 6, -4 , -69,158,30 ,  -58/5.0, 6/5.0, -33 } );
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[0], mResult[1] ) << " - "; print( mResult[0] ); std::cout << std::endl;
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[0], mResult[2] ) << " - "; print( mResult[1] ); std::cout << std::endl;
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[1], mResult[2] ) << " - "; print( mResult[2] ); std::cout << std::endl;
   std::cout << " --" << std::endl;
  ::math::linear::matrix::GramSchmidt( mResult, {   1, 0,  0 , 1,1,0 , 0,0,1 } );
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[0], mResult[1] ) << " - "; print( mResult[0] ); std::cout << std::endl;
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[0], mResult[2] ) << " - "; print( mResult[1] ); std::cout << std::endl;
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[1], mResult[2] ) << " - "; print( mResult[2] ); std::cout << std::endl;
   std::cout << " --" << std::endl;
  ::math::linear::matrix::GramSchmidt( mResult, { 12, -69, -58/5.0 , 6,158,6/5.0 ,  -4, 30, -33  } );
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[0], mResult[1] ) << " - "; print( mResult[0] ); std::cout << std::endl;
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[0], mResult[2] ) << " - "; print( mResult[1] ); std::cout << std::endl;
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[1], mResult[2] ) << " - "; print( mResult[2] ); std::cout << std::endl;
   std::cout << " --" << std::endl;
  ::math::linear::matrix::GramSchmidt( mResult, { 2, 2, 1 , -2, 1, 2,  18, 0, 0 });
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[0], mResult[1] ) << " - "; print( mResult[0] ); std::cout << std::endl;
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[0], mResult[2] ) << " - "; print( mResult[1] ); std::cout << std::endl;
   std::cout << std::setw( 10 ) << ::math::linear::vector::dot( mResult[1], mResult[2] ) << " - "; print( mResult[2] ); std::cout << std::endl;
   std::cout << " --" << std::endl;

}


void QR()
 {
  std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
  ::math::linear::matrix::structure<double,3,3>   Q, R;
  ::math::linear::matrix::structure<double,3,3>   A = {   12, -51, 4 , 6, 167, -68, -4, 24, -41   };
   ::math::linear::matrix::QR( Q, R , A );

   print( A ); std::cout << std::endl;
   print( Q ); std::cout << std::endl;
   print( R ); std::cout << std::endl;
  ::math::linear::matrix::structure<double,3,3>   C;
  ::math::linear::matrix::multiply( C, Q, R );
   print( C ); std::cout << std::endl;
 }

void submatrix()
 {
  std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
  ::math::linear::matrix::structure<double,3,3>   m33;
  ::math::linear::matrix::structure<double,4,4>   m44{ 0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,};

   ::math::linear::matrix::submatrix( m33, m44, 2, 2 );

   std::cout << "--{" << std::endl;
   print( m33 );
   std::cout << " --" << std::endl;
   print( m44 );
   std::cout << "}--" << std::endl;
 }


void gauss()
 {
  std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
  ::math::linear::matrix::structure<double,3,3 >   A{ 1,0,0, 0,1,0 ,  0,0,1 };
//::math::linear::matrix::structure<double,3,3 >   B;
  ::math::linear::matrix::structure<double,3,6 >   E{123};
  ::math::linear::matrix::structure<double,4,3 >   sle1;
  ::math::linear::matrix::structure<double,3,2 >   sle2;
  ::math::linear::matrix::structure<double,4,3 >   sle3;

   std::cout << " --I" << std::endl;
  ::math::linear::matrix::gauss( A ); print( A ); std::cout << std::endl;

   std::cout << " --E" << std::endl;
  ::math::linear::matrix::gauss( E ); print( E ); std::cout << std::endl;

   std::cout << " -- sle1" << std::endl;
   print( sle1 ={ 2,0,0, 5, 0,3,0,6 ,  0,0,4,7 } ); std::cout << std::endl;
   ::math::linear::matrix::gauss( sle1 ); print( sle1 ); std::cout << std::endl;

   std::cout << " --B_3_10" << std::endl;
  ::math::linear::matrix::structure<double,3, 10 >   B_3_10;

   std::cout << " --B_10_3" << std::endl;
  ::math::linear::matrix::structure<double,10, 3 >   B_10_3;

   std::cout << " --B_3_10" << std::endl; print( B_3_10 );
  ::math::linear::matrix::gauss( B_3_10 ); print( B_3_10 ); std::cout << std::endl;

   std::cout << " -- B_10_3" << std::endl;
  ::math::linear::matrix::gauss( B_10_3 ); print(B_10_3 ); std::cout << std::endl;

   std::cout << " -- B_6_3" << std::endl;
/*
 -0.750000,   0.500000,  -0.250000,
  0.250000,   0.000000,   0.250000,
  1.250000,  -0.500000,  -0.250000,
*/
  ::math::linear::matrix::structure<double, 6, 3 >   B_6_3= { +1,+2,1 ,   1,0,0,
                                                              +3,+4,+1,   0,1,0,
                                                              -1,+2,-1,   0,0,1    };
    print(B_6_3 ); std::cout << std::endl;
  ::math::linear::matrix::gauss( B_6_3 ); print(B_6_3 ); std::cout << std::endl;

   std::cout << " -- B_5_4" << std::endl; // Solve system of linear equations
  ::math::linear::matrix::structure<double, 5, 4 >   B_5_4= { -2,  0,  3,  0,  13, /*  53/29 */
                                                               0,  1,  0, -3,   0, /*  72/29 */
                                                               2, +3, -2,  0,   0, /* 161/29 */
                                                               0,  0, -3,  2, -15  /*  24/29 */
    };
    print(B_5_4 ); std::cout << std::endl;
  ::math::linear::matrix::gauss( B_5_4 ); print(B_5_4 ); std::cout << std::endl;

   std::cout << " --sle2a" << std::endl;
   print( sle2={ 1,1,20, 1, -1, 10 } ); std::cout << std::endl;
   ::math::linear::matrix::gauss( sle2 ); print( sle2 ); std::cout << std::endl;

   std::cout << " --sle2b" << std::endl;
   print( sle2={ 2, 3, 12, 1, 2, 7 } ); std::cout << std::endl;
   ::math::linear::matrix::gauss( sle2 ); print( sle2 ); std::cout << std::endl;

   std::cout << " -- sle3" << std::endl;
   print( sle3={ 2, 1, 1, 2,   -1, 1, -1 ,3 ,   1, 2,  3, -10 } ); std::cout << std::endl;
   ::math::linear::matrix::gauss( sle3 ); print(sle3 ); std::cout << std::endl;
 }

void retarget( )
 {
  ::math::linear::vector::structure<double,3>   i0, i1;
  ::math::linear::matrix::structure<double,3,3>   m33a, m33b;
  ::math::linear::matrix::retarget( m33a, m33b, i0, i1 );
 }

 void TaitGryan()
 {
  ::math::linear::vector::structure<double,3>       angle;
  ::math::linear::matrix::structure<double,3,3>     to_world;

 ::math::linear::matrix::TaitBryanXZY( angle, to_world );
 ::math::linear::matrix::TaitBryanXYZ( angle, to_world );
 ::math::linear::matrix::TaitBryanYXZ( angle, to_world );
 ::math::linear::matrix::TaitBryanYZX( angle, to_world );
 ::math::linear::matrix::TaitBryanZYX( angle, to_world );
 ::math::linear::matrix::TaitBryanZXY( angle, to_world );
 }

int main( int argc, char*argv[] )
 {
  std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
  TaitGryan();

  gauss();

  QR();
  GS();
  GS2();
  submatrix();
  retarget();
  ::math::linear::matrix::structure<double,10,11> mAB;
//::math::linear::matrix::structure<double,11,12> mBC;
  ::math::linear::matrix::structure<double,2,2>   m22;
  ::math::linear::matrix::structure<double,3,3>   m33;
  ::math::linear::matrix::structure<double,4,4>   m44;
  ::math::linear::matrix::structure<double,6,6>   m66;

  ::math::linear::vector::structure<double,2>   v2;
  ::math::linear::vector::structure<double,3>   v3;
  ::math::linear::vector::structure<double,4>   v4;

  ::math::linear::matrix::zero( mAB );

  ::math::linear::matrix::addition( mAB, mAB, mAB );  ::math::linear::matrix::addition( mAB, mAB );
  ::math::linear::matrix::addition( m22, m22, m22 );  ::math::linear::matrix::addition( m22, m22 );
  ::math::linear::matrix::addition( m33, m33, m33 );  ::math::linear::matrix::addition( m33, m33 );
  ::math::linear::matrix::addition( m44, m44, m44 );  ::math::linear::matrix::addition( m44, m44 );

  ::math::linear::matrix::subtraction( mAB, mAB, mAB );  ::math::linear::matrix::subtraction( mAB, mAB );
  ::math::linear::matrix::subtraction( m22, m22, m22 );  ::math::linear::matrix::subtraction( m22, m22 );
  ::math::linear::matrix::subtraction( m33, m33, m33 );  ::math::linear::matrix::subtraction( m33, m33 );
  ::math::linear::matrix::subtraction( m44, m44, m44 );  ::math::linear::matrix::subtraction( m44, m44 );

  //::math::linear::matrix::multiply( mAB, mAB, mAB );  ::math::linear::matrix::multiply( mAB, mAB );
  ::math::linear::matrix::multiply( m22, m22, m22 );
  ::math::linear::matrix::multiply( m33, m33, m33 );
  ::math::linear::matrix::multiply( m44, m44, m44 );

  ::math::linear::matrix::id<double,3,3>();
  ::math::linear::matrix::id( mAB );
  ::math::linear::matrix::id( ::math::linear::matrix::structure<double,4,4>{} );

  ::math::linear::matrix::one<double,3,3>(  );
  ::math::linear::matrix::one( mAB );
  ::math::linear::matrix::one( m22 );
  ::math::linear::matrix::one( m33 );
  ::math::linear::matrix::one( m44 );

  ::math::linear::matrix::zero( mAB );
  ::math::linear::matrix::zero( m22 );
  ::math::linear::matrix::zero( m33 );
  ::math::linear::matrix::zero( m44 );

  //::math::linear::matrix::invert( mAB );
  ::math::linear::matrix::invert( m22, m22 );
  ::math::linear::matrix::invert( m33, m33 );
  ::math::linear::matrix::invert( m44, m44 );

  //::math::linear::matrix::determinant( mAB );
  ::math::linear::matrix::determinant( m22 );
  std::cout<< "m33: " <<::math::linear::matrix::determinant( m33 =
     {
       1, 0, 2,
       0, 1, 0,
       1, 0, 9
     }
   ) << std::endl; // ???
  std::cout<< "m33: " <<::math::linear::matrix::determinant( m33 =
     {
       10, 20, 30,
       33, 55, 77,
       99, 87, 35
     }
   ) << std::endl; // ???
   std::cout<< "m44a: " << ::math::linear::matrix::determinant( m44 =
    {
      1, 0, 0, 1,
      0, 1, 0, 2,
      1, 0, 1, 0,
      0, 1, 0, 9
     } ) << std::endl; // ???

   std::cout<< "m44b: " << ::math::linear::matrix::determinant( m44 =
    {
      2,  3,  3,  1,
      1,  5,  4,  3,
      4,  6,  8,  5,
     -2, -3, -3,  4
     } ) << std::endl; // ???

   std::cout<< "m44c: " << ::math::linear::matrix::determinant( m44 =
    {
      1,  2,  2,  1,
      1,  2,  4,  2,
      2,  7,  5,  2,
     -1,  4, -6,  3
     } ) << std::endl; // -42

   std::cout<< "m44d: " << ::math::linear::matrix::determinant( m44 =
    {
      4,  3,  4,  2,
      8,  7,  5,  3,
      4,  3,  8,  5,
      4,  3,  4,  3
     } ) << std::endl; // 16

   std::cout<< "m44e: " << ::math::linear::matrix::determinant( m44 =
    {
      3,  3,  9,  5,
      6,  9,  5,  4,
     -3, -3, -4, -7,
      3,  3,  9,  8
     } ) << std::endl; // 135

   std::cout<< "m44f: " << ::math::linear::matrix::determinant( m44 =
    {
      4,  3,  2,  2,
      0,  1, -3,  3,
      0, -1,  3,  3,
      0,  3,  1,  1
     } ) << std::endl; // 240

    std::cout<< "m44g: " << ::math::linear::matrix::determinant( m44 =
    {
      5, -7,  2,  2,
      0,  3,  0,  -4,
     -5, -8,  0,  3,
      0,  5,  0, -6
     } ) << std::endl; // 20

  std::cout<< "m66: " << ::math::linear::matrix::determinant( m66 =
  {   0.29,     0.98,     1.86,     2.84,     3.63,     5.59,
      2.94,     4.12,     5.88,     8.43,    10.39,    12.35,
      8.14,     9.71,    12.06,    15.10,    17.84,    20.59,
     14.90,    18.24,    21.47,    24.71,    27.55,    31.18,
     24.90,    27.94,    32.45,    36.08,    39.71,    43.92,
     36.37,    39.61,    43.82,    47.25,    51.37,    55.29 } ) << std::endl;

//::math::linear::matrix::multiply( mAB );
  ::math::linear::matrix::multiply( m22, m22, m22 );
  ::math::linear::matrix::multiply( m33, m33, m33 );
  ::math::linear::matrix::multiply( m44, m44, m44 );

  ::math::linear::matrix::NaN( mAB );
  ::math::linear::matrix::NaN( m22 );
  ::math::linear::matrix::NaN( m33 );
  ::math::linear::matrix::NaN( m44 );

  ::math::linear::matrix::NaN( mAB );
  ::math::linear::matrix::NaN( m22 );
  ::math::linear::matrix::NaN( m33 );
  ::math::linear::matrix::NaN( m44 );

   ::math::linear::matrix::transpose(m22,m22);
   ::math::linear::matrix::transpose(m33,m33);
   ::math::linear::matrix::transpose(m44,m44);
   ::math::linear::matrix::transpose(m22);
   ::math::linear::matrix::transpose(m33);
   ::math::linear::matrix::transpose(m44);

    ::math::linear::matrix::system( m22,v2,v2);
    ::math::linear::matrix::system( m33,v3,v3,v3);
    ::math::linear::matrix::system( m44,v4,v4,v4,v4);

    ::math::linear::matrix::scale( m22, 123.0 );
    ::math::linear::matrix::scale( m33, 123.0 );
    ::math::linear::matrix::scale( m44, 123.0 );

    ::math::linear::matrix::scale( m22, 123.0, m22 );
    ::math::linear::matrix::scale( m33, 123.0, m33 );
    ::math::linear::matrix::scale( m44, 123.0, m44 );

    ::math::linear::matrix::scale( m22, m22, 123.0 );
    ::math::linear::matrix::scale( m33, m33, 123.0 );
    ::math::linear::matrix::scale( m44, m44, 123.0 );

    ::math::linear::matrix::transform( v2, m22, v2 );
    ::math::linear::matrix::transform( v3, m33, v3 );
    ::math::linear::matrix::transform( v4, m44, v4 );

    ::math::linear::matrix::transform( v2, v2, m22 );
    ::math::linear::matrix::transform( v3, v3, m33 );
    ::math::linear::matrix::transform( v4, v4, m44 );

  ::math::linear::matrix::rotate( m33, v3, 123.0 );
  ::math::linear::matrix::rotateX( m33, 123.456 );
  ::math::linear::matrix::rotateY( m33, 123.456 );
  ::math::linear::matrix::rotateZ( m33, 123.456 );

  ::math::linear::matrix::fill<double>( m33, 0 );
  ::math::linear::matrix::fill( m33, 0.0 );


  return 0;
 }