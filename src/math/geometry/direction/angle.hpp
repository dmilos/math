#ifndef math_geometry_direction_angle
#define math_geometry_direction_angle

// ::math::geometry::direction::angle( two, two )
// ::math::geometry::direction::angle( abc, abc )

#include "../../linear/vector/structure.hpp"
#include "../../linear/vector/angle.hpp"
#include "../../linear/vector/load.hpp"
#include "./two.hpp"
#include "./abc.hpp"



namespace math
 {
  namespace geometry
   {
    namespace direction
     {

      template< typename scalar_name >
       struct angleX
        {
         public:
           typedef scalar_name scalar_type;

           typedef ::math::linear::vector::structure< scalar_type, 2 >        vector_type;

           typedef ::math::geometry::direction::two< scalar_type, 2 >            two_type;
           typedef ::math::geometry::direction::ABC2D < scalar_type >            ABC_type;
           typedef ::math::geometry::direction::parametric<scalar_name, 2> parametric_type;

           static scalar_type process
            (
              two_type         const & left
             ,two_type         const & right
            )
            {
             vector_type ld; ::math::linear::vector::subtraction( ld, left.second(),  left.first() );
             vector_type rd; ::math::linear::vector::subtraction( rd, right.second(), right.first() );
             return ::math::linear::vector::angle( ld, rd );
            }

           static scalar_type process
            (
              ABC_type    const & left
             ,ABC_type    const & right
            )
            {
             vector_type ln; ::math::linear::vector::load( ln, left.A(),  left.B()  );
             vector_type rn; ::math::linear::vector::load( rn, right.A(), right.B() );

             return ::math::linear::vector::angle( ln, rn );
            }

           static scalar_type process
            (
              parametric_type    const & left
             ,parametric_type    const & right
            )
            {
             return ::math::linear::vector::angle( left.direction(), right.direction() );
            }

        };


      template<  typename scalar_name >
      scalar_name angle
        (
          ::math::geometry::direction::two< scalar_name, 2 >         const & left
         ,::math::geometry::direction::two< scalar_name, 2 >         const & right
        )
        {
         return ::math::geometry::direction::angleX<scalar_name>::process( left, right );
        }

      template<  typename scalar_name >
      scalar_name angle
        (
          ::math::geometry::direction::ABC2D < scalar_name >    const & left
         ,::math::geometry::direction::ABC2D < scalar_name >    const & right
        )
        {
         return ::math::geometry::direction::angleX<scalar_name>::process( left, right );
        }

      template<  typename scalar_name >
      scalar_name angle
        (
          ::math::geometry::direction::parametric < scalar_name,2 >    const & left
         ,::math::geometry::direction::parametric < scalar_name,2 >    const & right
        )
        {
         return ::math::geometry::direction::angleX<scalar_name>::process( left, right );
        }

     }
   }
 }

#endif
