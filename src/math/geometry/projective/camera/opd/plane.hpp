#ifndef math_geometry_projective_camera_opd_plane
#define math_geometry_projective_camera_opd_plane

// ::math::geometry::projective::camera::opd::plane( center, f, r, A, B )

#include "../../../../linear/vector/structure.hpp"



namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {
        namespace opd
         {

        template < typename scalar_name >
         class plane
          {
           public:
             typedef std::size_t size_type;
             typedef scalar_name scalar_type;
             typedef ::math::linear::vector::point<  scalar_name, 3 > point_type;
             typedef ::math::linear::vector::vector<  scalar_name, 3 > vector_type;
             typedef ::math::linear::affine::structure< scalar_name, 3 > affine_type;

             typedef ::math::geometry::plane::parametric3d<scalar_name> parametric_type;
             
             static void to_world( affine_type & result, parametric_type const& p )
              {
               vector_type normal;

               ::math::linear::vector::cross( normal, p.x(), p.y() );

               ::math::linear::affine::system
                 ( result,
                                                 p.origin()
                  ,::math::linear::vector::unit( p.x()      )
                  ,::math::linear::vector::unit( p.y()      )
                  ,::math::linear::vector::unit( normal     )
                 );
              }

             static void to_world( affine_type & result, point_type const& normal, parametric_type const& p )
              {
               ::math::linear::affine::system
                 ( result,
                                                 p.origin()
                  ,::math::linear::vector::unit( p.x()      )
                  ,::math::linear::vector::unit( p.y()      )
                  ,::math::linear::vector::unit( normal     )
                 );
              }

             static void to_local( affine_type & result, point_type const& normal, parametric_type const& p )
              {
               //TODO
              }

           };

         }
       }
     }
   }
 }

#endif
