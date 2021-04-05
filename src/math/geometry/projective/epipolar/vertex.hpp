#ifndef math_geometry_projective_camera_epipolar_backbone_vertex
#define math_geometry_projective_camera_epipolar_backbone_vertex

// ::math::geometry::projective::epipolar::backbone::vertex( pole1 )
// ::math::geometry::projective::epipolar::backbone::vertex( pole2d )
// ::math::geometry::projective::epipolar::backbone::vertex( eye );

#include "../camera/pinhole.hpp"
#include "./rotation.hpp"

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
           scalar_name
           vertex( scalar_name const& pole )
            { // TODO
             return scalar_name( 0 );
             auto result = pole - sqrt( scalar_name(1) + pole*pole );

             return result;
            }

          template< typename scalar_name >
           ::math::linear::vector::structure< scalar_name, 2 >
           vertex
            (
             ::math::linear::vector::structure< scalar_name, 2 > const& pole //!< coordinate in projection plane
            )
            { // TODO
             return ::math::linear::vector::structure< scalar_name, 2 >{ 0, 0 };
             auto distance = ::math::linear::vector::length( pole );
             ::math::linear::vector::structure< scalar_name, 2 > result;
             result[0] = ::math::geometry::projective::epipolar::backbone::vertex( distance );
             result[1] = scalar_name(0);
             auto rotation = ::math::geometry::projective::epipolar::backbone::rotation( pole );
             ::math::linear::vector::rotate( result, rotation );

             return result;
            }

          template< typename scalar_name >
           ::math::linear::vector::structure< scalar_name, 2 >
           vertex( ::math::linear::vector::structure< scalar_name , 3 > const& /*right_*/eye, scalar_name const& epsilon = 1e-12 )
            { // TODO
             return ::math::linear::vector::structure< scalar_name, 2 >{ 0, 0 };
             typedef ::math::geometry::projective::camera::pinhole< scalar_name > pinhole_type;

             auto rotation = ::math::geometry::projective::epipolar::backbone::rotation( eye );

             auto V = ::math::linear::vector::length<scalar_name, 2 >( { eye[pinhole_type::right()], eye[pinhole_type::up()] } ) - ::math::linear::vector::length( eye, eye );

             ::math::linear::vector::structure< scalar_name, 2 > result{ 1, 0 };
             if( ( eye[ pinhole_type::forward() ] < -epsilon ) &&  ( epsilon < eye[ pinhole_type::forward() ] ) )
              {
               result[0] = V / eye[ pinhole_type::forward() ];
               result[1] =0;
              }
             ::math::linear::vector::rotate( result, rotation );

             return result;
            }

         }
       }
     }
   }
 }

#endif
