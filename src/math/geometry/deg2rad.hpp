#ifndef math_geometry_deg2rad
#define math_geometry_deg2rad

 // ::math::geometry::deg2rad( ) 

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name, typename scalar_output_name = double >
     scalar_output_name deg2rad( scalar_name const& degree )
      {
       return (scalar_output_name(degree) / scalar_output_name(180) ) * math::constants::PHI;
      }

    template< typename scalar_name, typename scalar_output_name = double >
     constexpr scalar_output_name deg2rad( scalar_name const&& degree )
      {
       return (scalar_output_name(degree) / scalar_output_name(180) ) * math::constants::PHI;
      }

   }
 }

#endif
