#ifndef math_function_hilbert3D
#define math_function_hilbert3D

 // ::math::function::hilbert3D

namespace math
 {
  namespace function
   {

    template < typename scalar_name, typename size_name = unsigned >
     void hilbert3D( scalar_name & x, scalar_name & y, scalar_name &z, scalar_name const& value, size_name iteration = 16 )
      {
       // TODO
      }

    template < typename scalar_name, typename size_name = unsigned >
     void hilbert3D( std::array< scalar_name, 3 > & coord, scalar_name const& value, size_name iteration = 16 )
      {
       ::math::function::hilbert3D( coord[0], coord[1], coord[2], value, iteration );
      }


   }
 }

#endif


