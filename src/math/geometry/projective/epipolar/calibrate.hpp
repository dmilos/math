#ifndef math_geometry_projective_camera_calibrate
#define math_geometry_projective_camera_calibrate

// ::math::geometry::projective::camera::calibrate( alpha, h_scale, v_scale )

//#include <utility>

#include "../../../linear/affine/affine.hpp"
#include "../../../linear/vector/structure.hpp"
#include "../../plane/parametric3d.hpp"

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {

        template < typename scalar_name >
         class calibrate //!< calculate transform from right camera to left, TODO change name to OPD or align or something else
          {
           public:
             typedef ::math::linear::vector::point<  scalar_name, 3 > point_type;
             typedef ::math::linear::vector::vector< scalar_name, 3 > vector_type;
             typedef ::math::linear::affine::structure< scalar_name, 3 > affine_type;

             typedef ::math::geometry::plane::parametric3d<scalar_name> parametric_type;
             //typedef ::math::geometry::plane::no3d<scalar_name> no3d_type;

             static void to_affine( affine_type & to_world, parametric_type const& p )
              {
               vector_type normal;

               ::math::linear::vector::cross( normal, p.x(), p.y() );

               ::math::linear::affine::system
                 ( to_world,
                                                 p.origin()
                  ,::math::linear::vector::unit( p.x()      )
                  ,::math::linear::vector::unit( p.y()      )
                  ,::math::linear::vector::unit( normal     )
                 );
              }

             static void to_affine( affine_type & to_world, point_type const& normal, parametric_type const& p )
              {
               ::math::linear::affine::system
                 ( to_world,
                                                 p.origin()
                  ,::math::linear::vector::unit( p.x()      )
                  ,::math::linear::vector::unit( p.y()      )
                  ,::math::linear::vector::unit( normal     )
                 );
              }

             static bool process ( affine_type  & to_world, affine_type const& left_to_local, affine_type const& right_to_local )
              {
               affine_type       right_to_world;

               if( false == ::math::linear::affine::invert( right_to_world, right_to_local ) )
                {
                 return false;
                }

               ::math::linear::affine::compose( to_world, left_to_local, right_to_world );
                return true;
               }

             static bool process ( affine_type  & to_world, parametric_type const& left_to_local, parametric_type const& right_to_local )
              {
               affine_type left_a;
               to_affine( left_a, left_to_local );

               affine_type right_b;
               to_affine(  right_b, right_to_local );

               return process( to_world, left_a, right_b );
              }

          };

       }
     }
   }
 }

#endif



