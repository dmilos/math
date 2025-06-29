#include "math/math.hpp"

/*
::math::geometry::projective::camera::f2a(  )
::math::geometry::projective::camera::f2w(  )
::math::geometry::projective::camera::i2d(  )
::math::geometry::projective::camera::w2a(  )
::math::geometry::projective::camera::w2f(  )
*/

int main( )
 {
  double angle = ::math::geometry::deg2rad(90);
  double window = 2;
  double focus = ::math::geometry::projective::camera::a2f( angle, window );
  window = ::math::geometry::projective::camera::f2w( focus, angle );
  angle = ::math::geometry::rad2deg( ::math::geometry::projective::camera::w2a( window, focus ) );

  window = ::math::geometry::projective::camera::a2w(::math::geometry::deg2rad( angle ), focus);
  focus = ::math::geometry::projective::camera::w2f(window, ::math::geometry::deg2rad(angle));
  angle = ::math::geometry::rad2deg( ::math::geometry::projective::camera::f2a( focus, window ) );

  angle = ::math::geometry::rad2deg( ::math::geometry::projective::camera::f2a( focus, window ) );
  window = ::math::geometry::projective::camera::a2w(::math::geometry::deg2rad(angle), focus );
  focus = ::math::geometry::projective::camera::w2f(window, ::math::geometry::deg2rad( angle ) );

  window = ::math::geometry::projective::camera::f2w( focus,::math::geometry::deg2rad( angle ) );
  angle = ::math::geometry::rad2deg( ::math::geometry::projective::camera::w2a( window, focus ) );
  focus = ::math::geometry::projective::camera::a2f(::math::geometry::deg2rad(angle), window );

  focus = ::math::geometry::projective::camera::w2f(window, ::math::geometry::deg2rad( angle ) );
  angle = ::math::geometry::rad2deg( ::math::geometry::projective::camera::f2a( focus, window ) );
  window = ::math::geometry::projective::camera::a2w(::math::geometry::deg2rad(angle), focus );

  angle = ::math::geometry::rad2deg( ::math::geometry::projective::camera::w2a( window, focus ) );
  focus = ::math::geometry::projective::camera::a2f(::math::geometry::deg2rad(angle), window );
  window = ::math::geometry::projective::camera::f2w( focus,::math::geometry::deg2rad( angle ) );

  return 0;
 }