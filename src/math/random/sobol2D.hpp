#ifndef _DDMRM_math_random_sobol2d_HPP_
 #define _DDMRM_math_random_sobol2d_HPP_

// ::math::random::sobol2D<scalar>

#include <cstdint>
#include <array>

namespace math
 {
  namespace random
   {

    template< typename scalar_name >
    class sobol2D
     {
     public:
         typedef std::uint32_t T_uint32;
         typedef scalar_name scalar_type;

     public:

       sobol2D():sobol2D(0,0)
        {
        }

       sobol2D( T_uint32 seedX, T_uint32 seedY )
        {
         this->seed( seedX, seedY );
         this->Fs_init();
        }

       void seed( T_uint32 s0, T_uint32 s1 )
        {
         m_d0 = s0;
         m_d1 = s1;
         M2_index  = 0;
        }

        void next( scalar_type &P_x, scalar_type &P_y )
         {
          T_uint32 Is_max = 0xFFFFFF;
          P_x = (m_d0 >> 8) * ( 1.0/ Is_max );
          P_y = (m_d1 >> 8) * ( 1.0/ Is_max );
          this->updateState();
         }

        void operator()( scalar_type &P_x, scalar_type &P_y ){ return this->next( P_x, P_y); }

        T_uint32 getPos() { return M2_index; }

     private:
       // state data
       T_uint32 M2_index, m_d0, m_d1;


     private:
       void updateState()
        {
         // = Integer.numberOfTrailingZeros(~M2_index);
         T_uint32 c = 0;
          {
           uint32_t num = M2_index;
           while( 1 == ( num & 1 ) )
            {
             c++;
             num >>= 1;
            }
          }

          m_d0 ^= ( 0x80000000 ) >> c;
          m_d1 ^= Fs_cache()[ c ];
          ++M2_index;
        }

     private:
       typedef std::array< T_uint32, 33 > T_cache;

       static T_cache M2s_cache; //!< direction table

       static void Fs_init()
        {
         T_uint32 c = F2s_cache()[0] = 1 << 31;

         for( T_uint32 i = 1; i < 32; i++ )
          {
           c = c ^ (c >> 1);
           F2s_cache()[i] = c;
          }
        }

    public:
      static T_cache const& Fs_cache()
       {
        //static T_cache Is_cache;
        //return Is_cache;
        return M2s_cache;
       }

    private:
      static T_cache & F2s_cache()
       {
        //static T_cache Is_cache;
        //return Is_cache;
        return M2s_cache;
       }

     };

    template< typename scalar_name >
     typename sobol2D<scalar_name>::T_cache sobol2D<scalar_name>::M2s_cache;

   }
 }


#endif
