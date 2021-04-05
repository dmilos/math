#ifndef math_topology_sico_star
#define math_topology_sico_star

// ::math::topology::sico::star <data_name>( result<>, dimension, index, structure )
// ::math::topology::sico::star <data_name>( result<<>>, dimension, index, structure )


#include <algorithm>
#include <vector>
#include "./structure.hpp"

namespace math
 {
  namespace topology
   {
    namespace sico
     {

      template
       <
         typename  data_name
       >
       size_t star  // All simplexes of dimension+1 that contain this simplex(dimension,index)
        (
           std::vector< std::size_t >                       & result
         , std::size_t                                 const& dimension
         , std::size_t                                 const& index
         ,::math::topology::sico::structure<data_name> const& sico
        )
        {
         result.clear();
         if( false == sico.exists( dimension, index ) )
          {
           return result.size();
          }
         result = sico.simplex( dimension, index ).cell();
         return result.size();
        }

      template
       <
         typename  data_name
       >
       size_t star  // All simplexes that contain this simplex(dimension,index)
        (
           std::vector< std::vector< std::size_t > >        & result
         , std::size_t                                 const& dimension
         , std::size_t                                 const& index
         ,::math::topology::sico::structure<data_name> const& sico
        )
        {
         result.clear();
         if( false == sico.exists( dimension, index ) )
          {
           return result.size();
          }
         result.reserve( sico.size() );
         result.resize( dimension + 1 );
         result[dimension].push_back( index );
         std::vector< std::size_t > rrr;
         for( std::size_t level = dimension; level < sico.size(); ++level )
          {
           result.resize( result.size() + 1 );
           auto & upper_level = result[ level + 1 ];
           for( std::size_t position=0; position < result[level].size(); ++position )
            {
             ::math::topology::sico::star( rrr, level, result[level][position], sico );
             upper_level.insert( upper_level.end(), rrr.begin(), rrr.end() );
            }

           std::sort( upper_level.begin(), upper_level.end() );
           upper_level.erase( std::unique( upper_level.begin(), upper_level.end() ), upper_level.end() );

           if( 0 == upper_level.size() )
            {
             result.resize( result.size() - 1 );
             break;
            }
          }

         return result.size();
        }

     }
   }
 }

#endif
