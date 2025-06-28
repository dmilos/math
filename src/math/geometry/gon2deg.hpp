#ifndef math_geometry_gon2deg
#define math_geometry_gon2deg

 // ::math::geometry::gon2deg( )

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name, typename scalar_output_name = double >
     scalar_output_name gon2deg( scalar_name const& gradian  )
      {
       return scalar_output_name(200) * ( scalar_output_name( gradian  ) / math::constants::PHI );
      }

    template< typename scalar_name, typename scalar_output_name = double >
     constexpr scalar_output_name gon2deg( scalar_name const&& gradian  )
      {
       return scalar_output_name(200) * ( scalar_output_name( gradian  ) / math::constants::PHI );
      }

   }
 }

#endif
