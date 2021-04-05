#ifndef math_function_lebesgue2D
#define math_function_lebesgue2D

#include <array>

 // ::math::function::lebesgue2D

namespace math
 {
  namespace function
   {

    /*
      2|3
      -+-
      0|1
     */
    template< typename scalar_name, typename size_name = unsigned >
     inline void lebesgue2D( scalar_name & x, scalar_name &y, scalar_name value, size_name iteration = 16 )
      {
       static const size_name  dimension_number = 2;
       static const size_name  square = dimension_number * dimension_number;
       scalar_name add = scalar_name( 1 );

       x = y = scalar_name(1) / scalar_name( 2 ) /  scalar_name( 1 << iteration );

       while( iteration-- )
        {
         add *= scalar_name( 0.5 );

         size_name direction = size_name( (1 << dimension_number) * value );
         switch( direction )
          {
           case(0):
            {
            }break;
           case(1):
            {
             x += add;
            } break;
           case(2):
            {
             y += add;
            }break;
           case(3):
            {
             x += add;
             y += add;
            }break;
          }

         value = fmod( (1 << dimension_number) * value, scalar_name( 1 ) );
        }

      }

    template < typename scalar_name, typename size_name=unsigned >
     void lebesgue2D( std::array<scalar_name, 2 > & coord, scalar_name const& value, size_name iterations = 16 )
      {
       ::math::function::lebesgue2D( coord[0], coord[1], value, iterations );
      }

   }
 }

#endif



