#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

using namespace std;

template < typename scalar_name >
 void print( ::math::linear::vector::vector<scalar_name,3> const& coord )
  {
   std::cout << "{" << coord[0] << ", "<< coord[1] << ", "<< coord[2] << "} " ;
  }

::math::linear::vector::point<double,3> cloud_normal( std::vector< ::math::linear::vector::point<double,3> > const& cloud )
 {
  ::math::linear::vector::point<double,3> const& O = cloud[0];
  ::math::linear::vector::point<double,3>        X = cloud[1];
  ::math::linear::vector::point<double,3>        Y = cloud[2];
  ::math::linear::vector::point<double,3>        N;

  ::math::linear::vector::subtraction( X , X, O );
  ::math::linear::vector::subtraction( Y , Y, O );

  ::math::linear::vector::cross( N , X, Y );

  ::math::linear::vector::length<double>( N, 1 );
  return N;
 }

void fit3d_X()
 {
  ::math::geometry::plane::no3d<double>                 no3d;
  std::vector< ::math::linear::vector::point<double,3> > cloud;

  cloud.clear();
  cloud.push_back({0,0,0}); cloud.push_back({0,1,0}); cloud.push_back({0,0,1});
  std::cout << __LINE__ << ". ";print( cloud_normal( cloud ) ); std::cout << " == " ;::math::geometry::plane::fit( no3d, cloud );    print( no3d.normal() ); std::cout << std::endl;

  cloud.clear();
  cloud.push_back({0, -1, -1 });
  cloud.push_back({0, -1, +1 });
  cloud.push_back({0, +1, -1 });
  cloud.push_back({0, +1, +1 });
  //std::cout << __LINE__ << ". "; print( cloud_normal( cloud ) ); std::cout << " == "; ::math::geometry::plane::fit( no3d, cloud );   print( no3d.normal() ); std::cout << std::endl;
 }

void fit3d_Y()
{
  ::math::geometry::plane::no3d<double>                 no3d;
  std::vector< ::math::linear::vector::point<double,3> > cloud;

  cloud.clear();
  cloud.push_back({0,0,0}); cloud.push_back({1,0,0}); cloud.push_back({0,0,1});
  std::cout << __LINE__ << ". ";print( cloud_normal( cloud ) ); std::cout << " == "; ::math::geometry::plane::fit( no3d, cloud );    print( no3d.normal() ); std::cout << std::endl;


  cloud.clear();
  cloud.push_back({-1, 0, -1 });
  cloud.push_back({-1, 0, +1 });
  cloud.push_back({+1, 0, -1 });
  cloud.push_back({+1, 0, +1 });
  //std::cout << __LINE__ << ". "; print( cloud_normal( cloud ) ); std::cout << " == "; ::math::geometry::plane::fit( no3d, cloud );   print( no3d.normal() ); std::cout << std::endl;
}

void fit3d_Z()
 {
  ::math::geometry::plane::no3d<double>                no3d;
  std::vector< ::math::linear::vector::point<double,3> > cloud;

  cloud.clear();
  cloud.push_back({0,0,0}); cloud.push_back({1,0,0}); cloud.push_back({0,1,0});
  std::cout << __LINE__ << ". "; print( cloud_normal( cloud ) ); std::cout << " == "; ::math::geometry::plane::fit( no3d, cloud );     print( no3d.normal() ); std::cout << std::endl;

  cloud.clear();
  cloud.push_back({-1,-1,0});
  cloud.push_back({-1,+1,0});
  cloud.push_back({+1,-1,0});
  cloud.push_back({+1,+1,0});
  //std::cout << __LINE__ << ". "; print( cloud_normal( cloud ) ); std::cout << " == "; ::math::geometry::plane::fit( no3d, cloud );   print( no3d.normal() ); std::cout << std::endl;
}

void fit3d()
 {
  ::math::geometry::plane::no3d<double>              a, no3d;
  std::vector< ::math::linear::vector::point<double,3> > cloud;


  cloud.clear();
  cloud.push_back({1,0,0}); cloud.push_back({0,1,0}); cloud.push_back({1,0,1});
  std::cout << __LINE__ << ". "; print( cloud_normal( cloud ) ); std::cout << " == "; ::math::geometry::plane::fit( no3d, cloud );   print( no3d.normal() ); std::cout << std::endl;
  // -------

  cloud.clear();
  cloud.push_back({1,0,0}); cloud.push_back({0,1,0}); cloud.push_back({0,0,1});
  std::cout << __LINE__ << ". ";print( cloud_normal( cloud ) ); std::cout << " == ";::math::geometry::plane::fit( no3d, cloud );     print( no3d.normal() ); std::cout << std::endl;

  cloud.clear();
  cloud.push_back({1,0,0}); cloud.push_back({0,1,0}); cloud.push_back({1,0,1});
  std::cout << __LINE__ << ". "; print( cloud_normal( cloud ) ); std::cout << " == "; ::math::geometry::plane::fit( no3d, cloud );     print( no3d.normal() ); std::cout << std::endl;

  cloud.clear();
  cloud.push_back({1,0,0}); cloud.push_back({0,1,1}); cloud.push_back({0,0,1});
  std::cout << __LINE__ << ". "; print( cloud_normal( cloud ) ); std::cout << " == "; ::math::geometry::plane::fit( no3d, cloud );     print( no3d.normal() ); std::cout << std::endl;

  cloud.clear();
  cloud.push_back({0,1,0}); cloud.push_back({1,1,0}); cloud.push_back({0,0,1});
  std::cout << __LINE__ << ". "; print( cloud_normal( cloud ) ); std::cout << " == ";::math::geometry::plane::fit( no3d, cloud );     print( no3d.normal() ); std::cout << std::endl;

  cloud.clear();
  cloud.push_back({2,0,0}); cloud.push_back({0,1,0}); cloud.push_back({0,0,1});
  std::cout << __LINE__ << ". "; print( cloud_normal( cloud ) ); std::cout << " == "; ::math::geometry::plane::fit( no3d, cloud );     print( no3d.normal() ); std::cout << std::endl;

  cloud.clear();
  cloud.push_back({1,0,0}); cloud.push_back({0,2,0}); cloud.push_back({0,0,1});
  std::cout << __LINE__ << ". "; print( cloud_normal( cloud ) ); std::cout << " == ";::math::geometry::plane::fit( no3d, cloud );     print( no3d.normal() ); std::cout << std::endl;

  cloud.clear();
  cloud.push_back({1,0,0}); cloud.push_back({0,1,0}); cloud.push_back({0,0,2});
  std::cout << __LINE__ << ". "; print( cloud_normal( cloud ) ); std::cout << " == "; ::math::geometry::plane::fit( no3d, cloud );    print( no3d.normal() ); std::cout << std::endl;

  cloud.clear();
  cloud.push_back({1,0,0}); cloud.push_back({0,2,0}); cloud.push_back({0,0,2});
  std::cout << __LINE__ << ". "; print( cloud_normal( cloud ) ); std::cout << " == ";::math::geometry::plane::fit( no3d, cloud );     print( no3d.normal() ); std::cout << std::endl;

  cloud.clear();
  cloud.push_back({2,0,0}); cloud.push_back({0,1,0}); cloud.push_back({0,0,2});
  std::cout << __LINE__ << ". "; print( cloud_normal( cloud ) ); std::cout << " == ";::math::geometry::plane::fit( no3d, cloud );     print( no3d.normal() ); std::cout << std::endl;

  cloud.clear();
  cloud.push_back({2,0,0}); cloud.push_back({0,2,0}); cloud.push_back({0,0,1});
  std::cout << __LINE__ << ". "; print( cloud_normal( cloud ) ); std::cout << " == ";::math::geometry::plane::fit( no3d, cloud );     print( no3d.normal() ); std::cout << std::endl;


 }

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  ::math::geometry::plane::no3d<double>              a, no3d;
  ::math::geometry::plane::parametric3d<double>      b, param3d;
  ::math::geometry::plane::noNd<double, 3>           c;
  ::math::geometry::plane::noNd<double, 5>           c5;
  ::math::geometry::plane::three<double>             d;

  a=b;   a = d;
  b=a;   b = d;

  d=a; d=b;

  double l;
  ::math::linear::vector::point<double,3>             point3;
  ::math::linear::vector::point<double,2>             point2{0};   point2 = point2;

  ::math::geometry::direction::ABC2D<double>           abc;
  ::math::geometry::plane::ABCD3D<double>             abcd;
  ::math::geometry::plane::three<double>             tttt;

  abcd    =  no3d; abcd    = param3d; abcd    = tttt;
  no3d    =  abcd; no3d    = param3d; no3d    = tttt;
  param3d =  abcd; param3d = abcd;    param3d = tttt;
  tttt = abcd;     tttt    = no3d;    tttt    = param3d;

  ::math::geometry::direction::parametric<double, 3 > parametric;

  ::math::geometry::plane::intersect( point3, no3d, parametric );
  ::math::geometry::plane::intersect( point3, l, no3d, parametric );

  ::math::geometry::plane::distance( point3, no3d );

  fit3d_X();
  fit3d_Y();
  fit3d_Z();

  fit3d();

  auto plane1 = ::math::geometry::plane::bisector( point3, point3 );
  ::math::linear::vector::point<double,10>             point10a;
  ::math::linear::vector::point<double,10>             point10b;
  auto planeN = ::math::geometry::plane::bisector( point10a, point10b );

  return EXIT_SUCCESS;
 }
