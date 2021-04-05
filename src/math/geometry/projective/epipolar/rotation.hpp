#ifndef math_geometry_projective_camera_epipolar_backbone_rotation
#define math_geometry_projective_camera_epipolar_backbone_rotation

// ::math::geometry::projective::epipolar::backbone::rotation( pole )
// ::math::geometry::projective::epipolar::backbone::rotation( eye );

#include "../camera/pinhole.hpp"

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {
        namespace backbone
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
             scalar_name length =  eye[ pinhole_type::up()    ] * eye[ pinhole_type::up()    ]
                                 + eye[ pinhole_type::right() ] * eye[ pinhole_type::right() ];
             if( length < epsilon )
              {
               return scalar_name( 0 );
              }
             return atan2( eye[ pinhole_type::up() ], eye[ pinhole_type::right() ] );
            }

         }
       }
     }
   }
 }
#endif
