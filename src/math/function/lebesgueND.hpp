#ifndef math_function_lebesgueND
#define math_function_lebesgueND

 // ::math::function::lebesgueND

namespace math
 {
  namespace function
   {

    template < typename scalar_name, unsigned dimension_number, typename size_name = unsigned >
     void lebesgueND( std::array<scalar_name,dimension_number> & coord, scalar_name value, size_name iteration=16 )
      {
       scalar_name add = scalar_name( 1 );

       {
        auto projection = dimension_number;
        while( projection-- )
         {
          coord[ projection ] = scalar_name(1) / scalar_name( 2 ) /  scalar_name( 1 << iteration );
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
             coord[ projection ] += add;
            }
          }

         value = fmod( (1 << dimension_number) * value, scalar_name( 1 ) );
        }
      }

   }
 }

#endif
