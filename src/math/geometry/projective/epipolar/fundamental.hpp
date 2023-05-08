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
                 homography_type          & result
                ,affine_type         const& right_to_world
               )    //it is assume that  left_to_world is ID
               {
                auto const FORWARD = pinhole_type::forward();
                auto const RIGHT   = pinhole_type::right();
                auto const UP      = pinhole_type::up();

                coord_type A0y = right_to_world[0]; ::math::linear::vector::scale( A0y, right_to_world.vector()[FORWARD] );
                coord_type A0z = right_to_world[0]; ::math::linear::vector::scale( A0z, right_to_world.vector()[UP] );

                coord_type A1x = right_to_world[1]; ::math::linear::vector::scale( A1x, right_to_world.vector()[RIGHT] );
                coord_type A1z = right_to_world[1]; ::math::linear::vector::scale( A1z, right_to_world.vector()[UP] );

                coord_type A2x = right_to_world[2]; ::math::linear::vector::scale( A2x, right_to_world.vector()[RIGHT] );
                coord_type A2y = right_to_world[2]; ::math::linear::vector::scale( A2y, right_to_world.vector()[FORWARD] );

                coord_type A0;  ::math::linear::vector::subtraction( A0, A2y, A1z );
                coord_type A1;  ::math::linear::vector::subtraction( A1, A1x, A0y );
                coord_type A2;  ::math::linear::vector::subtraction( A2, A0z, A2x );

                ::math::linear::matrix::load( result, A0, A1, A2 );


                //homography_type          result2;
                //homography_type          cross; 
                //
                //::math::linear::matrix::multiply( result2, ::math::linear::matrix::cross( result2,  right_to_world.vector() ), right_to_world.matrix() );
                //result2 = result2;
               }

              static void process
               (
                 homography_type      & result
                ,affine_type     const& left_to_world
                ,affine_type     const& right_to_world
               )
               {
                affine_type span;

                ::math::linear::affine::transform( span, right_to_world, left_to_world );

                return ::math::geometry::projective::epipolar::fundamental<scalar_type>::process( result, span );
               }

              static bool process
               (
                 direction_type               & right_direction
                ,homography_type         const& left2right
                ,uv_type                 const& left_point
               )
               {
                coord_type reproject = pinhole_type::reproject( left_point );
                ::math::linear::matrix::transform( right_direction.array(), left2right, reproject );
                // right_direction.normalize();
                return true;
               }
           };

       }
     }
   }
 }
#endif
