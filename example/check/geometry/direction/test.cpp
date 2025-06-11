#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;

template< typename scalar_name >
 void print(::math::geometry::direction::two<scalar_name, 2> const& dir )
  {
   std::cout << "[ "<< std::setw(9) << dir.first()[0] << ", " << std::setw(9) << dir.first()[1] << "; " << std::setw(9) << dir.second()[0] << ", " << std::setw(9) << dir.second()[1] << " ]";
  }

template< typename scalar_name >
 void print(::math::geometry::direction::polar<scalar_name> const& dir )
  {
   std::cout << "[ " << std::setw(9) << dir.origin()[0] << ", " << std::setw(9) << dir.origin()[1] << "; " << std::setw(9) << math::geometry::rad2deg( dir.angle() ) << " ]";
  }

template< typename scalar_name >
 void print(::math::geometry::direction::parametric<scalar_name, 2> const& dir )
  {
   std::cout << "[ " << std::setw(9) << dir.origin()[0] << ", " << std::setw(9) << dir.origin()[1] << "; " << std::setw(9) << dir.direction()[0] << ", " << std::setw(9) << dir.direction()[1] << " ]";
  }

template< typename scalar_name >
 void print(::math::geometry::direction::ABC2D<scalar_name> const& dir )
  {
   std::cout << "[ " << std::setw(9) << dir.A() << ", " << std::setw(9)  << dir.B() << "; " << std::setw(9)  << dir.C() << " ]";
  }

template< typename scalar_name >
 void print(::math::geometry::direction::normal<scalar_name, 2> const& dir )
  {
   std::cout << "[ " << std::setw(9)  << math::geometry::rad2deg( dir.angle() ) << ", " << std::setw(9) << dir.radius() << " ]";
  }

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  typedef  ::math::geometry::direction::two<double, 2> two_type;
  typedef  ::math::geometry::direction::polar<double> polar_type;
  typedef  ::math::geometry::direction::parametric<double,2> parametric_type;
  typedef  ::math::geometry::direction::ABC2D<double> ABC2D_type;
  typedef  ::math::geometry::direction::normal<double> normal_type;

  std::cout << "---------  referent  --------" << std::endl;
  ::math::linear::vector::structure<double, 2>  p0{ 0.5,1 };
  ::math::linear::vector::structure<double, 2>  p1{ 1,  0.9 };

  ::math::geometry::direction::two<double, 2>            t_ref{ p0, p1 };     print(  t_ref );
  ::math::geometry::direction::polar<double>            po_ref{ t_ref };      print( po_ref );
  ::math::geometry::direction::parametric<double, 2>    pp_ref{ t_ref };      print( pp_ref );
  ::math::geometry::direction::ABC2D<double>             a_ref{ t_ref };      print(  a_ref );
  ::math::geometry::direction::normal<double>            n_ref{ t_ref };      print(  n_ref );

  ::math::geometry::direction::two<double, 2>             t;
  ::math::geometry::direction::polar<double>             po;
  ::math::geometry::direction::parametric<double, 2>     pp;
  ::math::geometry::direction::ABC2D<double>              a;
  ::math::geometry::direction::normal<double>             n;

  std::cout << "---------  two_type  --------" << std::endl;

   t = t_ref; print(  t ); std::cout << std::endl;
  po = t_ref; print( po ); std::cout << std::endl;
  pp = t_ref; print( pp ); std::cout << "  " << ::math::geometry::direction::distance( pp, p0) << ", " << ::math::geometry::direction::distance(pp, p1 ) << std::endl;
  a  = t_ref; print(  a ); std::cout << "  " << ::math::geometry::direction::distance( a, p0 ) << ", " << ::math::geometry::direction::distance( a, p1 ) << std::endl;
  n  = t_ref; print(  n ); std::cout << "  " << ::math::geometry::direction::distance( n, p0 ) << ", " << ::math::geometry::direction::distance( n, p1 ) << std::endl;

  std::cout << "----  polar_type  ---------" << std::endl;

   t = po_ref; print(   t );  std::cout << std::endl;
  po = po_ref; print(  po );  std::cout << std::endl;
  pp = po_ref; print(  pp );  std::cout << "  " << ::math::geometry::direction::distance( pp, p0 ) << ", " << ::math::geometry::direction::distance(pp, p1 ) << std::endl;
   a = po_ref; print(   a );  std::cout << "  " << ::math::geometry::direction::distance( a,  p0 ) << ", " << ::math::geometry::direction::distance( a, p1 ) << std::endl;
   n = po_ref; print(   n );  std::cout << "  " << ::math::geometry::direction::distance( n,  p0 ) << ", " << ::math::geometry::direction::distance( n, p1 ) << std::endl;

   std::cout << "----  parametric_type  ----------" << std::endl;
   t  = pp_ref; print(  t );  std::cout << std::endl;
   po = pp_ref; print( po );  std::cout << std::endl;
   pp = pp_ref; print( pp );  std::cout << "  " << ::math::geometry::direction::distance( pp,  p0 ) << ", " << ::math::geometry::direction::distance(pp, p1 ) << std::endl;
   a  = pp_ref; print(  a );  std::cout << "  " << ::math::geometry::direction::distance(  a,  p0 ) << ", " << ::math::geometry::direction::distance( a, p1 ) << std::endl;
   n  = pp_ref; print(  n );  std::cout << "  " << ::math::geometry::direction::distance(  n,  p0 ) << ", " << ::math::geometry::direction::distance( n, p1 ) << std::endl;

   std::cout << "----  ABC_type  ----------" << std::endl;
   t  = a_ref; print(  t );  std::cout << std::endl;
   po = a_ref; print( po );  std::cout << std::endl;
   pp = a_ref; print( pp );  std::cout << "  " << ::math::geometry::direction::distance( pp, p0 ) << ", " << ::math::geometry::direction::distance(pp, p1 ) << std::endl;
   a  = a_ref; print(  a );  std::cout << "  " << ::math::geometry::direction::distance( a,  p0 ) << ", " << ::math::geometry::direction::distance( a, p1 ) << std::endl;
   n  = a_ref; print(  n );  std::cout << "  " << ::math::geometry::direction::distance( n,  p0 ) << ", " << ::math::geometry::direction::distance( n, p1 ) << std::endl;

   std::cout << "----  normal_type  ----------" << std::endl;
   t  = n_ref; print(  t );  std::cout << std::endl;
   po = n_ref; print( po );  std::cout << std::endl;
   pp = n_ref; print( pp );  std::cout << "  " << ::math::geometry::direction::distance( pp, p0 ) << ", " << ::math::geometry::direction::distance(pp, p1 ) << std::endl;
   a  = n_ref; print(  a );  std::cout << "  " << ::math::geometry::direction::distance( a,  p0 ) << ", " << ::math::geometry::direction::distance( a, p1 ) << std::endl;
   n  = n_ref; print(  n );  std::cout << "  " << ::math::geometry::direction::distance( n,  p0 ) << ", " << ::math::geometry::direction::distance( n, p1 ) << std::endl;
   std::cout << std::endl;

  ::math::geometry::direction::rotate( t, 123, t );
  ::math::geometry::direction::rotate( po, 123, po );
  ::math::geometry::direction::rotate( pp, 123, pp );
  ::math::geometry::direction::rotate( a, 123, a );

  ::math::geometry::direction::rotate( t, {1,2}, 12, t );

  return EXIT_SUCCESS;
 }
