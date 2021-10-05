#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  ::math::linear::vector::point<double,2>            point2;
  ::math::linear::vector::point<double,3>            point3{1,1,2}; point3 = point3;

  ::math::geometry::direction::two<double,2>            two;
  ::math::geometry::direction::polar<double>            po;
  ::math::geometry::direction::parametric<double, 2>    pp;
  ::math::geometry::direction::parametric<double, 3>    pp3;
  ::math::geometry::direction::parametric<double, 4>    pp4;
  ::math::geometry::direction::parametric<double,10>    pp10;
  ::math::geometry::direction::ABC2D<double>            abc;

  two = two; two = po; two = pp; two = abc;
  po =  two; po = po; po = pp; po = abc;
  pp =  two; pp = po; pp = pp; pp = abc;
  abc =   two; abc = po; abc = pp; abc = abc;

  ::math::geometry::direction::rotate( two, 123, two );
  ::math::geometry::direction::rotate( po, 123, po );
  ::math::geometry::direction::rotate( pp, point2, 123, pp );
  ::math::geometry::direction::rotate( abc, 123, abc );

  ::math::geometry::direction::rotate( two, {1,2}, 12, two );

  ::math::geometry::direction::redirect( two  );
  ::math::geometry::direction::redirect( po );
  ::math::geometry::direction::redirect( pp );
  ::math::geometry::direction::redirect( abc  );

  ::math::geometry::direction::intersect( point2, two, two );
  ::math::geometry::direction::intersect( point2, abc, abc );

  ::math::geometry::direction::P2L< double, 2>::process( pp, point2  );
  ::math::geometry::direction::P2ABC2D<double>::process( abc, point2 );
  ::math::geometry::direction::L2L< double, 2> distance2; distance2.process( pp, pp );

   ::math::geometry::direction::L2L< double,3> distance3; distance3.process( pp3, pp3 );
  ::math::geometry::direction::L2L< double, 4> distance4; distance4.process( pp4, pp4 );
  ::math::geometry::direction::L2L< double,10> distance10; distance10.process( pp10, pp10 );

  ::math::geometry::direction::distance( pp3, pp3 );
  ::math::geometry::direction::distance( pp, point2  );
  ::math::geometry::direction::distance( abc, point2  );

  ::math::geometry::direction::angle( two, two );
  ::math::geometry::direction::angle( pp, pp  );
  ::math::geometry::direction::angle( abc, abc  );

  ::math::geometry::direction::horizon<double> h;
  h.process( point2, point2, point2, point2 );
  h.process( abc, abc, abc, abc );

  ::math::geometry::direction::fit2D<double>::process( abc, std::vector< ::math::linear::vector::point<double,2> >() );

  std::vector< ::math::linear::vector::point<double,2> > cloud2D;
  std::vector< ::math::linear::vector::point<double,3> > cloud3D;

  ::math::geometry::plane::fit( pp3, cloud2D, cloud3D );

  return EXIT_SUCCESS;
 }
