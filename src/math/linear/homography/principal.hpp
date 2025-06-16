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
       class principal //!< calculate principal axis.
        {
         public:
           typedef scalar_name scalar_type;
           typedef ::math::linear::vector::structure<scalar_type,3> point_type;
           typedef ::math::linear::matrix::structure<double,3,3> matrix_type;
           typedef ::math::linear::homography::structure<scalar_type,2> homography_type;
           typedef ::math::geometry::direction::ABC2D<scalar_type> ABC_type;

           typedef ::math::linear::homography::principal<scalar_type> this_type;

         public:
           static void axis( ABC_type & direction, homography_type const& plane2display )
            { //!< exists always  // display = irrelevant, can be image pixels
             auto const& H = plane2display;   
       
             auto const& h1 = H[0][0]; auto const& h2 = H[0][1]; auto const& h3 = H[0][2]; 
             auto const& h4 = H[1][0]; auto const& h5 = H[1][1]; auto const& h6 = H[1][2]; 
             auto const& h7 = H[2][0]; auto const& h8 = H[2][1]; auto const& h9 = H[2][2]; 
             auto denominator = h7 *h7 + h8*h8;

             direction.A() = -h1 * h8 + h2*h7; direction.A() *= denominator;
             direction.B() = -h4 * h8 + h5*h7; direction.B() *= denominator;

             direction.C()  = ( h2*h2 + h5*h5 - h1*h1 - h4*h4 ) * h7 * h8;
             direction.C() += ( h1*h2 + h4*h5 ) * ( h7*h7 - h8*h8 );
             direction.C()  = -direction.C();
            }

           void process( homography_type const& plane2display )
            { // display = N(0,0,1) + O(0,0,0)
             this_type::process( m_axis, plane2display );
            }

         public:
           ABC_type const& axis()const
            {
             return m_axis;
            }
         private:
           ABC_type m_axis;     //!< in display coordinates
        };

     }
   }
 }

#endif
