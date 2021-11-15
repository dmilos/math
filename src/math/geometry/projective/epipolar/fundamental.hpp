#ifndef math_geometry_projective_camera_epipolar_fundamental
#define math_geometry_projective_camera_epipolar_fundamental

// ::math::geometry::projective::epipolar::fundamental<scalar>::process( matrix, sinister, dexter );
// ::math::geometry::projective::epipolar::fundamental<scalar>::process( direction, matrix, point2d );

#include "../camera/pinhole.hpp"
#include "../../../linear/matrix/load.hpp"
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
              typedef ::math::linear::vector::structure< scalar_name, 2 >               uv_type;
              typedef ::math::linear::vector::structure< scalar_name, 3 >             coord_type;
              typedef ::math::geometry::direction::ABC2D<scalar_name >           direction_type;
              typedef ::math::linear::affine::structure< scalar_name, 3 >            affine_type;
              typedef ::math::linear::matrix::structure< scalar_name, 3,3 >          matrix_type;

              typedef ::math::geometry::projective::camera::pinhole< scalar_name >  pinhole_type;

            public:

              static void process
               (
                 matrix_type          & result
                ,affine_type     const& right_to_local
               )
               {
                auto const FORWARD = pinhole_type::forward();
                auto const RIGHT   = pinhole_type::right();
                auto const UP      = pinhole_type::up();

                affine_type const& span = right_to_local;

                coord_type A0y = span[0]; ::math::linear::vector::scale( A0y, span.vector()[FORWARD] );
                coord_type A0z = span[0]; ::math::linear::vector::scale( A0z, span.vector()[UP] );

                coord_type A1x = span[1]; ::math::linear::vector::scale( A1x, span.vector()[RIGHT] );
                coord_type A1z = span[1]; ::math::linear::vector::scale( A1z, span.vector()[UP] );

                coord_type A2x = span[2]; ::math::linear::vector::scale( A2x, span.vector()[RIGHT] );
                coord_type A2y = span[2]; ::math::linear::vector::scale( A2y, span.vector()[FORWARD] );

                coord_type A0;  ::math::linear::vector::subtraction( A0, A2y, A1z );
                coord_type A1;  ::math::linear::vector::subtraction( A1, A1x, A0y );
                coord_type A2;  ::math::linear::vector::subtraction( A2, A0z, A2x );

                ::math::linear::matrix::load( result, A0, A1, A2 );
               }

              static void process
               (
                 matrix_type          & result
                ,affine_type     const& left_to_world
                ,affine_type     const& right_to_local
               )
               {
                affine_type span;

                ::math::linear::affine::transform( span, right_to_local, left_to_world );

                return ::math::geometry::projective::epipolar::fundamental<scalar_type>::process( result, span );
               }

              static bool process
               (
                 direction_type           & result
                ,matrix_type         const& matrix
                ,uv_type              const& point
               )
               {
                coord_type reproject = pinhole_type::reproject( point );
                ::math::linear::matrix::transform( result.array(), matrix, reproject );
                // result.normalize();
                return true;
               }
           };

       }
     }
   }
 }
#endif
