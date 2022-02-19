#ifndef math_geometry_interval_confine_hpp_
 #define math_geometry_interval_confine_hpp_

// ::math::geometry::interval::confine( result, point, interval )
// ::math::geometry::interval::confine( point, interval )
// ::math::geometry::interval::confine( line, interval )

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
        confine
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >           & result
          ,::math::linear::vector::structure< scalar_name, dimension_number >      const& point
          ,::math::geometry::interval::structure< scalar_name, dimension_number >  const& structure
         )
         {
          auto index = dimension_number;

          auto lo = structure[0];
          auto hi = structure[1];

          while( index-- )
           {
            auto const& v = point[index];
            if( v < lo[index] ){ result[index] = lo[index]; continue; }
            if( hi[index] < v ){ result[index] = hi[index]; continue; }
            result[index] = v;
           }
         }

       template< typename scalar_name, unsigned dimension_number >
        inline
        void
        confine
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >           & result
          ,::math::geometry::interval::structure< scalar_name, dimension_number >  const& structure
         )
         {
          auto index = dimension_number;

          auto lo = structure[0];
          auto hi = structure[1];

          while( index-- )
           {
            auto const& v = result[index];
            if( v < lo[index] ){ result[index] = lo[index]; continue; }
            if( hi[index] < v ){ result[index] = hi[index]; continue; }
           }
         }

       template < typename scalar_name, unsigned dimension_number >
        bool
        confine
         (
           ::math::geometry::direction::parametric< scalar_name, dimension_number >       & line
          ,::math::geometry::interval::structure<   scalar_name, dimension_number >  const& window
         )
         {
          std::tuple< unsigned, scalar_name, unsigned, scalar_name > result;
          if( false == ::math::geometry::interval::intersect( result, window, line ) )
           {
            return false;
           }
          ::math::linear::vector::combine( line.origin(), line.origin(), std::get<1>(result), line.direction() );
          ::math::linear::vector::scale( line.direction(), std::get<3>(result) - std::get<1>(result) );
          return true;
         }

       template < typename scalar_name, unsigned dimension_number >
        bool
        confine
         (
           ::math::geometry::direction::two< scalar_name, dimension_number >              & line
          ,::math::geometry::interval::structure<   scalar_name, dimension_number >  const& window
         )
         {
          ::math::geometry::direction::parametric< scalar_name, dimension_number >  parametric { line };
          if( false == ::math::geometry::interval::confine( parametric, window ) )
           {
            return false;
           }
          line = parametric;

          return true;
         }

      }
    }
  }

#endif
