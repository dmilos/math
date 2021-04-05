#ifndef Dh_math_linear_vector_GramSchmidt
 #define Dh_math_linear_vector_GramSchmidt

 // ::math::linear::vector::GramSchmidt<scalar_name,width_number,height_number>

#include "./length.hpp"
#include "./scale.hpp"
#include "./subtraction.hpp"

 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, unsigned dimension_number >
        bool
        GramSchmidt
         (
            std::vector< ::math::linear::vector::structure<scalar_name,dimension_number> >      & result
          , std::vector< ::math::linear::vector::structure<scalar_name,dimension_number> > const& system
         )
         {
          typedef decltype(  system.size() ) size_type;
          if( dimension_number < system.size() ) return false;
          result.resize( system.size() );

          ::math::linear::vector::length( result[0], system[0] , scalar_name(1) );

          for( size_type i=1; i< system.size(); ++i )
           {
            ::math::linear::vector::structure< scalar_name, dimension_number> p;
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

      }
    }
  }

#endif
