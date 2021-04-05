#ifndef math_geometry_triangle_centroid_hpp_
 #define math_geometry_triangle_centroid_hpp_

// ::math::geometry::triangle::centroid




 namespace math
  {
   namespace geometry
    {
     namespace triangle
      {


       template<  typename scalar_name >
        void
        centroid
         (
           ::math::linear::vector::point<scalar_name, 2 >      & result
          ,::math::linear::vector::point<scalar_name, 2 > const& a0
          ,::math::linear::vector::point<scalar_name, 2 > const& a1
          ,::math::linear::vector::point<scalar_name, 2 > const& a2
          )
         {
          result[0] = ( a0[0] + a1[0] + a2[0] ) / scalar_name(3);
          result[1] = ( a0[1] + a1[1] + a2[1] ) / scalar_name(3);
         }

      }
    }
  }

#endif
