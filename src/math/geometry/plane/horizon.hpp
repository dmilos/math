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
          typedef ::math::linear::vector::structure<scalar_name,3>  vector_type, vector3d_type;

          typedef ::math::geometry::direction::ABC2D<scalar_name>  direction_type;
          typedef ::math::geometry::plane::ABCD3D<scalar_name>        ABCD3D_type;

          static void processX(   direction_type & line,        vector3d_type const& normal )  //!< it is calculated against : dot( (X,Y,Z)-(1,0,0), (1,0,0) ) = 0
           { //! mapping is ( x, y ) <-> ( -Y, Z )
            line[0] = + normal[1];
            line[1] = - normal[2];
            line[2] = - normal[0];
           }
          static void constructX( vector_type      & normal,  direction_type const& line  )  //!< it is calculated against : dot( (X,Y,Z)-(1,0,0), (1,0,0) ) = 0
           { //! mapping is ( x, y ) <-> ( -Y, Z );
            normal[1] = + line.A() ;
            normal[2] = - line.B() ;
            normal[0] = - line.C() ;
           }
          static void processX( direction_type   & line,     ABCD3D_type const & plane ) //!< it is calculated against : dot( (X,Y,Z)-(1,0,0), (1,0,0) ) = 0
           { //! mapping is ( x, y ) <-> ( -Y, Z )
            line[0] = + plane.B();
            line[1] = - plane.C();
            line[2] = - plane.A();
           }

          static void processY(   direction_type & line,        vector3d_type const& normal )  //!< it is calculated against : dot( (X,Y,Z)-(0,1,0), (0,1,0) ) = 0
           { //! mapping is ( x, y ) <-> ( X, Z )
            line.A() = - normal[0];
            line.B() = - normal[2];
            line.C() = - normal[1];
           }
          static void constructY( vector_type      & normal,  direction_type const& line  ) //!< it is calculated against : dot( (X,Y,Z)-(0,1,0), (0,1,0) ) = 0
           { //! mapping is ( x, y ) <-> ( X, Z );
            normal[0] = - line.A();
            normal[2] = - line.B();
            normal[1] = - line.C();
           }
          static void processY( direction_type   & line,     ABCD3D_type const & plane ) //!< it is calculated against : dot( (X,Y,Z)-(0,1,0), (0,1,0) ) = 0
           { //! mapping is ( x, y ) <-> ( X, Z );
            line.A() = - plane.A();
            line.B() = - plane.C();
            line.C() = - plane.B();
           }

          static void processZ(   direction_type & line,       vector3d_type const& normal )  //!< it is calculated against : dot( (X,Y,Z)-(0,0,1), (0,0,1) ) = 0
           { //! mapping is ( x, y ) <-> ( X, Y )
            line.A() = + normal[0];
            line.B() = + normal[1];
            line.C() = + normal[2];
           }
          static void constructZ( vector_type      & normal, direction_type const& line  ) //!< it is calculated against : dot( (X,Y,Z)-(0,0,1), (0,0,1) ) = 0
           {  //! mapping is ( x, y ) <-> ( X, Y );
            normal[0] = + line[0];
            normal[1] = + line[1];
            normal[2] = + line[2];
           }
          static void processZ( direction_type   & line,    ABCD3D_type const & plane ) //!< it is calculated against : dot( (X,Y,Z)-(0,0,1), (0,0,1) ) = 0
           { //! mapping is ( x, y ) <-> ( X, Y );
            line[0] = + plane.A();
            line[1] = + plane.B();
            line[2] = + plane.C();
           }

        };

     }
   }
 }

#endif
