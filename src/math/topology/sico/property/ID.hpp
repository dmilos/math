#ifndef math_topology_sico_property_ID
#define math_topology_sico_property_ID

// ::math::topology::sico::property::ID<data_name>


#include "../simplex/loaded.hpp"

namespace math
 {
  namespace topology
   {
    namespace sico
     {
      namespace property
       {

       template
        <
         typename         data_name //!< Essentially whatever. Copyable
        >
        inline std::size_t const &
        ID
         (
           ::math::topology::sico::simplex::loaded<data_name> const& simplex
         )
         {
          static std::size_t id=0;
          return id;
         }

       }
     }
   }
 }

#endif
