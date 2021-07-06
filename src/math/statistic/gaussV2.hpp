#ifndef math_statistic_gauss_V2
#define math_statistic_gauss_V2

// ::math::statistic::gauss::V2< double, unsigned >

#include "./count.hpp"
#include "./summae.hpp"
#include "./average.hpp"





namespace math
 {
  namespace statistic
   {
    namespace gauss
     {

      template
       <
         typename scalar_name         = long double
        ,typename size_name           = long unsigned
       >
       class V2
       {
        public:
          typedef scalar_name scalar_type;
          typedef size_name     size_type;

          typedef ::math::statistic::summae< scalar_name, 1 >              summae_type;
          typedef ::math::statistic::count< size_name >                     count_type;
          typedef ::math::statistic::average< scalar_name, 1, size_name > average_type;

          typedef typename average_type::sample_type  sample_type;

          V2()
           {
            reset();
           }

          void reset()
           {
            m_count.reset( 0 );
            m_summae.reset( sample_type{ scalar_type() } );

            m_s = 0;
            m_average = 0;
           }

          void push( sample_type const& sample )
           {
            m_count.push();
            m_summae.push( sample );

            sample_type delta = sample - m_average;

            m_average += delta / m_count;
            m_s       += delta * ( sample - m_average );
           }

          sample_type deviation() const
           {
            sample_type result =  m_s / ( m_count.value() );
            return result;
           }

          sample_type mean() const
           {
            return m_summae.value() / static_cast<scalar_type> ( m_count.value() );
           }

          size_type const& count() const
           {
            return m_count.value();
           }

         private:
           count_type  m_count;
           summae_type m_summae;

           sample_type m_average;
           sample_type m_s;

       /*
         scalar_type thrust( scalar_type const& perent )
         {
             // constants
             scalar_type a1 =  0.254829592;
             scalar_type a2 = -0.284496736;
             scalar_type a3 =  1.421413741;
             scalar_type a4 = -1.453152027;
             scalar_type a5 =  1.061405429;
             scalar_type p  =  0.3275911;

             // Save the sign of x
             int sign = 1;
             if (x < 0)
                 sign = -1;
             x = fabs(x)/sqrt(2.0);

             // A&S formula 7.1.26
             double t = 1.0/(1.0 + p*x);
             double y = 1.0 - (((((a5*t + a4)*t) + a3)*t + a2)*t + a1)*t*exp(-x*x);

             return 0.5*(1.0 + sign*y);
         }
       */

       };


     }
   }
 }

#endif
