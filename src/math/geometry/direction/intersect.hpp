#ifndef math_geometry_direction_intersect
#define math_geometry_direction_intersect

// ::math::geometry::direction::intersect( point, two, two, epsilon )
// ::math::geometry::direction::intersect( point, abc, abc, epsilon )
// ::math::geometry::direction::intersect( point, para, para, epsilon )

#include "../../linear/vector/structure.hpp"
#include "./two.hpp"
#include "./abc.hpp"



namespace math
 {
  namespace geometry
   {
    namespace direction
     {

      template< typename scalar_name >
       struct intersectX
        {
         public:
           typedef scalar_name scalar_type;

           typedef ::math::linear::vector::point<  scalar_type, 2 > point_type;
           typedef ::math::geometry::direction::two< scalar_type, 2 > two_type;
           typedef ::math::geometry::direction::ABC2D < scalar_type > ABC_type;
           typedef ::math::geometry::direction::parametric < scalar_type, 2 > parametric_type;

           static bool process
            (
              point_type             & point
             ,two_type         const & left
             ,two_type         const & right
             ,scalar_type      const & epsilon = 1e-6
            )
            {
             scalar_type const& x1 = left.first() [0];
             scalar_type const& y1 = left.first() [1];
             scalar_type const& x2 = left.second()[0];
             scalar_type const& y2 = left.second()[1];

             scalar_type const& x3 = right.first() [0];
             scalar_type const& y3 = right.first() [1];
             scalar_type const& x4 = right.second()[0];
             scalar_type const& y4 = right.second()[1];

             scalar_type denominator = ( x1 - x2 ) * ( y3 - y4 ) - ( y1 - y2 )*( x3 - x4 );

             if( ( - epsilon < denominator ) && ( denominator < epsilon ) )
              {
               return false;
              }

             point[0] = ( x1 * y2 - y1*x2  )*( x3 - x4 )  -  ( x1-x2 ) * ( x3 * y4  -  y3 * x4 );
             point[1] = ( x1 * y2 - y1*x2  )*( y3 - y4 )  -  ( y1-y2 ) * ( x3 * y4  -  y3 * x4 );

             point[0] /= denominator;
             point[1] /= denominator;

             return true;
            }

           static bool process
            (
              point_type        & point
             ,ABC_type    const & left
             ,ABC_type    const & right
             ,scalar_type const & epsilon = 1e-6
            )
            {
             scalar_type const& a1 = left.A();
             scalar_type const& b1 = left.B();
             scalar_type const& c1 = left.C();

             scalar_type const& a2 = right.A();
             scalar_type const& b2 = right.B();
             scalar_type const& c2 = right.C();

             scalar_type D = a1*b2 - b1*a2;

             if( ( - epsilon < D ) && ( D < epsilon ) )
              {
               return false;
              }

             point[0] =  ( b1 * c2 - c1 * b2 ) / D;
             point[1] =  ( c1 * a2 - a1 * c2 ) / D;

             // scalar_type T0 = a1 * point[0] + b1 * point[1] + c1;
             // scalar_type T1 = a2 * point[0] + b2 * point[1] + c2;

             return true;
            }

           static bool process
            (
              point_type             & point
             ,parametric_type      const & left
             ,parametric_type      const & right
             ,scalar_type      const & epsilon = 1e-6
            )
            {
             scalar_type const& x1 = left.origin()[0];
             scalar_type const& y1 = left.origin()[1];
             scalar_type const& x2 = left.origin()[0] + left.direction()[0];
             scalar_type const& y2 = left.origin()[1] + left.direction()[1];

             scalar_type const& x3 = right.origin()[0];
             scalar_type const& y3 = right.origin()[1];
             scalar_type const& x4 = right.origin()[0] + right.direction()[0];
             scalar_type const& y4 = right.origin()[1] + right.direction()[1];

             scalar_type const& x1_minus_x2 = x1 - x2;
             scalar_type const& y1_minus_y2 = y1 - y2;
             scalar_type const& x3_minus_x4 = x3 - x4;
             scalar_type const& y3_minus_y4 = y3 - y4;

             scalar_type denominator = x1_minus_x2 * y3_minus_y4 - y1_minus_y2 * x3_minus_x4;

             if( ( - epsilon < denominator ) && ( denominator < epsilon ) )
              {
               return false;
              }

             point[0] = ( x1 * y2 - y1*x2  )*x3_minus_x4  -  x1_minus_x2 * ( x3 * y4  -  y3 * x4 );
             point[1] = ( x1 * y2 - y1*x2  )*y3_minus_y4  -  y1_minus_y2 * ( x3 * y4  -  y3 * x4 );

             point[0] /= denominator;
             point[1] /= denominator;

             return true;
            }

        };


      template<  typename scalar_name >
       bool intersect
        (
          ::math::linear::vector::point<  scalar_name, 2 >                 & point
         ,::math::geometry::direction::two< scalar_name, 2 >         const & left
         ,::math::geometry::direction::two< scalar_name, 2 >         const & right
         ,scalar_name      const & epsilon = 1e-6
        )
        {
         return ::math::geometry::direction::intersectX<scalar_name>::process( point, left, right, epsilon );
        }


      template<  typename scalar_name >
       bool intersect
        (
          ::math::linear::vector::point<  scalar_name, 2 >            & point
         ,::math::geometry::direction::ABC2D < scalar_name >    const & left
         ,::math::geometry::direction::ABC2D < scalar_name >    const & right
         ,scalar_name const & epsilon = 1e-6
        )
        {
         return ::math::geometry::direction::intersectX<scalar_name>::process( point, left, right, epsilon );
        }

      template<  typename scalar_name >
       bool intersect
        (
          ::math::linear::vector::point<  scalar_name, 2 >                    & point
         ,::math::geometry::direction::parametric < scalar_name, 2 >    const & left
         ,::math::geometry::direction::parametric < scalar_name, 2 >    const & right
         ,scalar_name const & epsilon = 1e-6
        )
        {
         return ::math::geometry::direction::intersectX<scalar_name>::process( point, left, right, epsilon );
        }

     }
   }
 }

#endif
