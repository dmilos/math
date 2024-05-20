#ifndef math_statistic_histogram
#define math_statistic_histogram

// ::math::statistic::histogram<bucket_name,scalar_number,size_name, dimension>
// ::math::statistic::histogramNd<dimension_number,bucket_name,scalar_name,size_name>

#include "./count.hpp"



namespace math
 {
  namespace statistic
   {

    template
     <
       typename bucket_name = ::math::statistic::count<math::type::size_type>
      ,typename scalar_name = ::math::type::scalar_t
      ,typename size_name   = ::math::type::size_type
     >
     class histogram
      {
       public:
         typedef scalar_name scalar_type, sample_type;
         typedef size_name     size_type;

         typedef bucket_name    bucket_type;
         typedef std::vector< bucket_type >  container_type;

         explicit histogram( size_type const& length = 1 )
          {
           this->resize( length );
          }

       public:
         bool push( sample_type const& S )
          {
           size_type I = this->index( S );
           if( I < this->m_container.size() )
            {
             auto & bucket = this->m_container[ I ];
             bucket.push( S );
             return true;
            }

           return false;
          }

         void reset()
          {
           for( auto & bucket : this->m_container )
            {
             bucket.reset();
            }
          }

        size_type size() const
         {
          return this->m_container.size();
         }

        void resize(  size_type const& len )
         {
          this->m_container.resize( len );
          this->reset();
         }

       public:
         container_type const& container() const
          {
           return this->m_container;
          }
       private:
         static size_type index( scalar_type const& S )
          {
           return size_type( S );
          }
         container_type m_container;
      };


    template
     <
       ::math::type::size_type dimension_number = 1
      ,typename bucket_name    = ::math::statistic::count<math::type::size_type>
      ,typename scalar_name    = ::math::type::scalar_t
      ,typename size_name      = ::math::type::size_type
     >
     class histogramNd
      {
       public:
         typedef scalar_name scalar_type;
         typedef std::array<scalar_name,dimension_number>     sample_type;

         typedef size_name     size_type;
         typedef std::array<size_name,dimension_number>     sizeNd_type;

         typedef bucket_name    bucket_type;
         typedef std::vector< bucket_type >  container_type;

         explicit histogramNd()
          {
           sizeNd_type L; std::fill( L.begin(), L.end(), 1 );
           this->resize( L );
          }

         explicit histogramNd( sizeNd_type const& length )
          {
           this->resize( length );
          }

       public:
         bool push( sample_type const& S )
          {
           size_type I = this->index( this->location( S ) );
           if( I < m_container.size() )
            {
             auto & bucket = m_container[ I ];
             bucket.push( S );
             return true;
            }

           return false;
          }

         void reset()
          {
           for( auto & bucket : m_container )
            {
             bucket.reset();
            }
          }

        sizeNd_type const& size() const
         {
          return m_size;
         }

        void resize(  sizeNd_type const& size )
         {
          size_type volume = 1;
          for( size_type p=0; p < dimension_number; ++p )
           {
            volume *= size[ p ];
           }
          m_size = size;
          m_container.resize( volume );
          this->reset();
         }

       public:
         size_type valid( sizeNd_type const& location )
          {
           for( size_type p=0; p < dimension_number; ++p )
            {
             auto const& local = location[ p ];
             if( local < m_size[p] )
              {
               continue;
              }
             return false;
            }
           return true;
          }

       public:
         size_type index( sizeNd_type const& coord )
          {
           size_type result = 0;
           size_type volume = 1;
           for( size_type p=0; p < dimension_number; ++p )
            {
             auto const& local = coord[ p ];
             if( local < m_size[p] )
              {
               result += local * volume;
               volume *= m_size[ p ];
               continue;
              }
             return m_container.size();
            }
           return result;
          }

         container_type const& container() const
          {
           return m_container;
          }

       public:
         sizeNd_type location( sample_type const& S )
          {
           sizeNd_type result;
           for( size_type p=0; p < dimension_number; ++p )
            {
             result[ p ] = static_cast<size_type>( S[p] );
            }
           return result;
          }
         container_type m_container;
         sizeNd_type    m_size;
      };


   }
 }

#endif
