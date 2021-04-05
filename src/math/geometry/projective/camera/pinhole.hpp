#ifndef math_geometry_projective_camera_pinhole
#define math_geometry_projective_camera_pinhole

// ::math::geometry::projective::camera::pinhole< scalar >

#include "../../../linear/vector/structure.hpp"
#include "../../../linear/matrix/structure.hpp"

/*
          ^       -/
          |       /|
      +---|------+
      |   |     /|
      |   |    / |
      |   Z   /  |
      |   |  Y   |
      |   | /    |
---------------X-|----->
      |   |      |
      |   |      |
      +---|----- +
*/

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {

        template< typename scalar_name/* unsigned dimension_number, unsigned orientation_number, unsigned permutation_number*/ >
         class pinhole // Project on to y=1 plane;
          {
           public:
             typedef scalar_name  scalar_type;

           public:
             enum direction_enum
              { // common for all dimensions
                forward_index = 0
               ,backward_index = 1
              };
             enum axis_enum
              { // dimension_number
                X_index = 0
               ,Y_index = 1
               ,Z_index = 2
              };

             enum orientation_enum
              { // pow( 2, dimension_number )
                FFF = ( forward_index   << 0 ) + ( forward_index  << 1 ) + ( forward_index << 2 )
               ,BFF = ( backward_index  << 0 ) + ( forward_index  << 1 ) + ( forward_index << 2 )
               ,FBF = ( forward_index   << 0 ) + ( backward_index << 1 ) + ( forward_index << 2 )
               ,BBF = ( backward_index  << 0 ) + ( backward_index << 1 ) + ( forward_index << 2 )
               ,FFB = ( forward_index   << 0 ) + ( forward_index  << 1 ) + ( backward_index<< 2 )
               ,BFB = ( backward_index  << 0 ) + ( forward_index  << 1 ) + ( backward_index<< 2 )
               ,FBB = ( forward_index   << 0 ) + ( backward_index << 1 ) + ( backward_index<< 2 )
               ,BBB = ( backward_index  << 0 ) + ( backward_index << 1 ) + ( backward_index<< 2 )
              };

             enum permutation_enum
              { // factorial( dimension_number )
                XYZ// TODO = X_index * f( 0 ) + Y_index * f( 1 ) + Z_index * f( 2 )
               ,YXZ// TODO = Y_index * f( 0 ) + X_index * f( 1 ) + Z_index * f( 2 )
               ,XZY// TODO = X_index * f( 0 ) + Z_index * f( 1 ) + Y_index * f( 2 )
               ,ZXY// TODO = Z_index * f( 0 ) + X_index * f( 1 ) + Y_index * f( 2 )
               ,YZX// TODO = Y_index * f( 0 ) + Z_index * f( 1 ) + X_index * f( 2 )
               ,ZYX// TODO = Z_index * f( 0 ) + Y_index * f( 1 ) + X_index * f( 2 )
              };

           public:
             typedef ::math::linear::vector::point< scalar_type, 2/*dimension_number-1*/ >        uv_type;
             typedef ::math::linear::vector::point< scalar_type, 3/*dimension_number*/ >         point3d_type, point_type;
             typedef ::math::linear::matrix::structure< scalar_type, 3/*dimension_number*/,3/*dimension_number*/ >   matrix_type;

             typedef ::math::geometry::projective::camera::pinhole< scalar_name >   this_type;

           public:
             pinhole()
              {
              }

             static uv_type project( point3d_type const& point3d )
              {
               return uv_type{ point3d[this_type::right()] / point3d[this_type::forward()],
                               point3d[this_type::up()]    / point3d[this_type::forward()] };
              }

             static uv_type & project( uv_type & uv, point3d_type const& point3d )
              {
               uv[0] = point3d[ this_type::right() ] / point3d[ this_type::forward() ];
               uv[1] = point3d[ this_type::up()    ] / point3d[ this_type::forward() ];
               return uv;
              }

             static point3d_type reproject( uv_type const& uv )
              {
               point3d_type result;
               result[ this_type::right()    ] = uv[0];
               result[ this_type::forward()  ] = scalar_type(1);
               result[ this_type::up()       ] = uv[1];

               return result;
              }

             static point3d_type reproject( uv_type const& uv, scalar_type const& depth )
              {
               point3d_type result;
               result[ this_type::right()   ] = uv[0] * depth;
               result[ this_type::forward() ] =         depth;
               result[ this_type::up()      ] = uv[1] * depth;

               return result;
              }

             static std::size_t right()
              {
               return 0;
              }

             static std::size_t forward( )
              {
               return 1; //!< dimension_number - 1
              }

             static std::size_t up( )
              {
               return 2;
              }

             static matrix_type const& matrix()
              {
               matrix_type result;
               // TODO scalar_type x = scalar_type( ( orientation_number & ( 0<<1 ) ) ? +1 : -1 );
               // TODO scalar_type y = scalar_type( ( orientation_number & ( 1<<1 ) ) ? +1 : -1 );
               // TODO scalar_type z = scalar_type( ( orientation_number & ( 2<<1 ) ) ? +1 : -1 );

               //TODO permutation_number

               return result;
              }

          };

       }
     }
   }
 }

#endif
