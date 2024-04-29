#ifndef math_statistic_histogram
#define math_statistic_histogram

// ::math::statistic::histogram<scalar_name,dimension_number,size_name>

#include "./count.hpp"



namespace math
 {
  namespace statistic
   {

    template< typename bucket_name = ::math::statistic::count<math::type::size_type>, typename scalar_name = math::type::scalar_t, typename size_name = ::math::type::size_type >
      class histogram
      {
       public:
         typedef scalar_name scalar_type, sample_type;
         typedef size_name     size_type;

         typedef bucket_name    bucket_type;
         typedef std::vector< bucket_type >  container_type;

         histogram()
          {
          }

       public:
         bool push( sample_type const& S )
          {
           size_type I = this->index( S );
           if( I < m_container.size() )
            {
             auto & bucket = m_container[ I ];
             bucket.push( S );
             return true;
            }

           return false;
          }

         void reset( )
          {
           for( auto & bucket : m_container )
            {
             bucket.reset();
            }
          }

        size_type size() const
         {
          return m_container.size();
         }

        void resize(  size_type const& len )
         {
          m_container.resize( len );
          this->reset();
         }

       public:
         container_type const& container() const
          {
           return m_container;
          }
       private:
         static size_type index( scalar_type const& S )
          {
           return size_type( S );
          }
         container_type m_container;
      };

   }
 }

#endif
