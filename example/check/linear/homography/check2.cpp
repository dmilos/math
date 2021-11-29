#include "opencv2/opencv.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <string>

#include <iostream>
#include <iomanip>

#include "math/math.hpp"

#include "../../../../_ocv/lib/ocv/draw.hpp"


#include "math/math.hpp"


typedef std::array<std::uint8_t,3> ColorType;
typedef cv::Mat ImageType;

void putPixel( ImageType & image, std::array<std::size_t,2> const& size, std::array<std::size_t,2> const& location, ColorType const& color )
 {
  if( size[0] - 1 < location[0] ) return;
  if( size[1] - 1 < location[1] ) return;
   
   image.at<cv::Vec3b>( (int)location[1], (int)location[0])[0] = color[0];
   image.at<cv::Vec3b>( (int)location[1], (int)location[0])[1] = color[1];
   image.at<cv::Vec3b>( (int)location[1], (int)location[0])[2] = color[2];
 }

void putPixel( ImageType & image, std::array<std::size_t,2> const& size, std::array<std::array<double,2>,2> const& window , std::array<double,2> const& location, ColorType const& color )
 {
  std::size_t x = (std::size_t)(::math::function::any_to_any<double>( (double)location[0], window[0][0], window[1][0], (double)      0, (double)size[0] ) + 0.5);
  std::size_t y = (std::size_t)(::math::function::any_to_any<double>( (double)location[1], window[0][1], window[1][1], (double)size[1], (double)      0 ) + 0.5);

  putPixel( image, size, { x,y }, color );
 }





using namespace std;
using namespace cv;

typedef std::array<double,2> point2d_type;
typedef std::array<double, 3> point3d_type;

int g_X = 100;
int g_Y = 100;
int g_Z = 200;
int g_T = 250;
int g_U = 200;
int g_V = 200;
int g_alpha = 45;

void initUI()
 {
  namedWindow( "Command", WINDOW_FREERATIO );
  ::cv::createTrackbar("X", "Command", &g_X, 1000, NULL);
  ::cv::createTrackbar("Y", "Command", &g_Y, 1000, NULL);
  ::cv::createTrackbar("Z", "Command", &g_Z, 500, NULL);
  ::cv::createTrackbar("T", "Command", &g_T, 500, NULL);
  ::cv::createTrackbar("U", "Command", &g_U, 500, NULL);
  ::cv::createTrackbar("V", "Command", &g_V, 500, NULL);
  ::cv::createTrackbar("AA", "Command", &g_alpha, 360, NULL);
 }


void monitor( cv::Mat & frame )
 { 
  point2d_type p0{(double)g_X,(double)g_Y};
  point2d_type p1{(double)g_Z,(double)g_T};
  point2d_type center{(double)g_U,(double)g_V};
 ::math::geometry::projective::camera::optical<double> camera( frame.cols, frame.rows  );
  camera.window( {2,2} );

  ::math::linear::homography::structure<double,2> h2;
  ::math::linear::homography::construct<double>
     ( h2, 
      {0,0}, {0,0}, 
      {1,0}, {1,0}, 
      {0,1}, {0,1}, 
      {1,1}, { math::function::any_to_any<double>( g_X, 0, 1000, -1, 1 ), math::function::any_to_any<double>(g_Y, 0, 1000, -1, 1 ) } );

  ::math::geometry::projective::camera::principal<double>  princip;

   princip.process( h2 );

   draw<double>( frame, camera, princip.horizon(), ::cv::Scalar(127, 0, 127) );
   draw<double>( frame, camera, princip.axis(), ::cv::Scalar(127, 0, 127) );

   ::math::linear::vector::structure<double,3>  point;
   ::math::geometry::projective::epipolar::pole<double >::self( point, h2 );


  for( double x =-1; x < +1; x+=0.01 )
   for( double y =-1; y < +1; y+=0.01 )
    {
     ::math::linear::vector::structure<double,2> result;

    ::math::linear::homography::transform( result, h2, {x,y} );

     putPixel( frame, { (std::size_t) frame.cols, (std::size_t)frame.rows }, { -2.0, -2.0, +2.0, +2.0 }, result, { (std::uint8_t)(255*x), std::uint8_t(255*y), (std::uint8_t)127 } );
    }

    putPixel( frame, { (std::size_t) frame.cols, (std::size_t)frame.rows }, { -2.0, -2.0, +2.0, +2.0 }, {point[0]/point[2], point[1]/point[2] }, { (std::uint8_t)(255 ), std::uint8_t(255 ), (std::uint8_t)255 } );
}


int main()
 {
  Mat frame( 800,800,CV_8UC3 );

  initUI();

  for(unsigned long counter = 0; true;++counter )
   {
    rectangle(frame, cv::Point2i(0, 0), ::cv::Point2i(frame.cols, frame.rows), ::cv::Scalar(0, 0, 0), cv::FILLED);

    monitor(frame);

    ::cv::line( frame, ::cv::Point2i( 0, frame.rows/2 ), ::cv::Point2i( frame.cols, frame.rows/2 ), ::cv::Scalar(   255,   255, 255 ), 1 );
    ::cv::line( frame, ::cv::Point2i( frame.cols/2, 0 ), ::cv::Point2i( frame.cols/2, frame.rows ), ::cv::Scalar(   255,   255, 255 ), 1 );

    imshow( "Frame-frame", frame );
    char c = (char)waitKey(1);
    if( c == 27 ) break;
   }

  return 0;
}