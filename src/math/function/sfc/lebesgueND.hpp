#ifndef math_function_lebesgueND
#define math_function_lebesgueND

 // ::math::function::lebesgueND

namespace math
 {
  namespace function
   {

    template < typename scalar_name, ::math::type::size_type dimension_number, typename size_name = unsigned >
     void lebesgueND( std::array<scalar_name,dimension_number> & point, scalar_name value, size_name iteration = 16 )
      {
       scalar_name add = scalar_name( 1 );

       {
        auto projection = dimension_number;
        while( projection-- )
         {
          point[ projection ] = scalar_name(1) / scalar_name( 2 ) /  scalar_name( 1 << iteration );
         }
       }

       while( iteration-- )
        {
         add *= scalar_name( 0.5 );
         size_name direction = size_name( (1 << dimension_number) * value );
         auto projection = dimension_number;
         while( projection-- )
          {
           if( 0 != ( direction & ( 1 << projection ) ) )
            {
             point[ projection ] += add;
            }
          }

         value = fmod( (1 << dimension_number) * value, scalar_name( 1 ) );
        }
      }

    template < typename scalar_name, ::math::type::size_type dimension_number, typename size_name = unsigned >
     scalar_name lebesgueND( std::array<scalar_name,dimension_number>  point, size_name iterations = 16 )
      {
        static const size_name  count = 1 << dimension_number;

       typedef ::math::linear::affine::structure<scalar_name, dimension_number  > affine_type;
       typedef ::math::linear::vector::point<scalar_name,2> vector_type;

       scalar_name result=0;
       for( size_name level = 0; level < iterations; ++level )
        {
         size_name index =0;
         size_name projection = dimension_number;
         while( projection-- )
          {
           if( point[projection] < 0.5  )
            {
             index += 0;
             point[projection] *= 2;
            }
           else
            {
             index +=  1 << projection;
             point[projection] = 2*(point[projection] - 0.5 );
            }
          }

         result += scalar_name( index ) / pow( pow(2,dimension_number), level+1 );
        }

       return result;
      }

   }
 }

#endif
