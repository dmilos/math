#ifndef math_geometry_plane_fit3D
#define math_geometry_plane_fit3D

// ::math::geometry::plane::fit3D<double>::process( abc, cloud )

#include <vector>
#include "../../linear/vector/vector.hpp"
#include "./no3d.hpp"


namespace math
 {
  namespace geometry
   {
    namespace plane
     {

      template
       <
        typename scalar_name = double
       >
       struct fit3D
        {
         public:

           typedef scalar_name scalar_type;
           typedef ::math::linear::vector::point<scalar_type,3>    point_type;
           typedef ::math::geometry::plane::no3d<scalar_type>      plane_type;

           typedef std::vector< point_type > cloud_type;

           static bool process( plane_type & plane, cloud_type const& cloud, scalar_type const& epsilon = 1e-12 )
            {
             if( cloud.size() < 3 )
              {
               return false;
              }

             auto & origin = plane.origin() = {0,0,0};
             auto & normal = plane.normal();

             scalar_type XX = 0;
             scalar_type XY = 0;
             scalar_type XZ = 0;
             scalar_type YY = 0;
             scalar_type YZ = 0;
             scalar_type ZZ = 0;
             scalar_type X = origin[0];
             scalar_type Y = origin[1];
             scalar_type Z = origin[2];

             for( auto const& point: cloud )
              {
               X += point[0]; Y += point[1]; Z += point[2];
              }
             X /= cloud.size(); Y /= cloud.size(); Z /= cloud.size();

             for( auto const& point: cloud )
              {
               XX += (point[0]-X)*(point[0]-X);
               XY += (point[0]-X)*(point[1]-Y);
               XZ += (point[0]-X)*(point[2]-Z);
               YY += (point[1]-Y)*(point[1]-Y);
               YZ += (point[1]-Y)*(point[2]-Z);
               ZZ += (point[2]-Z)*(point[2]-Z);
              }

             XX /= cloud.size();
             XY /= cloud.size();
             XZ /= cloud.size();
             YY /= cloud.size();
             YZ /= cloud.size();
             ZZ /= cloud.size();

             auto dx = YY*ZZ - YZ*YZ;
             auto dy = XX*ZZ - XZ*XZ;
             auto dz = XX*YY - XY*XY;

             auto d_max = std::max( std::max( fabs( dx ), fabs( dy ) ), fabs( dz ) );

             if( d_max < epsilon )
              {
               return false;
              }

             if( fabs(dx) == d_max )
              {
               normal[0] = dx;
               normal[1] = XZ*YZ - XY*ZZ;
               normal[2] = XY*YZ - XZ*YY;
              }

             if( fabs(dy) == d_max )
              {
               normal[0] = XZ*YZ - XY*ZZ;
               normal[1] = dy;
               normal[2] = XY*XZ - YZ*XX;
              }

             if( fabs(dz) == d_max )
              {
               normal[0] = XY*YZ - XZ*YY;
               normal[1] = XY*XZ - YZ*XX;
               normal[2] = dz;
              }

             ::math::linear::vector::length<scalar_type>( normal, 1 );
             return true;
            }

       };

      template
       <
        typename scalar_name = double
       >
       bool fit
        (
         ::math::geometry::plane::no3d<scalar_name>                         & abcd
         , std::vector< ::math::linear::vector::point<scalar_name,3> > const& cloud
        )
        {
         return ::math::geometry::plane::fit3D<scalar_name>::process( abcd, cloud );
        }

     }
   }
 }

#endif

