#ifndef math_geometry_projective_camera_opd_sphere
#define math_geometry_projective_camera_opd_sphere

// ::math::geometry::projective::camera::opd::sphere_distance( center, focus, radius, mayor, minor )





namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {
        namespace opd
         {

         template < typename scalar_name >
          scalar_name
          sphere_distance
           (
             scalar_name const& focus   //!< focus
            ,scalar_name const& radius  //!< radus of sphere
            ,scalar_name const& mayor   //!< mayor axis of ellipse on display
            ,scalar_name const& minor   //!< minor axis of ellipse on display
           )
           {
            scalar_name result;

            result =  scalar_name(1) + scalar_name(4)*focus*focus * mayor*mayor / ( minor*minor*minor*minor ) ;
            result *= radius*radius;
            return sqrt( result );
           }

         }
       }
     }
   }
 }

#endif
