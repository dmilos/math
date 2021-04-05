#ifndef math_geometry_tetrahedron_volume_hpp_
 #define math_geometry_tetrahedron_volume_hpp_

// ::math::geometry::tetrahedron::volume( A, B, C, D )

#include "./structure.hpp"
#include "../../linear/vector/subtraction.hpp"
#include "../../linear/vector/cross.hpp"
#include "../../linear/vector/dot.hpp"



 namespace math
  {
   namespace geometry
    {
     namespace tetrahedron
      {

       template<  typename scalar_name >
        scalar_name
        volume
         (
           ::math::linear::vector::point<scalar_name, 3 > const& A
          ,::math::linear::vector::point<scalar_name, 3 > const& B
          ,::math::linear::vector::point<scalar_name, 3 > const& C
          ,::math::linear::vector::point<scalar_name, 3 > const& D
          )
         {
          typedef ::math::linear::vector::point<scalar_name, 3 > point_type;

          point_type AB; ::math::linear::vector::subtraction( AB, B, A );
          point_type AC; ::math::linear::vector::subtraction( AC, C, A );
          point_type AD; ::math::linear::vector::subtraction( AD, D, A );

          point_type n; ::math::linear::vector::cross( n, AB, AC );

          return ::math::linear::vector::dot( AD, n ) / scalar_name(6);
         }

       template<  typename scalar_name >
        scalar_name
        volume
         (
           ::math::geometry::tetrahedron::structure<scalar_name, 3 > const& t
          )
         {
          return ::math::geometry::tetrahedron::volume( t[0], t[1], t[2], t[3] );
         }

      }
    }
  }

#endif
