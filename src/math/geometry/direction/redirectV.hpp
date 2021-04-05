#ifndef math_geometry_direction_redirect
#define math_geometry_direction_redirect

// ::math::geometry::object::direction::redirect<scalar_name>( ... )

#include <cmath>

#include "./ABC.hpp"
//#include "./parametric.hpp"
#include "./polar.hpp"
#include "../../geometry/rad2deg.hpp"


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
       redirect( std::vector< ::math::geometry::direction::ABC2D< scalar_name > > & beam )
        {
         typedef ::math::geometry::direction::ABC2D< scalar_name >    ABC2D_type;

         ABC2D_type orientation = beam[ beam.size()/2 ].normalize();

         for( auto & direction: beam )
          {
           direction.normalize();
           if( 0 < ( direction.A() * orientation.A() +  direction.B() * orientation.B() ) )
            {
             continue;
            }
           direction.A() = -direction.A();
           direction.B() = -direction.B();
           direction.C() = -direction.C();
          }
        }

      template
       <
         typename scalar_name = double
       >
       void
       redirect( std::vector< ::math::geometry::direction::polar< scalar_name > > & beam )
        {
         using namespace ::math::linear::vector;
         typedef ::math::geometry::direction::polar< scalar_name >    polar_type;

         polar_type & orientation =  beam[  beam.size()/2].fix();

         for( auto & direction: beam )
          {
           direction.fix();

           auto delta = direction.angle() - orientation.angle();

           if( ( ::math::geometry::deg2rad( 90.0 ) < delta ) && ( delta< ::math::geometry::deg2rad( 270.0 ) ) )
            {
             direction.angle() -= ::math::geometry::deg2rad( 180.0 );
             direction.fix();
             continue;
            }

           if( ( ::math::geometry::deg2rad( -270.0 ) < delta ) && (  delta < ::math::geometry::deg2rad( -90.0 ) ) )
            {
             direction.angle() += ::math::geometry::deg2rad( 180.0 );
             direction.fix();
             continue;
            }
          }
        }

     }
   }
 }

#endif

