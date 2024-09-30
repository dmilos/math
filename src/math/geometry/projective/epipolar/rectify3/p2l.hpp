#ifndef math_geometry_projective_epipolar_rectify3_p2l
#define math_geometry_projective_epipolar_rectify3_p2l

// ::math::geometry::projective::epipolar::rectify3::p2l<double>.process(  left2world, right2world )


#include "../../../../linear/vector/vector.hpp"
#include "../../../../linear/matrix/structure.hpp"
#include "../../../../linear/matrix/column.hpp"
#include "../../../../linear/affine/structure.hpp"
#include "../../../../linear/homography/structure.hpp"
#include "./pbase.hpp"

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {
        namespace rectify3
         {

        template < typename scalar_name >
         class p2l    //!< Project on to left plane camera
          : public ::math::geometry::projective::epipolar::rectify3::pbase<scalar_name>
          {
           public:
            typedef scalar_name       scalar_type;

            typedef ::math::geometry::projective::epipolar::rectify3::pbase<scalar_name>  pbase_type;

            typedef ::math::linear::vector::structure<scalar_name,3>           vector_type, point_type;
            typedef ::math::linear::affine::structure< scalar_name, 3 >                     affine_type;

            typedef ::math::geometry::projective::camera::pinhole< scalar_name >           pinhole_type;

            p2l()
             {
             }

            bool process( affine_type const& left2world, affine_type const& right2world )
             {
              auto & right  = pbase_type::m_plane.x();
              auto & up     = pbase_type::m_plane.y();
              auto & origin = pbase_type::m_plane.origin();

              origin = left2world.vector();

              ::math::linear::matrix::column(   m_rightForward,  right2world.matrix(), pinhole_type::forward() );
              ::math::linear::vector::addition( m_spikeWorld, m_rightForward, right2world.vector() );
              ::math::linear::affine::invert( m_left2local, left2world );
              ::math::linear::affine::transform( m_spikeLocal, m_left2local, m_spikeWorld );
              m_bound = m_spikeLocal[ pinhole_type::forward() ];
              ::math::linear::matrix::column(   m_leftForward,  left2world.matrix(), pinhole_type::forward() );
              if( 1.0 < m_bound )
               {
                ::math::linear::vector::combine( origin, m_bound, m_leftForward );
               }
              else
               {
                ::math::linear::vector::addition( origin, m_leftForward );
               }

              ::math::linear::matrix::column( right,   left2world.matrix(), pinhole_type::right() );
              ::math::linear::matrix::column( up   ,   left2world.matrix(), pinhole_type::up() );

              return true;
             }
            private:
              scalar_type m_bound;
              affine_type m_left2local;
              point_type m_spikeWorld, m_spikeLocal;
              vector_type m_leftForward;
              vector_type m_rightForward;
          };

         }
       }
     }
   }
 }

#endif
