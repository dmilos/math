#ifndef math_statistic_maximum
#define math_statistic_maximum

// ::math::statistic::maximum<scalar_name,dimension_number>

#include "../linear/vector/structure.hpp"
#include "../linear/vector/fill.hpp"
#include "../linear/vector/min.hpp"




namespace math
 {
  namespace statistic
   {

    template
      <
        typename scalar_name      = long double
       ,::math::type::size_type dimension_number = 1
      >
      class maximum
      {
       public:
         typedef scalar_name scalar_type;
         typedef ::math::linear::vector::point<scalar_name,dimension_number> sample_type;

         maximum()
          {
           ::math::linear::vector::fill( m_value, 0 );
          }

         void reset( )
          {
           this->reset( 0 );
          }
         void reset( sample_type const& value )
          {
           this->m_value = value;
          }

         void push( sample_type const& sample )
          {
           ::math::linear::vector::max( m_value, sample );
          }

         sample_type const& value()const
          {
           return m_value;
          }

         operator sample_type const& () const
          {
           return value();
          }

        private:
          sample_type m_value;
      };


    template< typename scalar_name >
      class maximum< scalar_name, 1 >
      {
       public:
         typedef scalar_name scalar_type;
         typedef scalar_type sample_type;

         maximum()
          {
           this->reset( 0 );
          }

         void reset( sample_type const& value )
          {
           this->m_value = value;
          }

         void push( sample_type const& sample )
          {
           if( sample < m_value )
            {
             return;
            }
           m_value = sample;
          }

         sample_type const& value()const
          {
           return m_value;
          }

         operator sample_type const& () const
          {
           return value();
          }

        private:
          sample_type m_value;
      };

   }
 }

#endif
