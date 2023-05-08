#ifndef math_geometry_distance_P2L
#define math_geometry_distance_P2L

// ::math::geometry::direction::P2L< scalar, dimension>::process( parametric, point )
// ::math::geometry::direction::distance( parametric, point  )

#include "../../../linear/vector/structure.hpp"
#include "../../../linear/vector/subtraction.hpp"

#include "../parametric.hpp"



namespace math
 {
  namespace geometry
   {
    namespace direction
     {

      template<  typename scalar_name, std::size_t dimension_number >
       struct P2L //!< distance from point to parametric line
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

             scalar_type lambda = ::math::linear::vector::dot<scalar_type>( heading, line.direction() );
             lambda /= ::math::linear::vector::dot<scalar_type>( line.direction(), line.direction() );

             ::math::linear::vector::scale<scalar_type>( projection, lambda, line.direction() );

             scalar_type result = ::math::linear::vector::distance<scalar_type>( heading, projection );

             return result;
            }
        };


      template<  typename scalar_name, std::size_t dimension_number >
       scalar_name distance
        (
          ::math::geometry::direction::parametric< scalar_name, dimension_number > const& parametric
         ,::math::linear::vector::point< scalar_name, dimension_number >           const& point
        )
        {
         return ::math::geometry::direction::P2L<scalar_name,dimension_number>::process( parametric, point );
        }

     }
   }
 }

#endif
