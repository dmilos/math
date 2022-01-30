#ifndef math_geometry_triangle_inside_hpp_
 #define math_geometry_triangle_inside_hpp_

// ::math::geometry::triangle::inside< scalar_name, dimension_number >

#include "./structure.hpp"
#include "../../linear/matrix/matrix.hpp"


 namespace math
  {
   namespace geometry
    {
     namespace triangle
      {

       template < typename scalar_name >
         bool inside
          (
            ::math::geometry::triangle::structure< scalar_name, 2 > const& triangle
           ,::math::linear::vector::point< scalar_name, 2 >            const& point
          )
          {
           typedef ::math::linear::vector::structure<  scalar_name, 2 > vector_type;
           typedef ::math::linear::matrix::structure<  scalar_name, 2, 2 > matrix_type;

           vector_type const& origin = triangle[0];
           vector_type x; ::math::linear::vector::subtraction( x, triangle[1], origin );
           vector_type y; ::math::linear::vector::subtraction( y, triangle[2], origin );

           vector_type p; ::math::linear::vector::subtraction( p, point,       origin );

           matrix_type m, i;
           ::math::linear::matrix::system( m, x, y );
           ::math::linear::matrix::invert( i, m );
           ::math::linear::matrix::transform( i, p );

          return    ( scalar_name(0) < p[0] )
                 && ( scalar_name(0) < p[1] )
                 && ( ( p[0] + p[1] ) <  scalar_name(1) );
          }

      }
    }
  }

#endif
