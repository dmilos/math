#ifndef math_geometry_triangle_barycentric_hpp_
 #define math_geometry_triangle_barycentric_hpp_

 // ::math::geometry::triangle::barycentric( result, point, triangle )



#include "./structure.hpp"
#include "./area.hpp"






 namespace math
  {
   namespace geometry
    {
     namespace triangle
      {

       template< typename scalar_name >
        inline
        bool
        barycentric
         (
           ::math::linear::vector::structure< scalar_name, 3 >          &   result_param
          ,::math::linear::vector::structure< scalar_name, 2 >     const&    point_param
          ,::math::geometry::triangle::structure< scalar_name, 2 > const& triangle_param
          ,scalar_name const& epsilon = 1e-6
         )
         {
          auto const& a = triangle_param[0];
          auto const& b = triangle_param[1];
          auto const& c = triangle_param[2];
          auto const& p = point_param;

          scalar_name whole = ::math::geometry::triangle::area( triangle_param );
          if( ( -epsilon < whole ) && ( whole < epsilon ) )
           {
            return false;
           }

          result_param[0] = ::math::geometry::triangle::area( p, b, c ) / whole;
          result_param[1] = ::math::geometry::triangle::area( a, p, c ) / whole;
          result_param[2] = ::math::geometry::triangle::area( a, b, p ) / whole;

          return true;
         }

     }
   }
 }

#endif