#ifndef math_geometry_distance_P2T
#define math_geometry_distance_P2T

// ::math::geometry::direction::P2T<scalar>::process( two, point )
// ::math::geometry::direction::distance ( two, point )

#include "../../../linear/vector/distance.hpp"
#include "../../../geometry/triangle/area.hpp"
#include "../../../geometry/triangle/valid.hpp"
#include "../two.hpp"


namespace math
 {
  namespace geometry
   {
    namespace direction
     {

      template<typename scalar_name, std::size_t dimension_number >
       struct P2T
        {
         public:
           typedef scalar_name scalar_type;

           typedef ::math::linear::vector::structure< scalar_type, dimension_number > point_type;
           typedef ::math::geometry::direction::two < scalar_type, dimension_number > two_type;

           static scalar_type process
            (
              two_type    const& line
             ,point_type  const& point
            )
            {
             scalar_type a = ::math::linear::vector::distance( line.first(), point );
             scalar_type b = ::math::linear::vector::distance( line.second(), point );
             scalar_type c = ::math::linear::vector::distance( line.first(), line.second() ); //!< it is expected that this is non zero
             if( false == ::math::geometry::triangle::valid< scalar_name>( a, b, c ) ) return 0;

             scalar_type p = ::math::geometry::triangle::area( a, b, c );
             scalar_type result = scalar_type(2)*p/c;
             return  result;
            }

        };

      template<typename scalar_name, std::size_t dimension_number >
       scalar_name distance
        (
          ::math::geometry::direction::two < scalar_name, dimension_number >  const& t
         ,::math::linear::vector::point< scalar_name, 2 >     const& point
        )
        {
         return ::math::geometry::direction::P2T<scalar_name,dimension_number>::process( t, point );
        }

     }
   }
 }

#endif

