#ifndef math_topology_sico_closure
#define math_topology_sico_closure

// ::math::topology::sico::closure <data_name>( result, dimension, index, structure )
// ::math::topology::sico::closure <data_name>( result<<>>, dimension, index, structure )
// ::math::topology::sico::closure <data_name>( structure, dimension, index, structure )

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
       inline size_t closure // All faces of given simplex( dimension, index )
        (
           std::vector< std::size_t >              & result
         , std::size_t const& dimension
         , std::size_t const& index
         ,::math::topology::sico::structure<data_name> const& sc // can be very big.
        )
        {
         if( false == sc.exists( dimension, index ) )
          {
           return result.size();
          }

         auto const& simplex = sc.simplex( dimension, index );
         result = simplex.face();

         return result.size();
        }

      template
       <
         typename  data_name
       >
       inline size_t closure // All (sub-...)faces
        (
           std::vector< std::vector< std::size_t > >         & result
         , std::size_t                                         dimension
         , std::size_t                                  const& index
         , ::math::topology::sico::structure<data_name> const& sc // can be very big.
        )
        {
         result.clear();
         if( false == sc.exists( dimension, index ) )
          {
           return result.size();
          }
         result.resize( dimension + 1 );
         result[dimension].push_back( index );

         std::vector< std::size_t > closure;
         for( ; dimension; dimension-- )
          {
           auto const& face = result[ dimension ];
           auto & lower_level = result[ dimension -1 ];

           for( auto const& index : face )
            {
             ::math::topology::sico::closure( closure, dimension, index, sc );
             lower_level.insert( lower_level.end(), closure.begin(), closure.end() );
            }

           std::sort( lower_level.begin(), lower_level.end() );
           lower_level.erase( std::unique( lower_level.begin(), lower_level.end() ), lower_level.end() );
          }

         return result.size();
        }

      template
       <
         typename  data_name
       >
       inline size_t closure // All (sub-...)faces as new topology
        (
          ::math::topology::sico::structure<data_name>      & result
         ,std::size_t                                  const& dimension
         ,std::size_t                                  const& index
         ,::math::topology::sico::structure<data_name> const& sico // can be very big.
        )
        {
         result.clear();
         if( false == sico.exists( dimension, index ) )
          {
           return result.size();
          }

         std::vector< std::vector< std::size_t > > closure;
         ::math::topology::sico::closure( closure, dimension, index, sico );

         std::vector< std::size_t > reindex;
         reindex = closure[0];
         for( std::size_t index=0; index < closure[0].size(); ++index )
          {
           result.push( sico.vertex( reindex[index] ), {} );
          }

         // TODO calc reindex
         // TODO face_type face;
         for( std::size_t level=0; level < dimension; ++level )
          {
           for( std::size_t index=0; index < closure[level].size(); ++index )
            {
             // TODO face.reserve( sico.simplex( level, index ).face().size() );
             for( std::size_t fi=0; fi< sico.simplex( level, index ).face().size(); ++ fi)
              {
               // face[ index ] = TODO
              }
             // TODO result.push( sico.simplex( level, closure[ reindex[index] ] ).data(), face );
            }
          }

         return result.size();
        }

     }
   }
 }

#endif
