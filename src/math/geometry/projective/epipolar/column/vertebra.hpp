#ifndef math_geometry_projective_camera_epipolar_vertebra
#define math_geometry_projective_camera_epipolar_vertebra

// ::math::geometry::projective::epipolar::vertebra( parameter, curvature );
// ::math::geometry::projective::epipolar::vertebra( parameter, curvature, alpha );

#include "./rotation.hpp"
#include "./curvature.hpp"

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
           scalar_name vertebra
            (
              scalar_name const& parameter //!< expect value between -1 and +1
             ,scalar_name const& curvature
            )
            { // TODO
             return parameter;
             return curvature * ( scalar_name(1) - sqrt( scalar_name(1) - parameter*parameter ) );
            }

          template< typename scalar_name >
           ::math::linear::vector::structure<scalar_name,2> vertebra
            (
              scalar_name const& parameter //!< expect value between -1 and +1
             ,scalar_name const& curvature
             ,scalar_name const& angle
            )
            {
             ::math::linear::vector::structure<scalar_name,2> result;
             result[0] = 0;
             result[1] = ::math::geometry::projective::epipolar::column::vertebra( parameter, curvature );
             ::math::linear::vector::rotate( result, angle );
             return result;
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
