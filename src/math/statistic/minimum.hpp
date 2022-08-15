#ifndef math_statistic_minimum
#define math_statistic_minimum

// ::math::statistic::minimum<scalar_name,dimension_number>

#include "../linear/vector/structure.hpp"
#include "../linear/vector/fill.hpp"
#include "../linear/vector/max.hpp"




namespace math
 {
  namespace statistic
   {

    template
      <
        typename scalar_name      = long double
       ,::math::type::size_type dimension_number = 1
      >
      class minimum
      {
       public:
         typedef scalar_name scalar_type;
         typedef ::math::linear::vector::point<scalar_name,dimension_number>  sample_type;

         minimum()
          {
           ::math::linear::vector::fill( m_value, 0 );
          }

         void reset( sample_type const& value )
          {
           this->m_value = value;
          }

         void push( sample_type const& sample )
          {
           ::math::linear::vector::min( m_value, sample );
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
      class minimum< scalar_name, 1 >
      {
       public:
         typedef scalar_name scalar_type;
         typedef scalar_type sample_type;

         minimum()
          {
           this->reset( 0 );
          }

         void reset( sample_type const& value )
          {
           this->m_value = value;
          }

         void push( sample_type const& sample )
          {
           if( m_value < sample )
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
