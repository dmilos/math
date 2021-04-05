#ifndef math_geometry_homography_opd
#define math_geometry_homography_opd

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
         ,::math::linear::homography::structure<scalar_name,2>   const& homography
        )
        {
         ::math::linear::vector::structure<scalar_name, 3> x,y,z,t;

         t = { homography[0][2], homography[2][2], -homography[1][2] };
         x = { homography[0][0], homography[2][0], -homography[1][0] };
         y = { homography[0][1], homography[2][1], -homography[1][1] };

         ::math::linear::vector::cross( z, x, y );
         ::math::linear::affine::system( affine, t, x, y, z );

         return ;
        }

     }
   }
 }

#endif
