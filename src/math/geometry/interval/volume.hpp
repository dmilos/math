#ifndef math_geometry_interval_volume_hpp_
 #define math_geometry_interval_volume_hpp_
 
// ::math::geometry::interval::volume( )

#include <cmath>

#include "./structure.hpp"



 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template < typename scalar_name >
        scalar_name volume ( ::math::geometry::interval::structure<scalar_name,1> const& box )
         {
          return fabs( box[0][0] - box[1][0] );
         }

       template < typename scalar_name >
        scalar_name volume ( ::math::geometry::interval::structure<scalar_name,2> const& box )
         {
          return   fabs( box[0][0] - box[1][0] )
                 * fabs( box[0][1] - box[1][1] );
         }

       template < typename scalar_name >
        scalar_name volume ( ::math::geometry::interval::structure<scalar_name,3> const& box )
         {
          return    fabs( box[0][0] - box[1][0] )
                  * fabs( box[0][1] - box[1][1] )
                  * fabs( box[0][2] - box[1][2] )
                  ;
         }

       template < typename scalar_name >
        scalar_name volume ( ::math::geometry::interval::structure<scalar_name,4> const& box )
         {
          return    fabs( box[0][0] - box[1][0] )
                  * fabs( box[0][1] - box[1][1] )
                  * fabs( box[0][2] - box[1][2] )
                  * fabs( box[0][3] - box[1][3] );
         }

       template < typename scalar_name, ::math::type::size_type dimension_number >
        scalar_name volume ( ::math::geometry::interval::structure<scalar_name,dimension_number> const& box )
         {
          scalar_name result = 1;
          auto index = dimension_number;
          while( index-- )
           {
            result *= fabs( box[1][index] - box[0][index] );
           }
          return result;
         }

       inline std::uint16_t volume ( ::math::geometry::interval::structure<std::int8_t,  2 > const& box ) { return abs( box[0][0] - box[1][0] ) * abs( box[0][1] - box[1][1] ); }
       inline std::uint32_t volume ( ::math::geometry::interval::structure<std::int16_t, 2 > const& box ) { return abs( box[0][0] - box[1][0] ) * abs( box[0][1] - box[1][1] ); }
       inline std::uint64_t volume ( ::math::geometry::interval::structure<std::int32_t, 2 > const& box ) { return abs( box[0][0] - box[1][0] ) * abs( box[0][1] - box[1][1] ); }

       //std::uint16_t volume ( ::math::geometry::interval::structure<std::uint8_t,2>  const& box ) { return abs( box[0][0] - box[1][0] ) * abs( box[0][1] - box[1][1] ); }
       //std::uint32_t volume ( ::math::geometry::interval::structure<std::uint16_t,2> const& box ) { return abs( box[0][0] - box[1][0] ) * abs( box[0][1] - box[1][1] ); }
       //std::uint64_t volume ( ::math::geometry::interval::structure<std::uint32_t,2> const& box ) { return abs( box[0][0] - box[1][0] ) * abs( box[0][1] - box[1][1] ); }

      }
    }
  }

#endif
