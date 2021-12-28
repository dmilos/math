#ifndef math_geometry_plane_horizon
#define math_geometry_plane_horizon

// ::math::geometry::plane::horizon( point, no3d );


#include "../../linear/vector/structure.hpp"
#include "../direction/abc.hpp"
#include "./abcd.hpp"
#include "./no3d.hpp"


namespace math
 {
  namespace geometry
   {
    namespace plane
     {

      template<  typename scalar_name >
       struct horizon
        {
         public:
          typedef scalar_name scalar_type;

          typedef ::math::geometry::direction::ABC2D<scalar_name>  direction_type;
          typedef ::math::geometry::plane::ABCD3D<scalar_name>        ABCD3D_type;
          typedef ::math::geometry::plane::no3d<scalar_type>            no3d_type;


          static void process( direction_type & line, no3d_type const& plane )  //!< it is calucated against : dot( (x,y,z)-(0,0,1), (0,0,1) ) = 0
           {
            line[0] = + plane.normal()[0];
            line[1] = + plane.normal()[1];
            line[2] = - plane.normal()[2];
           }

          static void process( direction_type & line, ABCD3D_type const& plane ) //!< it is calucated against : dot( (x,y,z)-(0,0,1), (0,0,1) ) = 0
           {
            line[0] = +plane.A();
            line[1] = +plane.B();
            line[2] = -plane.C();
           }

        };

     }
   }
 }

#endif
