#ifndef math_geometry_projective_epipolar_pole
#define math_geometry_projective_epipolar_pole

// ::math::geometry::projective::epipolar::pole<scalar_name, size_name = std::size_t >

#include "../camera/mobile.hpp"
#include "../../../linear/affine/transform.hpp"


namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {

        template
         <
           typename  scalar_name
          ,typename    size_name = std::size_t
         >
         struct pole //!< calculate epipoles in homogeneous of camera plane. Epipole can be in infinity
          {
           public:
             typedef std::size_t   size_type;
             typedef scalar_name scalar_type;

             typedef ::math::linear::vector::point<scalar_name,3>         point_type;
             typedef ::math::linear::vector::point<scalar_name,3>   homogeneous_type;

             typedef ::math::linear::affine::structure< scalar_name, 3 >       affine_type;

             typedef ::math::geometry::projective::camera::mobile< scalar_name, size_name > mobile_type;

           public:
             static bool left( point_type & result, affine_type const& left_to_local, point_type const& right_eye/* in world coord */ )
              {
               ::math::linear::affine::transform( result, left_to_local, right_eye );
              }

             static bool left( homogeneous_type & result, mobile_type const& sinister/*left*/, mobile_type const& dexter/*right*/ )
              {
               return left( result, sinister.to_local(), dexter.to_world().vector() );
              }


             static bool right( point_type & result, affine_type const& right_to_local, point_type const& left_eye /* in world coord */ )
              {
               ::math::linear::affine::transform( result, right_to_local, left_eye );
              }

             static bool right( homogeneous_type & result, mobile_type const& sinister/*left*/, mobile_type const& dexter/*right*/ )
              {
               return left( result, dexter.to_local(), sinister.to_world().vector() );
              }

          };

       }
     }
   }
 }

#endif
