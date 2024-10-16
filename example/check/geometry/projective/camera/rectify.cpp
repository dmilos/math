#include "math/math.hpp"


typedef  ::math::geometry::projective::camera::mobile<double> camera_type;


void rectify_sbs( camera_type const& snister, camera_type const& dexter )
 {
  ::math::geometry::projective::epipolar::rectify3::psbs<double>      planer_psbs; //!< we want real rectification
  ::math::geometry::projective::epipolar::rectify3::processor<double> rectificator;
  rectificator.process( snister, dexter, planer_psbs );
 }

void rectify_forward(  camera_type const& snister, camera_type const& dexter )
 {
  ::math::geometry::projective::epipolar::rectify3::pforward<double>  planer_pforward;
  ::math::geometry::projective::epipolar::rectify3::processor<double> rectificator;
  rectificator.process( snister, dexter, planer_pforward );
 }

void rectify_md(  camera_type const& snister, camera_type const& dexter )
 {
  ::math::geometry::projective::epipolar::rectify3::pmd<double>  planer_pmd;
  ::math::geometry::projective::epipolar::rectify3::processor<double> rectificator;
  rectificator.process( snister, dexter, planer_pmd );
 }

void rectify_2left(  camera_type const& snister, camera_type const& dexter )
 {
  ::math::geometry::projective::epipolar::rectify3::p2l<double>  planer_2l;
  ::math::geometry::projective::epipolar::rectify3::processor<double> rectificator;
  rectificator.process( snister, dexter, planer_2l );
 }

void rectify_2right(  camera_type const& snister, camera_type const& dexter )
 {
  ::math::geometry::projective::epipolar::rectify3::p2r<double>  planer_2r;
  ::math::geometry::projective::epipolar::rectify3::processor<double> rectificator;
  rectificator.process( snister, dexter, planer_2r );
 }


int main( )
 {
  camera_type snister, dexter;
  ::math::linear::affine::structure< double, 3> A;

  snister.optical().horizontalFV( ::math::geometry::deg2rad( 67 ) );
  ::math::linear::matrix::id( A.matrix() );
  ::math::linear::vector::load( A.vector(), 0.0, 0.0, 0.0 );
  snister.to_world( A );

  dexter.optical().horizontalFV( ::math::geometry::deg2rad( 95 ) );
  ::math::linear::matrix::id( A.matrix() );
  ::math::linear::vector::load( A.vector(), 0.5, 0.0, 0.01 );
  dexter.to_world( A );
  rectify_sbs( snister, dexter );
  rectify_forward( snister, dexter );
  rectify_md( snister, dexter );
  rectify_2left( snister, dexter );
  rectify_2right( snister, dexter );
  return 0;
 }