#ifndef math_topology_sico_structure
#define math_topology_sico_structure

// ::math::topology::sico::structure<data_name>



#include <algorithm>
#include <map>
#include "./simplex/loaded.hpp"
#include "../../function/binomial.hpp"

namespace math
 {
  namespace topology
   {
    namespace sico
     {

      template
       <
         typename  data_name  //!< Essentially whatever
       >
       class structure
        {
         public:
           typedef std::size_t     size_type;

           typedef data_name       data_type;

           typedef ::math::topology::sico::simplex::loaded<data_name> simplex_type;
           typedef typename simplex_type::face_type face_type;

           typedef std::vector< simplex_type > level_type;
           typedef std::vector< level_type > container_type;
           typedef std::initializer_list<size_type> list_type;

         public:
           structure()
            {
             this->clear();
            }

           size_t push( face_type const& face )
            {
             return push( data_name{}, face );
            }

           size_t push( data_name const& data, face_type const& face )
            {
             auto index = m_container[0].size();
             if( 0 == face.size() )
              {
               m_container[0].emplace_back( data, face );
               index = m_container[0].size()-1;
               return index;
              }

             if( 1 == face.size() )
              {
               if( m_container[0].size() <= face[0] )
                {
                 return index;
                }
               m_container[0][ face[0] ].data() = data;
               index = face[0];
               return index;
              }

             size_type dimension = face.size() -1;
             if( m_container.size() < dimension )
              {
               return index;
              }

             if( dimension == m_container.size() )
              {
               m_container.resize( dimension + 1 );
              }

             for( size_type index=0; index < face.size(); ++index )
              { // check: all faces belongs to this.
               if( m_container[ dimension-1 ].size() <= face[index] )
                {
                 return index;
                }
              }

             {
              index = this->find( face );
              if( m_container[dimension].size() != index )
               {
                return index;
               }
             }

             if( 1 == dimension )
              {
               m_container[1].emplace_back( data, face );
               index = m_container[1].size() - 1;
               m_container[0][ face[0] ].cell().emplace_back( index );
               m_container[0][ face[1] ].cell().emplace_back( index );
               return index;
              }

            // Is this Tetrahedron. TODO not optimal.
             std::map<size_type, size_type> counter;
             for( auto const& index_face: face )
              {
               for( auto const& index_point: m_container[dimension-1][index_face].face() )
                 {
                  auto & size = counter[ index_point ];
                  size ++;
                  if( 2 < size )
                   {
                    return index;
                   }
                 }
              }

             if( ::math::function::binomial( dimension + 1, dimension - 1 ) != counter.size() )
              {
               return index;
              }

             for( auto a : counter )
              {
               if( a.second != 2 )
                {
                 return index;
                }
              }

             // Insert!
             m_container[dimension].emplace_back( data, face );
             index = m_container[dimension].size()-1;
             for( auto const& face: m_container[ dimension][ index ].face() )
              {
               auto & cell = m_container[ dimension-1][ face ].cell();
               cell.emplace_back( index );
              }

             return index;
            }

           bool erase( size_type const& dimension, size_type const& index )
            {
             if( false == this->exists( dimension, index ) )
              {
               return false;
              }
             auto & simplex = m_container[dimension][index];
             if( 0 != dimension )
              {
               auto & face =  simplex.face();
               for( auto face_index : face )
                {
                 auto & cell = m_container[dimension-1][face_index].cell();
                 auto iterator = std::find( cell.begin(), cell.end(), index );
                 if( iterator != cell.end() )
                  {
                   cell.erase( iterator );
                  }
                else
                 {
                  iterator = iterator;
                 }
                }

               for( auto & face : m_container[dimension-1] )
                {
                 for( auto & cell : face.cell() )
                  {
                   if( index < cell )
                    {
                     --cell;
                    }
                  }
                }
              }

             if( this->dimension() == dimension )
              {
               m_container[dimension].erase( m_container[dimension].begin() + index );
              // TODO trim if zero
               return true;
              }

             std::vector< size_type> to_remove;
             to_remove = m_container[dimension][index].cell();
             std::sort( to_remove.begin(), to_remove.end() );
             auto upper = dimension + 1;
             for (auto iteratori = to_remove.rbegin(); iteratori != to_remove.rend(); ++iteratori )
              {
               this->erase( upper, *iteratori );
              }

             for( size_type index_up=0; index_up < this->size( upper ); ++index_up )
              {
               auto & face = m_container[upper][ index_up ].face();
               for( auto & i : face )
                {
                 if( index <= i )
                  {
                   --i;
                  }
                }
              }

             this->m_container[dimension].erase( m_container[dimension].begin() + index );
             // TODO trim if zero
             return true;
            }

           void clear()
            {
             this->m_container.clear();
             this->m_container.resize( 1 );
            }

           size_type find( face_type const& face )const
            {
             if( m_container.size() < face.size() )
              {
               return m_container.size();
              }

             size_type dimension = face.size() -1;
             auto other = face;
             std::sort( other.begin(), other.end() );

             for( size_type index=0; index < m_container[ dimension ].size(); ++index )
              {
               auto const& simplex = m_container[ dimension ][index];
               auto me = simplex.face();
               std::sort( me.begin(), me.end() );

               if( other == me )
                {
                 return index;
                }
              }

             return m_container[dimension].size();
            }

           bool exists( size_type const& dimension, size_type const& index )const
            {
             if( m_container.size() <= dimension )
              {
                return false;
              }
             return index < m_container[dimension].size();
            }

            size_type dimension()const
             {
              return ( 0 !=m_container.size() )? m_container.size()-1 : 0;
             }

            size_type size()const
             {
              return m_container.size();
             }

           size_type size( size_type const& dimension )const
            {
             if( m_container.size() <= dimension )
              {
               return 0;
              }
             return m_container[ dimension ].size();
            }

           level_type const & vertex()const
            {
              return m_container[0];
            }

           simplex_type const & vertex( size_type const&  index )const
            {
             return m_container[0][index];
            }

           simplex_type       & vertex( size_type const&  index )
            {
             return m_container[0][index];
            }

           simplex_type const & cloud( size_type const&  dimension )const
            {
             return m_container[dimension];
            }

           simplex_type const & cell( size_type const&  index )const
            {
             return m_container.back()[index];
            }

           simplex_type       & cell( size_type const&  index )
            {
             return m_container.back()[index];
            }

            size_t trim( size_type dimension )
             {
              dimension = std::min( dimension, this->dimension() );
              do
               {
                if( 0 == this->size( dimension ) )
                 {
                  this->m_container.resize( dimension );
                  continue;
                 }
                break;
               }
              while( --dimension );

              this->m_container.resize( dimension + 1 );
              for( auto & simplex : this->m_container[ dimension ] )
               {
                simplex.cell().clear();
               }
              return this->dimension();
             }

            level_type const& level( size_type const& dimension )
            {
             static level_type empty;
             if( this->size() < dimension )
              {
               return empty;
              }
             if( 0 == this->m_container[ dimension ] )
              {
               return empty;
              }
              return this->m_container[ dimension ];
             }

           simplex_type const & simplex( size_type const& dimension, size_type const&  index )const
            {
             return m_container[dimension][index];
            }

           simplex_type       & simplex( size_type const& dimension, size_type const&  index )
            {
             return m_container[dimension][index];
            }

         public:
           container_type const& container()const{ return m_container; }
         protected:
         //container_type      & container()     { return m_container; }
         private:
           container_type       m_container;
        };

     }
   }
 }

#endif
