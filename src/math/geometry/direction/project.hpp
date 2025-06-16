#ifndef math_geometry_direction_project_HPP_
 #define math_geometry_direction_project_HPP_

// ::math::geometry::direction::project( point, direction )

#include "./parametric.hpp"
#include "./two.hpp"
#include "./abc.hpp"



 namespace math
  {
   namespace geometry
    {
     namespace direction
      {

       template< typename scalar_name >
        struct project
        {
         public:
           typedef scalar_name scalar_type;

           typedef ::math::linear::vector::point< scalar_type, 2 > point2D_type;

           typedef ::math::geometry::direction::ABC2D<scalar_name>              ABC2D_type;
           typedef ::math::geometry::direction::polar<scalar_name>               this_type;

           typedef ::math::geometry::direction::parametric<scalar_name, 2> parametric_type;
           //typedef ::math::geometry::direction::two<scalar_name, 2>               two_type;

          point2D_type process( point2D_type const& point, ABC2D_type const& direction )
           {
            auto const& A = direction.A();
            auto const& B = direction.B();
            auto        C = - direction.C();

            scalar_type cramer = A*A + B*B;

            scalar_type D =  B * point[0] - A * point[1];

            point2D_type result;
            result[0] = (   C * A  +  D * B ) / cramer;
            result[1] = ( - A * D  +  B * C ) / cramer;
            return result;
           }

          point2D_type process( ABC2D_type const& direction )  //!< This will project origin to direction
           {
            point2D_type result;
            auto const& A = direction.A();
            auto const& B = direction.B();
            auto const& C = direction.C();

            scalar_type c = - C / ( A*A + B*B );

            result[0] = - A * c;
            result[1] = + B * c;
            return result;
           }

          template< ::math::type::size_type dimension_number >
           ::math::linear::vector::point< scalar_type, dimension_number >
           process
            (
              ::math::linear::vector::point< scalar_type, dimension_number >          const& point
             ,::math::geometry::direction::parametric<scalar_name, dimension_number>  const& direction
            )
            {
             auto const& P = point;
             auto const& D = direction.direction();
             auto const& O = direction.origin();

             ::math::linear::vector::point< scalar_type, dimension_number > pivot;
             ::math::linear::vector::subtraction( pivot, P, O );

             scalar_type pivot_dot_direction = ::math::linear::vector::dot( pivot, D );
             scalar_type d_dot_d = ::math::linear::vector::dot( D, D );

             scalar_type coefficient = pivot_dot_direction / d_dot_d;

             ::math::linear::vector::point< scalar_type, dimension_number > result;

             direction.point( result, coefficient );

             return result;
            }
          template< ::math::type::size_type dimension_number >
           ::math::linear::vector::point< scalar_type, dimension_number >
           process
            (
              math::geometry::direction::parametric<scalar_name, dimension_number>  const& direction
            )
            {
             auto const& D = direction.direction();
             auto const& O = direction.origin();

             scalar_type pivot_dot_direction = - ::math::linear::vector::dot( O, D );
             scalar_type d_dot_d = ::math::linear::vector::dot( D, D );

             scalar_type coefficient = pivot_dot_direction / d_dot_d;

             ::math::linear::vector::point< scalar_type, dimension_number > result;

             direction.point( result, coefficient );

             return result;
            }

        };

      }
    }
  }

#endif
