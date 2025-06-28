#ifndef math_geometry_rad2slope
#define math_geometry_rad2slope

 // ::math::geometry::rad2slope( )

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name, typename scalar_output_name = double >
     scalar_output_name rad2slope( scalar_name const& radians )
      {
       return scalar_output_name(100) * tan( radians );
      }

    template< typename scalar_name, typename scalar_output_name = double >
     constexpr scalar_output_name rad2slope( scalar_name const&& radians )
      {
       return scalar_output_name(100) * tan( radians );
      }

   }
 }

#endif
