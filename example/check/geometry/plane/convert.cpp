#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/math.hpp"

#include "math/geometry/plane/horizon.hpp"

using namespace std;

  ::math::geometry::direction::ABC2D<double> horizon;
  ::math::geometry::direction::parametric<double, 3 >    intersect;

template< typename scalar_name >
 void print( ::math::geometry::direction::ABC2D<scalar_name> const& P )
  {
   std::cout << "{ ";
   std::cout<< std::setw(4) << P.A() << ", ";
   std::cout<< std::setw(4) << P.B() << ", ";
   std::cout<< std::setw(4) << P.C() << " ";
   std::cout << "}";
  }

template< typename scalar_name, math::type::size_t dimension_number >
 void print( ::math::geometry::direction::parametric<scalar_name,dimension_number> const& P )
  {
   std::cout << "{ ";
   std::cout << "[ ";
   for( int index = 0; index < dimension_number; ++index ) std::cout << P.origin()[index] << "; ";
   std::cout << "]";
   std::cout << "[ ";
   for( int index = 0; index < dimension_number; ++index ) std::cout << P.direction()[index] << "; ";
   std::cout << "]";
   std::cout << "}";
  }

 template< typename scalar_name >
 void print( ::math::geometry::plane::no3d<scalar_name> const& P )
  {
   std::cout << "{ ";
   std::cout << "[ ";
   for( int index = 0; index < 3; ++index ) std::cout << P.origin()[index] << "; ";
   std::cout << "]";
   std::cout << " ~ ";
   std::cout << "[ ";
   for( int index = 0; index < 3; ++index ) std::cout << P.normal()[index] << "; ";
   std::cout << "]";
   std::cout << "}";
  }




int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  cout << "Hello World" << endl;

  ::math::geometry::plane::ABCD3D<double>            abcd_ref{ 0,0,1,0};
  ::math::geometry::plane::no3d<double>              no3d_ref{{0,0,0},{0,0,1}};
  ::math::geometry::plane::parametric3d<double>      p3d_ref{{0,0,0},{1,0,0} ,{0,1,0} };
  ::math::geometry::plane::three<double>             t_ref{{0,0,0},{1,0,0},{0,1,0}};

  ::math::geometry::plane::ABCD3D<double>            abcd_tmp = abcd_ref;
  ::math::geometry::plane::no3d<double>              no3d_tmp = no3d_ref;
  ::math::geometry::plane::parametric3d<double>      p3d_tmp  =  p3d_ref;
  ::math::geometry::plane::three<double>             t_tmp    =    t_ref;
 
   
  abcd_tmp = abcd_ref;  abcd_tmp = abcd_tmp; abcd_tmp = abcd_tmp;
  abcd_tmp = abcd_ref;  no3d_tmp = abcd_tmp; abcd_tmp = no3d_tmp;
  abcd_tmp = abcd_ref;  p3d_tmp  = abcd_tmp; abcd_tmp =  p3d_tmp;
  abcd_tmp = abcd_ref;  t_tmp    = abcd_tmp; abcd_tmp =    t_tmp;
  
  no3d_tmp = no3d_ref;  abcd_tmp = no3d_tmp; no3d_tmp = abcd_tmp;
  no3d_tmp = no3d_ref;  no3d_tmp = no3d_tmp; no3d_tmp = no3d_tmp;
  no3d_tmp = no3d_ref;  p3d_tmp  = no3d_tmp; no3d_tmp =  p3d_tmp;
  no3d_tmp = no3d_ref;  t_tmp    = no3d_tmp; no3d_tmp =    t_tmp;

  p3d_tmp = no3d_ref;  abcd_tmp = p3d_tmp; p3d_tmp = abcd_tmp;
  p3d_tmp = no3d_ref;  no3d_tmp = p3d_tmp; p3d_tmp = no3d_tmp;
  p3d_tmp = no3d_ref;  p3d_tmp  = p3d_tmp; p3d_tmp =  p3d_tmp;
  p3d_tmp = no3d_ref;  t_tmp    = p3d_tmp; p3d_tmp =    t_tmp;
  
  t_tmp = t_ref;       abcd_tmp = t_tmp;      t_tmp = abcd_tmp;
  t_tmp = t_ref;       no3d_tmp = t_tmp;      t_tmp = no3d_tmp;
  t_tmp = t_ref;       p3d_tmp  = t_tmp;      t_tmp =  p3d_tmp;
  t_tmp = t_ref;       t_tmp    = t_tmp;      t_tmp =    t_tmp;
 
  ::math::geometry::plane::noNd<double, 3>           c;
  ::math::geometry::plane::noNd<double, 5>           c5;
 
 
  return EXIT_SUCCESS;
 }
