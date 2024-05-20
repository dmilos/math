#ifndef math_geometry_interval_center_hpp_
 #define math_geometry_interval_center_hpp_
 
// ::math::geometry::interval::center( interval )
// ::math::geometry::interval::center( point, interval)
// ::math::geometry::interval::center( interval, point ) //!< this is re-centering

#include "./structure.hpp"
#include "./size.hpp"
#include "../../linear/vector/addition.hpp"
#include "../../linear/vector/scale.hpp"
#include "../../type/scalar.hpp"



 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template< typename scalar_name, ::math::type::size_type dimension_number, typename value_name = math::type::scalar_t >
        inline
        typename ::math::geometry::interval::structure< scalar_name, dimension_number >::point_type 
        center
         (
                   ::math::geometry::interval::structure< scalar_name, dimension_number >            const& instance
         ) //!< return version of center
         {
          typename ::math::geometry::interval::structure< scalar_name, dimension_number >::point_type     result;
          ::math::linear::vector::addition( result, instance[1], instance[0] );
          ::math::linear::vector::scale( result, value_name(0.5) );
          return result;
         }

       template< typename scalar_name, ::math::type::size_type dimension_number, typename value_name = math::type::scalar_t >
        inline
        void
        center
         (
          typename ::math::geometry::interval::structure< scalar_name, dimension_number >::point_type     & point
          ,        ::math::geometry::interval::structure< scalar_name, dimension_number >            const& instance
         ) //!< parameter version of center
         {
          ::math::linear::vector::addition( point, instance[1], instance[0] );
          ::math::linear::vector::scale( point, value_name(0.5) );
         }

       template< typename scalar_name, ::math::type::size_type dimension_number, typename value_name = math::type::scalar_t >
        inline
        void
        center
         (
                    ::math::geometry::interval::structure< scalar_name, dimension_number >                    & instance
          ,typename ::math::geometry::interval::structure< scalar_name, dimension_number >::point_type const  & point
         ) //!< keep size just recenter;
         { // TODO not optimal
           typename ::math::geometry::interval::structure< scalar_name, dimension_number >::point_type size;
          ::math::geometry::interval::size( size, instance );

          ::math::linear::vector::scale( size, value_name(0.5) );
          ::math::linear::vector::addition(    instance[1], point, size );
          ::math::linear::vector::subtraction( instance[0], point, size );
         }

      }
    }
  }

#endif