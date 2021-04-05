#ifndef math_topology_sico_simplex_base
#define math_topology_sico_simplex_base

// ::math::topology::sico::simplex::base

#include "./basic.hpp"

namespace math
 {
  namespace topology
   {
    namespace sico
     {
      namespace simplex
       {

        struct base
         : public ::math::topology::sico::simplex::basic
         {
          public:
            typedef ::math::topology::sico::simplex::basic basic_type;

            using basic_type::size_type;
            using basic_type::face_type;

            typedef std::vector<size_type> cell_type;

                     base(){}
            explicit base( face_type const& face ): basic_type(face) { }
            explicit base( face_type const& face, cell_type const& cell ): basic_type(face), m_cell(cell){ }

          public:
            cell_type const& cell() const{ return m_cell; }
            cell_type      & cell()      { return m_cell; }
          private:
            cell_type m_cell;
         };

       }
     }
   }
 }

#endif
