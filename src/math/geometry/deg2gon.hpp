#ifndef math_geometry_deg2gon
#define math_geometry_deg2gon

 // ::math::geometry::deg2gon( )

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name, typename scalar_output_name = double >
     scalar_output_name deg2gon( scalar_name const& degree )
      {
       return (scalar_output_name(degree) / scalar_output_name(200) ) * math::constants::PHI;
      }

    template< typename scalar_name, typename scalar_output_name = double >
     constexpr scalar_output_name deg2gon( scalar_name const&& degree )
      {
       return (scalar_output_name(degree) / scalar_output_name(200) ) * math::constants::PHI;
      }

   }
 }

#endif
