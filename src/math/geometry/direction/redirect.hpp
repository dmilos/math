#ifndef math_geometry_direction_redirect
#define math_geometry_direction_redirect

// ::math::geometry::object::direction::redirect<scalar_name>( direction )

#include <cmath>

#include "./ABC.hpp"
#include "./parametric.hpp"
#include "./polar.hpp"
#include "./two.hpp"

#include "../../linear/vector/negate.hpp"


namespace math
 {
  namespace geometry
   {
    namespace direction
     {

      template
       <
         typename scalar_name = double
       >
       void
       redirect( ::math::geometry::direction::ABC2D< scalar_name > & direction )
        { // flip direction
         direction.A() = -direction.A();
         direction.B() = -direction.B();
         direction.C() = -direction.C();
        }

      template
       <
         typename scalar_name = double
       >
       void
       redirect( ::math::geometry::direction::polar< scalar_name >  & direction )
        { // flip direction
         direction.fix();
         direction.angle() += ::math::geometry::deg2rad( 180.0 );
         direction.fix();
         return;
        }

      template
       <
         typename scalar_name
        ,unsigned dimesion_number
       >
       void
       redirect( ::math::geometry::direction::parametric< scalar_name, dimesion_number > & direction )
        { // flip direction
         ::math::linear::vector::negate( direction.direction() );
        }

      template
       <
         typename scalar_name
        ,unsigned dimesion_number
       >
       void
       redirect( ::math::geometry::direction::two< scalar_name, dimesion_number > & direction )
        { // flip direction
         std::swap( direction.first(), direction.second() );
        }

     }
   }
 }

#endif

