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
          ::math::linear::affine::structure< scalar_name, 3 >         & affine
         ,::math::linear::homography::structure<scalar_name,2>   const& display2spaces //!< TODO check this
        )
        { //  TODO need pinhole camera::forward, up, right. move to camera
         ::math::linear::vector::structure<scalar_name, 3> x,y,z,t;

         t = { display2spaces[0][2], display2spaces[2][2], -display2spaces[1][2] };
         x = { display2spaces[0][0], display2spaces[2][0], -display2spaces[1][0] };
         y = { display2spaces[0][1], display2spaces[2][1], -display2spaces[1][1] };

         ::math::linear::vector::cross( z, x, y );
         ::math::linear::affine::system( affine, t, x, y, z );

         return ;
        }

     }
   }
 }

#endif
