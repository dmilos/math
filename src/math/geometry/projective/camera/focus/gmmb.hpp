#ifndef math_geometry_projective_camera_focus_gmmb
#define math_geometry_projective_camera_focus_gmmb

// ::math::geometry::projective::camera::focus::gmmb().process( F, a00, aX, aY, a11 )

#include "../../../../linear/vector/structure.hpp"
#include "../../../../linear/vector/dot.hpp"
#include "../../../../geometry/direction/horizon.hpp"
#include "../../../../geometry/direction/abc.hpp"
#include "../../../../geometry/direction/rotate.hpp"
#include "../../../../geometry/direction/intersect.hpp"
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
           Display: (-whatever, +whatever )x(-1,1);
           Optical center: (0,0);
           */
          template < typename scalar_name >
           class gmmb
            {// E. Guillou, D. Meneveaux, E. Maisel, K. Bouatouch
             public:
               typedef scalar_name   scalar_type;

               typedef ::math::linear::vector::structure<scalar_name,2>         uv_type;
               typedef ::math::geometry::direction::horizon<scalar_name>   horizon_type;
               typedef ::math::geometry::direction::ABC2D<scalar_name>       ABC2D_type;
             public:
               gmmb()
                : m_center{0,0}
                {
                }

             public:
             // four points on some quad
               bool process( scalar_type & focus, uv_type const& O, uv_type const& X, uv_type const& Y, uv_type const& z, scalar_type const& epsilon = 1e-4  )
                {
                 m_horizon.process( O, X, z, Y );  //!< always exists

                 if( true == ::math::geometry::interval::in( m_horizon.first()[2],  -epsilon, +epsilon ) )
                  {
                   return false;
                  }
                 if( true == ::math::geometry::interval::in( m_horizon.second()[2], -epsilon, +epsilon) )
                  {
                   return false;
                  }

                 auto F = m_horizon.first();  F[0] /= F[2]; F[1] /= F[2]; F[2] /= F[2];
                 auto S = m_horizon.second(); S[0] /= S[2]; S[1] /= S[2]; S[2] /= S[2];

                 ABC2D_type horizon{ m_horizon.line() }; 
                 horizon.normalize();
                 math::geometry::direction::rotate<scalar_type,scalar_type>( m_axis, ::math::geometry::deg2rad<scalar_type>( 90 ), horizon );
                 this->m_axis[2] = 0;

                 math::geometry::direction::intersect( m_sunset, horizon, this->m_axis );

                 auto value2 =   ::math::linear::vector::distance( { F[0], F[1] }, m_sunset )
                               * ::math::linear::vector::distance( { S[0], S[1] }, m_sunset );

                 focus =   value2 - ::math::linear::vector::dot( m_sunset, m_sunset );
                 if( focus < 0 )
                  {
                   return false;
                  }
                 focus = sqrt( fabs( focus ) );
                 return true;
                }

             public:
               uv_type const& sunset()const
                {
                 return m_sunset;
                };
             private:
              uv_type m_sunset;

             public:
               ABC2D_type const& axis()const //!< principal axis
                {
                 return m_axis;
                };
             private:
              ABC2D_type m_axis;

             public:
               horizon_type const& horizon()const
                {
                 return m_horizon;
                };
             private:
              horizon_type m_horizon;
             public:
               uv_type const& center()const //!< optical center
                {
                 return m_center;
                };
             private:
              uv_type m_center;
            };

         }
       }
     }
   }
 }

#endif
