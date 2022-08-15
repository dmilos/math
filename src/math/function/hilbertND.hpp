#ifndef math_function_hilbertND
#define math_function_hilbertND

 // ::math::function::hilbertND

namespace math
 {
  namespace function
   {

    template < typename scalar_name, ::math::type::size_type dimension_number, typename size_name = ::math::type::size_type >
     void hilbertND( std::array<scalar_name,dimension_number> & coord, scalar_name value, size_name iteration=16 )
      {
       scalar_name scale = scalar_name( 0.5 );

       ::math::linear::vector::fill( coord, 0 );

      }

   }
 }

#endif
