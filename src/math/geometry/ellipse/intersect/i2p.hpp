#ifndef Dh_math_geometry_ellipse_intersect_I2P
 #define Dh_math_geometry_ellipse_intersect_I2P

 // ::math::geometry::ellipse::I2P<scalar_name>
 // ::math::geometry::ellipse::intersect<scalar_name>( l1, l2, ellipse, line );

#include "../implicit2d.hpp"
#include "../../direction/parametric.hpp"
#include "../../../polynomial/quadric/solve.hpp"



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
        struct I2P
         {
          public:
            typedef scalar_name scalar_type;

            typedef ::math::linear::vector::point<scalar_name,2>   point_type;
            typedef ::math::geometry::circle::unit<scalar_name,2>               circle_type;
            typedef ::math::geometry::ellipse::implicit2D<scalar_name>          ellipse_type;
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
              std::array< scalar_type, 3 > coefficient;


              auto const& a = ellipse.A() ;
              auto const& b = ellipse.B() ;
              auto const& c = ellipse.C() ;
              auto const& d = ellipse.D() ;
              auto const& e = ellipse.E() ;
              auto const& f = ellipse.F() ;

              auto const& Dx = line.direction()[0];
              auto const& Dy = line.direction()[1];

              auto const& Ox = line.origin()[0];
              auto const& Oy = line.origin()[1];

              coefficient[0] = a * Ox*Ox + b *Ox*Oy + c * Oy*Oy + d * Ox + e * Oy + f;
              coefficient[1] = a * 2 * Dx*Ox + b * ( Dx*Oy + Ox*Dy ) + c*2 * Dy*Oy + d * Dx + e * Dy;
              coefficient[2] = a * Dx*Dx  +  b * 2 * Dx * Dy  +  c * Dy*Dy;

              return ::math::polynomial::quadric::solve::general( l1, l2, coefficient );
             }

         };

       template
        <
          typename scalar_name
        >
        unsigned intersect
         (
           scalar_name & l1
          ,scalar_name & l2
          ,::math::geometry::ellipse::implicit2D<scalar_name>      const& ellipse
          ,::math::geometry::direction::parametric<scalar_name,2> const& line
         )
         {
          return ::math::geometry::ellipse::I2P<scalar_name>::process( l1, l2, ellipse, line );
         }


      }
    }
  }

#endif
