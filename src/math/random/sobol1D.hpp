#ifndef _DDMRM_math_random_sobol1d_HPP_
 #define _DDMRM_math_random_sobol1d_HPP_

// ::math::random::sobol1D<scalar>

#include <cstddef>

 namespace math
  {
   namespace random
    {

     template< typename scalar_name >
      class sobol1D
       {
        public:
          typedef scalar_name         scalar_type;
          typedef std::size_t         size_type;

        public:
          sobol1D()
           {
            seed( 0 );
           }

          explicit sobol1D( size_type const& seedX )
           {
            seed( seedX );
           }

          void seed( size_type const& s0 )
           {
            this->M2_d0 = s0;
            this->M2_index  = 0;
           }

          size_type position()
           {
            return this->M2_index;
           }

          scalar_type next()
           {
            size_type Is_max = 0xFFFFFF;
            scalar_type Ir_value = ( (this->M2_d0) >> 8 ) * ( scalar_type(1)/ Is_max );
            updateState();
            return Ir_value;
          }

         scalar_type operator()(){ return this->next(); }

        private:
        // state data
         size_type M2_index, M2_d0;

         void updateState()
          {
            // = Integer.numberOfTrailingZeros(~M2_index);
            size_type c = 0;
            {
             uint32_t num = M2_index;
             while( 1 == ( num & 1 ) )
             {
              c++;
              num >>= 1;
             }
          }

          M2_d0 ^= ( 0x80000000 ) >> c;
          ++M2_index;
         }

        public:

      };

    }
  }

#endif