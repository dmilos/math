#ifndef Dh_math_linear_homography_principal
#define Dh_math_linear_homography_principal

// ::math::geometry::homography::principal<double>

#include "../vector/structure.hpp"

#include "../matrix/invert.hpp"
#include "../matrix/transpose.hpp"
#include "../matrix/transform.hpp"

#include "../homography/structure.hpp"

#include "../../geometry/direction/abc.hpp"



namespace math
 {
  namespace linear
   {
    namespace homography
     {

      /*
       "Camera Calibration using Vanishing Points", Paul Beardsley David Murray, BMVC 1992
      */
      template< typename scalar_name >
       class principal //!< calculate principal axis.
        {
         public:
           typedef scalar_name scalar_type;
           typedef ::math::linear::homography::structure<scalar_type,2> homography_type;
           typedef ::math::linear::matrix::structure<double,3,3> matrix_type;
           typedef ::math::geometry::direction::ABC2D<scalar_type> ABC_type;

         public:
           bool process( homography_type const&  space2display, scalar_type const& epsilon = 1e-8 )
            {
             static matrix_type   s_rotation{ 0, -1, 0, 1, 0, 0 , 0 , 0, 1 };
             m_space2display = space2display;
             if( false == ::math::linear::matrix::invert( m_display2space, m_space2display, epsilon ) )
              {
               return false;
              }

             ::math::linear::matrix::transpose( m_display2spaceT, m_display2space );
             ::math::linear::matrix::transpose( m_space2displayT, m_space2display );

             m_horizon.set( m_display2space[2][0], m_display2space[2][1], m_display2space[2][2] );

             auto length = sqrt( m_horizon.A() * m_horizon.A()  +  m_horizon.B() * m_horizon.B() );
             if( length < epsilon )
              {
               return false;
              }

             matrix_type combined, tmp;

             ::math::linear::matrix::multiply( tmp, s_rotation, m_space2displayT );
             ::math::linear::matrix::multiply( combined, m_display2spaceT, tmp );

             ::math::linear::vector::structure<scalar_name,3> constant;
             ::math::linear::matrix::transform( constant, combined, m_horizon.array() );

              auto A = constant[0] * m_horizon.A();
              auto B = constant[1] * m_horizon.B();

              auto D = combined[0][2] * m_horizon.A();
              auto E = combined[1][2] * m_horizon.B();

              auto alpha = -( A + B )/ ( D + E );

             ::math::linear::matrix::transform( m_axis.array(), combined, { m_horizon.A(), m_horizon.B(), m_horizon.C() + alpha } );
             return true;
            }

         public:
           ABC_type const& horizon()const
            {
             return m_horizon;
            }
         private:
           ABC_type m_horizon;  //!< in screen coordinates
         public:
           ABC_type const& axis()const
            {
             return m_axis;
            }
         private:
           ABC_type m_axis;     //!< in screen coordinates
         private:
           homography_type m_space2display, m_space2displayT;
           homography_type m_display2space, m_display2spaceT;
        };

     }
   }
 }

#endif
