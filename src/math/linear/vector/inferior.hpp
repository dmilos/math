#ifndef math_library_linear_algebra__vector_inferior_HPP_
 #define math_library_linear_algebra__vector_inferior_HPP_

 // ::math::linear::vector::inferior( coord )


#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, ::math::type::size_type dimension_number >
        inline
        std::pair<::math::type::size_type, scalar_name >
        inferior
         (
           ::math::linear::vector::structure< scalar_name, dimension_number > const& v
         )
         {
          std::pair<::math::type::size_type, scalar_name > result;
          auto & index = result.first = 0;
          auto & smallest = result.second = fabs( v[index] );

          for( ::math::type::size_type i = 1; i < dimension_number; ++i )// TODO not optimal
           {
            scalar_name chalenger = fabs( v[i] );
            if( chalenger < smallest )
             {
              smallest = chalenger;
              index = i;
             }
           }

          return result;
         }

       template< typename scalar_name >
        inline
        std::pair<::math::type::size_type, scalar_name >
        inferior
         (
           ::math::linear::vector::structure< scalar_name, 2 > const& v
         )
         {
          std::pair<::math::type::size_type, scalar_name > result;
          auto & index = result.first = 0;
          auto & smallest = result.second = fabs( v[index] );

          { scalar_name chalenger = fabs( v[1] ); if( chalenger < smallest ){ smallest = chalenger; index = 1; } }

          return result;
         }

       template< typename scalar_name >
        inline
        std::pair<::math::type::size_type, scalar_name >
        inferior
         (
           ::math::linear::vector::structure< scalar_name, 3 > const& v
         )
         {
          std::pair<::math::type::size_type, scalar_name > result;
          auto & index=result.first = 0;
          auto & smallest = result.second = fabs( v[index] );

          { scalar_name chalenger = fabs( v[1] ); if( chalenger < smallest ){ smallest = chalenger; index = 1; } }
          { scalar_name chalenger = fabs( v[2] ); if( chalenger < smallest ){ smallest = chalenger; index = 2; } }

          return result;
         }

       template< typename scalar_name >
        inline
        std::pair<::math::type::size_type, scalar_name >
        inferior
         (
           ::math::linear::vector::structure< scalar_name, 4 > const& v
         )
         {
          std::pair<::math::type::size_type, scalar_name > result;
          auto & index=result.first = 0;
          auto & smallest = result.second = fabs( v[index] );

          { scalar_name chalenger = fabs( v[1] ); if( chalenger < smallest ){ smallest = chalenger; index = 1; } }
          { scalar_name chalenger = fabs( v[2] ); if( chalenger < smallest ){ smallest = chalenger; index = 2; } }
          { scalar_name chalenger = fabs( v[3] ); if( chalenger < smallest ){ smallest = chalenger; index = 3; } }

          return result;
         }

     }
   }
 }

#endif
