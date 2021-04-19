#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

#include "opencv2/opencv.hpp"


int g_step=6;     // 


void initUI( )
 {
  cv::namedWindow( "Command", cv::WINDOW_FREERATIO );

  ::cv::createTrackbar( "step", "Command", &g_step, 8,  NULL );
 }

void make( cv::Mat & frame )
 {
     int width = frame.cols;
     int height = frame.rows;

    double step = pow(0.1, g_step );
    rectangle ( frame, cv::Point2i(0,0),  ::cv::Point2i( frame.cols, frame.rows ), ::cv::Scalar( 0,  0, 0 ), cv::FILLED  );

    for( int y=0; y< height;  ++y )
    for( int x=0; x< width;  ++x )
     {
      frame.at<std::uint8_t>( height - y-1, x) = std::uint8_t( int( 256*(double(x)/width) ) );
     }

    for( double t=0; t< 0.9999999999;  t+= step )
     {
      long double x,y;
      ::math::function::hilbert2D<long double>( x, y, t, int( g_step * 2 ) );

      double xr = ( x*width  );
      double yr = ( y*height );
       if( xr < 0 ) continue;
       if( yr < 0 ) continue;
       if( width < xr+1 ) continue;
       if( height< yr+1) continue;
      frame.at<std::uint8_t>( height - (int)yr-1, (int)xr) = std::uint8_t( int( 256*t ) );
     }

 }


int mainOCV( int argc, char *argv[] )
 {
  int frame_height = 600;
  int frame_width  = 800;

 initUI( );
  cv::Mat frame( frame_height, frame_width,  CV_8UC1 );
  while( true )
   {
    make( frame );
    cv::imshow( "Frame-frame", frame );
    char c = (char)cv::waitKey(1);
    if( c == 27 ) break;
   }

  return EXIT_SUCCESS;
 }

