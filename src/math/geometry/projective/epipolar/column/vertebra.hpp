#ifndef math_geometry_projective_camera_epipolar_vertebra
#define math_geometry_projective_camera_epipolar_vertebra

// ::math::geometry::projective::epipolar::vertebra( parameter, curvature );
// ::math::geometry::projective::epipolar::vertebra( parameter, curvature, alpha );

#include "./rotation.hpp"
#include "./curvature.hpp"


#include "../../../../geometry/direction/parametric.hpp"
#include "../../../../linear/vector/vector.hpp"

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {
        namespace column
         {

          template< typename scalar_name >
           ::math::linear::vector::structure<scalar_name,2> vertebra
            (
              scalar_name const& parameter //!< expect value between -1 and +1
             ,scalar_name const& curvature
             ,scalar_name const& angle
            )
            {
             ::math::geometry::direction::parametric< scalar_name, 2 > parametric;

             ::math::linear::vector::fill( parametric.origin(),    0 );
             ::math::linear::vector::load( parametric.direction(), cos( angle + ::math::constants::PHI_half ), sin( angle + ::math::constants::PHI_half ) );

             scalar_name X = fabs( parametric.direction()[0] );
             scalar_name Y = fabs( parametric.direction()[1] );

             ::math::linear::vector::scale( parametric.direction(), scalar_name(1)/( X < Y ? Y : X ) );

             return parametric.point( parameter );

             // TODO ::math::linear::vector::structure<scalar_name,2> result;
             // TODO result[0] = 0;
             // TODO result[1] = ::math::geometry::projective::epipolar::column::vertebra( parameter, curvature );
             // TODO ::math::linear::vector::rotate( result, angle );
            }

          template< typename scalar_name >
           ::math::linear::vector::structure<scalar_name,2> vertebra
            (
              scalar_name                                      const& parameter //!< expect value between -1 and +1
             ,::math::linear::vector::structure<scalar_name,2> const& pole
            )
            {
             scalar_name angle     = ::math::geometry::projective::epipolar::column::rotation( pole );
             scalar_name curvature = ::math::geometry::projective::epipolar::column::curvature( pole );
             return ::math::geometry::projective::epipolar::column::vertebra( parameter, curvature, angle );
            }

         }
       }
     }
   }
 }
#endif
