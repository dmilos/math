#ifndef math_statistic_average
#define math_statistic_average

// ::math::statistic::average<scalar_name,dimension_number,size_name>

#include "../linear/vector/scale.hpp"
#include "./count.hpp"
#include "./summae.hpp"


namespace math
 {
  namespace statistic
   {

    template
      <
        typename scalar_name        = long double
       ,unsigned  dimension_number  = 1
       ,typename size_name          = long unsigned
      >
      class average
      {
       public:
         typedef scalar_name scalar_type;
         typedef size_name     size_type;

         typedef math::statistic::summae< scalar_name, dimension_number > summae_type;
         typedef math::statistic::count< size_name >   count_type;
         
         typedef typename summae_type::sample_type sample_type;

         average()
          {
          }

         void reset()
          {
           this->m_summae.reset( );
           this->m_count.reset( 0 );
          }

         void reset( sample_type const& value, size_name const& count )
          {
           this->m_summae.reset( value );
           this->m_count.reset( count );
          }

         void push( sample_type const& sample )
          {
           m_summae.push( sample );
           m_count.push();
          }

         sample_type value()const
          {
           sample_type result;

           ::math::linear::vector::scale( result,  scalar_type(1) / scalar_type(m_count.value() ), m_summae.value() );

           return result;
          }

         operator sample_type () const
          {
           return value();
          }

         size_type const& count()const
          {
           return m_count;
          }

         private:
           summae_type m_summae;
           count_type  m_count;
      };

    template<typename scalar_name, typename size_name >
      class average< scalar_name, 1, size_name >
      {
       public:
         typedef scalar_name scalar_type;
         typedef size_name     size_type;

         typedef math::statistic::summae< scalar_name, 1 > summae_type;
         typedef math::statistic::count< size_name >   count_type;
         
         typedef typename summae_type::sample_type sample_type;

         average()
          {
          }

         void reset( )
          {
           this->m_summae.reset();
           this->m_count.reset();
          }

         void reset( sample_type const& value, size_name const& count )
          {
           this->m_summae.reset( value );
           this->m_count.reset( count );
          }

         void push( sample_type const& sample )
          {
           m_summae.push( sample );
           m_count.push();
          }

         sample_type value()const
          {
           return m_summae.value() / m_count.value();
          }

         operator sample_type () const
          {
           return value();
          }

         size_type const& count()const
          {
           return m_count.value();
          }

         private:
           summae_type m_summae;
           count_type  m_count;
      };

   }
 }

#endif
