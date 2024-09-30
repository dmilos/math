#include "math/math.hpp"
#include "opencv2/opencv.hpp"


typedef  ::math::geometry::projective::camera::mobile<double> camera_type;

cv::Mat convert( ::math::linear::homography::structure<double, 2> const& h )
 {
  cv::Mat r( 3, 3, CV_32F);
  r.at<float>(0,0 )=(float)h[0][0]; r.at<float>(0,1)=(float)h[0][1];  r.at<float>(0,2)=(float)h[0][2];
  r.at<float>(1,0 )=(float)h[1][0]; r.at<float>(1,1)=(float)h[1][1];  r.at<float>(1,2)=(float)h[1][2];
  r.at<float>(2,0 )=(float)h[2][0]; r.at<float>(2,1)=(float)h[2][1];  r.at<float>(2,2)=(float)h[2][2];
  return r;
 }

void rectify_sbs(cv::Mat &left, cv::Mat &right, camera_type const& snister, camera_type const& dexter )
 {
  ::math::geometry::projective::epipolar::rectify3::psbs<double>      planer_psbs; //!< we want real rectification
  ::math::geometry::projective::epipolar::rectify3::processor<double> rectificator;
  rectificator.process( snister, dexter, planer_psbs );

  cv::warpPerspective(  left,  left, convert( rectificator.left()  ), left.size());
  cv::warpPerspective( right, right, convert( rectificator.right() ), right.size());
 }

int main( )
 {
  cv::Mat left = cv::imread( "left-image.png" );
  cv::Mat right = cv::imread( "right-image.png" );

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
  rectify_sbs(  left,  right, snister, dexter );

  while( true )
   {
    cv::imshow( "left", left );
    cv::imshow( "right", right );
    if( cv::waitKey(1) == 27 ) break;
   }
 }