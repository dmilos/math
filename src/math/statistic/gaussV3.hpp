#ifndef math_statistic_gauss_V3
#define math_statistic_gauss_V3

// ::math::statistic::gauss::V3< double, unsigned >

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
       class V3 //!< by the book calculation
       {
        public:
          typedef scalar_name scalar_type;
          typedef size_name     size_type;

          typedef ::math::statistic::average< scalar_name, 1, size_name > average_type;



          typedef typename average_type::sample_type  sample_type;
          typedef std::vector< sample_type >  vector_type;

        public:
          V3()
           {
           }

          static void process( scalar_type & mean, scalar_type & deviation, vector_type const&S )
           {
            average_type average;

            for( auto const& sample : S )
             {
              average.push( sample );
             }
            mean = average.value();

            average_type radius;
            for( auto const& sample : S )
             {
              radius.push( ( sample - mean  ) * ( sample - mean ) );
             }
            deviation = sqrt( radius.value() );
           }
       };

     }
   }
 }

#endif
