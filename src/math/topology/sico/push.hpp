#ifndef math_topology_sico_push
#define math_topology_sico_push

// ::math::topology::sico::push<data_name>( result, data, list )

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
       size_t push
        (
          ::math::topology::sico::structure<data_name>      & sc
         , data_name                                   const& data
         ,::std::initializer_list<std::size_t>         const& list
        )
        {
         typedef ::math::topology::sico::structure<data_name> structure_type;
         typedef typename structure_type::simplex_type          simplex_type;
         typedef typename simplex_type::face_type                  face_type;

         return sc.push( data, face_type( list ) );
        }

     }
   }
 }

#endif
