#ifndef Dh_math_geometry_ellipse_intersectG2P
 #define Dh_math_geometry_ellipse_intersectG2P

 // ::math::geometry::ellipse::intersectG2P<scalar_name>

#include "../general2d.hpp"
#include "../../circle/unit.hpp"
#include "../../circle/intersect/U2P.hpp"
#include "../../direction/parametric.hpp"
#include "../../../linear/vector/rotate.hpp"
#include "../../../linear/vector/subtraction.hpp"



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
        struct G2P
         {
          public:
            typedef scalar_name scalar_type;

            typedef ::math::linear::vector::point<scalar_name,2>   point_type;
            typedef ::math::geometry::circle::unit<scalar_name,2>               circle_type;
            typedef ::math::geometry::ellipse::general2D<scalar_name>          ellipse_type;
            typedef ::math::geometry::direction::parametric<scalar_name,2>   direction_type;

            static unsigned process
             (
               scalar_type & l1
              ,scalar_type & l2
              ,ellipse_type   const& ellipse 
              ,direction_type const& line
             )
             {
              direction_type transformed;

              point_type origin;
              ::math::linear::vector::subtraction( origin, line.origin(), ellipse.center() );
              ::math::linear::vector::rotate( transformed.origin(), -ellipse.rotation() , origin );
              transformed.origin()[0] /= ellipse.size()[0];
              transformed.origin()[1] /= ellipse.size()[1];

              ::math::linear::vector::rotate( transformed.direction(), -ellipse.rotation(), line.direction() );
              transformed.direction()[0] /= ellipse.size()[0];
              transformed.direction()[1] /= ellipse.size()[1];

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
          ,::math::geometry::ellipse::general2D<scalar_name>      const& ellipse
          ,::math::geometry::direction::parametric<scalar_name,2> const& line
         )
         {
          return ::math::geometry::ellipse::G2P<scalar_name>::process( l1, l2, ellipse, line );
         }


      }
    }
  }

#endif
