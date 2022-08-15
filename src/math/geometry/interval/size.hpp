#ifndef math_geometry_interval_size_hpp_
 #define math_geometry_interval_size_hpp_
 
// ::math::geometry::interval::size( point, instance )
// ::math::geometry::interval::size( instance )

#include "./structure.hpp"
#include "../../linear/vector/addition.hpp"
#include "../../linear/vector/scale.hpp"



 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        void
        size
         (
          typename ::math::geometry::interval::structure< scalar_name, dimension_number >::point_type     & point
          ,        ::math::geometry::interval::structure< scalar_name, dimension_number >            const& instance
         )
         {
          ::math::linear::vector::subtraction( point, instance[1], instance[0] );
         }

       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        typename ::math::geometry::interval::structure< scalar_name, dimension_number >::point_type
        size
         (
                   ::math::geometry::interval::structure< scalar_name, dimension_number >            const& instance
         )
         {
          typename ::math::geometry::interval::structure< scalar_name, dimension_number >::point_type result;
          ::math::linear::vector::subtraction( result, instance[1], instance[0] );
          return result;
         }

      }
    }
  }

#endif