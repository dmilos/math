#ifndef math_geometry_interval_translate_hpp_
 #define math_geometry_interval_translate_hpp_

// ::math::geometry::interval::translate( )

#include "./structure.hpp"

#include "../../linear/vector/addition.hpp"



 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        void
        translate
         (
                     ::math::geometry::interval::structure< scalar_name, dimension_number >                  & result
          ,          ::math::geometry::interval::structure< scalar_name, dimension_number >             const& left
          ,typename  ::math::geometry::interval::structure< scalar_name, dimension_number >::point_type const& point
         )
         {
          ::math::linear::vector::addition( result[0], left[0], point );
          ::math::linear::vector::addition( result[1], left[1], point );
         }

       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        void
        translate
         (
                     ::math::geometry::interval::structure< scalar_name, dimension_number >                  & result
          ,typename  ::math::geometry::interval::structure< scalar_name, dimension_number >::point_type const& point
         )
         {
          ::math::linear::vector::addition( result[0], point );
          ::math::linear::vector::addition( result[1], point );
         }

      }
    }
  }

#endif