#ifndef math_geometry_projective_camera_focus_osgo
#define math_geometry_projective_camera_focus_osgo

// ::math::geometry::projective::camera::focus::osgo().process( F, a00, aX, aY, a11 )

#include "../../../../geometry/direction/horizon.hpp"
#include "../../../../geometry/direction/project.hpp"
#include "../../../../geometry/interval/in.hpp"



namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {
        namespace focus
         {

          /*
           Display: (-whatever, +whatever ) x (-1,1);
           Optical center: (0,0);
           alphaU = alphaV = 1;
           */
          template < typename scalar_name >
           class osgo
            { // R. Orghidan, J. Salvi, M. Gorgan, B. Ozra
             public:
               typedef scalar_name   scalar_type;

               typedef ::math::linear::vector::structure<scalar_name,2>         uv_type;
               typedef ::math::linear::vector::structure<scalar_name,3>         point3D_type;

               typedef ::math::geometry::direction::ABC2D<scalar_name>     ABC2D_type;
               typedef ::math::geometry::direction::horizon<scalar_name>   horizon_type;

             public:
               osgo( uv_type const& center = { 0, 0 } )
                : m_center( center )
                {
                }

             public:
             // four points on some parallelogram
               bool process( scalar_type & focus, uv_type const& O, uv_type const& X, uv_type const& Y, uv_type const& z, scalar_type const& epsilon = 1e-4  )
                {
                 m_horizon.process( O, X, z, Y );

                 if( true == ::math::geometry::interval::in( m_horizon.first()[2],  -epsilon, +epsilon ) )
                  {
                   return false;
                  }
                 if( true == ::math::geometry::interval::in( m_horizon.second()[2], -epsilon, +epsilon) )
                  {
                   return false;
                  }

                 auto      & V1 = m_V1;
                 {
                  auto A = m_horizon.first();  V1[0] = A[0]/A[2]; V1[1] = A[1]/A[2];
                 }

                 auto      & V2 = m_V2;
                 {
                  auto A = m_horizon.second();  V2[0] = A[0]/A[2]; V2[1] = A[1]/A[2];
                 }

                 auto const& Oi = m_center;

                 auto & Vi = m_sunset ;
                 Vi = ::math::geometry::direction::project<scalar_type>().process( Oi, ABC2D_type( m_horizon.line() ).normalize() );

                 auto V1Vi = ::math::linear::vector::distance( V1, Vi );
                 auto V2Vi = ::math::linear::vector::distance( Vi, V2 );
                 auto OiVi = ::math::linear::vector::distance( Vi, Oi );

                 auto OcVi = V1Vi*V2Vi;

                 focus = sqrt( fabs( OcVi - OiVi*OiVi ) );

                 return true;
                }

             public:
               horizon_type const& horizon()const
                {
                 return m_horizon;
                };
             public:
               uv_type m_sunset;
               uv_type m_V1;
               uv_type m_V2;

             private:
               horizon_type m_horizon;
               uv_type m_center;
            };

         }
       }
     }
   }
 }

#endif
