#ifndef math_geometry_triangle_valid_hpp_
 #define math_geometry_triangle_valid_hpp_

// ::math::geometry::triangle::valid< scalar_name>( length_a, length_b, length_c )



 namespace math
  {
   namespace geometry
    {
     namespace triangle
      {

       template < typename scalar_name >
        bool valid
         (
           scalar_name  const& length_a
          ,scalar_name  const& length_b
          ,scalar_name  const& length_c
          ,scalar_name     const& epsilon = 1e-6
         )
         {
          if( length_a < epsilon ) return false;
          if( length_b < epsilon ) return false;
          if( length_c < epsilon ) return false;
          if( ( length_a + length_b ) < length_c )  return false;
          if( ( length_a + length_c ) < length_b )  return false;
          if( ( length_b + length_c ) < length_a )  return false;

          return true;
         }

      }
    }
  }

#endif
