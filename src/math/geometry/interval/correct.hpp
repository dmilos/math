#ifndef math_geometry_interval_correct_hpp_
 #define math_geometry_interval_correct_hpp_

// ::math::geometry::interval::correct( )

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
        correct
         (
           ::math::geometry::interval::structure< scalar_name, dimension_number >       & result
          ,::math::geometry::interval::structure< scalar_name, dimension_number >  const& right
         )
         {
          unsigned index = dimension_number;

          while( index-- )
           {
            if( right[ 0 ][index] < right[ 1 ][index] )
             {
              result[ 0 ][ index ] = right[ 0 ][index];
              result[ 1 ][ index ] = right[ 1 ][index];
             }
            else
             {
              result[ 0 ][ index ] = right[ 1 ][index];
              result[ 1 ][ index ] = right[ 0 ][index];
             }
           }
         }

       template< typename scalar_name, unsigned dimension_number >
        inline
        void
        correct
         (
           ::math::geometry::interval::structure< scalar_name, dimension_number >   & instance
         )
         {
          unsigned index = dimension_number;

          while( index-- )
           {
            if( instance[ 1 ][index] < instance[ 0 ][index] )
             {
              std::swap( instance[ 1 ][index], instance[ 0 ][index] );
             }
           }
         }

      }
    }
  }

#endif


