#ifndef math_geometry_rad2gon
#define math_geometry_rad2gon

 // ::math::geometry::rad2gon( )

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name, typename scalar_output_name = double >
     scalar_output_name rad2gon( scalar_name const& radian )
      {
       return scalar_output_name(180) * ( scalar_output_name(radian) / math::constants::PHI );
      }

    template< typename scalar_name, typename scalar_output_name = double >
     constexpr scalar_output_name rad2gon( scalar_name const&& radian )
      {
       return scalar_output_name(180) * ( scalar_output_name(radian) / math::constants::PHI );
      }

   }
 }

#endif
