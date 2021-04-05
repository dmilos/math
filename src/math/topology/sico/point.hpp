#ifndef math_topology_sico_HyperPoint
#define math_topology_sico_HyperPoint

// ::math::topology::sico::hyper_point<data_name>( result, level, index, structure )



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
       size_t hyper_point // TODO change name
        (
           std::vector< std::size_t >              & result
         , std::size_t const& dimension
         , std::size_t const& index
         ,::math::topology::sico::structure<data_name> const& sc
        )
        {
         result.clear();
         if( false == sc.exists( dimension, index ) )
          {
           return result.size();
          }

         if( dimension < 3 )
          {
           return result.size();
          }

         auto const& simplex = sc.simplex( dimension, index );
         result.reserve( simplex.face().size() * ( simplex.face().size() -1 ) );
         for( size_t i =0; i < simplex.face().size(); ++i )
          {
           auto const& face = sc.simplex( dimension-1, simplex.face()[ i ] );

           for( size_t j =0; j < face.face().size(); ++j )
            {
             result.push_back( face.face()[ j ] );
            }
          }
         std::sort(result.begin(), result.end() );
         result.erase( std::unique( result.begin(), result.end() ), result.end() );
         return result.size();
        }

     }
   }
 }

#endif
