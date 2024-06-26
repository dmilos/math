#ifndef math_geometry_projective_camera_i2d
#define math_geometry_projective_camera_i2d

// ::math::geometry::projective::camera::i2d( point, resolution, pixel )

//#include <utility>



namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {

        template < typename scalar_name, typename size_name, typename integer_name >
         ::math::linear::vector::structure< scalar_name, 2 > &
         i2d
          (
            ::math::linear::vector::structure< scalar_name, 2 >          & point
           ,::math::linear::vector::structure< size_name, 2 >       const& resolution
           ,::math::linear::vector::structure< integer_name , 2 >   const& pixel
          )//! image [0, width]x[0, height] ; Display: [ -aspect/2, +aspect/2 ] x [ -1, +1 ]
          {
           scalar_name width  = resolution[0];
           scalar_name height = resolution[1];
           scalar_name aspect = width/height;

           point[0] = aspect * ( scalar_name(2) * pixel[0]/ width - scalar_name(1) ) ;
           point[1] = ( scalar_name(1) - scalar_name(2)*pixel[1]/ height) ;

           return point;
          }

       }
     }
   }
 }

#endif
