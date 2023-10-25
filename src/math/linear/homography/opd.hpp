#ifndef Dh_math_linear_homography_opd
#define Dh_math_linear_homography_opd

 // ::math::linear::homography::opd( affine, homography )

// Object pose detection from given homography

#include "../vector/cross.hpp"
#include "../affine/structure.hpp"
#include "../affine/system.hpp"
#include "./structure.hpp"




namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template<  typename scalar_name >
       void opd
        (
          ::math::linear::affine::structure< scalar_name, 3 >         & plane2world   //< ! world is NOT display
         ,::math::linear::homography::structure<scalar_name,2>   const& plane2display
        ) //! WARINING Plane is not unique. 
          //! WARINING Normal is not unit.
        {
         ::math::linear::vector::structure< scalar_name, 3 > X; ::math::linear::matrix::column( X, plane2display, 0 );
         ::math::linear::vector::structure< scalar_name, 3 > Y; ::math::linear::matrix::column( Y, plane2display, 1 );
         ::math::linear::vector::structure< scalar_name, 3 > T; ::math::linear::matrix::column( T, plane2display, 2 );
         ::math::linear::vector::structure< scalar_name, 3 > Z; ::math::linear::vector::cross( Z, X, Y );

         ::math::linear::affine::system( plane2world, T, X, Y, Z );
        }

     }
   }
 }

#endif
