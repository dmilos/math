#ifndef math_function_hilbert3D
#define math_function_hilbert3D

 // ::math::function::hilbert3D

namespace math
 {
  namespace function
   {

    template < typename scalar_name, typename size_name = unsigned >
     void hilbert3D( std::array< scalar_name, 3 > & result, scalar_name  value, size_name iteration = 16 )
      { // TODO
       static const size_name  dimension_number = 3;
       static const size_name  count = 1 << dimension_number;


       typedef ::math::linear::matrix::structure<scalar_name, dimension_number, dimension_number > matrix_type;
       typedef std::array<scalar_name, dimension_number > vector_type;

       static const matrix_type a000{  0,  1,  0,
                                       1,  0,  0,
                                       0,  0,  1 };
       static const matrix_type a001{  1,  0,  0,
                                       0,  1,  0,
                                       0,  0,  1 };
       static const matrix_type a010{  1,  0,  0,
                                       0,  1,  0,
                                       0,  0,  1 };
       static const matrix_type a011{  0, -1,  0,
                                      -1,  0,  0,
                                       0,  0,  1 };
       static const matrix_type a100{  1,  0,  0,
                                       0,  1,  0,
                                       0,  0,  1 };
       static const matrix_type a101{  1,  0,  0,
                                       0,  1,  0,
                                       0,  0,  1 };
       static const matrix_type a110{  1,  0,  0,
                                       0,  1,  0,
                                       0,  0,  1 };
       static const matrix_type a111{  1,  0,  0,
                                       0,  1,  0,
                                       0,  0,  1 };

       ::math::linear::matrix::structure<scalar_name, dimension_number, dimension_number > m{ 1,0,0,1 }, t;

       scalar_name scale = scalar_name( 0.5 );

       ::math::linear::vector::fill( result, 0 );
       vector_type local;
       vector_type piece;

       for( size_name level = 0; level < iteration; ++level )
        {
         value *= count;
         size_name location = size_name( value );

         t = m;
         switch( location )
          {
           case( 0 ): ::math::linear::matrix::multiply( m, a000, t );  local[0] =            0; local[1] =           0; local[2] =           0; break;
           case( 1 ): ::math::linear::matrix::multiply( m, a001, t );  local[0] =        scale; local[1] =           0; local[2] =           0; break;
           case( 2 ): ::math::linear::matrix::multiply( m, a010, t );  local[0] =        scale; local[1] =       scale; local[2] =           0; break;
           case( 3 ): ::math::linear::matrix::multiply( m, a011, t );  local[0] = (-2) * scale; local[1] = (-1)* scale; local[2] =           0; break;
           case( 4 ): ::math::linear::matrix::multiply( m, a100, t );  local[0] =            0; local[1] =           0; local[2] =       scale; break;
           case( 5 ): ::math::linear::matrix::multiply( m, a101, t );  local[0] =        scale; local[1] =           0; local[2] =       scale; break;
           case( 6 ): ::math::linear::matrix::multiply( m, a110, t );  local[0] =        scale; local[1] =       scale; local[2] =       scale; break;
           case( 7 ): ::math::linear::matrix::multiply( m, a111, t );  local[0] = (-2) * scale; local[1] = (-1)* scale; local[2] =       scale; break;
          }

        ::math::linear::matrix::transform( piece, m, local );
        ::math::linear::vector::addition( result, piece );

         scale *= scalar_name( 0.5 );
         value = fmod( value, scalar_name( 1 ) );
        }

      }

    template < typename scalar_name, typename size_name = unsigned >
     void hilbert3D( scalar_name & x, scalar_name & y, scalar_name &z, scalar_name const& value, size_name iteration = 16 )
      {
       std::array<scalar_name, 3 > c;
       ::math::function::hilbert3D( c, value, iteration );
       x = c[0];
       y = c[1];
       z = c[2];
      }

   }
 }

#endif


