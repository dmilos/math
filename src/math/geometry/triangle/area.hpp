#ifndef math_geometry_triangle_area_hpp_
 #define math_geometry_triangle_area_hpp_

// ::math::geometry::triangle::area( a0, a1, a2 )
// ::math::geometry::triangle::area( t )

#include "../../linear/vector/structure.hpp"
#include "../../linear/vector/subtraction.hpp"
#include "../../linear/vector/cross.hpp"
#include "../../linear/vector/length.hpp"
#include "./structure.hpp"



 namespace math
  {
   namespace geometry
    {
     namespace triangle
      {

       template<  typename scalar_name >
        scalar_name
        area
         (
           scalar_name const& a
          ,scalar_name const& b
          ,scalar_name const& c
          )
         {
          scalar_name s = ( a + b + c )/ scalar_name(2);
          return sqrt( s*(s-a)*(s-b)*(s-c) );
         }

       template<  typename scalar_name >
        scalar_name
        area
         (
           ::math::linear::vector::point<scalar_name, 2 > const& a0
          ,::math::linear::vector::point<scalar_name, 2 > const& a1
          ,::math::linear::vector::point<scalar_name, 2 > const& a2
          )
         {
          scalar_name const& Ax = a0[0];
          scalar_name const& Ay = a0[1];
          scalar_name const& Bx = a1[0];
          scalar_name const& By = a1[1];
          scalar_name const& Cx = a2[0];
          scalar_name const& Cy = a2[1];

          return fabs( Ax * ( By - Cy ) + Bx * ( Cy - Ay ) + Cx * ( Ay - By ) ) / scalar_name(2);
         }

       template<  typename scalar_name >
        scalar_name
        area
         (
           ::math::geometry::triangle::structure<scalar_name, 3 > const& t
          )
         {
          ::math::linear::vector::point<scalar_name, 3 > A;
          ::math::linear::vector::point<scalar_name, 3 > B;
          ::math::linear::vector::point<scalar_name, 3 > N;

          ::math::linear::vector::subtraction( A, t[1], t[0] );
          ::math::linear::vector::subtraction( B, t[2], t[0] );
          ::math::linear::vector::cross( N, A, B );
          return ::math::linear::vector::length( N )/ scalar_name(2);
         }

       template<  typename scalar_name, ::math::type::size_type dimension_number >
        scalar_name
        area
         (
           ::math::geometry::triangle::structure<scalar_name, dimension_number > const& t
          )
         {
          return ::math::geometry::triangle::area
           (
             ::math::linear::vector::distance(  t[0], t[1] )
            ,::math::linear::vector::distance(  t[0], t[2] )
            ,::math::linear::vector::distance(  t[1], t[2] )
           );
         }

      }
    }
  }

#endif
