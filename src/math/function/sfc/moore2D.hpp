#ifndef math_function_moore2D
#define math_function_moore2D

#include <array>

 // ::math::function::moore2D

namespace math
 {
  namespace function
   {

    /*
      2|3
      -+-
      1|4
     */
    template< typename scalar_name, typename size_name = ::math::type::size_type >
     inline void moore2D( std::array<scalar_name, 2 > & result, scalar_name value, size_name const& iteration = 16 )
      { // quasi  moore !!!
       static const size_name  dimension_number = 2;
       static const size_name  count = 4;

       typedef ::math::linear::matrix::structure<scalar_name, dimension_number, dimension_number > matrix_type;
       typedef ::math::linear::affine::structure<scalar_name, dimension_number  > affine_type;
       typedef std::array<scalar_name, dimension_number > vector_type;

        static affine_type A[4]={
              { { 0.0, -0.5, +0.5,  0.0 } , { +0.50,   0.00 } }
             ,{ { 0.0, -0.5, +0.5,  0.0 } , { +0.50,   0.50 } }
             ,{ { 0.0, +0.5, -0.5,  0.0 } , { +0.50 ,  1.00 } }
             ,{ { 0.0, +0.5, -0.5,  0.0 } , { +0.50 , +0.50 } }
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
     void  moore2D( scalar_name & x, scalar_name &y, scalar_name value, size_name iteration=16 )
      {
       std::array<scalar_name, 2 > c;
       ::math::function::moore2D( c, value, iteration );
       x = c[0];
       y = c[1];
      }

   }
 }

#endif



