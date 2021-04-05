#ifndef math_geometry_projective_camera_projector
#define math_geometry_projective_camera_projector

// ::math::geometry::projective::camera::projector<scalar_name, size_name = std::size_t >

#include "./optical.hpp"
#include "./finite.hpp"


namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {

        template
         <
           typename  scalar_name
          ,typename    size_name = std::size_t
         >
         class projector
          : public ::math::geometry::projective::camera::optical< scalar_name, size_name >
          , public ::math::geometry::projective::camera::finite<  scalar_name, size_name >
          {
           public:
             typedef scalar_name     scalar_type;
             typedef size_name         size_type;

             typedef ::math::geometry::projective::camera::optical< scalar_name, size_name >       optical_type;
             typedef ::math::geometry::projective::camera::finite<  scalar_name, size_name >        finite_type;

             explicit projector( )
              {
              }

          };

       }
     }
   }
 }

#endif
