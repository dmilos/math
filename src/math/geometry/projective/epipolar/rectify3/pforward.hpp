#ifndef math_geometry_projective_epipolar_rectify3_pforward
#define math_geometry_projective_epipolar_rectify3_pforward

// ::math::geometry::projective::epipolar::rectify3::pforward<double>.process(  left2world, right2world )


#include "../../../../linear/vector/vector.hpp"
#include "../../../../linear/matrix/structure.hpp"
#include "../../../../linear/matrix/multiply.hpp"
#include "../../../../linear/matrix/invert.hpp"
#include "../../../../linear/matrix/column.hpp"
#include "../../../../linear/matrix/tb.hpp"
#include "../../../../linear/matrix/euler.hpp"
#include "../../../../linear/matrix/transform.hpp"
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
         class pforward  //!< plane for forward motion. Expect forwar motion like positions of cameras
          : public ::math::geometry::projective::epipolar::rectify3::pbase<scalar_name>
          {
           public:
            typedef scalar_name       scalar_type;
            typedef ::math::geometry::projective::epipolar::rectify3::pbase<scalar_name>  pbase_type;

            typedef ::math::linear::vector::structure<scalar_name,3>           vector_type, point_type;
            typedef ::math::linear::matrix::structure< scalar_name, 3, 3 >                  matrix_type;
            typedef ::math::linear::affine::structure< scalar_name, 3 >                     affine_type;

            typedef ::math::geometry::projective::camera::pinhole< scalar_name >           pinhole_type;

            pforward()
             {
             }

            bool process( affine_type const& left2world, affine_type const& right2world )
             {
              auto & right = pbase_type::m_plane.x();
              auto & up    = pbase_type::m_plane.y();
              auto & origin= pbase_type::m_plane.origin();

              ::math::linear::vector::subtraction( m_forward, right2world.vector(), left2world.vector() );
              ::math::linear::vector::length<scalar_type>( m_forward, 1 );

              ::math::linear::matrix::column( m_leftForward,   left2world.matrix(), pinhole_type::forward() );
              ::math::linear::matrix::column( m_rightForward, right2world.matrix(), pinhole_type::forward() );

                auto orientation = ::math::linear::vector::dot( m_forward, m_leftForward ); 
                if( orientation < 0 ) 
                 {
                  origin = left2world.vector();
                  ::math::linear::vector::negate( m_forward );
                 }
                else
                 {
                  origin = right2world.vector();
                 }

              ::math::linear::matrix::column( m_leftRight,   left2world.matrix(), pinhole_type::right() );
              ::math::linear::matrix::column( m_rightRight, right2world.matrix(), pinhole_type::right() );

              ::math::linear::vector::addition( right, m_leftRight, m_rightRight );    ::math::linear::vector::length<scalar_type>( right, 1 );

              ::math::linear::vector::cross( up, right, m_forward );  ::math::linear::vector::length<scalar_type>( up, 1 );

              ::math::linear::vector::addition( origin, m_forward );

              return true;
             }

            private:
              vector_type m_forward;
              vector_type m_leftForward, m_leftRight;
              vector_type m_rightForward, m_rightRight;
          };

         }
       }
     }
   }
 }

#endif
