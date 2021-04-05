#ifndef math_topology_sico_intersect
#define math_topology_sico_intersect

// ::math::topology::sico::intersect <data_name>( result, left, right )


#include <algorithm>
#include <vector>
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
       struct intersect_struct
        {
         public:
           typedef std::size_t size_type;
           typedef std::vector< size_type > index_type;
           typedef std::pair< index_type, index_type > pair_type;

           typedef std::vector< pair_type > result_type;


           typedef ::math::topology::sico::structure<data_name> structure_type;

         public:
           static size_type process( result_type & result, structure_type const& left_sico, structure_type const& right_sico )
            {
             result.clear();
             result.reserve( std::min( left_sico.size(), right_sico.size() ) );

             {
              result.resize(1);
              index_type &  left_zero = result[0].first;
              index_type &  right_zero = result[0].second;

              left_zero.reserve( left_sico.size(0) );
              for( size_type left_index=0; left_index< left_sico.size(0) ; ++left_index )
               {
                left_zero.push_back( left_index );
               }

              right_zero.reserve( right_sico.size(0) );
              for( size_type right_index=0; right_index< right_sico.size(0) ; ++right_index )
               {
                right_zero.push_back( right_index );
               }

              remove
               (
                left_zero, right_zero
                ,0
                ,left_sico, right_sico
               );
              }

             for( size_type dimension=1; dimension < std::min( left_sico.size(), right_sico.size() ); ++dimension )
              {
               result.resize(dimension+1);
               index_type &  left_hi = result[dimension].first;
               index_type &  right_hi = result[dimension].second;
               index_type &  left_lo = result[dimension-1].first;
               index_type &  right_lo = result[dimension-1].second;
               fill
                (
                  left_hi, right_hi
                 ,dimension
                 ,left_lo, right_lo
                 ,left_sico,  right_sico
                );

               wrong( left_lo,  left_hi,  dimension, left_sico  );
               wrong( right_lo, right_hi, dimension, right_sico );

               remove
                (
                  left_hi, right_hi
                 ,dimension
                 ,left_sico, right_sico
                );
              }

             return 0;
            }

           static void fill
            (
              index_type &left_hi, index_type &right_hi
             ,size_type const& dimension
             ,index_type      const&left_lo,    index_type     const&right_lo
             ,structure_type  const&left_sico,  structure_type const&right_sico
            )
            {
             for( size_type left_index=0; left_index< left_lo.size() ; ++left_index )
              {
               auto const& cell = left_sico.simplex( dimension-1, left_lo[left_index] ).cell();
               left_hi.insert( left_hi.end(), cell.begin(), cell.end() );
              }

             for( size_type right_index=0; right_index< right_lo.size() ; ++right_index )
              {
               auto const& cell = right_sico.simplex( dimension-1, right_lo[right_index] ).cell();
               right_hi.insert( right_hi.end(), cell.begin(), cell.end() );
              }

             {
              std::sort( left_hi.begin(), left_hi.end()  ); left_hi.erase( std::unique( left_hi.begin(), left_hi.end() ), left_hi.end() );
              std::sort( right_hi.begin(), right_hi.end() ); right_hi.erase( std::unique( right_hi.begin(), right_hi.end() ), right_hi.end() );
             }

           }

           static void wrong
            (
              index_type const &index_lo, index_type           &index_hi
             ,size_type const& dimension
             ,structure_type const&sico
            )
            {
             for( size_type index=0; index < index_hi.size(); ++index )
              {
               for( auto const& face : sico.simplex( dimension, index ).face() )
                {
                 if( index_lo.end() == std::find( index_lo.begin(), index_lo.end(), face ) )
                   {
                    index_hi.erase( index_hi.begin() + index );
                    break;
                   }
                }
              }
            }

           static void remove
            (
              index_type &left_index, index_type           &right_index
             ,size_type const& dimension
             ,structure_type const&left_sico,  structure_type const &right_sico
            )
            {
             for( size_type i=0; i < left_index.size(); ++i )
              {
               bool flag = false;
               for( size_type j=0; j < right_index.size(); ++j )
                {
                 auto const& left_cell = left_sico.simplex( dimension, left_index[i] ).cell();
                 auto const& right_cell = right_sico.simplex( dimension, right_index[j] ).cell();
                 if( left_cell.size() == right_cell.size() )
                  {
                   flag = true;
                   break;
                  }
                }
               if( false == flag )
                {
                 left_index.erase( left_index.begin() + i );
                }
              }

             for( size_type j=0; j < right_index.size(); ++j )
              {
               bool flag = false;
               for( size_type i=0; i < left_index.size(); ++i )
                { 
                 auto const& left_cell = left_sico.simplex( dimension, left_index[i] ).cell();
                 auto const& right_cell = right_sico.simplex( dimension, right_index[j] ).cell();

                 if( left_cell.size() == right_cell.size() )
                  {
                   flag = true;
                   break;
                  }
                }
               if( false == flag )
                {
                 right_index.erase( right_index.begin() + j );
                }
              }

            }

       };



      template
       <
         typename  data_name
       >
       size_t intersect
        (
           typename intersect_struct<data_name>::result_type      & result
         ,::math::topology::sico::structure<data_name>       const& left
         ,::math::topology::sico::structure<data_name>       const& right
        )
        {
         return ::math::topology::sico::intersect_struct<data_name>::process( result, left, right );
        }

     }
   }
 }

#endif
