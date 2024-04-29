#ifndef math_statistic_skewness
#define math_statistic_skewness

// ::math::statistic::skewness<scalar_name,dimension_number,size_name>

#include "./average.hpp"



namespace math
 {
  namespace statistic
   {

    template<typename scalar_name, typename size_name = ::math::type::size_type >
      class skewness
      {
       public:
         typedef scalar_name scalar_type;
         typedef size_name     size_type;

         typedef ::math::statistic::average<scalar_name,1,size_name> aeverage_type;

          typedef scalar_name  sample_type;
          typedef std::vector< sample_type >  population_type;

         skewness()
          {
          }

         scalar_name b1( population_type const& S )
          {
           m_mean = this->average( S );

           scalar_type A = 0;
           scalar_type B = 0;
           for( auto const& sample : S )
            {
             A += ( sample - m_mean )*( sample - m_mean )*( sample - m_mean );
             B += ( sample - m_mean )*( sample - m_mean );
            }
           A /= S.size();
           B /= S.size() - 1; B = pow( B, 1.5 );
           scalar_type result = A / B ;
           return result;
          }

         scalar_name g1( population_type const& S )
          { // give result sam as by definition
           m_mean = this->average( S );
           scalar_type A = 0;
           scalar_type B = 0;
           for( auto const& sample : S )
            {
             A += ( sample - m_mean )*( sample - m_mean )*( sample - m_mean );
             B += ( sample - m_mean )*( sample - m_mean );
            }
           A /= S.size();
           B /= S.size(); B = pow( B, 1.5 );
           scalar_type result = A / B ;
           return result;
          }

         scalar_name G1( population_type const& S )
          {
           auto result = g1( S );
           result *= sqrt( S.size()*( S.size() -1 ) )/ ( S.size() -2 );
           return result;
          }
       private:
         scalar_type  m_mean;
       private:
         static scalar_type average( population_type const& S )
          {
           scalar_type result = 0;
           for( auto const& sample : S )
            {
             result += sample ;
            }
           result /= S.size() ;
           return result;
          }
      };

   }
 }

#endif
