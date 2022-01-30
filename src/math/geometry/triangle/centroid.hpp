#ifndef math_geometry_triangle_centroid_hpp_
 #define math_geometry_triangle_centroid_hpp_

// ::math::geometry::triangle::centroid




 namespace math
  {
   namespace geometry
    {
     namespace triangle
      {


       template<  typename scalar_name, unsigned dimension_number >
        void
        centroid
         (
           ::math::linear::vector::point<scalar_name, dimension_number >      & result
          ,::math::linear::vector::point<scalar_name, dimension_number > const& a0
          ,::math::linear::vector::point<scalar_name, dimension_number > const& a1
          ,::math::linear::vector::point<scalar_name, dimension_number > const& a2
          )
         {
          result = a0;
          ::math::linear::vector::addition( result, a1 );
          ::math::linear::vector::addition( result, a2 );
          ::math::linear::vector::scale( result, scalar_name(1) / scalar_name(3) );
         }

      }
    }
  }

#endif
