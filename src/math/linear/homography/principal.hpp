#ifndef Dh_math_linear_homography_principal
#define Dh_math_linear_homography_principal

// ::math::geometry::homography::principal<double>

#include "../vector/structure.hpp"
#include "../vector/combine03.hpp"

#include "../matrix/invert.hpp"
#include "../matrix/transpose.hpp"
#include "../matrix/transform.hpp"
#include "../matrix/column.hpp"

#include "../homography/structure.hpp"

#include "../../geometry/direction/abc.hpp"
#include "../../geometry/direction/distance/distance.hpp"
#include "../../geometry/plane/distance.hpp"



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
       class principal //!< calculate principal axis and point.
        {
         public:
           typedef scalar_name scalar_type;
           typedef ::math::linear::homography::structure<scalar_type,2> homography_type;
           typedef ::math::linear::vector::structure<scalar_type,3> point_type;
           typedef ::math::linear::matrix::structure<double,3,3> matrix_type;
           typedef ::math::geometry::direction::ABC2D<scalar_type> ABC_type;

         public:
           bool axis( homography_type const& plane2display, scalar_type const& epsilon = 1e-8 )
            {  // display = N(0,1,0) + O(0,0,0) << TODO check and adjust to N(0,0,1)
             static matrix_type   s_rotation{ 0, -1, 0,
                                              1,  0, 0 ,
                                              0 , 0, 1 };
             m_plane2display = plane2display;
             if( false == ::math::linear::matrix::invert( m_display2plane, m_plane2display, epsilon ) )
              {
               return false;
              }

             ::math::linear::matrix::transpose( m_display2planeT, m_display2plane );
             ::math::linear::matrix::transpose( m_plane2displayT, m_plane2display );

             m_horizon.set( m_display2plane[2][0], m_display2plane[2][1], m_display2plane[2][2] );

             auto length = sqrt( m_horizon.A() * m_horizon.A()  +  m_horizon.B() * m_horizon.B() );
             if( length < epsilon )
              {
               return false;
              }

             matrix_type combined, tmp;

             ::math::linear::matrix::multiply( tmp, s_rotation, m_plane2displayT );
             ::math::linear::matrix::multiply( combined, m_display2planeT, tmp );

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

           static void point( point_type & result, homography_type const&  plane2display, scalar_type const& epsilon = 1e-8 )
            { // display = N(0,0,1) + O(0,0,0)
             point_type X, Y;
             ::math::linear::matrix::column( X, plane2display, 0 );
             ::math::linear::matrix::column( Y, plane2display, 1 );

             ::math::linear::vector::cross( result, X, Y );
            }

           void point( homography_type const&  plane2display, scalar_type const& epsilon = 1e-8 )
            { // display = N(0,0,1) + O(0,0,0)
             return  point( m_point, plane2display, epsilon );
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

         public:
           point_type const& point()const
            {
             return m_point;
            }
         private:
           point_type m_point;     //!< in screen coordinates

         private:
           homography_type m_plane2display, m_plane2displayT;
           homography_type m_display2plane, m_display2planeT;
        };

     }
   }
 }

#endif
