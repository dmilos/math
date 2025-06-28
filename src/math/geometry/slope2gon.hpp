#ifndef math_geometry_slope2gon
#define math_geometry_slope2gon

 // ::math::geometry::slope2gon( )

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name, typename scalar_output_name = double >
     scalar_output_name slope2gon( scalar_name const& percent )
      {
       return ::math::geometry::rad2gon( ::math::geometry::slope2rad( percent ) );
      }

    template< typename scalar_name, typename scalar_output_name = double >
     constexpr scalar_output_name slope2gon( scalar_name const&& percent )
      {
       return ::math::geometry::rad2gon( ::math::geometry::slope2rad( percent ) );
      }

   }
 }

#endif
