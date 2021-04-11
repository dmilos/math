#ifndef math_function_hilbert2D
#define math_function_hilbert2D

#include <array>

 // ::math::function::hilbert2D

namespace math
 {
  namespace function
   {

    template < typename scalar_name, typename size_name = unsigned >
     void hilbert2D( std::array<scalar_name, 2 > & result, scalar_name value, size_name const& iteration = 16 )
      {
       static const size_name  dimension_number = 2;
       static const size_name  count = 1 << dimension_number;

       static const ::math::linear::matrix::structure<scalar_name, 2, 2 > a00{ 0, 1, 1, 0 };
     //static const ::math::linear::matrix::structure<scalar_name, 2, 2 > a01{ 1, 0, 0, 1 };
       static const ::math::linear::matrix::structure<scalar_name, 2, 2 > a10{ 0, -1, -1, 0 };
     //static const ::math::linear::matrix::structure<scalar_name, 2, 2 > a11{ 1, 0, 0, 1 };

       ::math::linear::matrix::structure<scalar_name, 2, 2 > m{ 1,0,0,1 }, t;

       scalar_name scale = scalar_name( 1 );

       ::math::linear::vector::fill( result, 0 );
       std::array<scalar_name, 2 > local;
       std::array<scalar_name, 2 > piece;

       for( size_name level = 0; level < iteration; ++level )
        {
         scale *= scalar_name( 0.5 );
         size_name location = size_name( count * value );

         t = m;
         switch( location )
          {
           case( 0 ): ::math::linear::matrix::multiply( m, a00, t );     local[0] =          0; local[1] =          0; break;
           case( 1 ):/* ::math::linear::matrix::multiply( m, a01, t );*/ local[0] =          0; local[1] =      scale; break;
           case( 2 ):/* ::math::linear::matrix::multiply( m, a11, t );*/ local[0] =      scale; local[1] =      scale; break;
           case( 3 ): ::math::linear::matrix::multiply( m, a10, t );     local[0] = scale*(-1); local[1] = scale*(-2); break;
          }

        ::math::linear::matrix::transform( piece, m, local );
        ::math::linear::vector::addition( result, piece );

         value = fmod( count * value, scalar_name( 1 ) );
        }

      }

    template < typename scalar_name, typename size_name = unsigned >
     void hilbert2D( scalar_name & x, scalar_name &y, scalar_name value, size_name iteration=16 )
      {
       std::array<scalar_name, 2 > c;
       ::math::function::hilbert2D( c, value, iteration );
       x = c[0];
       y = c[1];
      }



   }
 }

#endif
