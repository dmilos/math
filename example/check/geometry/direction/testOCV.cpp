#include "opencv2/opencv.hpp"
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

#include "../../../../_ocv/lib/ocv/draw.hpp"



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
  cv::namedWindow( "Command", cv::WINDOW_FREERATIO );

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

  ::math::geometry::direction::two<double, 2 >               two0{ p0, p1 },        two1;
  ::math::geometry::direction::parametric<double, 2 > parametric0{ two0 },   parametric1;
  ::math::geometry::direction::ABC2D<double >                abc0{ two0 },          abc1;

  draw<double>( frame,         two0, ::cv::Scalar(255, 127, 127) );
  draw<double>( frame,  parametric0, ::cv::Scalar(127, 255, 127) );
  draw<double>( frame,         abc0, ::cv::Scalar(127, 127, 255) );

  cv::circle( frame, { (int)center[0], (int)center[1] }, 20, ::cv::Scalar(127, 255, 127), 1 );
  ::math::geometry::direction::rotate<double>(        two1, center, ::math::geometry::deg2rad( g_alpha ),        two0 );
  ::math::geometry::direction::rotate<double>( parametric1, center, ::math::geometry::deg2rad( g_alpha ), parametric0 );
  ::math::geometry::direction::rotate<double>(        abc1, center, ::math::geometry::deg2rad( g_alpha ),        abc0 );

  //draw<double>( frame,        two1, ::cv::Scalar(127, 255, 127) );
  //draw<double>( frame, parametric1, ::cv::Scalar(127, 255, 127) );
  draw<double>( frame, abc1, ::cv::Scalar(127, 255, 127) );

} 

int main()
 {
  int frame_height = 600;
  int frame_width  = 800;

  cv::Mat frame( frame_height,frame_width,CV_8UC3 );

  initUI();

  for(unsigned long counter = 0; true;++counter )
   {
    cv::rectangle( frame, cv::Point2i(0, 0), ::cv::Point2i(frame.cols, frame.rows), ::cv::Scalar(0, 0, 0), cv::FILLED);

    monitor(frame);

    ::cv::line( frame, ::cv::Point2i( 0, frame.rows/2 ), ::cv::Point2i( frame.cols, frame.rows/2 ), ::cv::Scalar(   255,   255, 255 ), 1 );
    ::cv::line( frame, ::cv::Point2i( frame.cols/2, 0 ), ::cv::Point2i( frame.cols/2, frame.rows ), ::cv::Scalar(   255,   255, 255 ), 1 );

    cv::imshow( "Frame-frame", frame );
    char c = (char)cv::waitKey(1);
    if( c == 27 ) break;
   }

  return EXIT_SUCCESS;
}