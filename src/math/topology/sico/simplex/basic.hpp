#ifndef math_topology_sico_simplex_basic
#define math_topology_sico_simplex_basic

// ::math::topology::sico::simplex::basic

#include <vector>

namespace math
 {
  namespace topology
   {
    namespace sico
     {
      namespace simplex
       {

        struct basic //!< Does not contain cell
         {
          public:
            typedef size_t size_type;

            typedef std::vector<size_type> face_type;

                     basic(){ }
            explicit basic( face_type const& face ): m_face(face) { }

          public:
            face_type const& face() const{ return m_face; }
            face_type      & face()      { return m_face; }
          private:
            face_type m_face;
         };

       }
     }
   }
 }

#endif
