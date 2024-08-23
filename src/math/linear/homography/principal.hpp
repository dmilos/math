#ifndef Dh_math_linear_homography_principal
#define Dh_math_linear_homography_principal

// ::math::linear::homography::principal<double>

#include "../vector/structure.hpp"
#include "../vector/combine03.hpp"

#include "../matrix/invert.hpp"
#include "../matrix/transpose.hpp"
#include "../matrix/transform.hpp"
#include "../matrix/column.hpp"

#include "../homography/structure.hpp"

#include "../../geometry/direction/abc.hpp"



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
           static void process( ABC_type & axis, point_type & point, ABC_type & horizon, homography_type const& plane2display )
            { //!< exists always  // display = N(0,0,1) + O(0,0,0)
             this_type::horizon( horizon, plane2display );
             this_type::point(     point, plane2display );

             axis.A() = +horizon.B() * point[2];
             axis.B() = -horizon.A() * point[2];
             axis.C()= -( axis.A() * point[0] + axis.B() * point[1] );
            }

           void process( homography_type const& plane2display )
            { // display = N(0,0,1) + O(0,0,0)
             this_type::process( m_axis, m_point, m_horizon, plane2display );
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

           static void horizon( ABC_type & result, homography_type const&  plane2display ) //!< just wrapper for homography::horizon
            { //! display = N(0,0,1) + O(0,0,0)
             ::math::linear::homography::horizon<scalar_name>( result, plane2display );
            }

           void horizon( homography_type const&  plane2display )
            { // display = N(0,0,1) + O(0,0,0)
             return  this_type::horizon( m_horizon, plane2display );
            }

         public:
           ABC_type const& horizon()const
            {
             return m_horizon;
            }
         private:
           ABC_type m_horizon;  //!< in display coordinates

         public:
           ABC_type const& axis()const
            {
             return m_axis;
            }
         private:
           ABC_type m_axis;     //!< in display coordinates

         public:
           point_type const& point()const
            {
             return m_point;
            }
         private:
           point_type m_point;     //!< in homography coordinates
        };

     }
   }
 }

#endif
