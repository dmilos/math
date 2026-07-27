#ifndef math_function_peano2D
#define math_function_peano2D

#include <array>

 // ::math::function::peano2D

namespace math
 {
  namespace function
   {

    /*
      3|4|9
      -+-+
      2|5|8
      -+-+
      1|6|7
     */
    template< typename scalar_name, typename size_name = unsigned >
     inline void peano2D( std::array<scalar_name, 2 >& result, scalar_name value, size_name iteration = 16 )
      {
       static const size_name  dimension_number = 2;
       static const size_name  count = 9;

       typedef ::math::linear::matrix::structure<scalar_name, dimension_number, dimension_number > matrix_type;
       typedef ::math::linear::affine::structure<scalar_name, dimension_number  > affine_type;
       typedef std::array<scalar_name, dimension_number > vector_type;

       static   scalar_name zero      = 0.0 / 3.0;
       static   scalar_name third     = 1.0 / 3.0;
       static   scalar_name two_third = 2.0 / 3.0;
       static   scalar_name one       = 3.0 / 3.0;

        static affine_type A[9]={
              { {third,  zero ,  zero,  third } , { zero,  zero      } }
             ,{ {-third, zero,  zero,  third } , { third,  third    } }
             ,{ {third,  zero,  zero,   third } , { zero , two_third } }

             ,{ {third,  zero, zero, -third } , { third,  one } }
             ,{ {-third, zero, zero, -third } , { two_third,  two_third } }
             ,{ {third,  zero, zero, -third } , { third , third } }

             ,{ {third, zero, zero,  third } , { two_third , zero } }
             ,{ {-third,  zero, zero,  third } , { one , third } }
             ,{ {third, zero, zero,  third } , { two_third , two_third } }
         };
 
       ::math::linear::vector::fill( result, 0 );
       affine_type accumulator, temp;     ::math::linear::affine::id( accumulator );
       for( size_name level = 0; level < iteration; ++level )
        {
         value *= count;
         size_name location = size_name( value );
         value = fmod( value, scalar_name( 1 ) );

         ::math::linear::affine::compose( temp, accumulator, A[location] );
         accumulator = temp;
        }
       ::math::linear::affine::transform( result, accumulator, { 0.5, 0.5 } );
      }

    template < typename scalar_name, typename size_name = ::math::type::size_type >
     void  peano2D( scalar_name & x, scalar_name &y, scalar_name value, size_name iteration=16 )
      {
       std::array<scalar_name, 2 > c;
       ::math::function::peano2D( c, value, iteration );
       x = c[0];
       y = c[1];
      }

   }
 }

#endif



