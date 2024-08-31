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
#include "../plane/horizon.hpp"

#include "../projective/camera/pinhole.hpp"



namespace math
 {
  namespace geometry
   {
    namespace projective
     {

      template<  typename scalar_name >
       void plane // Assumed pinhole camera z-up, x-right, y-strait ahead ahead, project on to plane Z0X ( 0*x + 1*y + 0*z=0 )
        (
           ::math::linear::vector::structure<scalar_name, 3>        & normal
          ,::math::linear::vector::point<scalar_name, 3>       const& first    //!< Homogeneous coordinate of horizon point
          ,::math::linear::vector::point<scalar_name, 3>       const& second   //!< Homogeneous coordinate of horizon point
        )
       {
        typedef ::math::geometry::direction::horizon<scalar_name>   vanish_type;
        typedef ::math::geometry::direction::ABC2D<scalar_name> abc2d_type;
        typedef ::math::geometry::plane::horizon<scalar_name>   horizon_type;
        vanish_type vanish;
        vanish.process( first, second );
        horizon_type::constructY( normal, abc2d_type( vanish.line() ) );
       }

      template<  typename scalar_name >
       void plane  // Assumed pinhole camera z-up, x-right, y-strait ahead, project on to plane Z0X ( 0*x + 1*y + 0*z=0 )
        (
          ::math::linear::vector::structure<scalar_name, 3>          & normal
         ,::math::geometry::direction::ABC2D<scalar_name>       const& left
         ,::math::geometry::direction::ABC2D<scalar_name>       const& right
         ,::math::geometry::direction::ABC2D<scalar_name>       const& down
         ,::math::geometry::direction::ABC2D<scalar_name>       const& up
        )
        {
          typedef ::math::geometry::direction::ABC2D<scalar_name> abc2d_type;
          typedef ::math::geometry::direction::horizon<scalar_name>   vanish_type;
          typedef ::math::geometry::plane::horizon<scalar_name>   horizon_type;

          vanish_type vanish;
          vanish.process( left.normalize(), right.normalize(), down.normalize(), up.normalize() );
          horizon_type::constructY( normal, abc2d_type( vanish.line() ) ); 
       }

      template<  typename scalar_name >
       void plane // Assumed pinhole camera z-up, x-right, y-strait ahead ahead, project on to plane Z0X ( 0*x + 1*y + 0*z=0 )
        (
          ::math::linear::vector::structure<scalar_name, 3>         & normal
         ,::math::linear::vector::point<scalar_name, 2> const& a0 //!< (0,0) point
         ,::math::linear::vector::point<scalar_name, 2> const& a1 //!< (1,0) point
         ,::math::linear::vector::point<scalar_name, 2> const& a2 //!< (0,1) point
         ,::math::linear::vector::point<scalar_name, 2> const& a3 //!< (1,1) point
        ) //!< input is standard zig-zag
        {
         typedef ::math::geometry::direction::ABC2D<scalar_name>                abc2d_type;
         typedef ::math::geometry::direction::horizon<scalar_name>            vanish_type;
         typedef ::math::geometry::projective::camera::pinhole<scalar_name>   pinhole_type;
         typedef ::math::geometry::plane::horizon<scalar_name>   horizon_type;

         vanish_type vanish;
         vanish.process( a0, a1, a3, a2 ); //!< not zig-zag

         horizon_type::constructY( normal, abc2d_type( vanish.line() ) );
        }

     }
   }
 }

#endif

