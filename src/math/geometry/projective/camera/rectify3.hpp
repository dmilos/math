#ifndef math_geometry_projective_camera_rectify
#define math_geometry_projective_camera_rectify

// ::math::geometry::projective::camera::rectify( left, right, right2left )
// ::math::geometry::projective::camera::rectify( left, right, left2world, right2world )

//#include <utility>


#include "../../../linear/homography/structure.hpp"

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {

        template < typename scalar_name >
         bool
         rectify
          (
            ::math::linear::homography::structure< scalar_type, 2 >       & left
           ,::math::linear::homography::structure< scalar_type, 2 >       & right
           ,::math::linear::affine::structure< scalar_name, 3 >      const& right2left
          )
          {
              
              
           return false;
          }

        template < typename scalar_name >
         bool
         rectify
          (
            ::math::linear::homography::structure< scalar_type, 2 >       & left
           ,::math::linear::homography::structure< scalar_type, 2 >       & right
           ,::math::linear::affine::structure< scalar_name, 3 >      const& left2world
           ,::math::linear::affine::structure< scalar_name, 3 >      const& right2world
          )
          {
           ::math::linear::affine::structure< scalar_name, 3 > world2left;
           if( false == ::math::linear::affine::invert( world2left, left2world ) )
            {
             return false;
            }

           ::math::linear::affine::structure< scalar_name, 3 > right2left;
           ::math::linear::affine::compose( right2left, world2left, right2world );
           return ::math::geometry::projective::camera::rectify( left, right, right2left );
          }

       }
     }
   }
 }

#endif
