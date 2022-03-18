#ifndef math_geometry_projective_epipolar_rectify3
#define math_geometry_projective_epipolar_rectify3

// ::math::geometry::projective::epipolar::rectify( plane, left2world, right2world )
// ::math::geometry::projective::epipolar::rectify( H, plane, to_world )

//#include <utility>


#include "../../../linear/vector/convex.hpp"
#include "../../../linear/homography/structure.hpp"
#include "../camera/frustum/structure.hpp"

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {

        template < typename scalar_name >
         class rectify3
          {
           public:
            typedef scalar_name       scalar_type;
            typedef ::math::geometry::plane::parametric3d<scalar_name>                       plane_type;
            typedef ::math::linear::homography::structure< scalar_name, 2 >             homography_type;
            typedef ::math::linear::affine::structure< scalar_name, 3 >                     affine_type;
            typedef ::math::geometry::projective::camera::frustum::structure<scalar_name>  frustum_type;
            typedef ::math::geometry::projective::camera::pinhole< scalar_name >           pinhole_type;

            static bool common( plane_type &plane, affine_type const& left2world, affine_type const& right2world, scalar_type const& far )
              {
               ::math::linear::vector::structure< scalar_name, 3 > const&  axis =  plane.x();
               ::math::linear::vector::subtraction( plane.x(), right2world.vector(), left2world.vector() );
               ::math::linear::vector::length<scalar_name>( plane.x(), 1 );
               
               ::math::linear::vector::structure< scalar_name, 3 >   common_up, left_up, right_up;
               ::math::linear::matrix::column( left_up, left2world.matrix(), pinhole_type::up() );
               ::math::linear::matrix::column( right_up, right2world.matrix(), pinhole_type::up() );
               ::math::linear::vector::addition( common_up, left_up, right_up );
               ::math::linear::vector::scale( common_up, 0.5  );
               
               ::math::linear::vector::structure< scalar_name, 3 >   common_forward, left_forward, right_forward;
               ::math::linear::matrix::column( left_forward,  left2world.matrix(), pinhole_type::forward() );
               ::math::linear::matrix::column( right_forward, right2world.matrix(), pinhole_type::forward() );
               ::math::linear::vector::addition( common_forward, left_forward, right_forward );
               ::math::linear::vector::scale( common_forward, 0.5  );
               
               ::math::linear::vector::structure< scalar_name, 3 >   common_right, left_right, right_right;
               ::math::linear::matrix::column( left_right,  left2world.matrix(), pinhole_type::right() );
               ::math::linear::matrix::column( right_right, right2world.matrix(), pinhole_type::right() );
               ::math::linear::vector::addition( common_right, left_right, right_right );
               ::math::linear::vector::scale( common_right, 0.5 );

               std::array< scalar_name, 3 >  dot;
               dot[ 0 ] = fabs( ::math::linear::vector::dot( common_up,      axis ) );
               dot[ 1 ] = fabs( ::math::linear::vector::dot( common_right,   axis ) );
               dot[ 2 ] = fabs( ::math::linear::vector::dot( common_forward, axis ) );

               //switch( std::min_element( dot.begin(), dot.end() ) - dot.begin() )
               // {
               //  case(0): ::math::linear::vector::cross( common_forward, common_up, axis ); ::math::linear::vector::cross( common_up,      axis, common_forward ); break;
               //  case(1): ::math::linear::vector::cross( common_up, common_right,   axis ); ::math::linear::vector::cross( common_right,   axis, common_forward ); break;
               //  case(2): ::math::linear::vector::cross( common_up, common_forward, axis ); ::math::linear::vector::cross( common_forward, axis, common_up      ); break;
               // }
               ::math::linear::vector::length<scalar_name>( common_forward, 1 );
               ::math::linear::vector::length<scalar_name>( common_up, 1 );

               ::math::linear::vector::convex( plane.origin(), 0.5, left2world.vector(), right2world.vector() );
               ::math::linear::vector::combine( plane.origin(), plane.origin(), far, common_forward );

               plane.y() = common_up;

               return true;
              }


            static bool transformation( homography_type & result, plane_type &plane, affine_type const& to_world )
             {
               return true;
             }

            //bool
            //canvas
            // (
            //   plane_type                       & common
            //  ,affine_type                    const& sinister2world
            //  ,frustum_type  const& sinister
            //  ,affine_type                    const& dexter2world
            //  ,  const& dexter
            // )
            // {
            //
            //  return true;
            // }

          };

       }
     }
   }
 }

#endif
