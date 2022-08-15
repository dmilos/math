#ifndef math_algorithm_index_HPP_
 #define math_algorithm_index_HPP_

// math::algorithm::index

#include <array>

 namespace math
  {
   namespace algorithm
    {

     template< ::math::type::size_type dimension_number >
      std::size_t index
       (
         std::array< std::size_t, dimension_number > const& size_param
        ,std::array< std::size_t, dimension_number > const& position_param
       )
       {
        std::size_t result=0;
        std::size_t product=1;
        for( std::size_t ordinata=0; ordinata < dimension_number; ++ordinata )
        {
         result +=  position_param[ordinata] * product;
         product *= size_param[ ordinata ];
        }
        return result;
       }

      inline std::size_t index
       (
         std::array< std::size_t, 1 > const& size_param
        ,std::array< std::size_t, 1 > const& position_param
       )
       {
        return + position_param[0]
              ;
       }

      inline std::size_t index
       (
         std::array< std::size_t, 2 > const& size_param
        ,std::array< std::size_t, 2 > const& position_param
       )
       {
        return + position_param[1] * size_param[0]
               + position_param[0]
              ;
       }

      inline std::size_t index
       (
         std::array< std::size_t, 3 > const& size_param
        ,std::array< std::size_t, 3 > const& position_param
       )
       {
        return + position_param[2] * size_param[0] * size_param[1]
               + position_param[1] * size_param[0]
               + position_param[0]
              ;
       }

      inline std::size_t index
       (
         std::array< std::size_t, 4 > const& size_param
        ,std::array< std::size_t, 4 > const& position_param
       )
       {
        return + position_param[3] * size_param[0] * size_param[1] * size_param[2]
               + position_param[2] * size_param[0] * size_param[1]
               + position_param[1] * size_param[0]
               + position_param[0]
              ;
       }
    }
 }

#endif
