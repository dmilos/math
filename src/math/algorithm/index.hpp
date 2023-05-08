#ifndef math_algorithm_index_HPP_
 #define math_algorithm_index_HPP_

// math::algorithm::index( size, position )

#include <array>

 namespace math
  {
   namespace algorithm
    {

     template< ::math::type::size_type dimension_number >
      ::math::type::size_type index
       (
         std::array< ::math::type::size_type, dimension_number > const& size_param
        ,std::array< ::math::type::size_type, dimension_number > const& position_param
       )
       {
        ::math::type::size_type result=0;
        ::math::type::size_type product=1;
        for( ::math::type::size_type ordinata=0; ordinata < dimension_number; ++ordinata )
        {
         result +=  position_param[ordinata] * product;
         product *= size_param[ ordinata ];
        }
        return result;
       }

      inline ::math::type::size_type index
       (
         std::array< ::math::type::size_type, 1 > const& size_param
        ,std::array< ::math::type::size_type, 1 > const& position_param
       )
       {
        return + position_param[0]
              ;
       }

      inline ::math::type::size_type index
       (
         std::array< ::math::type::size_type, 2 > const& size_param
        ,std::array< ::math::type::size_type, 2 > const& position_param
       )
       {
        return + position_param[1] * size_param[0]
               + position_param[0]
              ;
       }

      inline ::math::type::size_type index
       (
         std::array< ::math::type::size_type, 3 > const& size_param
        ,std::array< ::math::type::size_type, 3 > const& position_param
       )
       {
        return + position_param[2] * size_param[0] * size_param[1]
               + position_param[1] * size_param[0]
               + position_param[0]
              ;
       }

      inline ::math::type::size_type index
       (
         std::array< ::math::type::size_type, 4 > const& size_param
        ,std::array< ::math::type::size_type, 4 > const& position_param
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
