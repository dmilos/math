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

      template<  typename scalar_name, ::math::type::size_type dimension_number >
       struct P2L //!< distance from point to parametric line
        {
         public:
           typedef scalar_name scalar_type;
           typedef ::math::linear::vector::point< scalar_type, dimension_number > point_type;
           typedef ::math::geometry::direction::parametric< scalar_type, dimension_number > parametric_type;

           scalar_type process( parametric_type const& line )
            { //! point is origin
             scalar_type l = ::math::linear::vector::dot<scalar_type>( line.direction(), line.direction() );
             scalar_type t = - ::math::linear::vector::dot<scalar_type>( line.origin(), line.direction() );
             scalar_type s = ::math::linear::vector::dot<scalar_type>( line.origin(), line.origin() );

             m_lambda = t/l;

             scalar_type result = s - t*t/l;
             return sqrt( result < 0 ? 0 : result );
            }

           scalar_type process( parametric_type const& line, point_type const& point )
            {
             point_type heading; ::math::linear::vector::subtraction( heading, point, line.origin() );

             scalar_type l = ::math::linear::vector::dot<scalar_type>( line.direction(), line.direction() );
             scalar_type t = ::math::linear::vector::dot<scalar_type>( heading, line.direction() );
             scalar_type s = ::math::linear::vector::dot<scalar_type>( heading, heading );

             m_lambda = t/l;
             auto result = s - t*t/l;

             return sqrt( result < 0 ? 0 : result );
            }

           scalar_type process( point_type & projection, parametric_type const& line )
            { // point is origin
             m_lambda = -::math::linear::vector::dot<scalar_type>( line.origin(), line.direction() );
             m_lambda /= ::math::linear::vector::dot<scalar_type>( line.direction(), line.direction() );

             ::math::linear::vector::scale<scalar_type>( projection, -m_lambda, line.direction() );

             scalar_type result = ::math::linear::vector::distance<scalar_type>( line.origin(), projection );
             ::math::linear::vector::addition<scalar_type>( projection, line.origin() );

             return result;
            }

           scalar_type process( point_type & projection, parametric_type const& line, point_type const& point )
            {
             point_type heading; ::math::linear::vector::subtraction( heading, point, line.origin() );

             m_lambda = ::math::linear::vector::dot<scalar_type>( heading, line.direction() );
             m_lambda /= ::math::linear::vector::dot<scalar_type>( line.direction(), line.direction() );

             ::math::linear::vector::scale<scalar_type>( projection, m_lambda, line.direction() );

             scalar_type result = ::math::linear::vector::distance<scalar_type>( heading, projection );
             ::math::linear::vector::addition<scalar_type>( projection, line.origin() );

             return result;
            }

           scalar_type const& lambda(){ return m_lambda; }
         private:
           scalar_type m_lambda;
        };


      template<  typename scalar_name, ::math::type::size_type dimension_number >
       scalar_name distance
        (
          ::math::geometry::direction::parametric< scalar_name, dimension_number > const& parametric
         ,::math::linear::vector::point< scalar_name, dimension_number >           const& point
        )
        {
         return ::math::geometry::direction::P2L<scalar_name,dimension_number>().process( parametric, point );
        }

     }
   }
 }

#endif
