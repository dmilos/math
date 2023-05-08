#ifndef math_geometry_projective_camera_epi
#define math_geometry_projective_camera_epi

// ::math::geometry::projective::epipolar::line<scalar>
// ::math::geometry::projective::epipolar::line( line, uv, camera )

#include "../../../linear/vector/cross.hpp"
#include "../../../linear/vector/make.hpp"
#include "../../../geometry/interval/structure.hpp"
#include "../../../geometry/plane/intersect.hpp"
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
         class line
          {
           public:
             typedef scalar_name   scalar_type;

             typedef ::math::geometry::direction::parametric<scalar_name, 2>    line2D_type;
             typedef ::math::geometry::direction::parametric<scalar_name, 3>    line3D_type;

             typedef ::math::linear::vector::structure< scalar_name , 2 >      point2D_type, uv_type;
             typedef ::math::linear::vector::structure< scalar_name , 3 >      point3D_type;
             typedef ::math::geometry::interval::structure<scalar_name,2>        window_type;
             typedef ::math::linear::affine::structure<scalar_name,3>          affine_type;

             typedef ::math::geometry::projective::camera::pinhole<scalar_name>    pinhole_type;
             typedef ::math::geometry::projective::camera::mobile< scalar_name >   mobile_type;
           //typedef ::math::geometry::projective::camera::optical<scalar_name >   optical_type, digital_type;

             typedef ::math::geometry::plane::no3d<scalar_name> no3d_type;
             typedef ::math::geometry::plane::parametric3d<scalar_name> parametric3D_type;
             typedef ::math::geometry::plane::three<scalar_name> three_type;

             line()
              {
              }

           public:

             bool process
              (
                line2D_type & epiL, line2D_type & epiR
               ,uv_type const& uv // on left camera
               ,affine_type const& to_world //!< right camera transformation from right to world
               ,affine_type const& to_right //!< right camera transformation from world to right
              )
              { //!< Compute line on both camera
               ::math::linear::vector::fill( m_leftEye, 0 );
               m_rightEye = to_world.vector();

               m_leftWorld.origin() = pinhole_type::reproject( uv );

               m_ePlane = three_type{ m_leftEye, m_rightEye, m_leftWorld.origin() };
               m_leftIP.normal() = pinhole_type::reproject( { 0,0 } );
               m_leftIP.origin() = pinhole_type::reproject( { 0,0 } );

               if( false == ::math::geometry::plane::intersect( m_leftWorld, m_leftIP, m_ePlane ) )
                {
                 return false;
                }
                m_leftLocal = m_leftWorld;
               ::math::linear::vector::load( epiL.origin(),    m_leftLocal.origin()[0],    m_leftLocal.origin()[2] );
               ::math::linear::vector::load( epiL.direction(), m_leftLocal.direction()[0], m_leftLocal.direction()[2] );

               ::math::linear::vector::load( m_rightIP.normal(), to_world[0][1], to_world[1][1], to_world[2][1] );
               ::math::linear::vector::addition( m_rightIP.origin(), m_rightEye, m_rightIP.normal() );
               if( false == ::math::geometry::plane::intersect( m_rightWorld, m_rightIP, m_ePlane ) )
                {
                 return false;
                }
               ::math::linear::affine::transform( m_rightLocal,  to_right, m_rightWorld );
               ::math::linear::vector::load( epiR.origin(),     m_rightLocal.origin()[0],    m_rightLocal.origin()[2] );
               ::math::linear::vector::load( epiR.direction(),  m_rightLocal.direction()[0], m_rightLocal.direction()[2] );

               return true;
              }

             bool process
              (
               line2D_type & epiL, line2D_type & epiR,
               uv_type const& uv_left,
               mobile_type const& sinister,
               mobile_type const& dexter
              )
              { //!< Compute line on both camera. TODO Not optimal!! Academically correct.
               m_leftEye  = sinister.to_world().vector();
               m_rightEye = dexter.to_world().vector();

               m_leftWorld.origin() = pinhole_type::reproject( uv_left );
               ::math::linear::affine::transform( m_leftWorld.origin(), sinister.to_world() );

               m_ePlane = three_type{ m_leftEye, m_rightEye, m_leftWorld.origin() };

               ::math::linear::vector::load(     m_leftIP.normal(), sinister.to_world()[0][1], sinister.to_world()[1][1], sinister.to_world()[2][1] );
               ::math::linear::vector::addition( m_leftIP.origin(), m_leftEye, m_leftIP.normal() );
               if( false == ::math::geometry::plane::intersect( m_leftWorld, m_leftIP, m_ePlane ) )
                {
                 return false;
                }
               ::math::linear::affine::transform( m_leftLocal,  sinister.to_local(), m_leftWorld );
               ::math::linear::vector::load( epiL.origin(),    m_leftLocal.origin()[0],    m_leftLocal.origin()[2] );
               ::math::linear::vector::load( epiL.direction(), m_leftLocal.direction()[0], m_leftLocal.direction()[2] );

               ::math::linear::vector::load(     m_rightIP.normal(), dexter.to_world()[0][1], dexter.to_world()[1][1], dexter.to_world()[2][1] );
               ::math::linear::vector::addition( m_rightIP.origin(), m_rightEye, m_rightIP.normal() );
               if( false == ::math::geometry::plane::intersect( m_rightWorld, m_rightIP, m_ePlane ) )
                {
                 return false;
                }
               ::math::linear::affine::transform( m_rightLocal,  dexter.to_local(), m_rightWorld );
               ::math::linear::vector::load( epiR.origin(),     m_rightLocal.origin()[0],    m_rightLocal.origin()[2] );
               ::math::linear::vector::load( epiR.direction(),  m_rightLocal.direction()[0], m_rightLocal.direction()[2] );

               return true;
              }

             bool processL
              (
                line2D_type & epiL
               ,uv_type const& uv // on left camera
               ,point3D_type const& right_eye //!< right eye, transformation is irrelevant
              )
              { //!< Compute line on both camera
               ::math::linear::vector::fill( m_leftEye, 0 );
               m_rightEye = right_eye;

               m_ePlane = three_type{ m_leftEye, m_rightEye, pinhole_type::reproject( uv ) };
               m_leftIP.normal() = pinhole_type::reproject( { 0,0 } );
               m_leftIP.origin() = pinhole_type::reproject( { 0,0 } );

               if( false == ::math::geometry::plane::intersect( m_leftWorld, m_leftIP, m_ePlane ) )
                {
                 return false;
                }
                m_leftLocal = m_leftWorld;
               ::math::linear::vector::load( epiL.origin(),    m_leftLocal.origin()[0],    m_leftLocal.origin()[2]    );
               ::math::linear::vector::load( epiL.direction(), m_leftLocal.direction()[0], m_leftLocal.direction()[2] );

               return true;
              }

             bool processL( line2D_type & epiL, uv_type const& uv_left, mobile_type const& sinister, mobile_type const& dexter )
              {
               m_leftEye  = sinister.to_world().vector();
               m_rightEye = dexter.to_world().vector();

               m_leftWorld.origin() = pinhole_type::reproject( uv_left );
               ::math::linear::affine::transform( m_leftWorld.origin(), sinister.to_world() );

               m_ePlane = three_type{ m_leftEye, m_rightEye, m_leftWorld.origin() };

               ::math::linear::vector::load( m_leftIP.normal(), sinister.to_world()[0][1], sinister.to_world()[1][1], sinister.to_world()[2][1] );
               ::math::linear::vector::addition( m_leftIP.origin(), m_leftEye, m_leftIP.normal() );

               if( false == ::math::geometry::plane::intersect( m_leftWorld, m_leftIP, m_ePlane ) )
                {
                 return false;
                }
               ::math::linear::affine::transform( m_leftLocal,  sinister.to_local(), m_leftWorld );
               ::math::linear::vector::load( epiL.origin(),    m_leftLocal.origin()[0],    m_leftLocal.origin()[2] );
               ::math::linear::vector::load( epiL.direction(), m_leftLocal.direction()[0], m_leftLocal.direction()[2] );

               return true;
              }

             bool processR( line2D_type & epiR, uv_type const& uv_left, mobile_type const& sinister, mobile_type const& dexter )
              {
               m_leftEye  = sinister.to_world().vector();
               m_rightEye = dexter.to_world().vector();

               m_leftWorld.origin() = pinhole_type::reproject( uv_left );
               ::math::linear::affine::transform( m_leftWorld.origin(), sinister.to_world() );

               m_ePlane = three_type{ m_leftEye, m_rightEye, m_leftWorld.origin() };

               ::math::linear::vector::load( m_rightIP.normal(), dexter.to_world()[0][1], dexter.to_world()[1][1], dexter.to_world()[2][1] );
               ::math::linear::vector::addition( m_rightIP.origin(), m_rightEye, m_rightIP.normal() );
               if( false == ::math::geometry::plane::intersect( m_rightWorld, m_rightIP, m_ePlane ) )
                {
                 return false;
                }
               ::math::linear::affine::transform( m_rightLocal,  dexter.to_local(), m_rightWorld );
               ::math::linear::vector::load( epiR.origin(),     m_rightLocal.origin()[0],    m_rightLocal.origin()[2] );
               ::math::linear::vector::load( epiR.direction(),  m_rightLocal.direction()[0], m_rightLocal.direction()[2] );

               return true;
              }


             bool processR( line2D_type & epiR, uv_type const& uv_left, affine_type const&right_to_world, affine_type const& right_to_local )
              {
               ::math::linear::vector::fill( m_leftEye, 0 );
               m_rightEye = right_to_world.vector();

               m_leftWorld.origin() = pinhole_type::reproject( uv_left );
               m_leftWorld.origin() = m_leftEye;

               m_ePlane = three_type{ m_leftEye, m_rightEye, m_leftWorld.origin() };

               ::math::linear::vector::load( m_rightIP.normal(), right_to_world[0][1], right_to_world[1][1], right_to_world[2][1] );
               ::math::linear::vector::addition( m_rightIP.origin(), m_rightEye, m_rightIP.normal() );
               if( false == ::math::geometry::plane::intersect( m_rightWorld, m_rightIP, m_ePlane ) )
                {
                 return false;
                }
               ::math::linear::affine::transform( m_rightLocal,  right_to_local, m_rightWorld );
               ::math::linear::vector::load( epiR.origin(),     m_rightLocal.origin()[0],    m_rightLocal.origin()[2] );
               ::math::linear::vector::load( epiR.direction(),  m_rightLocal.direction()[0], m_rightLocal.direction()[2] );

               return true;
              }

           public:
             no3d_type  m_leftIP;   //!< Left Image plane
             no3d_type  m_rightIP;  //!< Right Image plane
             no3d_type  m_ePlane;   //!< Epipolar plane

             point3D_type m_rightEye;
             point3D_type m_leftEye;

             line3D_type m_leftWorld,  m_leftLocal;  //!< left  epipolar direction in world space and in local space
             line3D_type m_rightWorld, m_rightLocal; //!< right epipolar direction in world space and in local space
          };

        template < typename scalar_name >
         void
         lineALL   //!< Compute line on both camera
          (
            ::math::geometry::direction::parametric<scalar_name, 2>               & epiL
           ,::math::geometry::direction::parametric<scalar_name, 2>               & epiR
           ,::math::linear::vector::structure< scalar_name , 2 >             const& uv_left
           ,::math::geometry::projective::camera::mobile< scalar_name >      const& dexter
          )
          {
           ::math::geometry::projective::epipolar::line<scalar_name> line;
           line.process( epiL, epiR, uv_left, dexter );
          }

        template < typename scalar_name >
         void
         lineALL   //!< Compute line on both camera
          (
            ::math::geometry::direction::parametric<scalar_name, 2>               & epiL
           ,::math::geometry::direction::parametric<scalar_name, 2>               & epiR
           ,::math::linear::vector::structure< scalar_name , 2 >             const& uv_left
           ,::math::geometry::projective::camera::mobile< scalar_name >      const& sinister
           ,::math::geometry::projective::camera::mobile< scalar_name >      const& dexter
          )
          {
           ::math::geometry::projective::epipolar::line<scalar_name> line;
           line.process( epiL, epiR, uv_left, dexter );
          }


        template < typename scalar_name >
         void
         lineL     //!< Compute line on left camera
          (
            ::math::geometry::direction::parametric<scalar_name, 2>               & epiL
           ,::math::linear::vector::structure< scalar_name , 2 >             const& uv_left
           ,::math::geometry::projective::camera::mobile< scalar_name >      const& dexter
          )
          {
           ::math::geometry::projective::epipolar::line<scalar_name> line;
           line.processL( epiL, uv_left, dexter );
          }

        template < typename scalar_name >
         void
         lineR   //!< Compute line on right camera
          (
            ::math::geometry::direction::parametric<scalar_name, 2>               & epiR
           ,::math::linear::vector::structure< scalar_name , 2 >             const& uv_left
           ,::math::geometry::projective::camera::mobile< scalar_name >      const& dexter
          )
          {
           ::math::geometry::projective::epipolar::line<scalar_name> line;
           line.processR( epiR, uv_left, dexter );
          }

       }
     }
   }
 }

#endif
