#ifndef math_geometry_triangle_height_hpp_
 #define math_geometry_triangle_height_hpp_

// ::math::geometry::triangle::height< scalar_name >

#include "./valid.hpp"

 namespace math
  {
   namespace geometry
    {
     namespace triangle
      {

       template < typename scalar_name >
        bool height_a
         (
             scalar_name          & altitude
            ,scalar_name     const& length_a
            ,scalar_name     const& length_b
            ,scalar_name     const& length_c
            ,scalar_name     const& epsilon = 1e-6
         )
         {
          if( false == ::math::geometry::triangle::valid< scalar_name>( length_a, length_b, length_c, epsilon ) ) return false;
          auto area = ::math::geometry::triangle::area( length_a, length_b, length_c );

          altitude = scalar_name(2) * area / length_a;
          return  true ;
         }

       template < typename scalar_name >
        bool height_b
         (
             scalar_name          & altitude
            ,scalar_name     const& length_a
            ,scalar_name     const& length_b
            ,scalar_name     const& length_c
            ,scalar_name     const& epsilon = 1e-6
         )
         {
          if( false == ::math::geometry::triangle::valid< scalar_name>( length_a, length_b, length_c, epsilon ) ) return false;
          auto area = ::math::geometry::triangle::area( length_a, length_b, length_c );

          altitude = scalar_name(2) * area / length_b;
          return  true ;
         }

       template < typename scalar_name >
        bool height_c
         (
             scalar_name          & altitude
            ,scalar_name     const& length_a
            ,scalar_name     const& length_b
            ,scalar_name     const& length_c
            ,scalar_name     const& epsilon = 1e-6
         )
         {
          if( false == ::math::geometry::triangle::valid< scalar_name>( length_a, length_b, length_c, epsilon ) ) return false;
          auto area = ::math::geometry::triangle::area( length_a, length_b, length_c );

          altitude = scalar_name(2) * area / length_c;
          return  true ;
         }

      }
    }
  }

#endif
