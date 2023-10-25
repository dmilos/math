#ifndef math_geometry_projective_epipolar_rectify3_system
#define math_geometry_projective_epipolar_rectify3_system

// ::math::geometry::projective::epipolar::rectify3::system<double>.system( system, left2world, right2world )

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
         class system
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
            typedef ::math::geometry::projective::camera::optical<scalar_name >            optical_type,digital_type;
            typedef ::math::geometry::projective::camera::mobile<scalar_name >            mobile_type;

            typedef ::math::geometry::projective::epipolar::rectify3::base<scalar_name>   base_type;

            bool process( affine_type const& left2world, affine_type const& right2world )
             {
              ::math::linear::vector::subtraction( m_right, right2world.vector(), left2world.vector() );
              ::math::linear::vector::convex( m_system.vector(), 0.5, left2world.vector(),  right2world.vector() );

              ::math::linear::vector::length<scalar_type>( m_right, 1 );

              ::math::linear::matrix::column( m_leftForward,     left2world.matrix(), pinhole_type::forward() );
              ::math::linear::matrix::column( m_leftUp,          left2world.matrix(), pinhole_type::up()      );
              ::math::linear::matrix::column( m_leftRight,       left2world.matrix(), pinhole_type::right()   );
              ::math::linear::matrix::column( m_rightForward,   right2world.matrix(), pinhole_type::forward() );
              ::math::linear::matrix::column( m_rightUp,        right2world.matrix(), pinhole_type::up()      );
              ::math::linear::matrix::column( m_rightRight,     right2world.matrix(), pinhole_type::right()   );

              ::math::linear::vector::cross( m_leftNewUp , m_right,  m_leftForward ); ::math::linear::vector::length<scalar_type>( m_leftNewUp,  1 );
              ::math::linear::vector::cross( m_rightNewUp, m_right, m_rightForward ); ::math::linear::vector::length<scalar_type>( m_rightNewUp, 1 );
              ::math::linear::vector::addition( m_up, m_leftNewUp, m_rightNewUp );    ::math::linear::vector::length<scalar_type>( m_up,         1 );

              ::math::linear::vector::cross( m_forward, m_up, m_right );
              ::math::linear::vector::length<scalar_type>( m_forward, 1 );

              ::math::linear::matrix::column( m_system.matrix(), pinhole_type::right()   ,  m_right     );
              ::math::linear::matrix::column( m_system.matrix(), pinhole_type::forward() ,  m_forward   );
              ::math::linear::matrix::column( m_system.matrix(), pinhole_type::up()      ,  m_up        );

              m_declination = ::math::linear::vector::angle( m_leftNewUp, m_rightNewUp );
              m_orientation = ::math::linear::vector::orientation(  m_leftNewUp, m_rightNewUp, m_right );
              m_skewL = ::math::linear::vector::angle( m_leftForward,  m_right ) - ::math::geometry::deg2rad<scalar_type>( 90 );
              m_skewR = ::math::linear::vector::angle( m_rightForward, m_right ) - ::math::geometry::deg2rad<scalar_type>( 90 );

              return true;
             }

            public:
              affine_type const& affine()const&{ return m_system; }
            private:
              affine_type m_system;

            public:
              scalar_type m_orientation;
              scalar_type m_declination;
              scalar_type m_skewL, m_skewR;

            public:
              vector_type m_right;
              vector_type m_up;
              vector_type m_forward;
              vector_type m_leftNewUp, m_rightNewUp;

            private:
              vector_type m_leftUp,  m_leftForward,  m_leftRight;
              vector_type m_rightUp, m_rightForward, m_rightRight;
          };

         }
       }
     }
   }
 }

#endif
