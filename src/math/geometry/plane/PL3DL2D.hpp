#ifndef math_geometry_intersect_PL3DL2D
#define math_geometry_intersect_PL3DL2D

// ::math::geometry::plane::intersect( lambda, axis, distance, parametric, epsilon )
// ::math::geometry::plane::intersect( lambda, plane, parametric, epsilon )
// ::math::geometry::plane::intersect( point, plane, parametric, epsilon )
// ::math::geometry::plane::intersect( point, lambda, plane, parametric, epsilon )
// ::math::geometry::plane::intersect( point, plane, two, epsilon )
// ::math::geometry::plane::intersect( lambda, uv, plane, parametric );

// ::math::geometry::plane::PL3DL2D<scalar_name>::process

#include "../../linear/vector/structure.hpp"
#include "../direction/parametric.hpp"

#include "./no3d.hpp"
#include "./parametric3d.hpp"
#include "../../linear/matrix/column.hpp"
#include "../../linear/matrix/invert.hpp"



namespace math
 {
  namespace geometry
   {
    namespace plane
     {

      template<  typename scalar_name, typename size_name = std::size_t >
       struct PL3DL2D  // Intersect plane and line in 3D
        {
         public:
           typedef scalar_name scalar_type;
           typedef size_name size_type;

           typedef ::math::linear::vector::point<scalar_type,2>                uv_type;
           typedef ::math::linear::vector::point<scalar_type,3>             point_type, vector_type;

           typedef ::math::geometry::plane::no3d <scalar_type>              no3d_type;
           typedef ::math::geometry::plane::parametric3d<scalar_name>   parametric3d_type;

           typedef ::math::geometry::direction::parametric<scalar_name, 3 > line_type;

           static bool process // Intersect line with plane with normal( 0, ... 1[axis], ..., 0) and origin( 0, ... distance[axis] ..., 0 )
            (
              scalar_type        & lambda
             ,size_type    const & axis
             ,scalar_type  const & distance
             ,line_type    const & line
             ,scalar_type  const & epsilon = 1e-7
            )
            {
             scalar_type const& dot_down = line.direction()[ axis ];

             if( fabs( dot_down ) < epsilon )
              {
               return false;
              }

             scalar_type dot_up = distance - line.origin()[ axis ];

             lambda = dot_up / dot_down;
             return true;
            }

           static bool process
            (
              scalar_type        & lambda
             ,vector_type  const & plane_normal,   point_type    const & plane_origin
             ,vector_type  const & line_direction, point_type    const & line_origin
             ,scalar_type  const & epsilon = 1e-6
            )
            {
             scalar_type dot_down = ::math::linear::vector::dot( line_direction, plane_normal );

             if( fabs( dot_down ) < epsilon )
              {
               return false;
              }

             point_type heading;

             ::math::linear::vector::subtraction( heading, plane_origin,line_origin );
             scalar_type dot_up = ::math::linear::vector::dot( heading, plane_normal );

             //point = line_origin + ( dot_up / dot_down ) * line_direction;
             lambda = dot_up / dot_down;
             return true;
            }

           static bool process
            (
              scalar_type        & lambda
             ,no3d_type    const & plane
             ,line_type    const & line
             ,scalar_type  const & epsilon = 1e-6
            )
            {
             scalar_type dot_down = ::math::linear::vector::dot( line.direction(), plane.normal() );

             if( fabs( dot_down ) < epsilon )
              {
               return false;
              }

             point_type heading;

             ::math::linear::vector::subtraction( heading, plane.origin(),line.origin() );
             scalar_type dot_up = ::math::linear::vector::dot( heading, plane.normal() );

             //point = line.origin() + ( dot_up / dot_down ) * line.direction();
             lambda = dot_up / dot_down;
             return true;
            }

           static bool process
            (
              point_type         & point
             ,scalar_type        & lambda
             ,no3d_type    const & plane
             ,line_type    const & line
             ,scalar_type  const & epsilon = 1e-6
            )
            {
             if( false == process( lambda, plane, line, epsilon ) )
              {
               return false;
              }

             line.point( point, lambda );
             return true;
            }

           static bool process
            (
              scalar_type              & lambda
             ,uv_type                  & uv
             ,parametric3d_type  const & plane
             ,line_type          const & line
             ,scalar_type        const & epsilon = 1e-6
            )
            {
             ::math::linear::matrix::structure< scalar_type, 3, 3 > M, I;

             ::math::linear::matrix::column( M, 0, plane.x()        );
             ::math::linear::matrix::column( M, 1, plane.y()        );
             ::math::linear::matrix::column( M, 2, line.direction() ); 

             if( false == ::math::linear::matrix::invert( I, M ) )
              {
               return false;
              }

             point_type heading;
             ::math::linear::vector::subtraction( heading, line.origin(), plane.origin() );
             point_type result;

            ::math::linear::matrix::transform( result, I, heading );

             uv[0]  = result[0];
             uv[1]  = result[1];
             lambda = - result[2];
             return true;
            }

        };

      template<  typename scalar_name, typename size_name = std::size_t >
       bool intersect
        (
          scalar_name        & lambda
         ,size_name    const & axis
         ,scalar_name  const & distance
         ,::math::geometry::direction::parametric<scalar_name, 3 >    const & parametric
         ,scalar_name  const & epsilon = 1e-7
        )
        {
         return ::math::geometry::plane::PL3DL2D<scalar_name,size_name>::process( lambda, axis, distance, parametric, epsilon );
        }

      template<  typename scalar_name, typename size_name = std::size_t >
       bool intersect
        (
          scalar_name                                                      & lambda
         ,::math::geometry::plane::no3d <scalar_name>                const & plane
         ,::math::geometry::direction::parametric<scalar_name, 3 >   const & parametric
         ,scalar_name                                                const & epsilon = 1e-6
        )
        {
         return ::math::geometry::plane::PL3DL2D<scalar_name,size_name>::process( lambda, plane, parametric, epsilon );
        }

      template<  typename scalar_name, typename size_name = std::size_t >
       bool intersect
        (
          ::math::linear::vector::point<scalar_name,3>                     & point
         ,::math::geometry::plane::no3d <scalar_name>                const & plane
         ,::math::geometry::direction::parametric<scalar_name, 3 >   const & parametric
         ,scalar_name                                                const & epsilon = 1e-6
        )
        {
         scalar_name  lambda;
         return ::math::geometry::plane::PL3DL2D<scalar_name,size_name>::process( point, lambda, plane, parametric, epsilon );
        }

      template<  typename scalar_name, typename size_name = std::size_t >
       bool intersect
        (
          ::math::linear::vector::point<scalar_name,3>                     & point
         ,scalar_name                                                      & lambda
         ,::math::geometry::plane::no3d <scalar_name>                const & plane
         ,::math::geometry::direction::parametric<scalar_name, 3 >   const & parametric
         ,scalar_name                                                const & epsilon = 1e-6
        )
        {
         return ::math::geometry::plane::PL3DL2D<scalar_name,size_name>::process( point, lambda, plane, parametric, epsilon );
        }

       template<  typename scalar_name, typename size_name = std::size_t >
       bool intersect
       (
         ::math::linear::vector::point<scalar_name,3>                      & point
         ,::math::geometry::plane::no3d <scalar_name>                const & plane
         ,::math::geometry::direction::two<scalar_name, 3 >          const & two
         ,scalar_name                                                const & epsilon = 1e-6
       )
       {
         scalar_name  lambda;
         ::math::geometry::direction::parametric<scalar_name, 3 > parametric( two );
         return ::math::geometry::plane::PL3DL2D<scalar_name,size_name>::process( point, lambda, plane, parametric, epsilon );
       }


      template<  typename scalar_name, typename size_name = std::size_t >
       bool intersect
       (
          scalar_name                                                      & lambda
         ,::math::linear::vector::point<scalar_name,2>                     & uv
         ,::math::geometry::plane::parametric3d<scalar_name>         const & plane
         ,::math::geometry::direction::parametric<scalar_name, 3 >   const & parametric
         ,scalar_name                                                const & epsilon = 1e-6
       )
       {
         return ::math::geometry::plane::PL3DL2D<scalar_name,size_name>::process( lambda, uv, plane, parametric, epsilon );
       }

     }
   }
 }

#endif
