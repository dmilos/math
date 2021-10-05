#ifndef math_geometry_interval_in_hpp_
 #define math_geometry_interval_in_hpp_

// ::math::geometry::interval::in( value, left, right )
// ::math::geometry::interval::in( interval, point )

#include "./structure.hpp"





 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template< typename scalar_name>
        inline
        bool
        in
         (
           scalar_name             const& value
          ,scalar_name             const& left
          ,scalar_name             const& right
         )
         {
          if( value < left )
           {
            return false;
           }
          if( right < value )
           {
            return false;
           }
          return true;
         }

       template< typename scalar_name, unsigned dimension_number >
        inline
        bool
        in
         (
                     ::math::geometry::interval::structure< scalar_name, dimension_number >             const& instance
          ,typename  ::math::geometry::interval::structure< scalar_name, dimension_number >::point_type const& point
         )
         {
          unsigned index = dimension_number;

          while( index-- )
           {
            if( point[index] < instance[ 0 ][index] )
             {
              return false;
             }
            if( instance[ 1 ][index] < point[index])
             {
              return false;
             }
           }

          return true;
         }

      }
    }
  }

#endif