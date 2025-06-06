#ifndef math_geometry_projective_camera_a2w
#define math_geometry_projective_camera_a2w

// ::math::geometry::projective::camera::a2w( angle )
// ::math::geometry::projective::camera::a2w( angle, focus )




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
        |  /         | + window / 2
        |/ angle/2   |
        +------------+------>
        | \  (focus)1|
        |   \        | - window / 2
        |     \      |
        |       \    |
        */
        template < typename scalar_name >
         scalar_name
         a2w
          (
            scalar_name const& angle  //!< angle of view
          ) //!< angle of view of interval [1,1] x [ -window/2, +window/2 ]
          {  //!< convert angle to window
           return scalar_name(2) * tan( angle / scalar_name(2) );
          }
        template < typename scalar_name >
         scalar_name
         a2w
          (
            scalar_name const& angle 
           ,scalar_name const& focus   
          ) //!< angle of view of interval [focus,focus] x [ -window/2, +window/2 ]
          {  //!< convert angle&focus to window
           return scalar_name(2) * focus * tan( angle / scalar_name(2) );
          }

       }
     }
   }
 }

#endif
