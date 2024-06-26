#ifndef math_geometry_projective_camera_d2i
#define math_geometry_projective_camera_d2i

// ::math::geometry::projective::camera::d2i( focus, aspect )

//#include <utility>



namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {

        template < typename integer_name, typename size_name, typename scalar_name >
         ::math::linear::vector::structure< integer_name, 2 > &
         d2i
          (
            ::math::linear::vector::structure< integer_name , 2 >        & pixel
           ,::math::linear::vector::structure< size_name, 2 >       const& resolution
           ,::math::linear::vector::structure< scalar_name, 2 >     const& point
          )//! image [0, width]x[0, height] ; Display: [ -aspect/2, +aspect/2 ] x [ -1, +1 ]
          {
           scalar_name width  = resolution[0];
           scalar_name height = resolution[1];
           scalar_name aspect = width/height;

           pixel[0] =integer_name( ( ( point[0] / aspect + scalar_name(1) ) / scalar_name(2) ) * width );
           pixel[1] =integer_name( height *( scalar_name(1)-point[1]*scalar_name(1) )/scalar_name(2) );

           return pixel;
          }

       }
     }
   }
 }

#endif
