#ifndef math_library_linear_algebra__vector_refract_HPP_
 #define math_library_linear_algebra__vector_refract_HPP_

/* ::math::linear::vector::refract( & result_param
          , ray_param
          , normal_param
          ,scalar_name  const& air_param
          ,scalar_name  const& watter_param
         )*/



#include "./structure.hpp"
#include "./combine.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, unsigned dimension_number >
        inline
        int
        refract
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& incident_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& normal_param
          ,scalar_name  const& air_param
          ,scalar_name  const& watter_param
          ,scalar_name  const& epsilon_param = 1e-10
         )
         {
          result_param = incident_param;

          scalar_name r = air_param / watter_param;
          scalar_name c = -::math::linear::vector::dot( incident_param, normal_param );

          scalar_name d = scalar_name(1)-r*r*(scalar_name(1)-c*c);
          if( d < - epsilon_param )
           { // Nice total reflection
            return -1;
           }

          if( d < epsilon_param )
           { // Ray is nether reflected or refracted
            return 0;
           }
          // Nice total refraction
          ::math::linear::vector::combine( result_param, r, incident_param, r*c - sqrt( d ), normal_param );
          return 1;
         }

      }
    }
  }

#endif
