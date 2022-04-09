#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

using namespace std;


void check2d()
 {
  ::math::linear::affine::structure<double,2> a1,a2,a3;
  ::math::linear::vector::structure<double,2> v1,v2,v3;
  ::math::linear::matrix::structure<double,2,2> m1,m2,m3{0}; m1 = m2 = m3;

  ::math::linear::affine::system( a1, v1, v2, v3 );

  ::math::linear::affine::construct( a1, { v1, v2, v3}, { v1, v2, v3} );
  ::math::linear::affine::construct( a1, { v1, v2, v3} );
  ::math::linear::affine::construct( a1, a2, a3 );


      a1 =  ::math::linear::affine::id<double,2>();
    ::math::linear::affine::id<double,2>( a2 );
    ::math::linear::affine::id( ::math::linear::affine::structure<double,2>{} );
    a1 =  ::math::linear::affine::one<double,2>();
   ::math::linear::affine::one<double,2>( a2 );
   ::math::linear::affine::one( ::math::linear::affine::structure<double,2>{} );
 }

 void check4d()
 {
  ::math::linear::affine::structure<double,4> a1,a2,a3;
  ::math::linear::vector::structure<double,4> v1,v2,v3, v4, v5;
  ::math::linear::matrix::structure<double,4,4> m2{0},m3{0}; m2 = m3;


  ::math::linear::affine::system( a1, v1, v2, v3, v4, v5 );
  ::math::linear::affine::construct( a1, { v1, v2, v3, v4, v5 }, { v1, v2, v3, v4, v5 } );
  ::math::linear::affine::construct( a1, { v1, v2, v3, v4, v5 }  );
  ::math::linear::affine::construct( a1, a2, a3 );

  a1 =  ::math::linear::affine::id<double,4>();
  ::math::linear::affine::id<double,4>( a2 );
  ::math::linear::affine::id( ::math::linear::affine::structure<double,4>{} );
  a1 =  ::math::linear::affine::one<double,4>();
  ::math::linear::affine::one<double,4>( a2 );
  ::math::linear::affine::one( ::math::linear::affine::structure<double,4>{} );
 }

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;
  check2d();
  check4d();

  ::math::linear::affine::structure<double,3> a1,a2,a3;
  ::math::linear::vector::structure<double,3> v1,v2,v3,v4;
  ::math::linear::matrix::structure<double,3,3> m1,m2,m3{0}; m2 = m3;
  ::math::geometry::interval::structure<double,3>   i0, i1, i2;


  a1 =  ::math::linear::affine::id<double,3>();
  ::math::linear::affine::id<double,3>( a2 );
  ::math::linear::affine::id( ::math::linear::affine::structure<double,2>{} );

  ::math::linear::affine::addition(a1,a2);
  ::math::linear::affine::addition(a1,a2,a3);

  //::math::linear::affine::compose(a1,a2);
  ::math::linear::affine::compose(a1,a2,a3);

  ::math::linear::affine::invert(a1);
  ::math::linear::affine::invert(a1,a2);


  ::math::linear::affine::NaN(a1);
  ::math::linear::affine::zero(a1);
  ::math::linear::affine::one(a1);

  ::math::linear::affine::NaN<double,5>();
  ::math::linear::affine::zero<double,5>();
  ::math::linear::affine::one<double,5>();

  ::math::linear::affine::scale<double>(a1,5,a2);
  ::math::linear::affine::scale<double>(a1,5);

  ::math::linear::affine::load(a1,m1,v1);
  ::math::linear::affine::look_at(a1,v1,v2,v3);

  ::math::linear::affine::transform(v1,a1,v2);
  ::math::linear::affine::transform(v1,a1);

  ::math::linear::affine::system( a1, v1, v2, v3, v4 );
  ::math::linear::affine::construct( a1, { v1, v2, v3, v4 }, { v1, v2, v3, v4 } );
  ::math::linear::affine::construct( a1, { v1, v2, v3, v4 } );
  ::math::linear::affine::construct( a1, a2, a3 );


  ::math::linear::affine::retarget(a1, a2, i0, i1 );


  return EXIT_SUCCESS;
 }
