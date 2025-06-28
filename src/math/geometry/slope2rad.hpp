#ifndef math_geometry_slope2rad
#define math_geometry_slope2rad

 // ::math::geometry::slope2rad( )

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name, typename scalar_output_name = double >
     scalar_output_name slope2rad( scalar_name const& percent )
      {
       return atan( percent / scalar_output_name( 100 ) );
      }

    template< typename scalar_name, typename scalar_output_name = double >
     constexpr scalar_output_name slope2rad( scalar_name const&& percent )
      {
       return atan( percent / scalar_output_name( 100 ) );
      }

   }
 }

#endif
