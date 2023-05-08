#ifndef Dh_math_geometry_ellipse_distance
 #define Dh_math_geometry_ellipse_distance

 // ::math::geometry::ellipse::distance<scalar_name>

#include "../circle/unit.hpp"
#include "../circle/distance.hpp"

#include "./base2d.hpp"
#include "./simple2d.hpp"
#include "./general2d.hpp"

#include "../../linear/vector/divide.hpp"
#include "../../linear/vector/subtraction.hpp"
#include "../../linear/vector/rotate.hpp"

 namespace math
  {
   namespace geometry
    {
     namespace ellipse
      {

       template
        <
          typename scalar_name
        >
        scalar_name distance
         (
           ::math::geometry::ellipse::base2D<scalar_name>   const& ellipse
          ,::math::linear::vector::point<scalar_name,2>     const& point
         )
         {
          ::math::linear::vector::point<scalar_name,2>           point_local;
          ::math::linear::vector::divide( point_local, ellipse.size(), point );
          ::math::geometry::circle::unit<scalar_name,2> unit_local;
          return ::math::geometry::circle::distance<scalar_name>( unit_local, point_local );
         }

       template
        <
          typename scalar_name
        >
        scalar_name distance
         (
           ::math::geometry::ellipse::simple2D<scalar_name>   const& ellipse
          ,::math::linear::vector::point<scalar_name,2>       const& point
         )
         {
          ::math::linear::vector::point<scalar_name,2>           p;
          ::math::linear::vector::subtraction( p, ellipse.center(), point );
          ::math::linear::vector::divide( p, ellipse.size() );
          ::math::geometry::circle::unit<scalar_name,2> unit;
          return ::math::geometry::circle::distance<scalar_name>( unit, p );
         }

       template
        <
          typename scalar_name
        >
        scalar_name distance
         (
           ::math::geometry::ellipse::general2D<scalar_name>  const& ellipse
          ,::math::linear::vector::point<scalar_name,2>       const& point
         )
         {
          ::math::linear::vector::point<scalar_name,2>           p;
          ::math::linear::vector::subtraction( p, point, ellipse.center() );
          ::math::linear::vector::rotate( p, -ellipse.rotation() );
          ::math::linear::vector::divide( p, ellipse.size() );
          ::math::geometry::circle::unit<scalar_name,2> unit;
          return ::math::geometry::circle::distance<scalar_name>( unit, p );
         }

      }
    }
  }

#endif
