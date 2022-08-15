#ifndef math_geometry_triangle_structure_hpp_
 #define math_geometry_triangle_structure_hpp_

// ::math::geometry::triangle::structure




 namespace math
  {
   namespace geometry
    {
     namespace triangle
      {

       template<  typename scalar_name, ::math::type::size_type dimension_number >
        using structure = std::array< ::math::linear::vector::point<scalar_name, dimension_number>, 3 >;


      }
    }
  }

#endif
