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

        template < typename scalar_name, typename    size_name = std::size_t
 >
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

             static bool retarget( homography_type & H, digital_type const& camera )
              { // retarget exiting homografy to be applied on image
               interval_type  target{ display_type{ 0, (double)camera.resolution()[1] }, display_type{ (double)camera.resolution()[0], 0 } };
               interval_type  codomain{ camera.window() };
               interval_type  domain{ camera.window() };
               interval_type  source = { display_type{ 0, (double)camera.resolution()[1] }, display_type{ (double)camera.resolution()[0], 0 } };

               return ::math::linear::homography::retarget( H, homography_type( H ), target, codomain, domain, source );
              }

             static bool recenter( homography_type & h, digital_type const& camera, scalar_name const& large = 2  )
              { // recenter so the image can occupy window space horizontal as much as possible
               point_type O, V, X, Y;
               math::linear::matrix::transform( O, h, { camera.window()[0][0], camera.window()[0][1], 1 } );
               math::linear::matrix::transform( X, h, { camera.window()[0][0], camera.window()[0][1], 1 } );
               math::linear::matrix::transform( Y, h, { camera.window()[0][0], camera.window()[1][1], 1 } );
               math::linear::matrix::transform( V, h, { camera.window()[1][0], camera.window()[1][1], 1 } );

               scalar_name width = camera.window()[1][0] - camera.window()[0][0];

               if( O[0]/O[2] < - large * width ){ return false; }
               if( X[0]/X[2] < - large * width ){ return false; }
               if( Y[0]/Y[2] < - large * width ){ return false; }
               if( V[0]/V[2] < - large * width ){ return false; }

               if( ( large + 1 ) * width < O[0]/O[2] ){ return false; }
               if( ( large + 1 ) * width < X[0]/X[2] ){ return false; }
               if( ( large + 1 ) * width < Y[0]/Y[2] ){ return false; }
               if( ( large + 1 ) * width < V[0]/V[2] ){ return false; }

               scalar_name min = std::min( { O[0]/O[2], X[0]/X[2], Y[0]/Y[2], V[0]/V[2] } );
               scalar_name max = std::max( { O[0]/O[2], X[0]/X[2], Y[0]/Y[2], V[0]/V[2] } );
               scalar_name center = ( max - min ) / scalar_name(2);

               interval_type  target{   display_type{ camera.window()[0][0]         , camera.window()[0][1] },
                                        display_type{ camera.window()[1][0]         , camera.window()[1][1] } };
               interval_type  codomain{ display_type{ camera.window()[0][0] - center, camera.window()[0][1] },
                                        display_type{ camera.window()[1][0] - center, camera.window()[1][1] } };

               return ::math::linear::homography::recodomain( h, homography_type( h ), target, codomain );
              }

             static bool recenter( homography_type & H, resolution_type const& resolution, scalar_name const& large = 2 )
              { // recenter so the image can occupy image space horizontal as much as possible
               point_type O, V, X, Y;
               math::linear::matrix::transform( O, H, { (scalar_type)            0, (scalar_type)            0, (scalar_type)1 } );
               math::linear::matrix::transform( X, H, { (scalar_type)resolution[0], (scalar_type)            0, (scalar_type)1 } );
               math::linear::matrix::transform( Y, H, { (scalar_type)            0, (scalar_type)resolution[1], (scalar_type)1 } );
               math::linear::matrix::transform( V, H, { (scalar_type)resolution[0], (scalar_type)resolution[1], (scalar_type)1 } );

               scalar_name width = static_cast<scalar_name>( resolution[0] );

               if( O[0]/O[2] < - large * width ){ return false; }
               if( X[0]/X[2] < - large * width ){ return false; }
               if( Y[0]/Y[2] < - large * width ){ return false; }
               if( V[0]/V[2] < - large * width ){ return false; }

               if( ( large + 1 ) * width < O[0]/O[2] ){ return false; }
               if( ( large + 1 ) * width < X[0]/X[2] ){ return false; }
               if( ( large + 1 ) * width < Y[0]/Y[2] ){ return false; }
               if( ( large + 1 ) * width < V[0]/V[2] ){ return false; }

               scalar_name min = std::min( { O[0]/O[2], X[0]/X[2], Y[0]/Y[2], V[0]/V[2] } );
               scalar_name max = std::max( { O[0]/O[2], X[0]/X[2], Y[0]/Y[2], V[0]/V[2] } );
               scalar_name center = ( max - min ) / scalar_name(2);
               scalar_name move = center - resolution[0]/2;

               interval_type  target{ display_type{ (scalar_type)0,                      (scalar_type)0  },
                                      display_type{ (scalar_type)resolution[0],          (scalar_type)resolution[1] } };
               interval_type  image{  display_type{ (scalar_type)0             - move, (scalar_type)0  },
                                      display_type{ (scalar_type)resolution[0] - move, (scalar_type)resolution[1] } };

               return ::math::linear::homography::recodomain( H, homography_type( H ), target, image );
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
