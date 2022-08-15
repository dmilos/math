#ifndef math_geometry_interval_inflate_hpp_
 #define math_geometry_interval_inflate_hpp_

// ::math::geometry::interval::inflate( result, pivot, scale, model )
// ::math::geometry::interval::inflate( result, scale, model )

#include "./structure.hpp"


 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        void
        inflate
         (
           ::math::geometry::interval::structure< scalar_name, dimension_number >       & result
          ,::math::linear::vector::structure< scalar_name, dimension_number >      const& pivot
          ,::math::linear::vector::structure< scalar_name, dimension_number >      const& scale
          ,::math::geometry::interval::structure< scalar_name, dimension_number >  const& model
         )
         {
          auto index = dimension_number;

          while( index-- )
           {
            result[1][index] = scale[index]*(model[1][index] - pivot[index] ) + pivot[index];
            result[0][index] = scale[index]*(model[0][index] - pivot[index] ) + pivot[index];
           }
         }

       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        void
        inflate
         (
           ::math::geometry::interval::structure< scalar_name, dimension_number >       & result
          ,::math::linear::vector::structure< scalar_name, dimension_number >      const& pivot
          ,scalar_name                                                             const& scale
          ,::math::geometry::interval::structure< scalar_name, dimension_number >  const& model
         )
         {
          auto index = dimension_number;

          while( index-- )
           {
            result[1][index] = scale*(model[1][index] - pivot[index] ) + pivot[index];
            result[0][index] = scale*(model[0][index] - pivot[index] ) + pivot[index];
           }
         }

       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        void
        inflate
         (
           ::math::geometry::interval::structure< scalar_name, dimension_number >       & result
          ,::math::linear::vector::structure< scalar_name, dimension_number >      const& scale
          ,::math::geometry::interval::structure< scalar_name, dimension_number >  const& model
         )
         {
          ::math::linear::vector::structure< scalar_name, dimension_number > pivot;
          ::math::linear::vector::convex<scalar_name>( pivot, scalar_name(0.5), model[0], model[1] );
          return ::math::geometry::interval::inflate<scalar_name,dimension_number>( result, pivot, scale, model );
         }
         
       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        void
        inflate
         (
           ::math::geometry::interval::structure< scalar_name, dimension_number >       & result
          ,scalar_name                                                             const& scale
          ,::math::geometry::interval::structure< scalar_name, dimension_number >  const& model
         )
         {
          ::math::linear::vector::structure< scalar_name, dimension_number > pivot;
          ::math::linear::vector::convex<scalar_name>( pivot, scalar_name(0.5), model[0],model[1] );
          return ::math::geometry::interval::inflate<scalar_name,dimension_number>( result, pivot, scale, model );
         }

      }
    }
  }

#endif


