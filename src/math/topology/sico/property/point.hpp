#ifndef math_topology_sico_property_point
#define math_topology_sico_property_point

// ::math::topology::sico::property::point<data_name>


#include "../simplex/loaded.hpp"
#include "./scalar.hpp"

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
           typename     scalar_number //=  ::math::topology::sico::property::scalar_struct<data_name>::type_type
          ,unsigned   dimesion_number
          ,typename         data_name //!< Essentially whatever. Copyable
         >
         inline ::math::linear::vector::point< scalar_number, dimesion_number > const &
         point
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
