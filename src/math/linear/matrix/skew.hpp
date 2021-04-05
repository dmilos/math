#ifndef math_linear_matrix_skew
 #define math_linear_matrix_skew

// math::linear::matrix::skew( result, angle )
// math::linear::matrix::skew( result, direction, angle, epsilon )

#include "../vector/structure.hpp"
#include "./structure.hpp"


 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name>
        inline
        void
        skew
         (
           ::math::linear::matrix::structure<scalar_name,2,2>      & result
          ,scalar_name                                        const& angle_x
          ,scalar_name                                        const& angle_y
         )
         {

          /*
          ^
          | angle_y /       /
          |       /       /
          |     /       /
          |   /      /
          |       / angle_x
          +--------->
          */
          result[0][0] = cos( angle_x ); result[ 0 ][ 1 ] = sin( angle_x );
          result[1][0] = cos( angle_y ); result[ 1 ][ 1 ] = sin( angle_y );
         }


     }
   }
 }

#endif