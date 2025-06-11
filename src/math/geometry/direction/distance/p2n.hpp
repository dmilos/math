#ifndef math_geometry_distance_P2N
#define math_geometry_distance_P2N

// ::math::geometry::direction::P2N<scalar>::process( normal, point )
// ::math::geometry::direction::distance ( normal, point )

#include "../../../linear/vector/structure.hpp"
#include "../normal.hpp"


namespace math
 {
  namespace geometry
   {
    namespace direction
     {

      template<  typename scalar_name >
       struct P2N
        {
         public:
           typedef scalar_name scalar_type;

           typedef ::math::linear::vector::point< scalar_type, 2 > point_type;
           typedef ::math::geometry::direction::normal < scalar_type > normal_type;

           static scalar_type process
            (
              normal_type    const& line
             ,point_type  const& point
            )
            {
             scalar_type numerator = - sin( line.angle() ) * point[0] + cos( line.angle() ) * point[1] + line.radius();
             scalar_type denumerator = line.radius();
             return  fabs( numerator ) / denumerator ;
            }

        };
        
      template<  typename scalar_name >
       scalar_name distance
        (
          ::math::geometry::direction::normal < scalar_name >  const& n 
         ,::math::linear::vector::point< scalar_name, 2 >     const& point 
        )
        {
         return ::math::geometry::direction::P2N<scalar_name>::process( n, point );
        }

     }
   }
 }

#endif

