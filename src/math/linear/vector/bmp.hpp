#ifndef math_linear_vector_BMP
#define math_linear_vector_BMP

// ::math::linear::vector::BMP<scalar_name,dimension_number>

#include <array>
#include <vector>
#include <limits>

#include "./structure.hpp"
#include "./distance.hpp"

 namespace math
  {
   namespace linear
    {
     namespace vector
      {

     template
       <
         typename    scalar_name
        ,::math::type::size_type  dimension_number
       >
       void BMP //!< Best matching pairs
       (
         ::std::vector< ::math::type::size_type >                                            & to_left  //!< index toward left  side.
        ,::std::vector< ::math::type::size_type >                                            & to_right //!< index toward right side.
        ,::std::vector< ::math::linear::vector::vector<scalar_name,dimension_number>  > const& left
        ,::std::vector< ::math::linear::vector::vector<scalar_name,dimension_number>  > const& right
       )
       {
        auto const& left_size = left.size();
        auto const& right_size = right.size();

        to_left.resize(  right_size ); std::fill( to_left.begin(),   to_left.end(),  ::math::type::size_type( -1 ) );
        to_right.resize(  left_size ); std::fill( to_right.begin(),  to_right.end(), ::math::type::size_type( -1 ) );

        while( true )
         {
          ::math::type::size_type alone_left = ::math::type::size_type( -1 );
          for( ::math::type::size_type index_left=0; index_left < left_size; ++index_left )
           {
            if( ::math::type::size_type( -1 ) == to_right[index_left] )
             {
              alone_left = index_left;
              break;
             }
           }

          if( ::math::type::size_type( -1 ) == alone_left )
           {
            return;
           }

          scalar_name best_span = std::numeric_limits<scalar_name>::max();
          ::math::type::size_type neighbor_right = ::math::type::size_type( -1 );

          for( ::math::type::size_type candidate_right=0; candidate_right < right_size; ++candidate_right )
           {
            scalar_name current_span = ::math::linear::vector::distance( left[alone_left], right[ candidate_right ] );
            if( best_span <= current_span )
             {
              continue;
             }

            if( ::math::type::size_type( -1 ) != to_left[ candidate_right ] )
             {
              auto challenge_span = ::math::linear::vector::distance( left[ to_left[ candidate_right ] ], right[ candidate_right ] );
              if( current_span < challenge_span )
               {
                best_span = current_span;
                neighbor_right = candidate_right;
               }
             }
            else
             {
              best_span = current_span;
              neighbor_right = candidate_right;
             }
           }

          if( ::math::type::size_type( -1 ) == neighbor_right )
           {
            return;
           }

          if( ::math::type::size_type( -1 ) != to_left[ neighbor_right ] )
           {
            to_right[ to_left[ neighbor_right ] ]= ::math::type::size_type( -1 );
           }

          to_left[  neighbor_right ] = alone_left;
          to_right[    alone_left  ] = neighbor_right;
         }
       }

     }
   }
 }

#endif
