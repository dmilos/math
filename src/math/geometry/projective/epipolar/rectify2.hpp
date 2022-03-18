#ifndef math_geometry_projective_epipolar_rectify2
#define math_geometry_projective_epipolar_rectify2

// ::math::geometry::projective::camera::rectify( left, right, right2left )
// ::math::geometry::projective::camera::rectify( left, right, left2world, right2world )


#include "../../../linear/homography/structure.hpp"

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {

        template < typename scalar_name >
         bool
         rectify
          (
            ::math::linear::homography::structure< scalar_name, 1 >       & left_param
           ,::math::linear::homography::structure< scalar_name, 1 >       & right_param
           ,::math::linear::affine::structure< scalar_name, 2 >      const& right2left
          )
          {
           static ::math::linear::vector::structure<scalar_name,2> X{1,0};

           auto const& heading   = right2left.vector();
           auto left_angle = ::math::linear::vector::angle( X, heading  ) ;
           ::math::linear::matrix::rotate( left_param, left_angle );

           ::math::linear::vector::structure< scalar_name, 2 > direction{ right2left.matrix()[0][0],right2left.matrix()[1][0] };
           auto right_angle = ::math::linear::vector::angle( direction,  heading );
           ::math::linear::matrix::rotate( right_param, right_angle );

           return true;
          }

        template < typename scalar_name >
         bool
         rectify
          (
            ::math::linear::homography::structure< scalar_name, 1 >       & left
           ,::math::linear::homography::structure< scalar_name, 1 >       & right
           ,::math::linear::affine::structure< scalar_name, 2 >      const& left2world
           ,::math::linear::affine::structure< scalar_name, 2 >      const& right2world
          )
          {
           ::math::linear::affine::structure< scalar_name, 2 > world2left;
           if( false == ::math::linear::affine::invert( world2left, left2world ) )
            {
             return false;
            }

           ::math::linear::affine::structure< scalar_name, 2 > right2left;
           ::math::linear::affine::compose( right2left, world2left, right2world );
           return ::math::geometry::projective::epipolar::rectify( left, right, right2left );
          }

       }
     }
   }
 }

#endif
