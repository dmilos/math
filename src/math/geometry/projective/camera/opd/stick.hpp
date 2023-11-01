#ifndef math_geometry_projective_camera_opd_stick
#define math_geometry_projective_camera_opd_stick

// ::math::geometry::projective::camera::opd::stick( center, screen, length, normal )

#include "../../../../linear/vector/structure.hpp"
#include "../../../../geometry/plane/horizon.hpp"
#include "../../../../linear/affine/affine.hpp"


namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {
        namespace opd
         {

          template < typename scalar_name >
           class stick
            {
             public:
               typedef scalar_name scalar_type;
               typedef ::math::linear::vector::structure<scalar_name,2>  screen_type;
               typedef ::math::linear::vector::structure<scalar_name,3>  vector_type, vector3d_type, point_type;
               typedef ::math::linear::affine::structure< scalar_name, 3 >           affine_type;

               typedef std::pair<screen_type,screen_type> pair_type;
               typedef ::math::geometry::projective::camera::pinhole< scalar_name >  pinhole_type;

               bool process( point_type & space, pair_type const& screen_pair, scalar_name const& length, vector_type const& normal )
                 {
                  if( false == this->factor( screen_pair, length, normal ) )
                   {
                    return false;
                   }
                  reposition( space, screen_pair.first );
                  return true;
                 }

               bool factor( pair_type const& screen_pair, scalar_name const& length, vector_type const& normal )
                {
                 m_dirX = pinhole_type::reproject( screen_pair.first );
                 auto nx = math::linear::vector::dot( normal, m_dirX );
                 auto xx = math::linear::vector::dot( m_dirX, m_dirX );

                 m_dirY = pinhole_type::reproject( screen_pair.second );
                 auto ny = math::linear::vector::dot( normal, m_dirY );
                 auto yy = math::linear::vector::dot( m_dirY, m_dirY );

                 auto xy = math::linear::vector::dot( m_dirX, m_dirY );

                 auto A = xx - scalar_type(2) * xy * nx / ny + (nx*nx) * yy/(ny*ny);
                 auto Ai = (ny*ny) * xx - scalar_type(2) * xy * nx * ny + (nx*nx) * yy;

                 m_factor = length*sqrt( ny * ny / Ai );

                 return true;
                }

               void reposition( point_type  & space, screen_type const& screen )
                {  //! NOTE: Only first point can be repositioned
                 space = pinhole_type::reproject( screen );
                 ::math::linear::vector::scale( space, m_factor );
                }

             public:
               scalar_name const& factor()const&
                {
                 return m_factor;
                }
             private:
               scalar_name m_factor;
               point_type m_dirX;
               point_type m_dirY;
             };

         }
       }
     }
   }
 }

#endif
