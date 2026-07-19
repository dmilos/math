#include "opencv2/opencv.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "math/math.hpp"



int g_stepX=20;     // 
int g_stepY=20;     // 


void initUI( )
 {
  cv::namedWindow( "Command", cv::WINDOW_FREERATIO );

  ::cv::createTrackbar( "stepX", "Command", &g_stepX,100,  NULL );
  ::cv::createTrackbar( "stepY", "Command", &g_stepY,100,  NULL );
 }

typedef double scalar_type;
typedef math::linear::vector::structure< scalar_type, 2>  point2d_type;
typedef math::linear::homography::structure< scalar_type, 2>  homography2d_type;
typedef math::geometry::interval::structure<scalar_type,2>  interval2d_type;

point2d_type s0{0,0}; 
point2d_type sx{1,0}; 
point2d_type sy{0,1}; 
point2d_type sz{1,1};

point2d_type t0{ 0,0 };
point2d_type tx{ 1,0 };
point2d_type ty{ 0,1 };
point2d_type tz{ 1,1 };

interval2d_type domain{ {-2,-2}, {+2,+2} };
interval2d_type g_screen{ {-5,-5}, {+5,5} };

cv::Point2i screen2frame( point2d_type const point, interval2d_type const screen, int width, int height )
 {
  cv::Point2i result;
  result.x = (int)::math::function::any_to_any<scalar_type>( point[0], screen[0][0], screen[1][0], 0, width  );
  result.y = (int)::math::function::any_to_any<scalar_type>( point[1], screen[0][1], screen[1][1], height, 0 );
  return result;
}

void monitor( cv::Mat & frame )
 {
  homography2d_type H;
  ::math::linear::homography::constructA( H, s0, t0, sx,tx, sy, ty, sz, tz );

  int width = frame.cols;
  int height = frame.rows;
  for( int y = 0; y < g_stepY; ++y ) 
  for( int x = 0; x < g_stepX; ++x )
  {
      frame.at<cv::Vec3b>( (int)y, (int)x)[0] = std::uint8_t( int( 255 ) );
      frame.at<cv::Vec3b>( (int)y, (int)x)[1] = std::uint8_t( int( 255 ) );
      frame.at<cv::Vec3b>( (int)y, (int)x)[2] = std::uint8_t( int( 255 ) );
  }

  cv::circle( frame, screen2frame( s0, g_screen, width, height ), 8, cv::Scalar( 96, 96, 96 ), 8 );
  cv::circle( frame, screen2frame( sx, g_screen, width, height ), 8, cv::Scalar( 0, 0, 192 ), 8  );
  cv::circle( frame, screen2frame( sy, g_screen, width, height ), 8, cv::Scalar( 0, 192, 0 ), 8 );
  cv::circle( frame, screen2frame( sz, g_screen, width, height ), 8, cv::Scalar( 192, 0, 0 ), 8 );
  cv::circle( frame, screen2frame( t0, g_screen, width, height ), 5, cv::Scalar( 127, 127, 127 ), 5 );
  cv::circle( frame, screen2frame( tx, g_screen, width, height ), 5, cv::Scalar( 0, 0, 255 ), 5  );
  cv::circle( frame, screen2frame( ty, g_screen, width, height ), 5, cv::Scalar( 0, 255, 0 ), 5 );
  cv::circle( frame, screen2frame( tz, g_screen, width, height ), 5, cv::Scalar( 255, 0, 0 ), 5 );

  point2d_type s,t;
  for( int y = 0; y < g_stepY; ++y )
   {
    s[1] = ::math::function::any_to_any<scalar_type>( y, 0, g_stepY, domain[0][1], domain[1][1] );
    for( int x=0; x< g_stepX;  ++x )
     {
      s[0] = ::math::function::any_to_any<scalar_type>( x, 0, g_stepX, domain[0][0], domain[1][0] );
      ::math::linear::homography::transform( t, H, s );

      auto screen = screen2frame( t, g_screen, width, height );

       if( screen.x < 0 ) continue;
       if( screen.y < 0 ) continue;
       if( width < screen.x +1 ) continue;
       if( height< screen.y+1  ) continue;
      frame.at<cv::Vec3b>( screen )[0] = std::uint8_t( int( 255 ) );
      frame.at<cv::Vec3b>( screen )[1] = std::uint8_t( int( 255 ) );
      frame.at<cv::Vec3b>( screen )[2] = std::uint8_t( int( 255 ) );
     }
    }
 }

int main( int argc, char *argv[] )
 {
  int frame_width  = 800;
  int frame_height = 600;

  cv::Mat frame( frame_height, frame_width,CV_8UC3 );

 initUI( );


 point2d_type *active_point = &s0; 
  while( true )
   {
    rectangle( frame, cv::Point2i( 0, 0 ), ::cv::Point2i( frame.cols-1, frame.rows-1 ), ::cv::Scalar( 0, 0, 0 ), cv::FILLED );
    monitor( frame );
    cv::circle( frame, screen2frame( *active_point, g_screen, frame_width, frame_height ), 15, cv::Scalar( 192, 192, 192 ), 2 );

    cv::imshow( "Frame-frame", frame );
    int c = (char)cv::waitKey(1);
    if( c == 27 ) break;
    switch( c )
     {
      case('1'): active_point = &s0 ;  break;
      case('2'): active_point = &sx ;  break;
      case('3'): active_point = &sy ;  break;
      case('4'): active_point = &sz ;  break;
 
      case('q'): active_point = &t0;  break;
      case('w'): active_point = &tx;  break;
      case('e'): active_point = &ty;  break;
      case('r'): active_point = &tz;  break;

      case('s'): (*active_point)[1] += 0.1 ;  break;
      case('x'): (*active_point)[1] -= 0.1 ;  break;
      case('z'): (*active_point)[0] -= 0.1 ;  break;
      case('c'): (*active_point)[0] += 0.1 ;  break;
      case(-1):   break;
       default:
       std::cout<< c << std::endl;

     }
   }

  return EXIT_SUCCESS;
 }

