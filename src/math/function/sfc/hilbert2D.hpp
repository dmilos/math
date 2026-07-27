#ifndef math_function_hilbert2D
#define math_function_hilbert2D

#include <array>
#include "../../linear/affine/construct.hpp"
#include "./affine.hpp"

 // ::math::function::hilbert2D

namespace math
 {
  namespace function
   {

    /*
      2|3
      -+-
      1|4
     */
    template < typename scalar_name, typename size_name = ::math::type::size_type >
     inline void hilbert2D( std::array<scalar_name, 2 > & result, scalar_name value, size_name const& iteration = 16 )
      {
       static const size_name  dimension_number = 2;
       static const size_name  count = 1 << dimension_number;

       typedef ::math::linear::vector::point<scalar_name, 2> vector_type;
       typedef ::math::linear::vector::point<scalar_name, 2> point_type;
       typedef ::math::linear::affine::structure<scalar_name, dimension_number  > affine_type;

           //  Vx
       static affine_type A[4]={
             { {0.0,  0.5,  0.5,  0.0 }, { +0.0,  0.0 } }
            ,{ {0.5,  0.0,  0.0,  0.5 }, { +0.5,  0.0 } }
            ,{ {0.5,  0.0,  0.0,  0.5 }, { +0.5 , 0.5 } }
            ,{ {0.0, -0.5, -0.5,  0.0 }, { +0.5 , 1.0 } }
        };

       //Vx
        ::math::function::sfc::direct( A[0], point_type{ 0.0, 0.0 }, point_type{ 0.5, 0.5 }, vector_type{ 0.5, 0.5 }, vector_type{ 0.0, 0.5 } );
        ::math::function::sfc::direct( A[1], point_type{ 0.5, 0.0 }, point_type{ 1.0, 0.5 }, vector_type{ 0.5, 0.5 }, vector_type{ 0.5, 0.0 } );
        ::math::function::sfc::direct( A[2], point_type{ 0.5, 0.5 }, point_type{ 1.0, 1.0 }, vector_type{ 0.5, 0.5 }, vector_type{ 0.5, 0.0 } );
        ::math::function::sfc::direct( A[3], point_type{ 0.5, 1.0 }, point_type{ 0.0, 0.5 }, vector_type{ 0.5, 0.5 }, vector_type{ 0.0,-0.5 } );
 
       //// Vy  TODO 

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
     void  hilbert2D( scalar_name & x, scalar_name &y, scalar_name value, size_name iteration=16 )
      {
       std::array<scalar_name, 2 > c;
       ::math::function::hilbert2D( c, value, iteration );
       x = c[0];
       y = c[1];
      }

    template < typename scalar_name, typename size_name = ::math::type::size_type >
     scalar_name  hilbert2D( std::array<scalar_name, 2 > point, size_name iteration=16 )
      {
       static const size_name  dimension_number = 2;
       static const size_name  count = 1 << dimension_number;

       typedef ::math::linear::affine::structure<scalar_name, dimension_number  > affine_type;
       typedef ::math::linear::vector::point<scalar_name,2> vector_type;

       static affine_type A[4]={
              { {0.0,  2.0,  2.0,  0.0 } , {  0.0,  0.0 } }
             ,{ {2.0,  0.0,  0.0,  2.0 } , { -1.0,  0.0 } }
             ,{ {2.0,  0.0,  0.0,  2.0 } , { -1.0 ,-1.0 } }
             ,{ {0.0, -2.0, -2.0,  0.0 } , {  2.0 , 1.0 } }
         };

       ////  Vx
       //::math::function::sfc::invert( A[0], point_type{ 0.0, 0.0 }, point_type{ 0.5, 0.5 }, vector_type{ 0.5, 0.5 }, vector_type{ 0.0, 0.5 } );
       //::math::function::sfc::invert( A[1], point_type{ 0.5, 0.0 }, point_type{ 1.0, 0.5 }, vector_type{ 0.5, 0.5 }, vector_type{ 0.5, 0.0 } );
       //::math::function::sfc::invert( A[2], point_type{ 0.5, 0.5 }, point_type{ 1.0, 1.0 }, vector_type{ 0.5, 0.5 }, vector_type{ 0.5, 0.0 } );
       //::math::function::sfc::invert( A[3], point_type{ 0.5, 1.0 }, point_type{ 0.0, 0.5 }, vector_type{ 0.5, 0.5 }, vector_type{ 0.0,-0.5 } );

       scalar_name result=0;
       for( size_name level = 0; level < iteration; ++level )
        {
         size_name index =0;
         index += (point[0] < 0.5 ? 0 : 1);
         index += (point[1] < 0.5 ? 0 : 2);
         index  = std::array<size_name, 4>{0, 3, 1, 2}[index];
         result += scalar_name( index ) / pow( 4, level+1 );
         ::math::linear::affine::transform( point, A[index ], vector_type( point ) );
        }

       return result;
      }

   }
 }

#endif
