#ifndef math_function_peano3D
#define math_function_peano3D

 // ::math::function::peano3D

namespace math
 {
  namespace function
   {

    template < typename scalar_name, typename size_name = unsigned >
     void peano3d( scalar_name & x, scalar_name & y, scalar_name &z, scalar_name const& value, size_name iteration = 16 )
      {
       // TODO
      }


    template < typename scalar_name, typename size_name = unsigned >
     void peano3d( std::array<scalar_name, 3 > & coord, scalar_name const& value, size_name iteration = 16 )
      {
       ::math::function::peano3d( coord[0], coord[1], coord[2], value, iteration );
      }

   }
 }

#endif
