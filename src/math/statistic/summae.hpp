#ifndef math_statistic_summae
#define math_statistic_summae

// ::math::statistic::minimum<scalar_name,dimension_number>

#include "../linear/vector/vector.hpp"
#include "../linear/vector/fill.hpp"
#include "../linear/vector/addition.hpp"




namespace math
 {
  namespace statistic
   {

    template
      <
        typename scalar_name      = long double
       ,unsigned dimension_number = 1
      >
      class summae
      {
       public:
         typedef scalar_name scalar_type;
         typedef ::math::linear::vector::point<scalar_name,dimension_number>  sample_type;

         summae()
          {
           ::math::linear::vector::fill( m_value, 0 );
          }

         void reset()
          {
           ::math::linear::vector::fill( this->m_value, 0 );
          }

         void reset( sample_type const& sample )
          {
           this->m_value = sample;
          }

         void push( sample_type const& sample )
          {
           ::math::linear::vector::addition( m_value, sample );
          }

       public:
         sample_type const& value()const
          {
           return m_value;
          }

        private:
          sample_type m_value;
      };

     template< typename scalar_name >
      class summae< scalar_name, 1 >
      {
       public:
         typedef scalar_name scalar_type;
         typedef scalar_name sample_type;

         summae()
          {
           this->reset( 0 );
          }

         void reset()
          {
           this->m_value = 0;
          }

         void reset( sample_type const& sample )
          {
           this->m_value = sample;
          }

         void push( sample_type const& sample )
          {
           m_value += sample;
          }

         sample_type const& value()const
          {
           return m_value;
          }

        private:
          sample_type m_value;
      };

   }
 }

#endif
