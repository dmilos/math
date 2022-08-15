#ifndef math_topology_sico_NNG
#define math_topology_sico_NNG

// ::math::topology::sico::NNG<data_name>

#include <array>
#include <vector>
#include <limits>

#include "../structure.hpp"
#include "../../../linear/vector/distance.hpp"
#include "../property/point.hpp"

namespace math
 {
  namespace topology
   {
    namespace sico
     {

     template
       <
         typename    scalar_name
        ,::math::type::size_type  dimesion_number
        ,typename      data_name //!< Essentially whatever. Copyable
       >
       std::size_t NNG //!< Nearest neighbor graph
       (
         ::math::topology::sico::structure<data_name>                     & result
       )
       {
        result.trim( 0 );
        for( ::math::type::size_type index=0; index < result.size(0); ++index )
         {
          size_t neighbor = result.size(0);
          scalar_name nearest = std::numeric_limits<scalar_name>::max();
          auto const & left  = ::math::topology::sico::property::point<scalar_name,dimesion_number>( result.simplex( 0, index ) );

          for( std::size_t challenger =0; challenger < result.size(0); ++challenger )
           {
            if( index == challenger )
             {
              continue;
             }

            scalar_name distance;
            {
             auto const & right = ::math::topology::sico::property::point<scalar_name,dimesion_number>( result.simplex( 0, challenger ) );
             distance = ::math::linear::vector::distance( left, right );
            }
            if( distance < nearest )
             {
              nearest = distance;
              neighbor = challenger;
             }
           }

           result.push( data_name{}, {index,neighbor} );
         }
        return result.size();
       }

     }
   }
 }

#endif
