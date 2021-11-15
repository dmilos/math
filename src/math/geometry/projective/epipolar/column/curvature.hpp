#ifndef math_geometry_projective_camera_epipolar_curvature
#define math_geometry_projective_camera_epipolar_curvature

// ::math::geometry::projective::epipolar::column::curvature( rotation, & radius, pole )
// ::math::geometry::projective::epipolar::column::curvature( rotation, curvature, /*right_*/eye );

#include "../../camera/pinhole.hpp"

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {
        namespace column
         {

          template< typename scalar_name >
           scalar_name curvature( ::math::linear::vector::structure< scalar_name, 2 > const& pole )
            { // TODO define this property
             auto result = sqrt( scalar_name(1) + ::math::linear::vector::dot( pole, pole ) );
             return result;
            }

          template< typename scalar_name >
           scalar_name curvature( ::math::linear::vector::structure< scalar_name , 3 > const& /*right_*/eye , scalar_name const& epsilon = 1e-8 )
            {// TODO define this property
             typedef ::math::geometry::projective::camera::pinhole< scalar_name > pinhole_type;
             auto length = ::math::linear::vector::length( eye );
             if( length < epsilon )
              {
               return 0;
              }
             auto result = eye[ pinhole_type::forward() ] / length;
             return result;
            }

         }
       }
     }
   }
 }
#endif
