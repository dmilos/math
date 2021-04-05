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
        ,unsigned  dimension_number
       >
       void BMP //!< Best matching pairs
       (
         ::std::vector< std::size_t >                                      & to_left  //!< index toward left  side.
        ,::std::vector< std::size_t >                                      & to_right //!< index toward right side.
        ,::std::vector< ::math::linear::vector::vector<scalar_name,dimension_number>  > const& left
        ,::std::vector< ::math::linear::vector::vector<scalar_name,dimension_number>  > const& right
       )
       {
        auto const& left_size = left.size();
        auto const& right_size = right.size();

        to_left.resize(  right_size ); std::fill( to_left.begin(),   to_left.end(),  std::size_t( -1 ) );
        to_right.resize(  left_size ); std::fill( to_right.begin(),  to_right.end(), std::size_t( -1 ) );

        while( true )
         {
          std::size_t alone_left = std::size_t( -1 );
          for( std::size_t index_left=0; index_left < left_size; ++index_left )
           {
            if( std::size_t( -1 ) == to_right[index_left] )
             {
              alone_left = index_left;
              break;
             }
           }

          if( std::size_t( -1 ) == alone_left )
           {
            return;
           }

          scalar_name best_span = std::numeric_limits<scalar_name>::max();
          std::size_t neighbor_right = std::size_t( -1 );

          for( std::size_t candidate_right=0; candidate_right < right_size; ++candidate_right )
           {
            scalar_name current_span = ::math::linear::vector::distance( left[alone_left], right[ candidate_right ] );
            if( best_span <= current_span )
             {
              continue;
             }

            if( std::size_t( -1 ) != to_left[ candidate_right ] )
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

          if( std::size_t( -1 ) == neighbor_right )
           {
            return;
           }

          if( std::size_t( -1 ) != to_left[ neighbor_right ] )
           {
            to_right[ to_left[ neighbor_right ] ]= std::size_t( -1 );
           }

          to_left[  neighbor_right ] = alone_left;
          to_right[    alone_left  ] = neighbor_right;
         }
       }

     }
   }
 }

#endif
