#ifndef math_geometry_plane_project_P2P3d
#define math_geometry_plane_project_P2P3d

// ::math::geometry::plane::project( projection, no3d );
// ::math::geometry::plane::project( projection, no3d, point );
// ::math::geometry::plane::project( uv, parametric3d );
// ::math::geometry::plane::project( uv, parametric3d, point );


#include "../../linear/vector/vector.hpp"
#include "../../linear/matrix/system.hpp"
#include "../direction/parametric.hpp"


namespace math
 {
  namespace geometry
   {
    namespace plane
     {

      template<  typename scalar_name >
       struct P2P3D_project
        {
         public:
          typedef scalar_name scalar_type;
          typedef ::math::linear::vector::point< scalar_type, 2 > uv_type;
          typedef ::math::linear::vector::point< scalar_type, 3 > point_type;
          typedef ::math::linear::matrix::structure< scalar_type, 3,3 > matrix_type;

          typedef ::math::geometry::plane::no3d<scalar_type> no3d_type;
          typedef ::math::geometry::plane::parametric3d<scalar_name>  parametric3d_type;

          static scalar_type process( point_type & projection, no3d_type const& no3d )
           {
            auto length2 = ::math::linear::vector::dot( no3d.normal(), no3d.normal() );

            auto lambda = - ::math::linear::vector::dot( no3d.origin(), no3d.normal() );

            lambda /= length2;

            ::math::linear::vector::scale( projection, -lambda, no3d.normal() );
            return lambda;
           }

          static scalar_type process( point_type & projection, no3d_type const& no3d, point_type const& point )
           {
            auto length2 = ::math::linear::vector::dot( no3d.normal(), no3d.normal() );

            point_type heading;
            ::math::linear::vector::subtraction( heading, point, no3d.origin() );
            auto lambda = ::math::linear::vector::dot( heading, no3d.normal() );

            lambda /= length2;

            ::math::linear::vector::combine<scalar_type>( projection, 1, point, -lambda, no3d.normal() );
            return lambda;
           }

          static bool process( uv_type &uv, parametric3d_type const& parametric3d )
           {
            point_type n;  ::math::linear::vector::cross( n, parametric3d.x(), parametric3d.y() );
            matrix_type m, mi;
            ::math::linear::matrix::system( m, parametric3d.x(), parametric3d.y(), n );
            if( false == ::math::linear::matrix::invert( mi, m ) )
             {
              return false;
             }
            point_type uvw;
            ::math::linear::matrix::transform( uvw, mi, parametric3d.origin() );
            ::math::linear::vector::negate( uvw );
            ::math::linear::vector::reduce( uv, uvw );
            return true;
           }

          static bool process( uv_type &uv, parametric3d_type const& parametric3d, point_type const&point )
           {
            point_type n;  ::math::linear::vector::cross( n, parametric3d.x(), parametric3d.y() );
            matrix_type m, mi;
            ::math::linear::matrix::system( m, parametric3d.x(), parametric3d.y(), n );
            if( false == ::math::linear::matrix::invert( mi, m ) )
             {
              return false;
             }
            point_type heading;
            ::math::linear::vector::subtraction( heading, point, parametric3d.origin() );
            point_type uvw;
            ::math::linear::matrix::transform( uvw, mi, heading );
            ::math::linear::vector::reduce( uv, uvw );
            return true;
           }
        };

      template<  typename scalar_name >
       scalar_name project
         (
           ::math::linear::vector::point<scalar_name,3>                     & projection
          ,::math::geometry::plane::no3d <scalar_name>                const & plane
         )
         {
          return ::math::geometry::plane::P2P3D_project<scalar_name>::process( projection, plane );
         }


      template<  typename scalar_name >
       scalar_name project
         (
           ::math::linear::vector::point<scalar_name,3>                     & projection
          ,::math::geometry::plane::no3d <scalar_name>                const & plane
          ,::math::linear::vector::point<scalar_name,3>               const & point
         )
         {
          return ::math::geometry::plane::P2P3D_project<scalar_name>::process( projection, plane, point);
         }

      template<  typename scalar_name >
        bool project
         (
           ::math::linear::vector::point<scalar_name,2>                     & uv
          ,::math::geometry::plane::parametric3d<scalar_name>         const & plane
         )
         {
          return ::math::geometry::plane::P2P3D_project<scalar_name>::process( uv, plane );
         }

      template<  typename scalar_name >
        bool project
         (
           ::math::linear::vector::point<scalar_name,2>                     & uv
          ,::math::geometry::plane::parametric3d<scalar_name>         const & plane
          ,::math::linear::vector::point<scalar_name,3>               const & point
         )
         {
          return ::math::geometry::plane::P2P3D_project<scalar_name>::process( uv, plane, point );
         }

     }
   }
 }

#endif
