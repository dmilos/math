#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

#include "math/geometry/projective/camera/focus/wand2d.hpp"

using namespace std;


void wanadCenter()
 {
  double focus;
  double aspect = 16.0/9.0;
  double A=0;
  double  distance0=0;
  double  distanceA=0;
  double  lengthW=0;

  A=1.5;
  distance0=4;
  distanceA=sqrt( 4*4 + 3*3 );
  lengthW=3;
 ::math::geometry::projective::camera::focus::wand2d<double>( focus, A,  distance0, distanceA, lengthW );

  A=0.75;
  distance0=4;
  distanceA=sqrt( 4*4 + 3*3 );
  lengthW=3;
 ::math::geometry::projective::camera::focus::wand2d<double>( focus, A,  distance0, distanceA, lengthW );

  for( int i=0;  i< 100; ++i )
   {
    double  O = 0.5 + rand()/(double)RAND_MAX;
    double  x = O + rand()/(double)RAND_MAX;
    double  y = O + rand()/(double)RAND_MAX;
    double  f = rand()/(double)RAND_MAX;

    distance0 = O;
    distanceA = sqrt( x*x+y*y );
    lengthW=sqrt( x *x + (y-O)*(y-O) );
    A = f*x/y;

    if( false == ::math::geometry::projective::camera::focus::wand2d<double>( focus, A,  distance0, distanceA, lengthW ) )
     {

     }
     if ( 1e-8 < fabs( focus - f ) ) 
      {
       std::cout << ( fabs( focus - f ) < 1e-8 ) << std::endl;
      }
   }

 }

void wanadCenter2()
 {
  double focus;
  double aspect = 16.0/9.0;
  double A=0;
  double B=0;
  double  distance0=0;
  double  distanceA=0;
  double  distanceB=0;
  double  lengthW=0;

  A=0;
  B = 2;
  distance0=0;
  distanceA=4;
  distanceB=sqrt( 4*4+4*4 );
  lengthW=4;
 ::math::geometry::projective::camera::focus::wand2d<double>( focus, A, B, distanceA, distanceB, lengthW );
  std::cout <<  "F: " << focus << std::endl;

  A=-1;
  B = 0;
  distanceA=sqrt( 2*2+4*4 );
  distanceB=4;
  lengthW=2;
  ::math::geometry::projective::camera::focus::wand2d<double>( focus, A, B, distanceA, distanceB, lengthW );
  std::cout <<  "F: " << focus << std::endl;

  A=-1;
  B = 2;
  distanceA=sqrt( 2*2+4*4 );
  distanceB=sqrt( 4*4+4*4 );
  lengthW=6;
  ::math::geometry::projective::camera::focus::wand2d<double>( focus, A, B, distanceA, distanceB, lengthW );
  std::cout <<  "F: " << focus << std::endl;

  A =   -1;
  B = -0.5;
  distanceA=sqrt( 2*2+4*4 );
  distanceB=sqrt( 1*1+4*4 );
  lengthW=1;
  ::math::geometry::projective::camera::focus::wand2d<double>( focus, A, B, distanceA, distanceB, lengthW );
  std::cout <<  "F: " << focus << std::endl;
 
  A =   -1;
  B = +0.5;
  distanceA=sqrt( 2*2+4*4 );
  distanceB=sqrt( 1*1+4*4 );
  lengthW=3;
  ::math::geometry::projective::camera::focus::wand2d<double>( focus, A, B, distanceA, distanceB, lengthW );
  std::cout <<  "F: " << focus << std::endl;

  A = -0.5;
  B = +1;
  distanceA=sqrt( 1*1+4*4 );
  distanceB=sqrt( 2*2+4*4 );
  lengthW=3;
  ::math::geometry::projective::camera::focus::wand2d<double>( focus, A, B, distanceA, distanceB, lengthW );
  std::cout <<  "F: " << focus << std::endl;


  for( int i=0;  i< 100; ++i )
   {
    double  xA = rand()/(double)RAND_MAX - 1;
    double  yA = rand()/(double)RAND_MAX;
    double  xB = rand()/(double)RAND_MAX + 1;
    double  yB = rand()/(double)RAND_MAX;
    double  f = rand()/(double)RAND_MAX;

    distanceA = sqrt( xA*xA+yA*yA );
    distanceB = sqrt( xB*xB+yB*yB );
    lengthW=sqrt( (xA-xB) *(xA-xB) + (yA-yB) *(yA-yB) );

    A = f*xA/yA;
    B = f*xB/yB;

    if( false == ::math::geometry::projective::camera::focus::wand2d<double>( focus, A, B, distanceA, distanceB, lengthW ) )
     {
      std::cout << "fail" << std::endl;
     }
     if ( 1e-8 < fabs( focus - f ) ) 
      {
       std::cout << ( fabs( focus - f ) < 1e-8 ) << std::endl;
      }
   }

 }

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  wanadCenter();
  wanadCenter2();

  double focus;

 ::math::geometry::projective::camera::focus::wand2d<double>( focus, -212/640.0, 608/640.0, 237, 257, 200 );
  std::cout << "Fh: " << focus << " ~ " << ::math::geometry::rad2deg( ::math::geometry::projective::camera::f2h( focus ) ) << std::endl;

 ::math::geometry::projective::camera::focus::wand2d<double>( focus, -52/360.0, 199/360.0, 210, 275, 87 );
  std::cout << "Fv: " << focus << " ~ " << ::math::geometry::rad2deg( ::math::geometry::projective::camera::f2h( focus ) ) << std::endl;

 ::math::geometry::projective::camera::focus::wand2d<double>( focus, -380/640.0, 380/640.0, 268, 268, 200 );
  std::cout << "Fh: " << focus << " ~ " << ::math::geometry::rad2deg( ::math::geometry::projective::camera::f2h( focus ) ) << std::endl;

 ::math::geometry::projective::camera::focus::wand2d<double>( focus, -1, 1, 225, 180, 229 );
  std::cout << "Fh: " << focus << " ~ " << ::math::geometry::rad2deg( ::math::geometry::projective::camera::f2h( focus ) ) << std::endl;

  std::cout << " --- " << std::endl;


  double gamma;
  ::math::geometry::triangle::angle_gamma<double>( gamma, 225, 180, 229 );  std::cout << "Fh: " << ::math::geometry::rad2deg( gamma ) <<  std::endl;

  ::math::geometry::triangle::angle_gamma<double>( gamma, 225, 180, 228 );  std::cout << "Fh: " << ::math::geometry::rad2deg( gamma ) <<  std::endl;
  ::math::geometry::triangle::angle_gamma<double>( gamma, 225, 180, 230 );  std::cout << "Fh: " << ::math::geometry::rad2deg( gamma ) <<  std::endl;

  ::math::geometry::triangle::angle_gamma<double>( gamma, 225, 179, 228 );  std::cout << "Fh: " << ::math::geometry::rad2deg( gamma ) <<  std::endl;
  ::math::geometry::triangle::angle_gamma<double>( gamma, 225, 180, 229 );  std::cout << "Fh: " << ::math::geometry::rad2deg( gamma ) <<  std::endl;
  ::math::geometry::triangle::angle_gamma<double>( gamma, 225, 181, 230 );  std::cout << "Fh: " << ::math::geometry::rad2deg( gamma ) <<  std::endl;

  ::math::geometry::triangle::angle_gamma<double>( gamma, 224, 179, 228 );  std::cout << "Fh: " << ::math::geometry::rad2deg( gamma ) <<  std::endl;
  ::math::geometry::triangle::angle_gamma<double>( gamma, 225, 180, 229 );  std::cout << "Fh: " << ::math::geometry::rad2deg( gamma ) <<  std::endl;
  ::math::geometry::triangle::angle_gamma<double>( gamma, 226, 181, 230 );  std::cout << "Fh: " << ::math::geometry::rad2deg( gamma ) <<  std::endl;

  ::math::geometry::triangle::angle_gamma<double>( gamma, 225, 179, 229 );  std::cout << "Fh: " << ::math::geometry::rad2deg( gamma ) <<  std::endl;
  ::math::geometry::triangle::angle_gamma<double>( gamma, 225, 180, 229 );  std::cout << "Fh: " << ::math::geometry::rad2deg( gamma ) <<  std::endl;
  ::math::geometry::triangle::angle_gamma<double>( gamma, 225, 181, 229 );  std::cout << "Fh: " << ::math::geometry::rad2deg( gamma ) <<  std::endl;

  ::math::geometry::triangle::angle_gamma<double>( gamma, 224, 180, 229 );  std::cout << "Fh: " << ::math::geometry::rad2deg( gamma ) <<  std::endl;
  ::math::geometry::triangle::angle_gamma<double>( gamma, 225, 180, 229 );  std::cout << "Fh: " << ::math::geometry::rad2deg( gamma ) <<  std::endl;
  ::math::geometry::triangle::angle_gamma<double>( gamma, 226, 180, 229 );  std::cout << "Fh: " << ::math::geometry::rad2deg( gamma ) <<  std::endl;


  return EXIT_SUCCESS;
 }
