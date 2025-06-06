#ifndef math_geometry_projective_camera_w2f
#define math_geometry_projective_camera_w2f

// ::math::geometry::projective::camera::w2f( window, angle )





namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {

        /*
        |      /     |
        |    /       |
        |  /         | +(window)/2
        |/ angle/2   |
        +------------+------>
        | \  (focus)1|
        |   \        | -(window)/2
        |     \      |
        |       \    |
        */
        template < typename scalar_name >
         scalar_name
         w2f
          (
            scalar_name const& window   
           ,scalar_name const& angle    
          ) //!< angle of view of interval [focus,focus] x [ -window/2, +window/2 ]
          {  //!< convert window & angle to angle
           return scalar_name(0.5) * window / tan( angle / scalar_name( 2 ) );
          }

       }
     }
   }
 }

#endif
