#ifndef math_geometry_projective_camera_focus_sbox2D
#define math_geometry_projective_camera_focus_sbox2D
// square box
// ::math::geometry::projective::camera::focus::sbox2D( result, base, depth )





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

          /************** image on display
                +---------base-----------+
                |                       /|
                d                      / |
                e                     /  |
                p                    /   |
                t                   /    |
                h                  /     |
                |                 /      |
            ----+-----------0-p--+-------+-----
                            |   /
                            |  /
                            | /
                            f
                            |
         **************/
          template < typename scalar_name >
           scalar_name
           sbox2D
            (
              scalar_name const& base        //!< length of box base
             ,scalar_name const& depth       //!< depth of box
             ,scalar_name const& p           //!< position on y=focus display
            )
            { //! box =[ ( -base/2, focus ), ( +base/2, focus + depth) ]
             scalar_name focus = p * depth / ( base/scalar_name(2) - p );
             return focus;
            }

         }
       }
     }
   }
 }

#endif
