#ifndef math_geometry_interval_out_hpp_
 #define math_geometry_interval_out_hpp_

// ::math::geometry::interval::out( )

#include "./structure.hpp"





 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        bool
        out
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
              return true;
             }
            if( instance[ 1 ][index] < point[index])
             {
              return true;
             }
           }
          return false;
         }

      }
    }
  }

#endif
