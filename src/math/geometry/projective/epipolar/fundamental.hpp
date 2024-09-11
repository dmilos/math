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
              typedef ::math::linear::matrix::structure< scalar_name, 3, 3 >             matrix_type;

              typedef ::math::geometry::projective::camera::pinhole< scalar_name >      pinhole_type;

            public:
              static void process
               (
                 matrix_type              & left2right
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

                //matrix_type          left2right;
                //matrix_type          cross; ::math::linear::matrix::cross( cross,  right_to_world.vector() )
                //::math::linear::matrix::multiply( left2right, cross, right_to_world.matrix() );
               }

              static void process
               (
                 matrix_type      & result
                ,affine_type     const& world_to_right
                ,affine_type     const& left_to_world
               )
               {
                affine_type span;

                ::math::linear::affine::compose( span, world_to_right, left_to_world );

                return ::math::geometry::projective::epipolar::fundamental<scalar_type>::process( result, span );
               }

              static bool apply
               (
                 direction_type               & right_direction
                ,matrix_type             const& left2right
                ,uv_type                 const& left_point
               ) //!< for right to left just use right2left = transpose( left2right )
               {
                coord_type reprojection = pinhole_type::reproject( left_point );
                ::math::linear::matrix::transform( right_direction.array(), left2right, reprojection );
                // right_direction.normalize();
                return true;
               }

              static coord_type          poleL( matrix_type  const& left2right )
               {
                static scalar_type epsilon = 1e-6;
                coord_type A;  ::math::linear::matrix::row( A, left2right, 0 );
                coord_type B;  ::math::linear::matrix::row( B, left2right, 1 );
                coord_type C;  ::math::linear::matrix::row( C, left2right, 2 );

                scalar_type Al = ::math::linear::vector::length<scalar_type>( A ); if( epsilon < Al ) { ::math::linear::vector::scale<scalar_type>( A, 1/Al ); Al = 1; } 
                scalar_type Bl = ::math::linear::vector::length<scalar_type>( B ); if( epsilon < Bl ) { ::math::linear::vector::scale<scalar_type>( B, 1/Bl ); Bl = 1; } 
                scalar_type Cl = ::math::linear::vector::length<scalar_type>( C ); if( epsilon < Cl ) { ::math::linear::vector::scale<scalar_type>( C, 1/Cl ); Cl = 1; } 

                scalar_type ab = fabs( ::math::linear::vector::dot( A, B ) );
                scalar_type ac = fabs( ::math::linear::vector::dot( A, C ) );
                scalar_type bc = fabs( ::math::linear::vector::dot( B, C ) );

                int type = 0;

                coord_type result;
                if( ( ( ab < ac ) && ( ab < bc ) ) || ( Cl < 0.5 ) )   { ::math::linear::vector::cross( result, A, B ); return result; }
                if( ( ( ac < ab ) && ( ac < bc ) ) || ( Bl < 0.5 ) )   { ::math::linear::vector::cross( result, A, C ); return result; }
              /*if( ( ( bc < ab ) && ( bc < ac ) ) || ( Al < 0.5 ) )*/ { ::math::linear::vector::cross( result, B, C ); return result; }

                return result;
               }

              static coord_type          poleR( matrix_type  const& left2right )
               {
                static scalar_type epsilon = 1e-6;
                coord_type A;  ::math::linear::matrix::column( A, left2right, 0 );
                coord_type B;  ::math::linear::matrix::column( B, left2right, 1 );
                coord_type C;  ::math::linear::matrix::column( C, left2right, 2 );

                scalar_type Al = ::math::linear::vector::length<scalar_type>( A ); if( epsilon < Al ) { ::math::linear::vector::scale<scalar_type>( A, 1/Al ); Al = 1; } 
                scalar_type Bl = ::math::linear::vector::length<scalar_type>( B ); if( epsilon < Bl ) { ::math::linear::vector::scale<scalar_type>( B, 1/Bl ); Bl = 1; } 
                scalar_type Cl = ::math::linear::vector::length<scalar_type>( C ); if( epsilon < Cl ) { ::math::linear::vector::scale<scalar_type>( C, 1/Cl ); Cl = 1; } 

                scalar_type ab = fabs( ::math::linear::vector::dot( A, B ) );
                scalar_type ac = fabs( ::math::linear::vector::dot( A, C ) );
                scalar_type bc = fabs( ::math::linear::vector::dot( B, C ) );

                int type = 0;

                coord_type result;
                if( ( ( ab < ac ) && ( ab < bc ) ) || ( Cl < 0.5 ) )   { ::math::linear::vector::cross( result, A, B ); return result; }
                if( ( ( ac < ab ) && ( ac < bc ) ) || ( Bl < 0.5 ) )   { ::math::linear::vector::cross( result, A, C ); return result; }
              /*if( ( ( bc < ab ) && ( bc < ac ) ) || ( Al < 0.5 ) )*/ { ::math::linear::vector::cross( result, B, C ); return result; }

                return result;
               }

           };

       }
     }
   }
 }
#endif
