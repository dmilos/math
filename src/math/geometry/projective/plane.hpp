#ifndef math_geometry_projective_plane
#define math_geometry_projective_plane

// ::math::geometry::projective::plane( no3d, left, right, down, up )
// ::math::geometry::projective::plane( no3d, a0, a1, a2 , a3 )
// ::math::geometry::projective::plane( no3d, h1, h2, o )
// ::math::geometry::projective::plane( parametric, no3d, x, y )


#include "../../linear/vector/structure.hpp"
#include "../direction/abc.hpp"
#include "../direction/horizon.hpp"
#include "../direction/intersect.hpp"

#include "../plane/no3d.hpp"
#include "../plane/parametric3d.hpp"
#include "../projective/camera/pinhole.hpp"



namespace math
 {
  namespace geometry
   {
    namespace projective
     {

      template<  typename scalar_name>
       void plane // Assumed pinhole camera z-up, x-right, y-strait ahead ahead, project on to plane Z0X ( 0*x + 1*y + 0*z=0 )
        (
          ::math::geometry::plane::no3d<scalar_name>            & no3d
         ,::math::geometry::direction::ABC2D<scalar_name> const& horizon
         ,::math::linear::vector::point<scalar_name, 3>   const& origin   //!< Any point of plane in (x,y,z)
        )
        {
         typedef ::math::geometry::projective::camera::pinhole<scalar_name>   pinhole_type; //!< TODO

         no3d.normal()[0] = -horizon.A();
         no3d.normal()[1] = -horizon.C();
         no3d.normal()[2] = -horizon.B();
         ::math::linear::vector::length<scalar_name>( no3d.normal(), scalar_name(1) );
         no3d.origin() = origin;
        }

      template<  typename scalar_name >
       void plane  // Assumed pinhole camera z-up, x-right, y-strait ahead, project on to plane Z0X ( 0*x + 1*y + 0*z=0 )
        (
          ::math::geometry::plane::no3d<scalar_name>           & no3d
         ,::math::geometry::direction::ABC2D<scalar_name> const& left
         ,::math::geometry::direction::ABC2D<scalar_name> const& right
         ,::math::geometry::direction::ABC2D<scalar_name> const& down
         ,::math::geometry::direction::ABC2D<scalar_name> const& up
        )
        {
         {
          typedef ::math::geometry::direction::ABC2D<scalar_name> abc2d_type;
          typedef ::math::geometry::direction::horizon<scalar_name>   horizon_type;

          horizon_type vanish;
          vanish.process( left.normalize(), right.normalize(), down.normalize(), up.normalize() );
          ::math::geometry::projective::plane( no3d, abc2d_type( vanish.line() ), no3d.origin() ); //!< no3d.origin() just dummy.
         }

         ::math::linear::vector::point<scalar_name, 2> origin;
         ::math::geometry::direction::intersect( origin, left, down );

         {
          typedef ::math::geometry::projective::camera::pinhole<scalar_name>   pinhole_type;
          no3d.origin() = pinhole_type::reproject( origin );  //!< default origin ( x, 1, z )
         }
        }


      template<  typename scalar_name >
       void plane // Assumed pinhole camera z-up, x-right, y-strait ahead ahead, project on to plane Z0X ( 0*x + 1*y + 0*z=0 )
        (
          ::math::geometry::plane::no3d<scalar_name>         & no3d
         ,::math::linear::vector::point<scalar_name, 2> const& a0 //!< (0,0) point
         ,::math::linear::vector::point<scalar_name, 2> const& a1 //!< (1,0) point
         ,::math::linear::vector::point<scalar_name, 2> const& a2 //!< (0,1) point
         ,::math::linear::vector::point<scalar_name, 2> const& a3 //!< (1,1) point
        ) //!< input is standard zig-zag
        {
         typedef ::math::geometry::direction::ABC2D<scalar_name>                abc2d_type;
         typedef ::math::linear::vector::point<scalar_name, 3>                point3D_type;
         typedef ::math::geometry::direction::horizon<scalar_name>            horizon_type;
         typedef ::math::geometry::projective::camera::pinhole<scalar_name>   pinhole_type;

         horizon_type vanish;
         vanish.process( a0, a1, a3, a2 ); //!< not zig-zag

         point3D_type origin = pinhole_type::reproject( a0 );

         ::math::geometry::projective::plane( no3d, abc2d_type( vanish.line() ), origin );
        }

      template<  typename scalar_name >
       bool plane // Assumed pinhole camera z-up, x-right, y-strait ahead ahead, project on to plane Z0X ( 0*x + 1*y + 0*z = 0 )
        (
          ::math::geometry::plane::parametric3d<scalar_name>       & parametric
         ,::math::geometry::plane::no3d<scalar_name>          const& no3d
         ,::math::linear::vector::point<scalar_name, 2>       const& x  //! Point on X axis in y=N(0,1,0) + P(0,1,0) plane
         ,::math::linear::vector::point<scalar_name, 2>       const& y  //! Point on Y axis in y=N(0,1,0) + P(0,1,0) plane
        )
        {
         typedef ::math::geometry::direction::parametric<scalar_name, 3 >      line3D_type;
         typedef ::math::linear::vector::point<scalar_name, 3>                point3D_type;
         typedef ::math::geometry::projective::camera::pinhole<scalar_name>   pinhole_type;

         parametric.origin() = no3d.origin();

         line3D_type  X( point3D_type{0,0,0}, pinhole_type::reproject( x ) );
         if( false == ::math::geometry::plane::intersect( parametric.x(), no3d, X ) )
          {
           return false;
          }

         line3D_type Y( point3D_type{0,0,0}, pinhole_type::reproject( y ) );
         if( false == ::math::geometry::plane::intersect( parametric.y(), no3d, Y ) )
          {
           return false;
          }

         ::math::linear::vector::subtraction( parametric.x(), parametric.origin() ); //!< no additional correction. Return as is.
         ::math::linear::vector::subtraction( parametric.y(), parametric.origin() ); //!< no additional correction. Return as is.
         return true;
        }

      template< typename scalar_name >
       bool plane // Assumed pinhole camera z-up, x-right, y-strait ahead ahead, project on to plane Z0X ( 0*x + 1*y + 0*z=0 )
        (
          ::math::geometry::plane::parametric3d<scalar_name>        & parametric
         ,::math::geometry::plane::no3d <scalar_name>          const& no3d //!< Note: do not forget to adjust origin() after this call
         ,::math::linear::vector::structure<scalar_name, 2>    const& x //!< point on X axis in y=(0,1,0) plane coordinate
         ,::math::linear::vector::structure<scalar_name, 2>    const& y //!< point on Y axis in y=(0,1,0) plane coordinate
         ,scalar_name const& width             //!< Expected length of X axis
         ,scalar_name const& height            //!< Expected length of Y axis
        )
        {
         if( false == ::math::geometry::projective::plane( parametric, no3d, x, y ) )
          {
           return false;
          }

         auto scale_width  = width  / ::math::linear::vector::length( parametric.x() );
         auto scale_height = height / ::math::linear::vector::length( parametric.y() );

         auto scale_average = ( scale_width + scale_height ) / scalar_name(2);

         ::math::linear::vector::scale<scalar_name>( parametric.x(),      scale_average );
         ::math::linear::vector::scale<scalar_name>( parametric.y() ,     scale_average );
         ::math::linear::vector::scale<scalar_name>( parametric.origin(), scale_average );

         //debug auto dot = ::math::linear::linear::dot( parametric.x() , parametric.y() );

         return true;
        }

      template<  typename scalar_name >
       void plane // Assumed pinhole camera z-up, x-right, y-strait ahead ahead, project on to plane Z0X ( 0*x + 1*y + 0*z=0 )
        (
           ::math::geometry::plane::no3d<scalar_name>               & no3d
          ,::math::linear::vector::point<scalar_name, 3>       const& first    //!< Homogeneous coordinate of horizon point
          ,::math::linear::vector::point<scalar_name, 3>       const& second   //!< Homogeneous coordinate of horizon point
          ,::math::linear::vector::point<scalar_name, 3>       const& origin   //!< Any point of plane
        )
       {
        typedef ::math::geometry::direction::horizon<scalar_name>   horizon_type;
        horizon_type vanish;
        vanish.process( first, second );
        ::math::geometry::projective::plane( no3d, ::math::geometry::direction::ABC2D<scalar_name>( vanish.line() ), origin );
       }

     }
   }
 }

#endif

