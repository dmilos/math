#ifndef math_topology_sico_skeleton
#define math_topology_sico_skeleton

// ::math::topology::sico::skeleton<data_name>( result, data, list )

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
       size_t skeleton
        (
          ::math::topology::sico::structure<data_name>       & result
         ,size_t                                        const& dimension
         ,::math::topology::sico::structure<data_name>  const& model
        )
        {
         result = model;
         return result.trim( dimension );
        }

     }
   }
 }

#endif
