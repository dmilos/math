#ifndef math_geometry_distance_P2L
#define math_geometry_distance_P2L


// ::math::geometry::distance::P2L< scalar, dimension>::process( point, parametric )

#include "../../../linear/vector/structure.hpp"
#include "../../../linear/vector/subtraction.hpp"

#include "../parametric.hpp"



namespace math
 {
  namespace geometry
   {
    namespace direction
     {

      template<  typename scalar_name, unsigned dimension_number >
       struct P2L
        {
         public:
          typedef scalar_name scalar_type;
          typedef ::math::linear::vector::point< scalar_type, dimension_number > point_type;
          typedef ::math::geometry::direction::parametric< scalar_type, dimension_number > parametric_type;

          static scalar_type process( parametric_type const& line, point_type const& point )
           {
            point_type heading; ::math::linear::vector::subtraction( heading, point, line.origin() );

            scalar_type l = ::math::linear::vector::dot<scalar_type>( line.direction(), line.direction() );
            scalar_type t = ::math::linear::vector::dot<scalar_type>( heading, line.direction() );
            scalar_type s = ::math::linear::vector::dot<scalar_type>( heading, heading );

            auto p = s - t*t/l;

            return sqrt( p < 0 ? 0 : p );
           }

          static scalar_type process( parametric_type const& line, point_type const& point, point_type & projection )
           {
            point_type heading; ::math::linear::vector::subtraction( heading, point, line.origin() );

            scalar_type t = ::math::linear::vector::dot<scalar_type>( heading, line.direction() );

            ::math::linear::vector::scale<scalar_type>( projection, t, line.direction() );
            ::math::linear::vector::addition<scalar_type>( projection,line.origin() );

            scalar_type l = ::math::linear::vector::length<scalar_type>( line.direction() );

            return fabs( t ) / l;
           }

        };

      template<  typename scalar_name, unsigned dimension_number >
       scalar_name distance
        (
          ::math::geometry::direction::parametric< scalar_name, dimension_number > const& parametric
         ,::math::linear::vector::point< scalar_name, dimension_number >          const& point
        )
        {
         return ::math::geometry::direction::P2L<scalar_name,dimension_number>::process( parametric, point );
        }

     }
   }
 }

#endif
