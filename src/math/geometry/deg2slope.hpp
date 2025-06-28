#ifndef math_geometry_deg2slope
#define math_geometry_deg2slope

 // ::math::geometry::deg2slope( ) 

#include "./deg2rad.hpp"
#include "./rad2slope.hpp"

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name, typename scalar_output_name = double >
     scalar_output_name deg2slope( scalar_name const& degree )
      {
       return ::math::geometry::rad2slope( ::math::geometry::deg2rad( degree ) );
      }

    template< typename scalar_name, typename scalar_output_name = double >
     constexpr scalar_output_name deg2slope( scalar_name const&& degree )
      {
       return ::math::geometry::rad2slope( ::math::geometry::deg2rad( degree ) );
      }

   }
 }

#endif
