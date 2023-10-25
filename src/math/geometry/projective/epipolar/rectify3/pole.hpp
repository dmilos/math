#ifndef math_geometry_projective_epipolar_rectify3_pole
#define math_geometry_projective_epipolar_rectify3_pole

// ::math::geometry::projective::epipolar::rectify3::pole<double>.process( left2world, right2world )
// ::math::geometry::projective::epipolar::rectify3::pole<double>.left( H, to_world )
// ::math::geometry::projective::epipolar::rectify3::pole<double>.left( H, to_world )

//#include <utility>


#include "../../camera/optical.hpp"
#include "../../../../linear/vector/vector.hpp"
#include "../../../../linear/matrix/matrix.hpp"
#include "../../../../linear/homography/structure.hpp"
#include "../../../../linear/homography/transform.hpp"
#include "../../../../linear/homography/retarget.hpp"
#include "./base.hpp"

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
         class pole
          : public ::math::geometry::projective::epipolar::rectify3::base<scalar_name>
          {
           public:
            typedef scalar_name       scalar_type;

            typedef ::math::linear::vector::structure<scalar_name,3>                      vector_type, point_type;
            typedef ::math::linear::vector::structure<scalar_name,2>                   display_type;
            typedef ::math::linear::vector::structure<scalar_name,2>                       pixel_type;
            typedef ::math::geometry::interval::structure<scalar_type,2>   interval_type;
            typedef ::math::linear::vector::point<scalar_name,3>   homogeneous_type;

            typedef ::math::linear::homography::structure< scalar_name, 2 >             homography_type;
            typedef ::math::linear::affine::structure< scalar_name, 3 >                     affine_type;
            typedef ::math::linear::matrix::structure< scalar_name, 3, 3 >                  matrix_type;
            typedef ::math::geometry::projective::camera::pinhole< scalar_name >           pinhole_type;
            typedef ::math::geometry::projective::camera::optical<scalar_name >            digital_type;
            typedef ::math::geometry::projective::camera::mobile<scalar_name >            mobile_type;

            typedef ::math::geometry::projective::epipolar::rectify3::base<scalar_name>   base_type;


            bool process( affine_type const& left2world, affine_type const& right2world )
             {
              ::math::linear::vector::subtraction( m_right, right2world.vector(), left2world.vector() );

              ::math::linear::vector::length<scalar_type>( m_right, 1 );

              ::math::linear::matrix::column( m_leftForward,   left2world.matrix(), pinhole_type::forward() );
              ::math::linear::matrix::column( m_rightForward, right2world.matrix(), pinhole_type::forward() );

              ::math::linear::vector::cross( m_leftNewUp , m_right,  m_leftForward ); ::math::linear::vector::length<scalar_type>( m_leftNewUp,  1 );
              ::math::linear::vector::cross( m_rightNewUp, m_right, m_rightForward ); ::math::linear::vector::length<scalar_type>( m_rightNewUp, 1 );

              m_declination = ::math::linear::vector::angle( m_leftNewUp, m_rightNewUp );
              m_orientation = ::math::linear::vector::orientation( m_leftNewUp, m_rightNewUp, m_right );

              return true;
             }

            bool left( homography_type & H, mobile_type const& sinister/*left*/, mobile_type const& dexter/*right*/ )
             {
              typedef ::math::geometry::projective::epipolar::pole<scalar_name > pole_type;

              vector_type right_pole;
              pole_type::left( right_pole, sinister, dexter );

              m_left_angle2torque   = + m_orientation * m_declination/2;
              m_left_angle2infinity = + atan2( right_pole[1], sqrt( right_pole[0]*right_pole[0]+right_pole[2]*right_pole[2] ) );
              m_left_angle2horizon  = - atan2( right_pole[2], right_pole[0] );

              ::math::linear::matrix::rotateX( m_left_torque,   m_left_angle2torque );
              ::math::linear::matrix::rotateZ( m_left_infinity, m_left_angle2infinity );
              ::math::linear::matrix::rotateY( m_left_horizon,  m_left_angle2horizon );

              ::math::linear::matrix::multiply( H, m_left_horizon, m_left_infinity, m_left_torque );
              this->base_type::convert( H );
              return true;
             }

            bool right( homography_type & H, mobile_type const& sinister/*left*/, mobile_type const& dexter/*right*/ )
             {
              typedef ::math::geometry::projective::epipolar::pole<scalar_name > pole_type;

              vector_type left_pole;
              pole_type::right( left_pole, sinister, dexter );

              m_right_angle2torque = - m_orientation * m_declination/2;
              m_right_angle2infinity = - atan2( left_pole[1], sqrt( left_pole[0]*left_pole[0]+left_pole[2]*left_pole[2] ) );
              m_right_angle2horizon = math::geometry::deg2rad( 180 ) - atan2( left_pole[2], left_pole[0] );

              ::math::linear::matrix::rotateX( m_right_torque,   m_right_angle2torque );
              ::math::linear::matrix::rotateZ( m_right_infinity, m_right_angle2infinity );
              ::math::linear::matrix::rotateY( m_right_horizon,  m_right_angle2horizon );

              ::math::linear::matrix::multiply( H, m_right_horizon, m_right_infinity, m_right_torque );
              this->base_type::convert( H );
              return true;
             }

            public:
              scalar_type m_orientation;
              scalar_type m_declination;

            public:
              scalar_type      m_left_angle2torque,   m_left_angle2horizon,  m_left_angle2infinity;
              homography_type  m_left_horizon, m_left_infinity, m_left_torque;

              scalar_type      m_right_angle2torque, m_right_angle2horizon, m_right_angle2infinity;
              homography_type  m_right_horizon, m_right_infinity, m_right_torque;

            public:
              vector_type m_right;
              vector_type m_leftNewUp, m_rightNewUp;

            private:
              vector_type m_leftForward;
              vector_type m_rightForward;
          };

         }
       }
     }
   }
 }

#endif
