#ifndef Dh_math_geometry_ellipse_intersectS2P
 #define Dh_math_geometry_ellipse_intersectS2P

 // ::math::geometry::ellipse::intersectS2P<scalar_name>

#include "../simple2d.hpp"
#include "../../circle/unit.hpp"
#include "../../circle/intersect/U2P.hpp"
#include "../../direction/parametric.hpp"

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
        struct S2P
         {
          public:
            typedef scalar_name scalar_type;

            typedef ::math::linear::vector::point<scalar_name,2>   point_type;
            typedef ::math::geometry::circle::unit<scalar_name,2>               circle_type;
            typedef ::math::geometry::ellipse::simple2D<scalar_name>           ellipse_type;
            typedef ::math::geometry::direction::parametric<scalar_name,2>   direction_type;

            static unsigned process
             (
                scalar_type & l1, scalar_type &l2
               ,ellipse_type   const& ellipse 
               ,direction_type const& line
             )
             {
              direction_type transformed;
              transformed.origin()[0] = ( line.origin()[0]  - ellipse.center()[0] )/ ellipse.mayor();
              transformed.origin()[1] = ( line.origin()[1]  - ellipse.center()[1] )/ ellipse.minor();

              transformed.direction ()[0] = line.direction()[0] / ellipse.mayor();
              transformed.direction ()[1] = line.direction()[1] / ellipse.minor();

              return ::math::geometry::circle::intersect( l1, l2, transformed );
             }
         };

       template
        <
          typename scalar_name
        >
        unsigned intersect
         (
           scalar_name & l1
          ,scalar_name &l2
          ,::math::geometry::ellipse::simple2D<scalar_name>       const& ellipse
          ,::math::geometry::direction::parametric<scalar_name,2> const& line
         )
         {
          return ::math::geometry::ellipse::S2P<scalar_name>::process( l1, l2, ellipse, line );
         }

      }
    }
  }

#endif
