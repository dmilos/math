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

       template< typename scalar_name, ::math::type::size_type width_number, ::math::type::size_type height_number >
        bool
        GramSchmidt
         (
           ::math::linear::matrix::structure<scalar_name,width_number, height_number >      & result
          ,::math::linear::matrix::structure<scalar_name,width_number, height_number > const& system
          , scalar_name const epsilon = 1e-6
         ) //!< WARNING: vectors are in rows
         {
          typedef decltype(  system.size() ) size_type;
          if( width_number < height_number ) return false;

          auto length = ::math::linear::vector::length( result[0], system[0], scalar_name(1) );

          if( length < epsilon )
           {
            return false;
           }

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

            length = ::math::linear::vector::length( result[i], scalar_name(1) );
            if( length < epsilon )
             {
              return false;
             }
           }

          return true;
         }

       template< typename scalar_name, ::math::type::size_type dimension_number >
        bool
        GramSchmidt
         (
           std::vector< ::math::linear::vector::structure< scalar_name, dimension_number > > & system
          ,scalar_name const epsilon = 1e-6
         )
         {
          typedef decltype( system.size() ) size_type;

          auto length = ::math::linear::vector::length( system[0], scalar_name(1) );
          if( length < epsilon )
           {
            return false;
           }

          for( size_type i=1; i < std::min<::math::type::size_type>( dimension_number, (::math::type::size_type)system.size() ); ++i )
           {
            ::math::linear::vector::structure< scalar_name, dimension_number> p;
            auto original = system[i];

            for( size_type j=0; j < i; ++j )
             {
              auto dot = ::math::linear::vector::dot( original, system[ j ] );
              ::math::linear::vector::scale( p, dot, system[ j ] );
              ::math::linear::vector::subtraction( system[ i ], p );
             }

            length = ::math::linear::vector::length( system[i], scalar_name(1) );
            if( length < epsilon )
             {
              return false;
             }
           }

          return true;
         }

      }
    }
  }

#endif
