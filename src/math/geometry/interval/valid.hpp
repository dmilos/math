#ifndef math_geometry_interval_valid_hpp_
 #define math_geometry_interval_valid_hpp_

// ::math::geometry::interval::valid( )

#include "./structure.hpp"





 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template< typename scalar_name, unsigned dimension_number >
        inline
        bool
        valid
         (
           ::math::geometry::interval::structure< scalar_name, dimension_number >   const& instance
         )
         {
          unsigned index = dimension_number;

          while( index-- )
           {
            if( instance[ 1 ][index] < instance[ 0 ][index] )
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
