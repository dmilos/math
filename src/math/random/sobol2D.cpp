#include "./sobol2D.hpp"

using namespace GS_DDMRM::S_math::S_random;

GC_sobol2D::GC_sobol2D()
 {
  seed(0,0);
  Fs_init();
 }

GC_sobol2D::GC_sobol2D( T_uint32 seedX, T_uint32 seedY )
 {
  seed( seedX, seedY );
 }

void GC_sobol2D::seed( T_uint32 s0, T_uint32 s1 )
 {
   d0 = s0;
   d1 = s1;
   M2_index  = 0;
 }

void GC_sobol2D::updateState()
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

   d0 ^= ( 0x80000000 ) >> c;
   d1 ^= Fs_cache()[ c ];
   ++M2_index;
 }


void GC_sobol2D::next( T_scalar &P_x, T_scalar &P_y )
 {
  T_uint32 Is_max = 0xFFFFFF;
  P_x = (d0 >> 8) * ( 1.0/ Is_max );
  P_y = (d1 >> 8) * ( 1.0/ Is_max );
  updateState();
 }

void GC_sobol2D::Fs_init()
 {
  T_uint32 c = Fs_cache()[0] = 1 << 31;

  for( T_uint32 i = 1; i < 32; i++ )
   {
    c = c ^ (c >> 1);
    Fs_cache()[i] = c;
   }
 }

