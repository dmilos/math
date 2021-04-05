#ifndef math_geometry_interval_load_hpp_
 #define math_geometry_interval_load_hpp_
 
// ::math::geometry::interval::load( )

#include "./structure.hpp"





 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template < typename scalar_name,unsigned dimension_number >
        bool
        load
         (
           ::math::geometry::interval::structure<scalar_name,dimension_number>      & result
          ,::math::linear::vector::structure<scalar_name,dimension_number> const& lo
          ,::math::linear::vector::structure<scalar_name,dimension_number> const& hi
          )
         {
          result[0] = lo;
          result[1] = hi;
          return true;
         }

      }
    }
  }

#endif
