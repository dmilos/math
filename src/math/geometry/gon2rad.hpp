#ifndef math_geometry_gon2rad
#define math_geometry_gon2rad

 // ::math::geometry::gon2rad( )

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name, typename scalar_output_name = double >
     scalar_output_name gon2rad( scalar_name const& gradian  )
      {
       return ( scalar_output_name( gradian ) / scalar_output_name(200) ) * math::constants::PHI;
      }

    template< typename scalar_name, typename scalar_output_name = double >
     constexpr scalar_output_name gon2rad( scalar_name const&& gradian  )
      {
       return ( scalar_output_name( gradian ) / scalar_output_name(200) ) * math::constants::PHI;
      }

   }
 }

#endif
