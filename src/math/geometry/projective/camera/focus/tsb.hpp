#ifndef math_geometry_projective_camera_focus_tsb
#define math_geometry_projective_camera_focus_tsb

// ::math::geometry::projective::camera::focus::tsb().process( F, a00, aX, aY, a11 )

#include "../../../../geometry/direction/horizon.hpp"
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
           class tsb
            {// T.N. Tan, G.D. Sulliven, K.D. Baker
             public:
               typedef scalar_name   scalar_type;

               typedef ::math::linear::vector::structure<scalar_name,2>         uv_type;
               typedef ::math::geometry::direction::horizon<scalar_name>   horizon_type;

             public:
               tsb()
                {
                }

             public:
             // four points on some quad
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

                 auto F = m_horizon.first();  F[0] /= F[2]; F[1] /= F[2]; F[2] /= F[2];
                 auto S = m_horizon.second(); S[0] /= S[2]; S[1] /= S[2]; S[2] /= S[2];

                 focus =  fabs ( F[0] * F[1] + S[0] * S[1] );
                 if( focus < 0 )
                  {
                   return false;
                  }
                 focus = sqrt( fabs( focus ) );
                 return true;
                }

             public:
               horizon_type const& horizon()const
                {
                 return m_horizon;
                };
             private:
              horizon_type m_horizon;
            };

         }
       }
     }
   }
 }

#endif
