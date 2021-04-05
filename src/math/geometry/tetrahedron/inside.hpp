#ifndef math_geometry_tetrahedron_inside_hpp_
 #define math_geometry_tetrahedron_inside_hpp_

// ::math::geometry::tetrahedron::inside< scalar_name, dimension_number >

#include "./structure.hpp"
#include "../../linear/matrix/matrix.hpp"


 namespace math
  {
   namespace geometry
    {
     namespace tetrahedron
      {

       template < typename scalar_name >
         bool inside
          (
            ::math::geometry::tetrahedron::structure< scalar_name, 3 > const& tetrahedron
           ,::math::linear::vector::point< scalar_name, 3 >            const& point
          )
          {
           typedef ::math::linear::vector::structure<  scalar_name, 3 > vector_type;
           typedef ::math::linear::matrix::structure<  scalar_name, 3, 3 > matrix_type;

           vector_type const& origin = tetrahedron[0];
           vector_type x; ::math::linear::vector::subtraction( x, tetrahedron[1], origin );
           vector_type y; ::math::linear::vector::subtraction( y, tetrahedron[2], origin );
           vector_type z; ::math::linear::vector::subtraction( z, tetrahedron[3], origin );
           vector_type p; ::math::linear::vector::subtraction( p, point,          origin );

           matrix_type m, i;
           ::math::linear::matrix::system( m, x, y, z );
           ::math::linear::matrix::invert( i, m );
           ::math::linear::matrix::transform( i, p );

          return    ( scalar_name(0) < p[0] )
                 && ( scalar_name(0) < p[1] )
                 && ( scalar_name(0) < p[2] )
                 && (  ( p[0] + p[1] + p[2] )  <  scalar_name(1) );
          }

      }
    }
  }

#endif
