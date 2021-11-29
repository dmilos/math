#ifndef Dh_math_linear_matrix_GramSchmidt
 #define Dh_math_linear_matrix_GramSchmidt

 // ::math::linear::matrix::GramSchmidt<scalar_name,width_number,height_number>
 // ::math::linear::matrix::GramSchmidt<scalar_name,dimenion_number>( system )

#include "./one.hpp"

 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        bool
        GramSchmidt
         (
           ::math::linear::matrix::structure<scalar_name,width_number, height_number >      & result
          ,::math::linear::matrix::structure<scalar_name,width_number, height_number > const& system
         )
         { // WARNING: vectors are in rows
          typedef decltype(  system.size() ) size_type;
          if( width_number < height_number ) return false;

          ::math::linear::vector::length( result[0], system[0] , scalar_name(1) );

          for( size_type i=1; i < system.size(); ++i )
           {
            ::math::linear::vector::structure< scalar_name, width_number> p;
            auto original = result[i] = system[i];

            for( size_type j=0; j < i; ++j )
             {
              auto dot = ::math::linear::vector::dot( original, result[ j ] );
              ::math::linear::vector::scale( p, dot, result[ j ] );
              ::math::linear::vector::subtraction( result[ i ], p );
             }

            ::math::linear::vector::length( result[i], scalar_name(1) );
           }

          return true;
         }

       template< typename scalar_name, unsigned dimension_number >
        bool
        GramSchmidt
         (
           std::vector< ::math::linear::vector::structure< scalar_name, dimension_number > > & system
         )
         {
          typedef decltype( system.size() ) size_type;

          ::math::linear::vector::length( system[0], scalar_name(1) );

          for( size_type i=1; i < std::min<unsigned>( dimension_number, (unsigned)system.size() ); ++i )
           {
            ::math::linear::vector::structure< scalar_name, dimension_number> p;
            auto original = system[i];

            for( size_type j=0; j < i; ++j )
             {
              auto dot = ::math::linear::vector::dot( original, system[ j ] );
              ::math::linear::vector::scale( p, dot, system[ j ] );
              ::math::linear::vector::subtraction( system[ i ], p );
             }

            ::math::linear::vector::length( system[i], scalar_name(1) );
           }

          return true;
         }

      }
    }
  }

#endif
