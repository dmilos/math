#ifndef math_geometry_plane_fit3D
#define math_geometry_plane_fit3D

// ::math::geometry::plane::fit3D<double>::process( abc, cloud )
//::math::geometry::plane::fit( plane3d, cloud3d, epsilon )
//::math::geometry::plane::fit( direction3d, cloud3d, cloud2d, epsilon )

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

           typedef std::size_t size_type;
           typedef scalar_name scalar_type;
           typedef ::math::linear::vector::point<scalar_type,2>                 point2D_type;
           typedef ::math::linear::vector::point<scalar_type,3>                 point_type, point3D_type;
           typedef ::math::geometry::direction::parametric<scalar_name, 2>      direction2D_type;
           typedef ::math::geometry::direction::parametric<scalar_name, 3>      direction_type, direction3D_type;
           typedef ::math::geometry::plane::no3d<scalar_type>                   plane_type, plane3D_type;

           typedef std::vector< point_type > cloud_type, cloud3D_type;
           typedef std::vector< point2D_type > cloud2D_type;

           typedef ::math::geometry::plane::fit3D<scalar_name> this_type;

           static bool process( plane_type & plane, cloud_type const& cloud3D, scalar_type const& epsilon = 1e-12 )
            {
             if( cloud3D.size() < 3 )
              {
               return false;
              }

             auto & origin = plane.origin() = {0,0,0};

             scalar_type XX = 0;
             scalar_type XY = 0;
             scalar_type XZ = 0;
             scalar_type YY = 0;
             scalar_type YZ = 0;
             scalar_type ZZ = 0;
             scalar_type & X = origin[0] = 0;
             scalar_type & Y = origin[1] = 0;
             scalar_type & Z = origin[2] = 0;

             for( auto const& point: cloud3D )
              {
               X += point[0]; Y += point[1]; Z += point[2];
              }
             X /= cloud3D.size(); Y /= cloud3D.size(); Z /= cloud3D.size();

             for( auto const& point: cloud3D )
              {
               XX += (point[0]-X)*(point[0]-X);
               XY += (point[0]-X)*(point[1]-Y);
               XZ += (point[0]-X)*(point[2]-Z);
               YY += (point[1]-Y)*(point[1]-Y);
               YZ += (point[1]-Y)*(point[2]-Z);
               ZZ += (point[2]-Z)*(point[2]-Z);
              }

             XX /= cloud3D.size();
             XY /= cloud3D.size();
             XZ /= cloud3D.size();
             YY /= cloud3D.size();
             YZ /= cloud3D.size();
             ZZ /= cloud3D.size();

             auto dx = YY*ZZ - YZ*YZ;
             auto dy = XX*ZZ - XZ*XZ;
             auto dz = XX*YY - XY*XY;

             const auto d_max = std::max( std::max( fabs( dx ), fabs( dy ) ), fabs( dz ) );

             if( d_max < epsilon )
              {
               return false;
              }

             auto & normal = plane.normal();

             if( d_max == fabs(dx) )
              {
               normal[0] = dx;
               normal[1] = XZ*YZ - XY*ZZ;
               normal[2] = XY*YZ - XZ*YY;
              }

             if( d_max == fabs(dy) )
              {
               normal[0] = XZ*YZ - XY*ZZ;
               normal[1] = dy;
               normal[2] = XY*XZ - YZ*XX;
              }

             if( d_max == fabs(dz) )
              {
               normal[0] = XY*YZ - XZ*YY;
               normal[1] = XY*XZ - YZ*XX;
               normal[2] = dz;
              }

             ::math::linear::vector::length<scalar_type>( normal, 1 );
             return true;
            }

           static bool process( direction_type & direction3d, cloud2D_type & cloud2D, cloud_type const& cloud3D, scalar_type const& epsilon = 1e-12 )
            {
             plane_type plane;
             if( false == this_type::process( plane, cloud3D, epsilon ) )
              {
               return false;
              }

             point3D_type const& Z = plane.normal();
             auto inferior  = ::math::linear::vector::inferior( Z );
             point3D_type X, Y;
             switch( inferior.first )
              {
               case( 0 ): ::math::linear::vector::cross( X, Z, {1,0,0} ); break;
               case( 1 ): ::math::linear::vector::cross( X, Z, {0,1,0} ); break;
               case( 2 ): ::math::linear::vector::cross( X, Z, {0,0,1} ); break;
              }

            ::math::linear::vector::cross( Y, Z, X ); ::math::linear::vector::length( Y, scalar_type(1) );
            ::math::linear::vector::cross( X, Y, Z ); ::math::linear::vector::length( X, scalar_type(1) );

             point3D_type const& O = plane.origin();
             for( size_type index=0; index < cloud3D.size(); ++index )
              {
               point3D_type V;
               ::math::linear::vector::subtraction( V, cloud3D[index], O );
               cloud2D[ index ][ 0 ] = ::math::linear::vector::dot( X, V );
               cloud2D[ index ][ 1 ] = ::math::linear::vector::dot( Y, V );
              }

             ::math::geometry::direction::ABC2D<scalar_type>  abc;
             if( false == ::math::geometry::direction::fit2D<scalar_type>::process( abc, cloud2D ) )
              {
               return false;
              }
             direction2D_type direction2d{ abc };

            ::math::linear::vector::combine( direction3d.origin(), direction2d.origin()[0], X, direction2d.origin()[1], Y );
            ::math::linear::vector::addition( direction3d.origin(), O );

            ::math::linear::vector::combine( direction3d.direction(), direction2d.direction()[0], X, direction2d.direction()[1], Y );

             return false;
            }

       };

      template
       <
        typename scalar_name = double
       >
       bool fit
        (
         ::math::geometry::plane::no3d<scalar_name>                         & no3d
         ,std::vector< ::math::linear::vector::point<scalar_name,3> > const& cloud
         ,scalar_name const& epsolon = 1e-12 
        )
        {
         return ::math::geometry::plane::fit3D<scalar_name>::process( no3d, cloud, epsolon );
        }

      template
       <
        typename scalar_name = double
       >
       bool fit
        (
          ::math::geometry::direction::parametric<scalar_name, 3>           & direction3D
         ,std::vector< ::math::linear::vector::point<scalar_name,2> >       & cloud2D
         ,std::vector< ::math::linear::vector::point<scalar_name,3> >  const& cloud3D
         ,scalar_name                                                  const& epsolon = 1e-12 
        )
        {
         return ::math::geometry::plane::fit3D<scalar_name>::process( direction3D, cloud2D, cloud3D, epsolon );
        }

     }
   }
 }

#endif

