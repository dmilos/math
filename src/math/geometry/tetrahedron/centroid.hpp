#ifndef math_geometry_tetrahedron_centroid_hpp_
 #define math_geometry_tetrahedron_centroid_hpp_

// ::math::geometry::tetrahedron::centroid< scalar_name, dimension_number >

#include "./structure.hpp"


 namespace math
  {
   namespace geometry
    {
     namespace tetrahedron
      {

       template < typename scalar_name, unsigned dimension_number >
         bool centroid
          (
            ::math::linear::vector::point< scalar_name, dimension_number >                 & result
           ,::math::geometry::tetrahedron::structure< scalar_name, dimension_number > const& tetrahedron
          )
          {
           typedef ::math::linear::vector::point< scalar_name, dimension_number > point_type;

           ::math::linear::vector::fill<scalar_name>( result, 0 );
           for( auto const& vertex : tetrahedron )
            {
             ::math::linear::vector::addition( result, vertex );
            }
           ::math::linear::vector::scale( result, scalar_name(1)/scalar_name(dimension_number) );
           return true;
          }

      }
    }
  }

#endif
