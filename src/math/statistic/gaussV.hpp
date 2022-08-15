#ifndef math_statistic_gauss_vector
#define math_statistic_gauss_vector

// ::math::statistic::gauss::vector< double, unsigned, 1 >

#include "./count.hpp"
#include "./summae.hpp"
#include "./average.hpp"
#include "../linear/vector/subtraction.hpp"
#include "../linear/vector/fill.hpp"



namespace math
 {
  namespace statistic
   {
    namespace gauss
     {

      template
       <
         typename scalar_name         = long double
        ,typename size_name           = std::size_t
        ,::math::type::size_type dimension_number    = 2
       >
       class vector
        {
         public:
           typedef scalar_name scalar_type;
           typedef size_name     size_type;

           typedef ::math::statistic::summae< scalar_name, dimension_number > summae_type;
           typedef ::math::statistic::count< size_name >     count_type;
           typedef ::math::statistic::average< scalar_name, dimension_number, size_name > average_type;

           typedef typename average_type::sample_type  sample_type;

           vector()
            {
             reset();
            }

          void reset()
           {
            m_count.reset( 0 );
            m_summae.reset( sample_type{ scalar_type() } );

            m_sqSumma.reset( ::math::linear::vector::fill<scalar_name, dimension_number >( 0 ) );
           }

          void push( sample_type const& sample = ::math::linear::vector::fill<scalar_name, dimension_number >( 0 ) )
           {
            using namespace ::math::linear::vector;
            m_count.push();
            m_summae.push( sample );

            sample_type square;
            ::math::linear::vector::multiply( square, sample, sample );
            m_sqSumma.push( square );
           }

          sample_type deviation() const
           {
            sample_type result;
            ::math::linear::vector::multiply(    result, m_summae.value(), m_summae.value() );
            ::math::linear::vector::scale(       result, scalar_type(1)/m_count.value() );
            ::math::linear::vector::subtraction( result, m_sqSumma.value(), result );
            ::math::linear::vector::scale(       result, scalar_type(1)/m_count.value() );
            return result;
           }

          sample_type mean() const
           {
            using namespace ::math::linear::vector;
            return m_summae.value() / static_cast<scalar_type> ( m_count.value() );
           }

          size_type const& count() const
           {
            return m_count.value();
           }

         private:
           count_type  m_count;
           summae_type m_summae;
           summae_type m_sqSumma;
        };

     }
   }
 }

#endif
