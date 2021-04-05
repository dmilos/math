#ifndef math_topology_sico_simplex_loaded
#define math_topology_sico_simplex_loaded

// ::math::topology::sico::simplex::loaded<data_name>

#include "./base.hpp"

namespace math
 {
  namespace topology
   {
    namespace sico
     {
      namespace simplex
       {

        template
         <
           typename  data_name //!< Essentially whatever. Copyable
         >
         struct loaded
          : public ::math::topology::sico::simplex::base
          {
           public:
             typedef data_name data_type;

             typedef ::math::topology::sico::simplex::base base_type;

                      loaded(){ }
             explicit loaded( data_name const& data_param ):m_data(data_param){ }
             explicit loaded( data_name const& data_param, face_type const& face ):m_data(data_param), base_type(face) { }
             explicit loaded( data_name const& data_param, face_type const& face, cell_type const& cell ):m_data(data_param), base_type(face,cell){ }

           public:
             data_name const& data() const{ return m_data; }
             data_name      & data()      { return m_data; }
           private:
             data_name m_data;
          };

       template<>
        struct loaded<void>
         : public ::math::topology::sico::simplex::base
         {
          public:
            typedef void   data_type;
            typedef ::math::topology::sico::simplex::base base_type;

          public:
            explicit loaded(){ }
            explicit loaded( face_type const& face ):base_type(face){ }
            explicit loaded( face_type const& face, cell_type const& cell ):base_type(face,cell){ }
         };

       }
     }
   }
 }

#endif
