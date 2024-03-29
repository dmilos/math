#ifndef math_geometry_projective_camera_epipolar_column_rotation
#define math_geometry_projective_camera_epipolar_column_rotation

// ::math::geometry::projective::epipolar::column::rotation( pole )
// ::math::geometry::projective::epipolar::column::rotation( eye );

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
           scalar_name rotation( ::math::linear::vector::structure< scalar_name, 2 > const& pole, scalar_name const& epsilon = 1e-8 )
            {
             scalar_name length =  pole[ 0 ] * pole[ 0 ]
                                 + pole[ 1 ] * pole[ 1 ];
             if( length < epsilon )
              {
               return scalar_name( 0 );
              }
             return atan2( pole[1], pole[0] );
            }

          template< typename scalar_name >
           scalar_name rotation( ::math::linear::vector::structure< scalar_name , 3 > const& /*right_*/eye, scalar_name const& epsilon = 1e-8 )
            {
             typedef ::math::geometry::projective::camera::pinhole< scalar_name > pinhole_type;
             typedef ::math::linear::vector::structure< scalar_name, 2 > point2d_type;

             return  ::math::geometry::projective::epipolar::column::rotation( point2d_type{ eye[ pinhole_type::right() ], eye[ pinhole_type::up() ] }, epsilon );
            }

         }
       }
     }
   }
 }
#endif
