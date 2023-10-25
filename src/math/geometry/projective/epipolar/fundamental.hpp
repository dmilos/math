#ifndef math_geometry_projective_camera_epipolar_fundamental
#define math_geometry_projective_camera_epipolar_fundamental

// ::math::geometry::projective::epipolar::fundamental<scalar>::process( matrix, sinister, dexter );
// ::math::geometry::projective::epipolar::fundamental<scalar>::process( direction, matrix, point2d );

#include "../camera/pinhole.hpp"
#include "../../../linear/matrix/load.hpp"
#include "../../../linear/matrix/cross.hpp"
#include "../../../linear/affine/affine.hpp"
#include "../../../geometry/direction/abc.hpp"

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {

        template< typename scalar_name >
         class fundamental
           {
            public:
              typedef scalar_name scalar_type;
              typedef ::math::linear::vector::structure< scalar_name, 2 >                    uv_type;
              typedef ::math::linear::vector::structure< scalar_name, 3 >                 coord_type;
              typedef ::math::geometry::direction::ABC2D<scalar_name >                direction_type;
              typedef ::math::linear::affine::structure< scalar_name, 3 >                affine_type;
              typedef ::math::linear::homography::structure< scalar_name, 2 >        homography_type;

              typedef ::math::geometry::projective::camera::pinhole< scalar_name >      pinhole_type;

            public:
              static void process
               (
                 homography_type          & left2right
                ,affine_type         const& world_to_right
               )    //it is assume that  left_to_world is ID
               {
                auto const FORWARD = pinhole_type::forward();
                auto const RIGHT   = pinhole_type::right();
                auto const UP      = pinhole_type::up();

                coord_type A0y = world_to_right[0]; ::math::linear::vector::scale( A0y, world_to_right.vector()[FORWARD] );
                coord_type A0z = world_to_right[0]; ::math::linear::vector::scale( A0z, world_to_right.vector()[UP] );

                coord_type A1x = world_to_right[1]; ::math::linear::vector::scale( A1x, world_to_right.vector()[RIGHT] );
                coord_type A1z = world_to_right[1]; ::math::linear::vector::scale( A1z, world_to_right.vector()[UP] );

                coord_type A2x = world_to_right[2]; ::math::linear::vector::scale( A2x, world_to_right.vector()[RIGHT] );
                coord_type A2y = world_to_right[2]; ::math::linear::vector::scale( A2y, world_to_right.vector()[FORWARD] );

                coord_type A0;  ::math::linear::vector::subtraction( A0, A2y, A1z );
                coord_type A1;  ::math::linear::vector::subtraction( A1, A1x, A0y );
                coord_type A2;  ::math::linear::vector::subtraction( A2, A0z, A2x );

                ::math::linear::matrix::load( left2right, A0, A1, A2 );

                //homography_type          left2right;
                //homography_type          cross;
                //::math::linear::matrix::multiply( left2right, ::math::linear::matrix::cross( cross,  right_to_world.vector() ), right_to_world.matrix() );
                //left2right = result2;
               }

              static void process
               (
                 homography_type      & result
                ,affine_type     const& world_to_right
                ,affine_type     const& left_to_world
               )
               {
                affine_type span;

                ::math::linear::affine::compose( span, world_to_right, left_to_world );

                return ::math::geometry::projective::epipolar::fundamental<scalar_type>::process( result, span );
               }

              static bool process
               (
                 direction_type               & right_direction
                ,homography_type         const& left2right
                ,uv_type                 const& left_point
               )
               {
                coord_type reprojection = pinhole_type::reproject( left_point );
                ::math::linear::matrix::transform( right_direction.array(), left2right, reprojection );
                // right_direction.normalize();
                return true;
               }

              static coord_type          pole( homography_type  const& left2right )
               {
                coord_type result;
                direction_type a; process( a, left2right, { 0, 0 } );
                direction_type b; process( b, left2right, { 1, 0 } );
                direction_type c; ::math::linear::vector::cross( result, a.array(), b.array() );
                ::math::linear::vector::length<double>( result, 1 );

                process( a, left2right, { -1, 0 } );
                process( b, left2right, {  0, 1 } );
                ::math::linear::vector::cross( c.array(), a.array(), b.array() );
                ::math::linear::vector::length<double>( result, 1 );
                return result;
               }

              static direction_type   horizon( homography_type  const& left2right )
               {
                direction_type result;
                return result;
               }

              static direction_type principal( homography_type  const& left2right )
               {
                direction_type result;
                return result;
               }

           };

       }
     }
   }
 }
#endif
