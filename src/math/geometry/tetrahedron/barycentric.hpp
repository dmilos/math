#ifndef math_geometry_tetrahedron_barycentric_hpp_
 #define math_geometry_tetrahedron_barycentric_hpp_

 // ::math::geometry::tetrahedron::barycentric( result, point, triangle )



#include "./structure.hpp"
#include "./volume.hpp"
#include "../../linear/vector/subtraction.hpp"



 namespace math
  {
   namespace geometry
    {
     namespace tetrahedron
      {

       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        bool
        barycentric
         (
           ::math::linear::vector::structure< scalar_name, dimension_number + 1 >         &      result_param
          ,::math::linear::vector::structure< scalar_name, dimension_number >        const&       point_param
          ,::math::geometry::tetrahedron::structure< scalar_name, dimension_number > const& tetrahedron_param
          ,scalar_name const& epsilon = 1e-6
         )
         {
          auto volume = ::math::geometry::tetrahedron::volume( tetrahedron_param );
          auto sub = tetrahedron_param;

          if( ( -epsilon < volume ) && ( volume < epsilon ) )
           {
            return false;
           }

          for( std::size_t index=0; index < tetrahedron_param.size(); ++index )
           {
            sub[index] = point_param;
            result_param[index] = ::math::geometry::tetrahedron::volume( sub ) / volume;
            sub[index] = tetrahedron_param[index];
           }

          return false;
         }
     }
   }
 }

#endif