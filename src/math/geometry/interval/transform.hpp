#ifndef math_geometry_interval_transform_hpp_
 #define math_geometry_interval_transform_hpp_

// ::math::geometry::interval::transform( )

#include "./structure.hpp"

#include "../../linear/affine/transform.hpp"
#include "../../algorithm/variation.hpp"


 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        void
        transform
         (
           ::math::geometry::interval::structure< scalar_name, dimension_number >        & result
          ,::math::linear::affine::structure< scalar_name, dimension_number >       const& affine
          ,::math::geometry::interval::structure< scalar_name, dimension_number >   const& model
         )
         {
          typedef ::math::linear::vector::point< scalar_name, dimension_number >  point_type;
          ::math::linear::affine::transform( result[0], affine, model[0] );
          result[1]= result[0];

          std::array<unsigned, dimension_number > variator{0};

          while( ::math::algorithm::next_variation<unsigned>(variator.begin(), variator.end(), 0, 2 ) )
           {
            point_type a, b;
            for( unsigned index=0; index < dimension_number; ++index )
             {
              a[index] = model[variator[index]][index];
             }
            ::math::linear::affine::transform( b, affine, a );
            ::math::geometry::interval::extend( result, b );
           }


         }

       template< typename scalar_name >
        inline
        void
        transform
         (
           ::math::geometry::interval::structure< scalar_name, 2 >       & result
          ,::math::linear::affine::structure< scalar_name, 2 >      const& affine
          ,::math::geometry::interval::structure< scalar_name, 2 >  const& model
         )
         {
          typedef ::math::linear::vector::point< scalar_name, 2 >  point_type;
          ::math::linear::affine::transform( result[0], affine, model[0] );
          result[1]= result[0];

          for( int x=0; x< 2; x++)
           {
            for( int y=0; y< 2; y++)
             {
              point_type a, b;
              a[0] = model[x][0];
              a[1] = model[y][1];
              ::math::linear::affine::transform( b, affine, a );
              ::math::geometry::interval::extend( result, b );
             }
           }
         }

       template< typename scalar_name >
        inline
        void
        transform
         (
           ::math::geometry::interval::structure< scalar_name, 3 >       & result
          ,::math::linear::affine::structure< scalar_name, 3 >      const& affine
          ,::math::geometry::interval::structure< scalar_name, 3 >  const& model
         )
         {
          typedef ::math::linear::vector::point< scalar_name, 3 >  point_type;
          ::math::linear::affine::transform( result[0], affine, model[0] );
          result[1]= result[0];

          for( int x=0; x < 2; x++)
           {
            for( int y=0; y < 2; y++)
             {
              for( int z=0; z < 2; z++)
               {
                point_type a, b;
                a[0] = model[x][0];
                a[1] = model[y][1];
                a[2] = model[z][2];
                ::math::linear::affine::transform( b, affine, a );
                ::math::geometry::interval::extend( result, b );
               }
             }
           }
         }

      }
    }
  }

#endif