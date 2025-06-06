#ifndef math_geometry_projective_camera_w2a
#define math_geometry_projective_camera_w2a

// ::math::geometry::projective::camera::w2a( window )
// ::math::geometry::projective::camera::w2a( window, focus )




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
        |  /         | +1 window /2
        |/ angle/2   |
        +------------+------>
        | \  (focus)1|
        |   \        | - window /2
        |     \      |
        |       \    |
        */
        template < typename scalar_name >
         scalar_name
         w2a
          (
            scalar_name const& window  //!< window of view
          ) //!< angle of view of interval [1,1] x [ -window/2, +window/2 ]
          {  //!< convert window to angle
           return scalar_name(2) * atan( scalar_name(0.5) * window );
          }

        template < typename scalar_name >
         scalar_name
         w2a
          (
            scalar_name const& window  //!< window of view
           ,scalar_name const& focus  //!< focus of plane
          ) //!< angle of view of interval [focus,focus] x [ -window/2, +window/2 ]
          {  //!< convert window&focus to angle
           return scalar_name(2) * atan( scalar_name(0.5) * window / focus  );
          }

       }
     }
   }
 }

#endif
