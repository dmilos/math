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

void X( ::math::linear::vector::structure<double,3> const& normal )
 {
  std::cout << "---   ---   ---"<< std::endl;
  ::math::geometry::plane::no3d<double>       display;
  ::math::linear::vector::load( display.origin(),  1, 0, 0 );
  ::math::linear::vector::load( display.normal(),  1, 0, 0 );
  std::cout << "display: "; print( display );  std::cout << std::endl;

  ::math::geometry::plane::no3d<double>       plane;
  ::math::linear::vector::load( plane.origin(), 0, 0, 0 );

  ::math::geometry::direction::ABC2D<double> horizon;
  ::math::geometry::direction::parametric<double, 3 >    intersect;
  ::math::geometry::direction::parametric<double, 2 >    intersectP;
  ::math::geometry::direction::ABC2D<double >            intersectABC;

   plane.normal() = normal;
  std::cout << "plane: "; print( plane );  std::cout << std::endl;
  ::math::geometry::plane::horizon<double>::processX( horizon, plane.normal() );
  ::math::geometry::plane::intersect( intersect, plane, display );
   std::cout << "intersect: ";print( intersect ); std::cout << std::endl;
  ::math::linear::vector::load( intersectP.origin(),    -intersect.origin()[1],    intersect.origin()[2]    );
  ::math::linear::vector::load( intersectP.direction(), -intersect.direction()[1], intersect.direction()[2] );
  std::cout << "intersectP: ";print( intersectP ); std::cout << std::endl;
  intersectABC = intersectP;
  std::cout << "horizon:      "; print( horizon ); std::cout << std::endl;
  std::cout << "intersectABC: "; print( intersectABC ); std::cout << std::endl;

  display = display;
 }

void Y( ::math::linear::vector::structure<double,3> const& normal )
 {
  std::cout << "---   ---   ---"<< std::endl;
  ::math::geometry::plane::no3d<double>       display;
  ::math::linear::vector::load( display.origin(),  0, 1, 0 );
  ::math::linear::vector::load( display.normal(),  0, 1, 0 );
  std::cout << "display: "; print( display );  std::cout << std::endl;

  ::math::geometry::plane::no3d<double>       plane;
  ::math::linear::vector::load( plane.origin(), 0, 0, 0 );

  ::math::geometry::direction::ABC2D<double> horizon;
  ::math::geometry::direction::parametric<double, 3 >    intersect;
  ::math::geometry::direction::parametric<double, 2 >    intersectP;
  ::math::geometry::direction::ABC2D<double >            intersectABC;

   plane.normal() = normal;
  std::cout << "plane: "; print( plane );  std::cout << std::endl;
  ::math::geometry::plane::horizon<double>::processY( horizon, plane.normal() );
  ::math::geometry::plane::intersect( intersect, plane, display );
   std::cout << "intersect: ";print( intersect ); std::cout << std::endl;
  ::math::linear::vector::load( intersectP.origin(),     intersect.origin()[0],     intersect.origin()[2]    );
  ::math::linear::vector::load( intersectP.direction(), -intersect.direction()[0], -intersect.direction()[2] );
  std::cout << "intersectP: ";print( intersectP ); std::cout << std::endl;
  intersectABC = intersectP;
  std::cout << "horizon:      "; print( horizon ); std::cout << std::endl;
  std::cout << "intersectABC: "; print( intersectABC ); std::cout << std::endl;

  display = display;
 }

void Z( ::math::linear::vector::structure<double,3> const& normal )
 {
  std::cout << "---   ---   ---"<< std::endl;
  ::math::geometry::plane::no3d<double>       display;
  ::math::linear::vector::load( display.origin(),  0, 0, 1 );
  ::math::linear::vector::load( display.normal(),  0, 0, 1 );
  std::cout << "display: "; print( display );  std::cout << std::endl;

  ::math::geometry::plane::no3d<double>       plane;
  ::math::linear::vector::load( plane.origin(), 0, 0, 0 );

  ::math::geometry::direction::ABC2D<double> horizon;
  ::math::geometry::direction::parametric<double, 3 >    intersect;
  ::math::geometry::direction::parametric<double, 2 >    intersectP;
  ::math::geometry::direction::ABC2D<double >            intersectABC;

   plane.normal() = normal;
  std::cout << "plane: "; print( plane );  std::cout << std::endl;
  ::math::geometry::plane::horizon<double>::processZ( horizon, plane.normal() );
  ::math::geometry::plane::intersect( intersect, plane, display );
   std::cout << "intersect: ";print( intersect ); std::cout << std::endl;
  ::math::linear::vector::load( intersectP.origin(),     intersect.origin()[0],     intersect.origin()[1]    );
  ::math::linear::vector::load( intersectP.direction(),  intersect.direction()[0],  intersect.direction()[1] );
  std::cout << "intersectP: ";print( intersectP ); std::cout << std::endl;
  intersectABC = intersectP;
  std::cout << "horizon:      "; print( horizon ); std::cout << std::endl;
  std::cout << "intersectABC: "; print( intersectABC ); std::cout << std::endl;

  display = display;
 }

#define RND ( rand()/(double)RAND_MAX - 0.5 )
void project()
 {
  typedef ::math::linear::vector::point< double, 2 > uv_type;
  typedef ::math::linear::vector::point< double, 3 > point_type;

  typedef ::math::geometry::plane::no3d<double> no3d_type;
  typedef ::math::geometry::plane::parametric3d<double>  parametric3d_type;


  //point_type point{ 0.1, 0.1, 0.1 };
  //no3d_type no3d;         no3d.origin( { 0.5, 0.9, 0.45 }); no3d.normal( { 0, 0, 1 } );
  //parametric3d_type p3d;  p3d.origin( { 0.5, 0.9, 0.0 } );  p3d.x( { RND, 0, 0 } ); p3d.y( { 0, RND, 1 } );

  for( int i=0; i< 100; ++i )
   {
    point_type point{ RND, RND, RND };
    no3d_type no3d;         no3d.origin( { RND, RND, RND } ); no3d.normal( { RND, RND, RND } );
    parametric3d_type p3d;  p3d.origin( { RND, RND, RND } );  p3d.x( { RND, RND, RND } ); p3d.y( { RND, RND, RND } );

    point_type  projection0;
    ::math::geometry::plane::project( projection0, no3d, point );
    auto d0 = ::math::linear::vector::distance( projection0, point );

    ::math::linear::vector::subtraction( no3d.origin(), point );
    point_type  projection1;
    ::math::geometry::plane::project( projection1, no3d );
    auto d1 = ::math::linear::vector::distance(projection1, {0,0,0} );

    if( 0.0000000001 < fabs( d1 - d0 ) )
     {
	  std::cout << "aaa" << std::endl;
     }

    uv_type uv0;
    ::math::geometry::plane::project( uv0, p3d, point );
    auto d2 = ::math::geometry::plane::distance( p3d.point( uv0 ), no3d_type( p3d ) );

    ::math::linear::vector::subtraction( p3d.origin(), point );
    uv_type uv1;
    ::math::geometry::plane::project( uv1, p3d );
    auto d3 = ::math::geometry::plane::distance( p3d.point( uv1 ), no3d_type( p3d ) );

    if( 0.0000000001 < fabs( d2 - d3 ) )
     {
	  std::cout << "bbb" << std::endl;
     }
   }

 }

int main( int argc, char *argv[] )
 {
  project();
  cout << "Hello World" << endl;

  X( { 0, -1, +1,} );
  X( {  1, 2, 3  } );
  X( {  3, 2, 1  } );

  Y( { 0, -1, +1,} );
  Y( { 0, +1, +1,} );
  Y( {  1, 2, 3  } );
  Y( {  3, 2, 1  } );

  Z( { +1, 0, +1 } );
  Z( { -1, 0, +1 } );
  Z( { +1, 0, -1 } );
  Z( { -1, 0, -1 } );
  
  Z( { +1, +1, 0 } );
  Z( { -1, +1, 0 } );
  Z( { +1, -1, 0 } );
  Z( { -1, -1, 0 } );
  
  Z( { 0, +1, +1,} );
  Z( { 0, -1, +1} );
  Z( { 0, +1, -1,} );
  Z( { 0, -1, -1,} );
  
  Z( {  1, 2, 3  } );
  Z( {  3, 2, 1  } );

  return EXIT_SUCCESS;
 }
