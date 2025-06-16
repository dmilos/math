#ifndef math_geometry_projective_camera_f2h
#define math_geometry_projective_camera_f2h

// ::math::geometry::projective::camera::f2a( focus )
// ::math::geometry::projective::camera::f2a( focus, window )




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
         f2a  //!< former f2h
          (
            scalar_name const& focus    
          )//! Display1D [focus,focus]x[ -1, +1 ] //!< 1D display viewed under horizontal angle
          { //!< convert focus to angle
           return scalar_name(2) * atan( scalar_name(0.5) / focus );
         //return scalar_name(2) * scalar_name(1) * acos( focus / sqrt( focus*focus + scalar_name(1*1) ) );
          }

        template < typename scalar_name >
         scalar_name
         f2a  //!< former f2h
          (
            scalar_name const& focus      
           ,scalar_name const& window     
          )//! Display1D [focus,focus]x[ -window/2, +window/2 ] //!< 1D display viewed under horizontal angle
          { //!< convert focus&window to angle
           return scalar_name(2) * atan( scalar_name(0.5) * window / focus );
         //return scalar_name(2) * scalar_name(1) * acos( focus / sqrt( focus*focus + window*window ) );
          }

       }
     }
   }
 }

#endif
