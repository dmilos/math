#ifndef math_geometry_projective_camera_epipolar_vertebra
#define math_geometry_projective_camera_epipolar_vertebra

// ::math::geometry::projective::epipolar::vertebra( parameter, curvature );
// ::math::geometry::projective::epipolar::vertebra( parameter, curvature, alpha );


namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {
        namespace backbone
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
             ,scalar_name const& rotation
            )
            {
             ::math::linear::vector::structure<scalar_name,2> result;
             result[0] = parameter;
             result[1] = ::math::geometry::projective::epipolar::backbone::vertebra( parameter, curvature );
             ::math::linear::vector::rotate( result, rotation );
            return result;
            }

          template< typename scalar_name >
           ::math::linear::vector::structure<scalar_name,2> vertebra
            (
              scalar_name                                      const& parameter //!< expect value between -1 and +1
             ,::math::linear::vector::structure<scalar_name,2> const& pole
            )
            {// TODO
            }

         }
       }
     }
   }
 }
#endif
