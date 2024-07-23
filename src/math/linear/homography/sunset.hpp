#ifndef Dh_math_linear_homography_sunset
#define Dh_math_linear_homography_sunset

// ::math::linear::homography::sunset<double>

#include "../vector/structure.hpp"
#include "../homography/structure.hpp"


namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template< typename scalar_name >
       void sunset
        ( 
          ::math::linear::vector::structure<scalar_type,3>          & point
         ,::math::linear::homography::structure<scalar_type,2> const& plane2display 
        )
        { // display = N(0,0,1) + O(0,0,0)
         ::math::geometry::direction::ABC2D<scalar_type> horizon;
         ::math::linear::homography::horizon<scalar_type>( horizon, plane2display );

         auto const& A = horizon.A();
         auto const& B = horizon.B();
         auto const& C = horizon.C();

         point[ 0 ] = ( 0 - C * A );
         point[ 1 ] = -( 0 - (-B) * C );
         point[ 2 ] = A*A + B*B;
        }

     }
   }
 }

#endif
