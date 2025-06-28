#ifndef math_geometry_slope2deg
#define math_geometry_slope2deg

 // ::math::geometry::slope2deg( ) 

#include "./rad2deg.hpp"
#include "./slope2rad.hpp"

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name, typename scalar_output_name = double >
     scalar_output_name slope2deg( scalar_name const& percent )
      {
       return ::math::geometry::rad2deg( ::math::geometry::slope2rad( percent ) );
      }

    template< typename scalar_name, typename scalar_output_name = double >
     constexpr scalar_output_name slope2deg( scalar_name const&& percent )
      {
       return ::math::geometry::rad2deg( ::math::geometry::slope2rad( percent ) );
      }

   }
 }

#endif
