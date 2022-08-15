#ifndef math_geometry_tetrahedron_structure_hpp_
 #define math_geometry_tetrahedron_structure_hpp_

// ::math::geometry::tetrahedron::structure< scalar_name, dimension_number >

#include "../../linear/vector/structure.hpp"


 namespace math
  {
   namespace geometry
    {
     namespace tetrahedron
      {

       template< typename scalar_name, ::math::type::size_type dimension_number >
        using structure = std::array< ::math::linear::vector::point<scalar_name, dimension_number>, dimension_number + 1 >;


      }
    }
  }

#endif
