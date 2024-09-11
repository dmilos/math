#ifndef math_geometry_projective_epipolar_rectify3_retarget
#define math_geometry_projective_epipolar_rectify3_retarget

// ::math::geometry::projective::epipolar::rectify3::retarget<double, std::size_t >

//#include <utility>


#include "../../../../linear/vector/vector.hpp"
#include "../../../../linear/homography/structure.hpp"
#include "../../../../linear/homography/transform.hpp"
#include "../../../../linear/homography/retarget.hpp"
#include "../../../../linear/homography/recodomain.hpp"

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {
        namespace rectify3
         {

          template < typename scalar_name, typename    size_name = std::size_t >
           class retarget
            {
             public:
               typedef scalar_name       scalar_type;
               typedef size_name       size_type;

               typedef ::math::linear::vector::structure< size_type   , 2 >  resolution_type;
               typedef ::math::linear::vector::structure<scalar_name,2>                   display_type;
               typedef ::math::geometry::interval::structure<scalar_type,2>   interval_type;

               typedef ::math::linear::homography::structure< scalar_name, 2 >             homography_type;
               typedef ::math::geometry::projective::camera::optical<scalar_name >            digital_type;

             public:
               bool process( homography_type & H, interval_type const& window, resolution_type const& resolution )
                { //! retarget exiting homografy to be applied on image
                 m_window = window;

                 m_target = interval_type{ display_type{ 0, (double)resolution[1] }, display_type{ (double)resolution[0], 0 } };
                 interval_type  const& codomain = window;
                 interval_type  const& domain = window;
                 m_source = interval_type{ display_type{ 0, (double)resolution[1] }, display_type{ (double)resolution[0], 0 } };

                 return ::math::linear::homography::retarget( H, homography_type( H ), m_target, codomain, domain, m_source );
                }


             bool process( homography_type & H, digital_type const& camera )
              { // retarget exiting homografy to be applied on image
               m_target = interval_type{ display_type{ 0, (double)camera.resolution()[1] }, display_type{ (double)camera.resolution()[0], 0 } };
               interval_type  codomain{ camera.window() };
               interval_type  domain{ camera.window() };
               m_source   = interval_type { display_type{ 0, (double)camera.resolution()[1] }, display_type{ (double)camera.resolution()[0], 0 } };

               return ::math::linear::homography::retarget( H, homography_type( H ), m_target, codomain, domain, m_source );
              }

             public:
              interval_type m_window;
              interval_type m_source;
              interval_type m_target;
            };

         }
       }
     }
   }
 }

#endif
