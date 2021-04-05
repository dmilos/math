#ifndef math_geometry_distance_P2ABC2D
#define math_geometry_distance_P2ABC2D

 // ::math::geometry::distance::P2ABC2D<scalar>::process( point, ABC )

#include "../../../linear/vector/structure.hpp"
#include "../abc.hpp"


namespace math
 {
  namespace geometry
   {
    namespace direction
     {

      template<  typename scalar_name >
       struct P2ABC2D
        {
         public:
           typedef scalar_name scalar_type;

           typedef ::math::linear::vector::point< scalar_type, 2 > point_type;
           typedef ::math::geometry::direction::ABC2D < scalar_type > ABC_type;

           static scalar_type process
            (
              ABC_type    const& line
             ,point_type  const& point
            )
            {
             return  fabs( line.A() * point[0] + line.B() * point[1] + line.C() ) / sqrt( line.A() * line.A() + line.B() * line.B() );
            }

        };
        
      template<  typename scalar_name >
       scalar_name distance
        (
          ::math::geometry::direction::ABC2D < scalar_name >  const& abc 
         ,::math::linear::vector::point< scalar_name, 2 >     const& point 
        )
        {
         return ::math::geometry::direction::P2ABC2D<scalar_name>::process( abc, point );
        }

     }
   }
 }

#endif

