#ifndef math_geometry_triangle_angle_hpp_
 #define math_geometry_triangle_angle_hpp_

// ::math::geometry::triangle::angle_a( angle, a, b, c );
// ::math::geometry::triangle::angle_a( angle, a, b, c );
// ::math::geometry::triangle::angle_a( angle, a, b, c );
// ::math::geometry::triangle::angle_a( angle, a, b, c );

#include "./valid.hpp"

 namespace math
  {
   namespace geometry
    {
     namespace triangle
      {

       template < typename scalar_name >
        bool angle_alpha
         (
             scalar_name          & result
            ,scalar_name     const& length_a
            ,scalar_name     const& length_b
            ,scalar_name     const& length_c
            ,scalar_name     const& epsilon = 1e-6
         )
         {
          if( false == ::math::geometry::triangle::valid< scalar_name>( length_a, length_b, length_c, epsilon ) ) return false;

          result = ( - length_a*length_a + length_b*length_b + length_c*length_c )/ ( 2 * length_b * length_c );
          if( scalar_name(1) < result  ) result = scalar_name(1);
          result = acos( result );
          return  true ;
         }

       template < typename scalar_name >
        bool angle_beta
         (
             scalar_name          & result
            ,scalar_name     const& length_a
            ,scalar_name     const& length_b
            ,scalar_name     const& length_c
            ,scalar_name     const& epsilon = 1e-6
         )
         {
          if( false == ::math::geometry::triangle::valid< scalar_name>( length_a, length_b, length_c, epsilon ) ) return false;

          result = ( + length_a*length_a - length_b*length_b + length_c*length_c )/ ( 2 * length_a * length_c );
          if( scalar_name(1) < result  ) result = scalar_name(1);
          result = acos( result );
          return  true ;
         }

       template < typename scalar_name >
        bool angle_gamma
         (
             scalar_name          & result
            ,scalar_name     const& length_a
            ,scalar_name     const& length_b
            ,scalar_name     const& length_c
            ,scalar_name     const& epsilon = 1e-6
         )
         {
          if( false == ::math::geometry::triangle::valid< scalar_name>( length_a, length_b, length_c, epsilon ) ) return false;

          result = ( + length_a*length_a + length_b*length_b - length_c*length_c )/ ( 2 * length_a * length_b );
          if( scalar_name(1) < result  ) result = scalar_name(1);
          result = acos( result );
          return  true ;
         }

      }
    }
  }

#endif
