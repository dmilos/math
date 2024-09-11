#ifndef math_geometry_projective_epipolar_rectify3_base
#define math_geometry_projective_epipolar_rectify3_base

// ::math::geometry::projective::epipolar::rectify3::base<double>

//#include <utility>


#include "../../camera/optical.hpp"
#include "../../../../linear/vector/vector.hpp"
#include "../../../../linear/matrix/matrix.hpp"
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
         class base
          {
           public:
             typedef scalar_name       scalar_type;
             typedef size_name       size_type;

             typedef ::math::linear::vector::structure<scalar_name,3>                      vector_type, point_type;
             typedef ::math::linear::vector::structure< size_type   , 2 >  resolution_type;
             typedef ::math::linear::vector::structure<scalar_name,2>                   display_type;
             typedef ::math::linear::vector::structure<scalar_name,2>                       pixel_type;
             typedef ::math::geometry::interval::structure<scalar_type,2>   interval_type;
             typedef ::math::linear::vector::point<scalar_name,3>   homogeneous_type;

             typedef ::math::linear::homography::structure< scalar_name, 2 >             homography_type;
             typedef ::math::linear::affine::structure< scalar_name, 3 >                     affine_type;
             typedef ::math::linear::matrix::structure< scalar_name, 3, 3 >                  matrix_type;
             typedef ::math::geometry::projective::camera::optical<scalar_name >            digital_type;
             typedef ::math::geometry::projective::camera::mobile<scalar_name >            mobile_type;

             static bool undo( display_type & display, homography_type const& H_invert, digital_type const& camera, pixel_type const& pixel_rectified )
              {
               display = camera.uv( pixel_rectified );
               ::math::linear::homography::transform( display, H_invert, display_type( display ) );
               return true;
              }

             //void project( display_type & system_point, mobile_type const & camera, display_type const & display_point )
             //  {
             //   auto display3d_point =  camera.pointUV( display_point );
             //   auto origin =  camera.to_world().vector();
             //
             //   // 1. intersect  two( origin, display3d_point ) and plane( m_system.vector(), m_right, m_up );
             //   // calculate system_point
             //  }
             //
             //public:
             //  affine_type const& system()const&{ return m_system; }
             //
             //protected:
             //  affine_type m_system;
           protected:
             static void convert( homography_type & H )
              {
               std::swap( H[0][1], H[2][0] );
               std::swap( H[0][2], H[1][0] );
               std::swap( H[1][1], H[2][2] );
              }
          };

         }
       }
     }
   }
 }

#endif
