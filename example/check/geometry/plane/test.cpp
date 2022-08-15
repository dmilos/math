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
  ::math::geometry::plane::horizon<double>::processX( horizon, plane );
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
  ::math::geometry::plane::horizon<double>::processY( horizon, plane );
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
  ::math::geometry::plane::horizon<double>::processZ( horizon, plane );
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

int main( int argc, char *argv[] )
 {
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
