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

      template< typename scalar_name >
       class principal //!< calculate principal axis and point.
        {
         public:
           typedef scalar_name scalar_type;
           typedef ::math::linear::homography::structure<scalar_type,2> homography_type;
           typedef ::math::linear::vector::structure<scalar_type,3> point_type;
           typedef ::math::linear::matrix::structure<double,3,3> matrix_type;
           typedef ::math::geometry::direction::ABC2D<scalar_type> ABC_type;

           typedef ::math::linear::homography::principal<scalar_type> this_type;

         public:
           ABC_type const& axis( homography_type const& plane2display )
            { //!< exists always  // display = N(0,0,1) + O(0,0,0)
             ::math::linear::homography::horizon_invert<scalar_name>( m_horizon, plane2display );
             this_type::point( m_point, plane2display );

             m_axis.A() = +m_horizon.B();
             m_axis.B() = -m_horizon.A();
             m_axis.A() *= m_point[2];
             m_axis.B() *= m_point[2];
             m_axis.C( { m_point[0], m_point[1] } );
             return m_axis;
            }

           static void point( point_type & result, homography_type const&  plane2display )
            { //! display = N(0,0,1) + O(0,0,0)
             point_type X, Y;
             ::math::linear::matrix::column( X, plane2display, 0 );
             ::math::linear::matrix::column( Y, plane2display, 1 );

             ::math::linear::vector::cross( result, X, Y );
            }

           void point( homography_type const&  plane2display )
            { // display = N(0,0,1) + O(0,0,0)
             return  this_type::point( m_point, plane2display );
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
           point_type m_point;     //!< in homography coordinates

         private:
           homography_type m_plane2display, m_plane2displayT;
           homography_type m_display2plane, m_display2planeT;
        };

     }
   }
 }

#endif
