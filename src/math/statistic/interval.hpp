#ifndef math_statistic_interval
#define math_statistic_interval

// ::math::statistic::interval<scalar_name,dimension_number>

#include "../linear/vector/structure.hpp"

#include "./minimum.hpp"
#include "./maximum.hpp"

namespace math
 {
  namespace statistic
   {

    template
      <
        typename scalar_name      = long double
       ,::math::type::size_type dimension_number = 1
      >
      class interval
      {
       public:
         typedef scalar_name scalar_type;

         typedef ::math::linear::vector::structure<scalar_name, dimension_number> sample_type;

         typedef ::math::statistic::minimum< scalar_name, dimension_number > minimum_type;
         typedef ::math::statistic::maximum< scalar_name, dimension_number > maximum_type;

         interval()
          {
          }

         interval( sample_type const& min, sample_type const& max )
          :m_min( min ), m_max( max )
          {
          }

         void reset( sample_type const& min, sample_type const& max )
          {
           this->m_min.reset( min );
           this->m_max.reset( max );
          }

         void push( sample_type const& sample )
          {
           m_min.push( sample );
           m_max.push( sample );
          }

         sample_type const& minimum()const
          {
           return m_min;
          }

         sample_type const& maximum()const
          {
           return m_max;
          }

        private:
          minimum_type m_min;
          maximum_type m_max;
      };

   }
 }

#endif
