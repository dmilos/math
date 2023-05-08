#ifndef math_geometry_projective_camera_projection
#define math_geometry_projective_camera_projection

// ::math::geometry::projective::camera::projection<scalar_name>::process( result, space, plane )

#include "../../../linear/matrix/gauss.hpp"
#include "../../../linear/vector/structure.hpp"



namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {

        template < typename scalar_name >
         struct projection
          { // calculate projection matrix from 6 given pairs.
           public:
             typedef std::size_t size_type;
             typedef scalar_name scalar_type;

             typedef ::math::linear::vector::structure< scalar_name, 2 >  uv_type;
             typedef ::math::linear::vector::structure< scalar_name, 3 >  coord_type;
             typedef ::math::linear::matrix::structure< scalar_name, 4, 3 >  result_type, matrix_type, matrix4x3_type;

             typedef std::pair< uv_type, coord_type > pair_type;
             typedef std::array< pair_type, 6 > input_type;

             typedef ::math::linear::matrix::structure< scalar_name, 12, 12 >  m12x12_type;
             typedef ::math::linear::vector::structure< scalar_name, 12 >  v12_type;

             typedef ::math::linear::matrix::structure< scalar_name, 13, 12 >  m13x12_type;
             typedef ::math::linear::vector::structure< scalar_name, 13 >  v13_type;

             typedef ::math::geometry::projective::camera::projection < scalar_name >  this_type;

             static v12_type rowX( uv_type const& display, coord_type const& space )
              {
               v12_type result;
               result[ 0] =    space[0];
               result[ 1] =    space[1];
               result[ 2] =    space[2];
               result[ 3] =            1;
               result[ 4] =  0;
               result[ 5] =  0;
               result[ 6] =  0;
               result[ 7] =  0;
               result[ 8] =  - space[0] * display[0];
               result[ 9] =  - space[1] * display[0];
               result[10] =  - space[2] * display[0];
               result[11] =  - 1        * display[0];
               return result;
              }

             static v12_type rowY( uv_type const& display, coord_type const& space )
              {
               v12_type result;
               result[ 0] =  0;
               result[ 1] =  0;
               result[ 2] =  0;
               result[ 3] =  0;
               result[ 4] =    space[0];
               result[ 5] =    space[1];
               result[ 6] =    space[2];
               result[ 7] =  1;
               result[ 8] =  - space[0] * display[1];
               result[ 9] =  - space[1] * display[1];
               result[10] =  - space[2] * display[1];
               result[11] =  - 1        * display[1];
               return result;
              }

             static void purge( m13x12_type & m, scalar_type const& epsilon )
              { // remove epsilons
               for( int i=0; i< m.size();++i )
                { 
                 for( int j=0; j< m[i].size();++j )
                  {
                   if( true == ::math::geometry::interval::in( m[i][j], -epsilon, epsilon ) )
                    {
                     m[i][j] = 0;
                    }
                  }
                }
              }

             static bool process( result_type & result, input_type const& input, size_type const& the_one = 7, scalar_type const& epsilon = 1e-7 )
              { // not so smart solution.
               m13x12_type m;

               for( size_type i=0; i < 6; ++i )
                {
                 m[ 0 + i ] = ::math::linear::vector::extend<13, scalar_type>( this_type::rowX( input[i].first, input[i].second ), 0 );
                 m[ 6 + i ] = ::math::linear::vector::extend<13, scalar_type>( this_type::rowY( input[i].first, input[i].second ), 0 );
                }

               for( size_t i=0; i< 12; ++i )
                {
                 std::swap( m[i][the_one] , m[i][12] );
                 m[i][12] = -m[i][12];
                }
               m[the_one][the_one]  = 1;
               m[the_one][12] = 1;

               auto rank = ::math::linear::matrix::gauss( m, epsilon );
               if( 12 != rank )
                {
                 return false;
                }

               m[the_one][12]  = 1;
               result[0][0] = m[ 0][12]; result[0][1] = m[ 1][12]; result[0][2] = m[ 2][12]; result[0][3] = m[ 3][12];
               result[1][0] = m[ 4][12]; result[1][1] = m[ 5][12]; result[1][2] = m[ 6][12]; result[1][3] = m[ 7][12];
               result[2][0] = m[ 8][12]; result[2][1] = m[ 9][12]; result[2][2] = m[10][12]; result[2][3] = m[11][12];
               return true;
              }

          };

       }
     }
   }
 }

#endif
