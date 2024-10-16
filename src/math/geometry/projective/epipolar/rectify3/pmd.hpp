#ifndef math_geometry_projective_epipolar_rectify3_pmd
#define math_geometry_projective_epipolar_rectify3_pmd

// ::math::geometry::projective::epipolar::rectify3::pmd<double>.process(  left2world, right2world )


#include "../../../../linear/vector/vector.hpp"
#include "../../../../linear/matrix/structure.hpp"
#include "../../../../linear/matrix/multiply.hpp"
#include "../../../../linear/matrix/invert.hpp"
#include "../../../../linear/matrix/column.hpp"
#include "../../../../linear/matrix/tb.hpp"
#include "../../../../linear/matrix/euler.hpp"
#include "../../../../linear/matrix/transform.hpp"
#include "../../../../linear/homography/structure.hpp"

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
         class pmd    //!<  calculate Minimal common Plane that give us minimal distortion. NOTE: quasi-rectification
          : public ::math::geometry::projective::epipolar::rectify3::pbase<scalar_name>
          {
           public:
             typedef scalar_name       scalar_type;
             typedef ::math::geometry::projective::epipolar::rectify3::pbase<scalar_name>  pbase_type;

             typedef ::math::linear::vector::structure<scalar_name,3>           vector_type, point_type;
             typedef ::math::linear::matrix::structure< scalar_name, 3, 3 >                  matrix_type;
             typedef ::math::linear::affine::structure< scalar_name, 3 >                     affine_type;

             typedef ::math::geometry::plane::parametric3d<scalar_name>                    plane_type;
             typedef ::math::geometry::projective::camera::pinhole< scalar_name >           pinhole_type;

           public:
             pmd()
              {
               m_epsilon = 1e-5;
              }

             bool process( affine_type const& left2world, affine_type const& right2world )
              {
               ::math::linear::matrix::column( m_left[0], left2world.matrix(), pinhole_type::right() );
               ::math::linear::matrix::column( m_left[1], left2world.matrix(), pinhole_type::forward() );
               ::math::linear::matrix::column( m_left[2], left2world.matrix(), pinhole_type::up() );

               ::math::linear::matrix::column( m_right[0], right2world.matrix(), pinhole_type::right() );
               ::math::linear::matrix::column( m_right[1], right2world.matrix(), pinhole_type::forward() );
               ::math::linear::matrix::column( m_right[2], right2world.matrix(), pinhole_type::up() );

               for( int iteration=0; iteration < 3; ++iteration )
               {
                auto x = ::math::linear::vector::dot( m_left[0], m_right[0] );         x = ::math::function::ramp<scalar_name>( x, -1, + 1 );
                auto aX = acos( x );x =  ( 0 < x ? fabs( x - 1 ) : fabs( x + 1 ) );
                auto y = ::math::linear::vector::dot( m_left[1], m_right[1] );         y = ::math::function::ramp<scalar_name>( y, -1, + 1 );
                auto aY = acos( y ); y =  ( 0 < y ? fabs( y - 1 ) : fabs( y + 1 ) );
                auto z = ::math::linear::vector::dot( m_left[2], m_right[2] );         z = ::math::function::ramp<scalar_name>( z, -1, + 1 );
                auto aZ = acos( z ); z =  ( 0 < z ? fabs( z - 1 ) : fabs( z + 1 ) );

                int axis = -1;
                auto v = scalar_name(-1);
                if( false == ::math::geometry::interval::in( x, -m_epsilon, +m_epsilon ) )             { axis = 0; v = x; }
                if( false == ::math::geometry::interval::in( y, -m_epsilon, +m_epsilon ) ) if( v < y  ){ axis = 1; v = y; }
                if( false == ::math::geometry::interval::in( z, -m_epsilon, +m_epsilon ) ) if( v < z  ){ axis = 2; v = z; }

                vector_type rotation;
                if( -1 == axis ) break;

                scalar_name angle;
                switch( axis )
                 {
                  case( 0 ): ::math::linear::vector::cross( rotation, m_left[0], m_right[0] ); angle = aX; break;
                  case( 1 ): ::math::linear::vector::cross( rotation, m_left[1], m_right[1] ); angle = aY; break;
                  case( 2 ): ::math::linear::vector::cross( rotation, m_left[2], m_right[2] ); angle = aZ; break;
                 }
                auto l = ::math::linear::vector::length( rotation );
                if( true == ::math::geometry::interval::in( l, -m_epsilon, +m_epsilon ) ) break;

                ::math::linear::vector::rotateA( m_tmp, m_left[0], rotation, -angle/2 ); m_left[0] = m_tmp;
                ::math::linear::vector::rotateA( m_tmp, m_left[1], rotation, -angle/2 ); m_left[1] = m_tmp;
                ::math::linear::vector::rotateA( m_tmp, m_left[2], rotation, -angle/2 ); m_left[2] = m_tmp;

                ::math::linear::vector::rotateA( m_tmp, m_right[0], rotation, +angle/2 ); m_right[0] = m_tmp;
                ::math::linear::vector::rotateA( m_tmp, m_right[1], rotation, +angle/2 ); m_right[1] = m_tmp;
                ::math::linear::vector::rotateA( m_tmp, m_right[2], rotation, +angle/2 ); m_right[2] = m_tmp;
               }

               pbase_type::m_plane.x() = m_left[0];
               pbase_type::m_plane.y() = m_left[2];

               ::math::linear::vector::subtraction(  m_heading, right2world.vector(), left2world.vector() );

               auto orientation = ::math::linear::vector::dot( m_heading, m_left[1] );
               if( 0 < orientation )
                {
                 ::math::linear::vector::addition(  pbase_type::m_plane.origin(), m_right[1], right2world.vector() );
                }
               else
                {
                 ::math::linear::vector::addition(  pbase_type::m_plane.origin(), m_left[1], left2world.vector() );
                }

               return true;
              }

           public:
             scalar_name m_epsilon;
             std::array< vector_type, 3 > m_left;
             std::array< vector_type, 3 > m_right;
             vector_type  m_tmp, m_heading;

          };

         }
       }
     }
   }
 }

#endif
