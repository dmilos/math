#ifndef math_geometry_rad2deg
#define math_geometry_rad2deg

 // ::math::geometry::rad2deg( )

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name, typename scalar_output_name = double >
     scalar_output_name rad2deg( scalar_name const& radians )
      {
       return ( scalar_output_name( radians ) * scalar_output_name(180)/ scalar_output_name( math::constants::PHI ) );
      }

    template< typename scalar_name, typename scalar_output_name = double >
     constexpr scalar_output_name rad2deg( scalar_name const&& radians )
      {
       return ( scalar_output_name( radians ) * scalar_output_name(180)/ scalar_output_name( math::constants::PHI ) );
      }

   }
 }

#endif
