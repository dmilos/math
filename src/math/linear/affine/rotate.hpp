#ifndef Dh_math_linear_affine_rotate
 #define Dh_math_linear_affine_rotate

 // ::math::linear::affine::rotate<scalar_name>

#include <limits>

#include "./structure.hpp"
#include "./one.hpp"
#include "./compose.hpp"
#include "../matrix/rotate.hpp"
#include "../vector/negate.hpp"

 namespace math
  {
   namespace linear
    {
     namespace affine
      {

         template< typename scalar_name>
          inline
          bool
          rotate
           (
             ::math::linear::affine::structure< scalar_name, 3 >          &   result
            ,::math::linear::vector::structure< scalar_name, 3 >       const& pivot
            ,::math::linear::vector::structure< scalar_name, 3 >       const& direction
            ,                                   scalar_name            const& angle
           )
           {
            typedef ::math::linear::affine::structure< scalar_name, 3 >  affine_type;
            affine_type I_move; ::math::linear::affine::id( I_move );  ::math::linear::vector::negate( I_move.vector(), pivot );

            affine_type I_rotate; ::math::linear::affine::id( I_rotate );
            ::math::linear::matrix::rotate( I_rotate.matrix(), direction, angle );

            affine_type I_back; ::math::linear::affine::id( I_back ); I_back.vector() = pivot;

            affine_type I_tmp;
            ::math::linear::affine::compose( I_tmp, I_rotate, I_move );

            ::math::linear::affine::compose( result, I_back, I_tmp );
            return true;
           }

      }
    }
  }

#endif
