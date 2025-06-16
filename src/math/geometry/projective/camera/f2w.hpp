#ifndef math_geometry_projective_camera_f2w
#define math_geometry_projective_camera_f2w

// ::math::geometry::projective::camera::f2w( focus, angle )





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
        |  /         | + window /2
        |/ angle/2   |
        +------------+------>
        | \  (focus)1|
        |   \        | - window /2
        |     \      |
        |       \    |
        */
        template < typename scalar_name >
         scalar_name
         f2w
          (
            scalar_name const& focus   
           ,scalar_name const& angle    
          ) //!< angle of view of interval [focus,focus] x [ -window/2, +window/2 ]
          {  //!< convert focus&angle to window
           return scalar_name( 2 ) * focus * tan( angle / scalar_name( 2 ) );
          }

       }
     }
   }
 }

#endif
