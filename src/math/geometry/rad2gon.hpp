#ifndef math_geometry_rad2gon
#define math_geometry_rad2gon

 // ::math::geometry::rad2gon( )

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name, typename scalar_output_name = double >
     scalar_output_name rad2gon( scalar_name const& radians )
      {
       return ( scalar_output_name( radians ) / math::constants::PHI )* scalar_output_name(200);
      }

    template< typename scalar_name, typename scalar_output_name = double >
     constexpr scalar_output_name rad2gon( scalar_name const&& radians )
      {
       return ( scalar_output_name( radians ) / math::constants::PHI ) * scalar_output_name(200);
      }

   }
 }

#endif
