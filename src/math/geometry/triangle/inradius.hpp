#ifndef math_geometry_triangle_inradius_hpp_
 #define math_geometry_triangle_inradius_hpp_

// ::math::geometry::triangle::inradius( t )

#include "../../linear/vector/distance.hpp"
#include "./structure.hpp"




 namespace math
  {
   namespace geometry
    {
     namespace triangle
      {

       template<  typename scalar_name >
        scalar_name
        inradius
         (
           scalar_name const& a
          ,scalar_name const& b
          ,scalar_name const& c
          )
         {
          scalar_name f0 =  +a + b + c;
          scalar_name fA =  -a + b + c;
          scalar_name fB =  +a - b + c;
          scalar_name fC =  +a + b - c;

          return scalar_name(0.5) * sqrt( ( fA * fB * fC ) / f0 );
         }

       template<  typename scalar_name, ::math::type::size_type dimension_number >
        scalar_name
        inradius
         (
           ::math::geometry::triangle::structure<scalar_name, dimension_number > const& t
          )
         {
          scalar_name a = ::math::linear::vector::distance( t[0], t[1] );
          scalar_name b = ::math::linear::vector::distance( t[0], t[2] );
          scalar_name c = ::math::linear::vector::distance( t[1], t[2] );

          return ::math::geometry::triangle::inradius( a, b, c );
         }
      }
    }
  }

#endif
