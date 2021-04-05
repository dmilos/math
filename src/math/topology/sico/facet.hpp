#ifndef math_topology_sico_facet
#define math_topology_sico_facet

// ::math::topology::sico::facet<data_name>( dimension, index, structure )

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
       bool facet // Is simplex( dimension,index) facet or not, 0 == star( dimension,index, sc )
        (
           std::size_t                                 const& dimension
         , std::size_t                                 const& index
         ,::math::topology::sico::structure<data_name> const& sc
        )
        {
         if( false == sc.exists( dimension, index ) )
          {
           return false;
          }

         auto upper = dimension + 1;

         for( size_t i = 0; i < sc.size( upper ); ++i )
          {
           auto const& simplex = sc.simplex( upper, i );
           for( size_t j = 0; j < simplex.face().size(); ++j )
            {
             if( index == simplex.face()[ j ] )
              {
               return false;
              }
            }
          }

         return true;
        }

     }
   }
 }

#endif
