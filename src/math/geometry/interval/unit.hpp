#ifndef math_geometry_interval_unit_hpp_
 #define math_geometry_interval_unit_hpp_

// ::math::geometry::interval::unit( interval, number )

#include "./structure.hpp"





 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template< typename scalar_name, unsigned dimension_number >
        inline
        void
        unit
         (
           ::math::geometry::interval::structure< scalar_name, dimension_number >                  & instance
         )
         {
          ::math::linear::vector::fill( instance[0], 0 );
          ::math::linear::vector::fill( instance[1], 1 );
         }

      }
    }
  }

#endif
