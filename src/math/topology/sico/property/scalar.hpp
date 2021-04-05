#ifndef math_topology_sico_property_scalar
#define math_topology_sico_property_scalar

// ::math::topology::sico::property::scalar_struct<data_name>::type_type


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
         struct scalar_struct
          {
           typedef double type_type;
          };

       }
     }
   }
 }

#endif
