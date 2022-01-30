#ifndef math_geometry_projective_camera_focus_wand2d
#define math_geometry_projective_camera_focus_wand2d

// ::math::geometry::projective::camera::focus::line2d( focus, A, B, length, distance )

//#include <utility>



namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {
        namespace focus
         {

          /************** 
                +------------------------+-length--+  parallel to focal plane
                |                       /       /
                |                      /       / 
                |                     /       /  
                d                    /       /   
                i                   /       /    
                s                  /       /     
                t                 /       /      
            ----a----------- f---A-------B-
                n            o  /       /
                c            c  /     /
                e            u /   /
                |            s /  /
                |            |/ /
                +            0
         **************/
          template < typename scalar_name >
           bool
           line2d
            (
              scalar_name                            & focus
             ,scalar_name     const& A         //!< projection of first point,
             ,scalar_name     const& B         //!< projection of second point,
             ,scalar_name     const& length    //!< length of line,
             ,scalar_name     const& distance  //!< distance from X axis,
            )
            {
             focus = fabs( B - A ) * distance / length;
             return true;
            }

         }
       }
     }
   }
 }

#endif
