#ifndef math_algorithm_BMP
#define math_algorithm_BMP

// ::math::algorithm::BMP<scalar_name,dimension_number>

#include<vector>



 namespace math
  {
   namespace algorithm
    {

     template
       <
         typename container_name
        ,typename        at_function_name
        ,typename  distance_function_name
        ,typename      size_function_name
       >
       void BMP //!< Best matching pairs
       (
         ::std::vector< std::size_t >       & to_left  //!< index toward left  side.
        ,::std::vector< std::size_t >       & to_right //!< index toward right side.
        ,container_name                const& left
        ,container_name                const& right
        , distance_function_name       const& distance
        ,       at_function_name       const& at
        ,     size_function_name       const& size
       )
       {
        auto const& left_size  = size(  left );
        auto const& right_size = size( right );

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

          decltype(  distance( at( left, std::size_t( 0 ) ), at( right, std::size_t( 0 ) ) ) ) best_span;
          bool single = true; 
          std::size_t neighbor_right = std::size_t( -1 );

          for( std::size_t candidate_right=0; candidate_right < right_size; ++candidate_right )
           {
            auto current_span = distance( at( left, alone_left ), at( right, candidate_right ) );

            if( ( false == single ) && ( best_span <= current_span ) )
             {
              continue;
             }

            if( std::size_t( -1 ) != to_left[ candidate_right ] )
             {
              auto challenge_span = distance( at( left, to_left[ candidate_right ] ), at( right, candidate_right ) );
              if( current_span < challenge_span )
               {
                best_span = current_span;
                neighbor_right = candidate_right;
                single = false;
               }
             }
            else
             {
              best_span = current_span;
              neighbor_right = candidate_right;
              single = false;
             }
           }

          if( std::size_t( -1 ) == neighbor_right )
           {
            return;
           }

          if( std::size_t( -1 ) != to_left[ neighbor_right ] )
           {
            to_right[ to_left[ neighbor_right ] ] = std::size_t( -1 );
           }

          to_left[  neighbor_right ] = alone_left;
          to_right[    alone_left  ] = neighbor_right;
         }
       }

   }
 }

#endif
