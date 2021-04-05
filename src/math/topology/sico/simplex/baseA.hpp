#ifndef math_topology_sico_simplex_baseA
#define math_topology_sico_simplex_baseA

// ::math::topology::sico::simplex::baseA<dimension_size>

#include <vector>

namespace math
 {
  namespace topology
   {
    namespace sico
     {
      namespace simplexxx
       {

        template
         <
           unsigned  dimension_size
         >
         struct base_fixed
          {
           public:
             typedef std::array<size_type, dimension_size + 1 > face_type;
             typedef std::vector<size_type> cell_type;

           public:
                       simplexA(){ }
              explicit simplexA( face_type const& face ): m_face(face) { }
              explicit simplexA( face_type const& face, cell_type const& cell ): m_face(face), m_cell(cell){ }

           public:
             face_type const& face() const{ return m_face; }
             face_type      & face()      { return m_face; }
           private:
             face_type m_face;

           public:
             cell_type const& cell() const{ return m_cell; }
             cell_type      & cell()      { return m_cell; }
           private:
             cell_type m_cell;
          };

        template<>
         struct simplexA < 0 >
          {
           public:
             // TODO
          };

     }
   }
 }

#endif
