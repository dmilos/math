#ifndef math_function_moore3D
#define math_function_moore3D

 // ::math::function::moore3D

namespace math
 {
  namespace function
   {

    template < typename scalar_name, typename size_name = unsigned >
     void moore3d( scalar_name & x, scalar_name & y, scalar_name &z, scalar_name const& value, size_name iteration = 16 )
      {
       // TODO
      }

    template < typename scalar_name, typename size_name = unsigned >
     void moore3d( std::array< scalar_name, 3 > & coord, scalar_name const& value, size_name iteration = 16 )
      {
       ::math::function::moore3d( coord[0], coord[1], coord[2], value, iteration );
      }


   }
 }

#endif


