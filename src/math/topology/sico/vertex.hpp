#ifndef math_topology_sico_vertex
#define math_topology_sico_vertex

// ::math::topology::sico::vertex<data_name>( result, level, index, structure )



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
       size_t vertex //!< All vertexes of given simplex(dimension,index)
        (
           std::vector< std::size_t >                       & result
         , std::size_t                                        dimension
         , std::size_t const                                & index
         ,::math::topology::sico::structure<data_name> const& sc
        )
        {
         result.clear();
         if( false == sc.exists( dimension, index ) )
          {
           return result.size();
          }

         std::vector< std::size_t > face( { index } );
         result.reserve( result.size() * result.size() );
         if( 0 == dimension )
          {
           result = face;
           return result.size();
          }

         do
          {
           result.clear();

           for( size_t i =0; i < face.size(); ++i )
            {
             auto other =  sc.simplex( dimension, face[ i ] ).face();
             result.reserve( result.size() + other.size() );
             result.insert( result.end(), other.begin(), other.end() );
            }
           std::sort(result.begin(), result.end() );
           result.erase( std::unique( result.begin(), result.end() ), result.end() );

           --dimension;
           if( 0 == dimension )
            {
             break;
            }
           face = result;
          }while( true );

         return result.size();
        }

     }
   }
 }

#endif
