#ifndef math_topology_sico_property_color
#define math_topology_sico_property_color

// ::math::topology::sico::property::color<data_name>

#ifdef color_a9f1aad2_e23c_4f7e_9dce_0f1c116f4968
#else
#include <cstdint>
#endif

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
#ifdef color_a9f1aad2_e23c_4f7e_9dce_0f1c116f4968
           typename     component_name,
#endif
           typename         data_name //!< Essentially whatever. Copyable
         >
#ifdef color_a9f1aad2_e23c_4f7e_9dce_0f1c116f4968
         inline ::color::rgb<component_name> const &
#else
         inline std::uint32_t const &
#endif
         color
          (
           ::math::topology::sico::simplex::loaded<data_name> const& simplex
          )
          {
           return simplex.data();
          }

       }
     }
   }
 }

#endif
