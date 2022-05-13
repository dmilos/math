#ifndef math_geometry_triangle_circumcenter_hpp_
 #define math_geometry_triangle_circumcenter_hpp_

// ::math::geometry::triangle::circumcenter( center, triangles )
// ::math::geometry::triangle::circumcenter( center, a, b, c )

#include "../../linear/vector/distance.hpp"
#include "./structure.hpp"




 namespace math
  {
   namespace geometry
    {
     namespace triangle
      {

       template<  typename scalar_name >
        bool
        circumcenter
         (
           ::math::linear::vector::structure< scalar_name, 2 >       & center_param
          ,::math::linear::vector::structure< scalar_name, 2 > const& a
          ,::math::linear::vector::structure< scalar_name, 2 > const& b
          ,::math::linear::vector::structure< scalar_name, 2 > const& c
          ,scalar_name const& epsilon = 1e-6
          )
         {
          auto A2 = ::math::linear::vector::dot( a, a );
          auto B2 = ::math::linear::vector::dot( b, b );
          auto C2 = ::math::linear::vector::dot( c, c );

          scalar_name D = 2* ( a[0]*( b[1] - c[1] ) + b[0]* ( c[1] - a[1] ) + c[0]*( a[1] - b[1] ) );
          if( ( -epsilon < D ) && ( D < epsilon ) )
           {
            return false;
           }

          center_param[0] = ( a[0]*a[0]  + a[1]*a[1] ) * ( b[1] - c[1] )
                          + ( b[0]*b[0]  + b[1]*b[1] ) * ( c[1] - a[1] )
                          + ( c[0]*c[0]  + c[1]*c[1] ) * ( a[1] - b[1] );
          center_param[1] = ( a[0]*a[0]  + a[1]*a[1] ) * ( c[0] - b[0] )
                          + ( b[0]*b[0]  + b[1]*b[1] ) * ( a[0] - c[0] )
                          + ( c[0]*c[0]  + c[1]*c[1] ) * ( b[0] - a[0] );

          center_param[0] /= D;
          center_param[1] /= D;
          return true;
         }

       template<  typename scalar_name >
        bool
        circumcenter
         (
           ::math::linear::vector::structure< scalar_name, 2 >       & center_param
          ,::math::geometry::triangle::structure<scalar_name,2> const& triangle_param
          ,scalar_name const& epsilon = 1e-6
          )
         {
          auto const& a = triangle_param[0];
          auto const& b = triangle_param[1];
          auto const& c = triangle_param[2];
          return ::math::geometry::triangle::circumcenter( center_param, a, b, c, epsilon );
         }

      }
    }
  }

#endif
