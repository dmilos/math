#ifndef math_topology_sico_link
#define math_topology_sico_link

// ::math::topology::sico::closure <data_name>( result, dimension, index, structure )
// ::math::topology::sico::closure <data_name>( result<<>>, dimension, index, structure )
// ::math::topology::sico::closure <data_name>( structure, dimension, index, structure )

#include <algorithm>
#include <vector>
#include "./structure.hpp"
#include "./star.hpp"

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
       inline size_t link // closure( star ) - star( closure )
        (
           std::vector< std::size_t >                        & result
         , std::size_t                                  const& dimension
         , std::size_t                                  const& index
         , ::math::topology::sico::structure<data_name> const& sc
        )
        { // todo
         result.clear();
         if( false == sc.exists( dimension, index ) )
          {
           return result.size();
          }

         std::vector< std::size_t > left; // todo
         { // closure( star ) // todo
          std::vector< std::size_t > star;
         ::math::topology::sico::star( star, dimension, index, sc );
          std::vector< std::size_t > closure;
          for( auto const& element : star )
           {
            ::math::topology::sico::closure (      closure, dimension+1, element, sc );
            left.insert( left.end(), closure.begin(), closure.end() );
           }
           std::sort( left.begin(), left.end() );
           left.erase( std::unique( left.begin(), left.end() ), left.end() );
         }

         std::vector< std::size_t > right; // todo
         { // star( closure ) // todo
          std::vector< std::size_t > closure;
          ::math::topology::sico::closure (      closure, dimension, index, sc );
          std::vector< std::size_t > star;
          for( auto const& element : closure )
           {
            ::math::topology::sico::star (      star, dimension-1, element, sc );
            right.insert( right.end(), star.begin(), star.end() );
           }
           std::sort( right.begin(), right.end() );
           right.erase( std::unique( right.begin(), right.end() ), right.end() );
         }

         for( auto const & face: left )
          { // result = left - right;
           if( right.end() != std::find( right.begin(), right.end(), face ) )
            {
             continue;
            }
            result.push_back( face );
          }

         return result.size();
        }

     }
   }
 }

#endif
