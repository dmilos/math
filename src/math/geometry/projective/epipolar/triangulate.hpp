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

        template < typename scalar_name, typename size_name = std::size_t >
         struct triangulate
          {
           public:
             typedef scalar_name   scalar_type;
             typedef size_name       size_type;

           private:
             typedef ::math::geometry::direction::parametric< scalar_type, 3 > ray_type;
             typedef ::math::geometry::direction::L2L< scalar_type, 3> L2L_type;

           public:
             typedef ::math::linear::vector::point<  scalar_name, 2 > uv_type;
             typedef ::math::linear::vector::point<  scalar_name, 3 > point3d_type;
             typedef ::math::linear::affine::structure< scalar_name, 3 > affine_type;

             typedef ::math::geometry::projective::camera::pinhole<scalar_name>                pinhole_type;
             typedef ::math::geometry::projective::camera::optical< scalar_name, size_name >   optical_type, digital_type;
             typedef ::math::geometry::projective::camera::mobile< scalar_name >               mobile_type;

             template< typename number_name >
              using vector_type = ::math::linear::vector::structure< number_name, 2 >;

           public:

             // Take two cameras, two pixels from each of them, return point in 3D.
             template< typename number_name >
              bool processXY
               (
                 digital_type const& camera_left,  vector_type< number_name > const& xy_left
                ,digital_type const& camera_right, vector_type< number_name > const& xy_right
                ,affine_type const& r2l
               )
               {
                uv_type uv_left  = camera_left.uv( xy_left );
                uv_type uv_right = camera_right.uv( xy_right );

                return this->processUV( uv_left, uv_right, r2l );
               }

             // Take two cameras, two pixels from each of them, return point in 3D.
             template< typename number_name >
              bool processXY
               (
                 mobile_type const& camera_left,  vector_type< number_name > const& xy_left
                ,mobile_type const& camera_right, vector_type< number_name > const& xy_right
               )
               {
                m_rayLeft.origin() =  camera_left.to_world().vector();
                m_rayLeft.direction() =  camera_left.rayXY( xy_left );

                m_rayRight.origin() =  camera_right.to_world().vector();
                m_rayRight.direction() =  camera_right.rayXY( xy_right );

                return this->m_L2L.process( m_rayLeft, m_rayRight );
               }

             // Take two cameras, two UVs from each of them, return point in 3D.
              bool processUV
               (
                 mobile_type const& sinister,  uv_type const& uv_left
                ,mobile_type const& dexter,    uv_type const& uv_right
               )
               {
                m_rayLeft.origin()    =  sinister.to_world().vector();
                m_rayLeft.direction() =  sinister.rayUV( uv_left ); 

                m_rayRight.origin()    =  dexter.to_world().vector();
                m_rayRight.direction() =  dexter.rayUV( uv_right );

                return this->m_L2L.process( m_rayLeft, m_rayRight );
               }

              // Take two UVs and right transformation from local to world.
              bool processUV
               (
                 uv_type  const& left, uv_type  const& right, affine_type const& r2l
               )
               {
                ::math::linear::vector::fill( m_rayLeft.origin(), 0 );

                m_rayLeft.direction() = pinhole_type::reproject( left );
                ::math::linear::vector::length( m_rayLeft.direction(), scalar_type(1) );

                ::math::linear::vector::fill( m_rayRight.origin(), 0 );
                ::math::linear::affine::transform( m_rayRight.origin(),    r2l, ::math::linear::vector::make<scalar_type>( 0, 0, 0 ) );

                ::math::linear::affine::transform( m_rayRight.direction(), r2l, pinhole_type::reproject( right ) );
                ::math::linear::vector::subtraction( m_rayRight.direction(), m_rayRight.origin() );
                ::math::linear::vector::length( m_rayRight.direction(), scalar_type(1) );

                return m_L2L.process( m_rayLeft, m_rayRight );
               }

              // Take two UVs. two cameras only translates along X axis by distance.
              // first camera is in zero position, second is translated by distance along X axis
              bool processUV
               (
                 uv_type const& left, uv_type  const& right, scalar_type const& distance
               )
               {
                ::math::linear::vector::fill( m_rayLeft.origin(), 0 );

                m_rayLeft.direction() = pinhole_type::reproject( left );
                ::math::linear::vector::length( m_rayLeft.direction(), scalar_type(1) );

                ::math::linear::vector::fill( m_rayRight.origin(), 0 );
                m_rayRight.origin()[0] = distance;

                 m_rayRight.direction() = pinhole_type::reproject( right );
                ::math::linear::vector::subtraction( m_rayRight.direction(), m_rayRight.origin() );
                ::math::linear::vector::length( m_rayRight.direction(), scalar_type(1) );

                return m_L2L.process( m_rayLeft, m_rayRight );
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
             ray_type m_rayLeft;
             ray_type m_rayRight;
          };

       }
     }
   }
 }

#endif
