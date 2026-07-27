#include "opencv2/opencv.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#define THECURVE hilbert2D

int g_step=3;     // 
int g_valueIndex = 1;     // 
int g_valueX = 2;     // 
int g_valueY = 2;     // 
int g_valueZ = 0;     // 

int g_fliper = 0;     // 

int g_valueTb = 0;     // 
int g_valueTe = 99;     // 
int g_valueTc = 100;     // 

int g_valueR = 0;     // 
int g_valueF = 0;     // 

int g_valueA11 = 0;     // 
int g_valueA12 = 0;     // 
int g_valueA21 = 0;     // 
int g_valueA22 = 0;     // 

int g_valueSv = 100;     // 
int g_valueSm = 100;     // 
int g_alphaX = 0;     // 
int g_alphaY = 0;     // 
int g_alphaZ = 0;     // 

#include "math/math.hpp"

typedef ::math::linear::affine::structure<double, 2  > affine_type;
typedef ::math::linear::affine::structure<double, 3  > affine3_type;
typedef ::math::linear::vector::point<double, 2> vector_type;
typedef ::math::linear::vector::point<double, 2> point_type, point2_type;
typedef ::math::linear::vector::point<double, 3> vector3_type;
typedef ::math::linear::vector::point<double, 3> point3_type;

void putpixel( cv::Mat & frame, int x, int y, ::cv::Vec3b const & color )
 {
  if( x < 0 ) return;
  if( y < 0 ) return;
  if( frame.cols <= x ) return;
  if( frame.rows <= y ) return;
  frame.at<cv::Vec3b>( frame.rows - y-1, x ) = color;
 }
 
void my_line( cv::Mat& frame, cv::Point2i const& c0, cv::Point2i const& c1, ::cv::Scalar const& color )
 {
  cv::line( frame, cv::Point2d( c0.x, frame.rows - c0.y - 1 ), cv::Point2d( c1.x, frame.rows - c1.y - 1 ), color );
 }

void my_circle( cv::Mat & frame, cv::Point2i const& c, int r, ::cv::Scalar const& color )
 {
  cv::circle( frame, cv::Point2d( c.x, frame.rows - c.y - 1 ), r, color, 3 );
 }

void my_rect( cv::Mat & frame, cv::Point2i const& c0, cv::Point2i const& c1, ::cv::Scalar const& color )
 {
  cv::rectangle( frame, cv::Point2d( c0.x, frame.rows - c0.y - 1 ), cv::Point2d( c1.x, frame.rows - c1.y - 1 ), color, cv::FILLED );
 }

void render_affine( cv::Mat& frame , affine_type const& A, ::cv::Vec3b const&color )
 {
  for( double y = 0; y < 1.0; y += 0.001 )
   {
    for( double x = 0; x < 1.0; x += 0.001 )
     {
      point_type P;

      math::linear::affine::transform(P, A, {x,y } );

      putpixel( frame, int(frame.cols*P[0]), int(frame.rows * P[1]), ::cv::Vec3b( 0, int(y*255), int(x*255) ) );
     }
   }
 }

void render_sweep( cv::Mat& frame, ::cv::Vec3b const&color )
 {
  int x = 0;
  int y = 0;
  for( double t = g_valueTb/ 100.0; t < g_valueTe/ 100.0 ; t += 1.0 / g_valueTc )
   {
    point2_type P;

    ::math::function::gen_z( P, t, g_step, (double)g_valueIndex );

    int X =(int) ( P[0] * frame.cols );
    int Y =(int) ( P[1] * frame.rows );

    my_line( frame, cv::Point( x,y ), cv::Point( X, Y ), ::cv::Vec3b( 255, int(t*255), int(t*255) ) );
    x = X;
    y = Y;
   }
 }

void render_hilbert( cv::Mat& frame, ::cv::Vec3b const&color )
 {
  double step = pow( 0.125, g_step );
  point3_type P;

  ::math::function::hilbert3D( P, step, g_valueIndex );
    P[0] = 2*P[0] - 1;
    P[1] = 2*P[1] - 1;
    P[2] = 2*P[2] - 1;
    ::math::linear::vector::rotateZ( P, math::geometry::deg2rad( g_alphaZ ) );
    ::math::linear::vector::rotateX( P, math::geometry::deg2rad( g_alphaX ) );
    ::math::linear::vector::rotateY( P, math::geometry::deg2rad( g_alphaY ) );
  auto x = P[0];
  auto y = P[2];
  x *= 0.3 * frame.cols;
  y *= 0.3 * frame.rows;

  x += frame.cols / 2;
  y += frame.rows / 2;

  my_circle( frame, cv::Point2d( x, y ), 5, ::cv::Scalar( 255, 255, 255 ) );

  for( double t = 2*step; t < g_valueTe / 100.0 ; t += step )
   {
  ::math::function::hilbert3D( P, t, g_valueIndex );

    P[0] = 2*P[0] - 1;
    P[1] = 2*P[1] - 1;
    P[2] = 2*P[2] - 1;

    ::math::linear::vector::rotateZ( P, math::geometry::deg2rad( g_alphaZ ) );
    ::math::linear::vector::rotateX( P, math::geometry::deg2rad( g_alphaX ) );
    ::math::linear::vector::rotateY( P, math::geometry::deg2rad( g_alphaY ) );

      auto X = P[0];
      auto Y = P[2];

      X *= 0.3 * frame.cols;
      Y *= 0.3 * frame.rows;

      X += frame.cols/2;
      Y += frame.rows/2;
      my_line( frame, cv::Point( (int)x, (int)y ), cv::Point( (int)X, (int)Y ), ::cv::Vec3b( 255, int(t*255), int(t*255) ) );
      x = X;
      y = Y;
   }
 }

void initUI( )
 {
  cv::namedWindow( "Command", cv::WINDOW_FREERATIO );

  ::cv::createTrackbar( "step", "Command", &g_step, 16, NULL );
  ::cv::createTrackbar( "I", "Command", &g_valueIndex, 20, NULL );
  ::cv::createTrackbar( "Sv", "Command", &g_valueSv, 200, NULL );
  ::cv::createTrackbar( "Sm", "Command", &g_valueSm, 200, NULL );
  ::cv::createTrackbar( "X", "Command", &g_valueX, 4, NULL );
  ::cv::createTrackbar( "Y", "Command", &g_valueY, 4, NULL );
  ::cv::createTrackbar( "Z", "Command", &g_valueZ, 100, NULL );
  ::cv::createTrackbar( "Tb", "Command", &g_valueTb, 100, NULL );
  ::cv::createTrackbar( "Te", "Command", &g_valueTe, 100, NULL );
  ::cv::createTrackbar( "Tc", "Command", &g_valueTc, 10000, NULL );

  //::cv::createTrackbar( "R", "Command",  &g_valueR, 3, NULL );
  //::cv::createTrackbar( "F", "Command",  &g_valueF, 3, NULL );
  //::cv::createTrackbar( "ff", "Command", &g_fliper, 15, NULL );

  //::cv::createTrackbar( "A11", "Command", &g_valueA11, 3, NULL );
  //::cv::createTrackbar( "A12", "Command", &g_valueA12, 3, NULL );
  //::cv::createTrackbar( "A21", "Command", &g_valueA21, 3, NULL );
  //::cv::createTrackbar( "A22", "Command", &g_valueA22, 3, NULL );

  ::cv::createTrackbar( "aX", "Command", &g_alphaX, 360, NULL );
  ::cv::createTrackbar( "aY", "Command", &g_alphaY, 360, NULL );
  ::cv::createTrackbar( "aZ", "Command", &g_alphaZ, 360, NULL );
}

void monitor( cv::Mat & frame )
 {
  int width = frame.cols;
  int height = frame.rows;
  cv::rectangle ( frame, cv::Point2i(0,0),  ::cv::Point2i( frame.cols, frame.rows ), ::cv::Scalar( 0,  0, 0 ), cv::FILLED  );

  render_sweep( frame,cv::Vec3b( 255, 255, 255 ) );
  
  //render_hilbert( frame,cv::Vec3b( 255, 255, 255 ) );
   return;
  if(false){
    static affine_type A[4] = {
          { { 0.0, -0.5, +0.5,  0.0 } , { +0.50,   0.00 } }
         ,{ { 0.0, -0.5, +0.5,  0.0 } , { +0.50,   0.50 } }
         ,{ { 0.0, +0.5, -0.5,  0.0 } , { +0.50 ,  1.00 } }
         ,{ { 0.0, +0.5, -0.5,  0.0 } , { +0.50 , +0.50 } }
    };
    ::math::function::sfc::direct( A[0], point_type{ 0.0, 0.0 }, point_type{ 0.50, 0.50 }, vector_type{ 0.5, 0.5 }, vector_type{ 0.5, 0.0 } );
    ::math::function::sfc::direct( A[1], point_type{ 0.5, 0.0 }, point_type{ 1.00, 0.50 }, vector_type{ 0.5, 0.5 }, vector_type{ 0.5, 0.0 } );
    ::math::function::sfc::direct( A[2], point_type{ 0.0, 0.5 }, point_type{ 0.50, 1.00 }, vector_type{ 0.5, 0.5 }, vector_type{ 0.5, 0.0 } );
    ::math::function::sfc::direct( A[3], point_type{ 0.5, 0.5 }, point_type{ 1.00, 1.00 }, vector_type{ 0.5, 0.5 }, vector_type{ 0.5, 0.0 } );

   render_affine( frame, A[0], cv::Vec3b( 255, 255, 255 ) );
   render_affine( frame, A[1], cv::Vec3b( 255, 255, 255 ) );
   render_affine( frame, A[2], cv::Vec3b( 255, 255, 255 ) );
   render_affine( frame, A[3], cv::Vec3b( 255, 255, 255 ) );
  }

  if(false){
   affine_type A;
   ::math::linear::affine::construct( A, { vector_type{ 0.0,0.0 }, vector_type{ 0.0,0.5 }, vector_type{ 0.5,0.0 } }, { vector_type{0.0,0.0}, vector_type{1.0,0.0}, vector_type{0.0,1.0} } );  render_affine( frame, A, cv::Vec3b(255, 255, 255) );
   ::math::linear::affine::construct( A, { vector_type{ 0.5,0.0 }, vector_type{ 1.0,0.0 }, vector_type{ 0.5,0.5 } }, { vector_type{0.0,0.0}, vector_type{1.0,0.0}, vector_type{0.0,1.0} } );  render_affine( frame, A, cv::Vec3b(255, 255, 255) );
   ::math::linear::affine::construct( A, { vector_type{ 0.5,0.5 }, vector_type{ 1.0,0.5 }, vector_type{ 0.5,1.0 } }, { vector_type{0.0,0.0}, vector_type{1.0,0.0}, vector_type{0.0,1.0} } );  render_affine( frame, A, cv::Vec3b(255, 255, 255) );
   ::math::linear::affine::construct( A, { vector_type{ 0.5,1.0 }, vector_type{ 0.5,0.5 }, vector_type{ 0.0,1.0 } }, { vector_type{0.0,0.0}, vector_type{1.0,0.0}, vector_type{0.0,1.0} } );  render_affine( frame, A, cv::Vec3b(255, 255, 255) );
  }

  double step = pow( 0.25, g_step );
  int xr, yr;
  long double x, y;

  ::math::function::THECURVE<long double>( x, y , 0, g_step );
  xr = int( x*width  );
  yr = int( y*height );
  cv::Point2d first( xr, yr );

  for( double t= step; true && ( t < g_valueTe / 100.0 - step )  ;  t += step )
   {
    ::math::function::THECURVE<long double>( x, y , t, g_step  );

    xr = int( x*width  );
    yr = int( y*height );
    cv::Point2d second( xr, yr );

    my_line(frame, first, second , ::cv::Scalar(  t*255, t * 255, (1-t)* 255 ) );
    first = second;
   }

  ::math::function::THECURVE<long double>( x, y , 0, g_step  );
  xr = int( x*width  );
  yr = int( y*height );

  my_circle( frame, cv::Point2d( xr,  yr ), 5, ::cv::Scalar( 255, 255, 255 ) );
 }

  void test_h3d_0()
  {
    affine3_type A;
    //::math::function::sfc::direct<double>( A, point3_type{0.5,0.5, 0.5}, point3_type{ 0.0, 0.0, 0.0 }, point3_type{ 1,0,0 }, point3_type{ 0,1,0 } );
 
   std::array<double, 3 > p0 ;
   ::math::function::hilbert3D<double>( p0, 0.0/8+1/16.0, 1 );
   ::math::function::hilbert3D<double>( p0, 1.0/8+1/16.0, 1 );
   ::math::function::hilbert3D<double>( p0, 2.0/8+1/16.0, 1 );
   ::math::function::hilbert3D<double>( p0, 3.0/8+1/16.0, 1 );
   ::math::function::hilbert3D<double>( p0, 4.0/8+1/16.0, 1 );
   ::math::function::hilbert3D<double>( p0, 5.0/8+1/16.0, 1 );
   ::math::function::hilbert3D<double>( p0, 6.0/8+1/16.0, 1 );
   ::math::function::hilbert3D<double>( p0, 7.0/8+1/16.0, 1 );
 }

 void test_h3d()
  {
   double step = pow( 0.1, 5 );
   std::array<double, 3 > p0, p1;
   ::math::function::hilbert3D( p0, 0.0, 16 );
   ::math::function::hilbert3D( p1, step, 16 );

   double distance = ::math::linear::vector::distance( p0, p1 );
   double distanceMin = distance;
   double distanceMax = distance;
   p0 = p1;
   for( double t = 2*step; true && (t < 1 - step); t += step )
    {
     ::math::function::hilbert3D( p1, t, 16 );
     distance = ::math::linear::vector::distance( p0, p1 );
     distanceMin = std::min( distanceMin, distance );
     distanceMax = std::max( distanceMax, distance );
    }
   std::cout << distanceMin << std::endl;
   std::cout << distanceMax << std::endl;
 }

int main( int argc, char *argv[] )
 {
  //test_h3d_0();

  int frame_height = 800;
  int frame_width  = 800;

  cv::Mat frame( frame_height,frame_width,CV_8UC3 );

  initUI( );
  while( true )
   {
    monitor( frame );
    cv::imshow( "Frame-frame", frame );
    char c = (char)cv::waitKey(1);
    if( c == 27 ) break;
   }

  return EXIT_SUCCESS;
 }

