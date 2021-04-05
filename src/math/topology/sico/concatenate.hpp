#ifndef math_topology_sico_concatenate
#define math_topology_sico_concatenate

// ::math::topology::sico::concatenation<data_name>

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
       size_t concatenate
        (
          ::math::topology::sico::structure<data_name>      & result
         ,::math::topology::sico::structure<data_name> const&  left
         ,::math::topology::sico::structure<data_name> const&  right
        )
        {
         typedef ::math::topology::sico::structure<data_name> structure_type;
         result = left;

         std::size_t offset = 0;
         std::vector< std::size_t > face_result;

         {
          face_result.resize( 0 );
          for( std::size_t index=0; index < right.size(0); ++index )
           {
            auto const& simplex = right.simplex(0,index);
            result.push( simplex.data(), face_result );
           }
         }

         for( std::size_t dimension=1; dimension < right.size(); ++dimension )
          {
           offset = left.size(dimension-1);
           face_result.resize( dimension + 1 );
           for( std::size_t index=0; index < right.size(dimension); ++index )
            {
             auto const& face_right = right.simplex(dimension,index).face();
             for( std::size_t j=0; j < face_result.size(); ++ j )
              {
               face_result[j] = face_right[j] + offset;
              }
             auto const& simplex = right.simplex(dimension,index);
             result.push( simplex.data(), face_result );
            }
          }

         return result.dimension();
        }

     }
   }
 }

#endif
