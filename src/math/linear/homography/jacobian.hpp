#ifndef Dh_math_linear_homography_jacobian
#define Dh_math_linear_homography_jacobian

// math::linear::homography::jacobian( result, H, point );

#include "./structure.hpp"
#include "../matrix/structure.hpp"
#include "../matrix/scale.hpp"




namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template<  typename scalar_name >
       bool jacobian
        (
          ::math::linear::matrix::structure<  scalar_name, 3, 3 >             & result
         ,::math::linear::homography::structure<  scalar_name, 3 >    const& H
         ,::math::linear::vector::structure<scalar_name,3>            const& point
         , scalar_name const& epsilon = 1e-6
        )
        { //! H can be multiply bu non zero factor

         auto const& X = point[0];
         auto const& Y = point[1];
         auto const& Z = point[2];

         // ::math::linear::matrix( d, H, I_point4(X,Y,Z,1) );

         scalar_name d0 = H[0][0] * X + H[0][1] * Y + H[0][2] * Z + H[0][3];
         scalar_name d1 = H[1][0] * X + H[1][1] * Y + H[1][2] * Z + H[1][3];
         scalar_name d2 = H[2][0] * X + H[2][1] * Y + H[2][2] * Z + H[2][3];
         scalar_name d3 = H[3][0] * X + H[3][1] * Y + H[3][2] * Z + H[3][3];

         result[0][0] = ( d3 * H[0][0] - H[3][0] * d0 );
         result[0][1] = ( d3 * H[0][1] - H[3][1] * d0 );
         result[0][2] = ( d3 * H[0][2] - H[3][2] * d0 );

         result[1][0] = ( d3 * H[1][0] - H[3][0] * d1 );
         result[1][1] = ( d3 * H[1][1] - H[3][1] * d1 );
         result[1][2] = ( d3 * H[1][2] - H[3][2] * d1 );

         result[2][0] = ( d3 * H[2][0] - H[3][0] * d2 );
         result[2][1] = ( d3 * H[2][1] - H[3][1] * d2 );
         result[2][2] = ( d3 * H[2][2] - H[3][2] * d2 );

         return true;
        }

     }
   }
 }

#endif