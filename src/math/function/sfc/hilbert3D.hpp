#ifndef math_function_hilbert3D
#define math_function_hilbert3D

// ::math::function::hilbert3D( result, parameter, iteration )
// ::math::function::hilbert3D( point iteration )

#include "../../linear/vector/structure.hpp"

namespace math
 {
  namespace function
   {

    template < typename scalar_name, typename size_name = unsigned >
     void hilbert3D( std::array< scalar_name, 3 > & result, scalar_name  value, size_name iteration = 16 )
      {
       static const size_name  dimension_number = 3;
       static const size_name  count = 1 << dimension_number;

       typedef ::math::linear::vector::point<scalar_name, dimension_number> vector_type;
       typedef ::math::linear::vector::point<scalar_name, dimension_number> point_type;
       typedef ::math::linear::affine::structure<scalar_name, dimension_number  > affine_type;

       static affine_type A[8]={
              { {  1.0,  0.0,  0.0
                 , 0.0,  1.0,  0.0, 
                   0.0,  0.0,  1.0 } , { +0.00,  0.00,  0.00 } }
              ,{ {  1.0,  0.0,  0.0
                 , 0.0,  1.0,  0.0, 
                   0.0,  0.0,  1.0 } , { +0.00,  0.00,  0.00 } }
              ,{ {  1.0,  0.0,  0.0
                 , 0.0,  1.0,  0.0, 
                   0.0,  0.0,  1.0 } , { +0.00,  0.00,  0.00 } }
              ,{ {  1.0,  0.0,  0.0
                 , 0.0,  1.0,  0.0, 
                   0.0,  0.0,  1.0 } , { +0.00,  0.00,  0.00 } }
              ,{ {  1.0,  0.0,  0.0
                 , 0.0,  1.0,  0.0, 
                   0.0,  0.0,  1.0 } , { +0.00,  0.00,  0.00 } }
              ,{ {  1.0,  0.0,  0.0
                 , 0.0,  1.0,  0.0, 
                   0.0,  0.0,  1.0 } , { +0.00,  0.00,  0.00 } }
              ,{ {  1.0,  0.0,  0.0
                 , 0.0,  1.0,  0.0, 
                   0.0,  0.0,  1.0 } , { +0.00,  0.00,  0.00 } }
              ,{ {  1.0,  0.0,  0.0
                 , 0.0,  1.0,  0.0, 
                   0.0,  0.0,  1.0 } , { +0.00,  0.00,  0.00 } }
         };
       ::math::function::sfc::direct<double>( A[0/*0+0+0*/], point_type{ 0.0, 0.0, 0.0 }, point_type{ 0.5, 0.5, 0.5 }, point_type{ 0.5, 0.5, 0.5 }, point_type{ 0.5, 0.0, 0.5 }, point_type{ 0.0, 0.5, 0.0 } );
       ::math::function::sfc::direct<double>( A[1/*1+0+0*/], point_type{ 0.5, 0.0, 0.0 }, point_type{ 1.0, 0.5, 0.5 }, point_type{ 0.5, 0.5, 0.5 }, point_type{ 0.5, 0.0, 0.5 }, point_type{ 0.0, 0.5, 0.0 } );
       ::math::function::sfc::direct<double>( A[2/*0+2+0*/], point_type{ 0.5, 0.5, 0.0 }, point_type{ 1.0, 1.0, 0.5 }, point_type{ 0.5, 0.5, 0.5 }, point_type{ 0.5, 0.0, 0.5 }, point_type{ 0.0, 0.5, 0.0 } );
       ::math::function::sfc::direct<double>( A[3/*1+2+0*/], point_type{ 0.0, 0.5, 0.0 }, point_type{ 0.5, 1.0, 0.5 }, point_type{ 0.5, 0.5, 0.5 }, point_type{ 0.5, 0.0, 0.5 }, point_type{ 0.0, 0.5, 0.0 } );

       ::math::function::sfc::direct<double>( A[4/*0+0+4*/], point_type{ 0.0, 0.5, 0.5 }, point_type{ 0.5, 1.0, 1.0 }, point_type{ 0.5, 0.5, 0.5 }, point_type{ 0.5, 0.0, 0.5 }, point_type{ 0.0, 0.5, 0.0 } );
       ::math::function::sfc::direct<double>( A[5/*1+2+4*/], point_type{ 0.5, 0.5, 0.5 }, point_type{ 1.0, 1.0, 1.0 }, point_type{ 0.5, 0.5, 0.5 }, point_type{ 0.5, 0.0, 0.5 }, point_type{ 0.0, 0.5, 0.0 } );
       ::math::function::sfc::direct<double>( A[7/*0+2+4*/], point_type{ 0.0, 0.0, 0.5 }, point_type{ 0.5, 0.5, 1.0 }, point_type{ 0.5 ,0.5, 0.5 }, point_type{ 0.5, 0.0, 0.5 }, point_type{ 0.0, 0.5, 0.0 } );
       ::math::function::sfc::direct<double>( A[6/*1+0+4*/], point_type{ 0.5, 0.0, 0.5 }, point_type{ 1.0, 0.5, 1.0 }, point_type{ 0.5 ,0.5, 0.5 }, point_type{ 0.5, 0.0, 0.5 }, point_type{ 0.0, 0.5, 0.0 } );

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
       ::math::linear::affine::transform( result, accumulator, { 0.5, 0.5, 0.5 } );
       }

    template < typename scalar_name, typename size_name = unsigned >
     void hilbert3D( scalar_name & x, scalar_name& y, scalar_name& z, scalar_name const& value, size_name iteration = 16 )
      {
       std::array<scalar_name, 3 > c;
       ::math::function::hilbert3D( c, value, iteration );
       x = c[0];
       y = c[1];
       z = c[2];
      }

    template < typename scalar_name, typename size_name = ::math::type::size_type >
     scalar_name  hilbert3D( std::array<scalar_name, 3 > point, size_name iteration=16 )
      {
       static const size_name  dimension_number = 3;
       static const size_name  count = 1 << dimension_number;

       typedef ::math::linear::vector::vector<scalar_name, dimension_number> vector_type;
       typedef ::math::linear::vector::point<scalar_name, dimension_number> point_type;
       typedef ::math::linear::affine::structure<scalar_name, dimension_number  > affine_type;

       static affine_type A[8]/*={
              { {0.0,  2.0,  2.0,  0.0,  2.0,  0.0,  2.0,  0.0,  0.0 } , {  0.0,  0.0, 1,0 } }
             ,{ {2.0,  0.0,  0.0,  2.0,  2.0,  0.0,  2.0,  0.0,  0.0 } , {  0.0, -1.0, 1,0 } }
             ,{ {2.0,  0.0,  0.0,  2.0,  2.0,  0.0,  2.0,  0.0,  0.0 } , { -1.0 ,-1.0, 1,0 } }
             ,{ {0.0, -2.0, -2.0,  0.0,  2.0,  0.0,  2.0,  0.0,  0.0 } , {  1.0 , 2.0, 1,0 } }
             ,{ {0.0,  2.0,  2.0,  0.0,  2.0,  0.0,  2.0,  0.0,  0.0 } , {  0.0,  0.0, 1,0 } }
             ,{ {2.0,  0.0,  0.0,  2.0,  2.0,  0.0,  2.0,  0.0,  0.0 } , {  0.0, -1.0, 1,0 } }
             ,{ {2.0,  0.0,  0.0,  2.0,  2.0,  0.0,  2.0,  0.0,  0.0 } , { -1.0 ,-1.0, 1,0 } }
             ,{ {0.0, -2.0, -2.0,  0.0,  2.0,  0.0,  2.0,  0.0,  0.0 } , {  1.0 , 2.0, 1,0 } }
         }*/;

       ::math::linear::affine::construct( A[0], { vector_type{ 0.0, 0.0, 0.0}, vector_type{ 1.0, 0.0, 0.0 }, vector_type{0.0,1.0, 0.0}, vector_type{0.0, 0.0, 1.0} }, { vector_type{ 0.0,0.0, 0.0 }, vector_type{ 0.0,0.5, 0.0 }, vector_type{ 0.5,0.0, 0.0 }, vector_type{ 0.0, 0.0, 1.0 } } );
       ::math::linear::affine::construct( A[1], { vector_type{ 0.0, 0.0, 0.0}, vector_type{ 1.0, 0.0, 0.0 }, vector_type{0.0,1.0, 0.0}, vector_type{0.0, 0.0, 1.0} }, { vector_type{ 0.0,0.5, 0.0 }, vector_type{ 0.5,0.5, 0.0 }, vector_type{ 0.0,1.0, 0.0 }, vector_type{ 0.0, 0.5, 1.0 } } );
       ::math::linear::affine::construct( A[2], { vector_type{ 0.0, 0.0, 0.0}, vector_type{ 1.0, 0.0, 0.0 }, vector_type{0.0,1.0, 0.0}, vector_type{0.0, 0.0, 1.0} }, { vector_type{ 0.5,0.5, 0.0 }, vector_type{ 1.0,0.5, 0.0 }, vector_type{ 0.5,1.0, 0.0 }, vector_type{ 0.5, 0.5, 1.0 } } );
       ::math::linear::affine::construct( A[3], { vector_type{ 0.0, 0.0, 0.0}, vector_type{ 1.0, 0.0, 0.0 }, vector_type{0.0,1.0, 0.0}, vector_type{0.0, 0.0, 1.0} }, { vector_type{ 1.0,0.5, 0.0 }, vector_type{ 1.0,0.0, 0.0 }, vector_type{ 0.5,0.5, 0.0 }, vector_type{ 1.0, 0.5, 1.0 } } );
       ::math::linear::affine::construct( A[4], { vector_type{ 0.0, 0.0, 0.0}, vector_type{ 1.0, 0.0, 0.0 }, vector_type{0.0,1.0, 0.0}, vector_type{0.0, 0.0, 1.0} }, { vector_type{ 1.0,0.5, 0.5 }, vector_type{ 1.0,0.0, 0.5 }, vector_type{ 0.5,0.5, 0.5 }, vector_type{ 1.0, 0.5, 1.0 } } );
       ::math::linear::affine::construct( A[5], { vector_type{ 0.0, 0.0, 0.0}, vector_type{ 1.0, 0.0, 0.0 }, vector_type{0.0,1.0, 0.0}, vector_type{0.0, 0.0, 1.0} }, { vector_type{ 0.5,0.5, 0.5 }, vector_type{ 1.0,0.5, 0.5 }, vector_type{ 0.5,1.0, 0.5 }, vector_type{ 0.5, 0.5, 1.0 } } );
       ::math::linear::affine::construct( A[6], { vector_type{ 0.0, 0.0, 0.0}, vector_type{ 1.0, 0.0, 0.0 }, vector_type{0.0,1.0, 0.0}, vector_type{0.0, 0.0, 1.0} }, { vector_type{ 0.0,0.5, 0.5 }, vector_type{ 0.5,0.5, 0.5 }, vector_type{ 0.0,1.0, 0.5 }, vector_type{ 0.0, 0.5, 1.0 } } );
       ::math::linear::affine::construct( A[7], { vector_type{ 0.0, 0.0, 0.0}, vector_type{ 1.0, 0.0, 0.0 }, vector_type{0.0,1.0, 0.0}, vector_type{0.0, 0.0, 1.0} }, { vector_type{ 0.0,0.0, 0.5 }, vector_type{ 0.0,0.5, 0.5 }, vector_type{ 0.5,0.0, 0.5 }, vector_type{ 0.0, 0.0, 1.0 } } );

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


