#include "opencv2/opencv.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
 

#include "math/math.hpp"

 

int main_l( int argc, char *argv[] )
 {
  int frame_height = 1024*2;
  int frame_width  = 1024*2;

  cv::Mat frame( frame_height,frame_width,CV_8UC3 );
  std::array<double, 2 > point2d;
  std::array<double, 3 > point3d;
  double t;
  for( int y=0; y< frame.rows; ++y )
   {
    for( int x=0; x< frame.cols; ++x )
     {
      point2d[0] = x/(double)(frame.cols-1);
      point2d[1] = y/(double)(frame.rows-1);

      t = ::math::function::lebesgueND( point2d, 20 );

      ::math::function::lebesgueND( point3d, t, 20 );

      frame.at<cv::Vec3b>(y,x)[0] = int( 255 * point3d[2]);
      frame.at<cv::Vec3b>(y,x)[1] = int( 255 * point3d[1]);
      frame.at<cv::Vec3b>(y,x)[2] = int( 255 * point3d[0]);
     }
   }
   cv::imwrite( "image.png", frame );
  return EXIT_SUCCESS;
 }

