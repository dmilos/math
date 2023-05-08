#ifndef math_geometry_rad2deg
#define math_geometry_rad2deg

 // ::math::geometry::rad2deg( )

namespace math
 {
  namespace geometry
   {

    template< typename scalar_name, typename scalar_output_name = double >
     scalar_output_name rad2deg( scalar_name const& radian )
      {
       return scalar_output_name(180) * ( scalar_output_name(radian) / scalar_output_name(3.14159265358979323846264338327950288419716939937510) );
      }

    template< typename scalar_name, typename scalar_output_name = double >
     constexpr scalar_output_name rad2deg( scalar_name const&& radian )
      {
       return scalar_output_name(180) * ( scalar_output_name(radian) / scalar_output_name(3.14159265358979323846264338327950288419716939937510) );
      }

   }
 }

#endif
