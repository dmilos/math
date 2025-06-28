#ifndef math_geometry_gon2slope
#define math_geometry_gon2slope

 // ::math::geometry::gon2slope( )

#include "./rad2slope.hpp"
#include "./gon2rad.hpp"

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name, typename scalar_output_name = double >
     scalar_output_name gon2slope( scalar_name const& gradian )
      {
       return ::math::geometry::rad2slope( ::math::geometry::gon2rad( gradian ) );
      }

    template< typename scalar_name, typename scalar_output_name = double >
     constexpr scalar_output_name gon2slope( scalar_name const&& gradian )
      {
       return ::math::geometry::rad2slope( ::math::geometry::gon2rad( gradian ) );
      }

   }
 }

#endif
