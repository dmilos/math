#ifndef math_geometry_projective_camera_triangulate
#define math_geometry_projective_camera_triangulate

// ::math::geometry::projective::epipolar::triangulate<scalar>;

#include "../../../linear/vector/vector.hpp"
#include "../../../linear/affine/affine.hpp"
#include "../../../geometry/direction/distance/L2L.hpp"
#include "../camera/mobile.hpp"
#include "../camera/pinhole.hpp"

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {

        template < typename scalar_name >
         struct triangulate
          {
           public:
             typedef scalar_name     scalar_type;

           private:
             typedef ::math::geometry::direction::parametric< scalar_type, 3 > ray_type;
             typedef ::math::geometry::direction::L2L< scalar_type, 3> L2L_type;

           public:
             typedef ::math::linear::vector::point<  scalar_name, 2 > uv_type;
             typedef ::math::linear::vector::point<  scalar_name, 3 > point3d_type;
             typedef ::math::linear::affine::structure<  scalar_name, 3 > affine_type;

             typedef ::math::geometry::projective::camera::pinhole<scalar_name>   pinhole_type;
             typedef ::math::geometry::projective::camera::mobile< scalar_name > camera_type;

             template< typename number_name >
              using vector_type = ::math::linear::vector::structure< number_name, 2 >;

           public:
             // Take two cameras, two pixels from each of them, return point in 3D.
             template< typename number_name >
              bool processXY
               (
                 camera_type const& camera_left,  vector_type< number_name > const& xy_left
                ,camera_type const& camera_right, vector_type< number_name > const& xy_right
               )
               {
                ray_type ray_left;
                ray_left.origin() =  camera_left.to_world().vector();
                ray_left.direction() =  camera_left.rayXY( xy_left );

                ray_type ray_right;
                ray_right.origin() =  camera_right.to_world().vector();
                ray_right.direction() =  camera_right.rayXY( xy_right );

                return this->m_L2L.process( ray_left, ray_right );
               }

             // Take two cameras, two UVs from each of them, return point in 3D.
              bool processUV
               (
                 camera_type const& camera_left,  uv_type const& uv_left
                ,camera_type const& camera_right, uv_type const& uv_right
               )
               {
                ray_type ray_left;
                ray_left.origin() =  camera_left.to_world().vector();
                ray_left.direction() =  camera_left.rayUV( uv_left );

                ray_type ray_right;
                ray_right.origin() =  camera_right.to_world().vector();
                ray_right.direction() =  camera_right.rayUV( uv_right );

                return this->m_L2L.process( ray_left, ray_right );
               }

                // Take two UVs and right transformation from local to world.
              bool processUV
               (
                 uv_type  const& left, uv_type  const& right, affine_type const& r2l
               )
               {
                ray_type ray_left;
                ::math::linear::vector::fill( ray_left.origin(), 0 );

                ray_left.direction() = pinhole_type::reproject( left );
                ::math::linear::vector::length( ray_left.direction(), scalar_type(1) );

                ray_type ray_right;
                ::math::linear::vector::fill( ray_right.origin(), 0 );
                ::math::linear::affine::transform( ray_right.origin(),    r2l, ::math::linear::vector::make<scalar_type>( 0, 0, 0 ) );

                ::math::linear::affine::transform( ray_right.direction(), r2l, pinhole_type::reproject( right ) );
                ::math::linear::vector::subtraction( ray_right.direction(), ray_right.origin() );
                ::math::linear::vector::length( ray_right.direction(), scalar_type(1) );

                return m_L2L.process( ray_left, ray_right );
               }

           public:
             point3d_type point()const
              {
               return this->m_L2L.median();
              }

             L2L_type const& L2L()const
              {
               return m_L2L;
              }

           private:
             L2L_type m_L2L;

          };

       }
     }
   }
 }

#endif
