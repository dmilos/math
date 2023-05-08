#ifndef math_geometry_projective_epipolar_rectify3_recenter
#define math_geometry_projective_epipolar_rectify3_recenter

// ::math::geometry::projective::epipolar::rectify3::recenter<double>

//#include <utility>


#include "../../camera/optical.hpp"
#include "../../../../linear/vector/vector.hpp"
#include "../../../../linear/matrix/matrix.hpp"
#include "../../../../linear/homography/structure.hpp"
#include "../../../../linear/homography/transform.hpp"
#include "../../../../linear/homography/retarget.hpp"

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
         class recenter
          {
           public:
             typedef scalar_name       scalar_type;
             typedef size_name       size_type;

             typedef ::math::linear::vector::structure< size_type   , 2 >  resolution_type;
             typedef ::math::linear::vector::structure<scalar_name,2>                   display_type;
             typedef ::math::geometry::interval::structure<scalar_type,2>   interval_type;
             typedef ::math::linear::vector::point<scalar_name,3>   homogeneous_type;
             typedef ::math::geometry::projective::camera::optical<scalar_name >            digital_type;
             typedef ::math::linear::homography::structure< scalar_name, 2 >             homography_type;


             bool process( homography_type & h, digital_type const& camera, scalar_name const& large = 2  )
              { // recenter so the image can occupy window space horizontal as much as possible
               homogeneous_type O, V, X, Y;
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

               scalar_name m_center = maxmin( O, X, Y, V );
               scalar_name m_move = m_center - 0;

               interval_type  target{   display_type{ camera.window()[0][0]         , camera.window()[0][1] },
                                        display_type{ camera.window()[1][0]         , camera.window()[1][1] } };
               interval_type  codomain{ display_type{ camera.window()[0][0] + m_move, camera.window()[0][1] },
                                        display_type{ camera.window()[1][0] + m_move, camera.window()[1][1] } };

               return ::math::linear::homography::recodomain( h, homography_type( h ), target, codomain );
              }

             bool process( homography_type & H, resolution_type const& resolution, scalar_name const& large = 2 )
              { // recenter so the image can occupy image space horizontal as much as possible
               homogeneous_type O, V, X, Y;
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

               scalar_name m_center = maxmin( O, X, Y, V );
               scalar_name m_move = m_center - resolution[0]/2;

               interval_type  target{ display_type{ (scalar_type)0,                      (scalar_type)0  },
                                      display_type{ (scalar_type)resolution[0],          (scalar_type)resolution[1] } };
               interval_type  image{  display_type{ (scalar_type)0             + m_move, (scalar_type)0  },
                                      display_type{ (scalar_type)resolution[0] + m_move, (scalar_type)resolution[1] } };

               return ::math::linear::homography::recodomain( H, homography_type( H ), target, image );
              }


             static scalar_type average3D(  homogeneous_type const& O,  homogeneous_type X,  homogeneous_type const&Y,  homogeneous_type const& V )
              {
               scalar_type result;

               result = ( O[0] + X[0] + Y[0] + V[0] ) /( O[2] + X[2] + Y[2] + V[2] );

               return result;
              }

             static scalar_type average2D(  homogeneous_type const& O,  homogeneous_type X,  homogeneous_type const&Y,  homogeneous_type const& V )
              {
               scalar_type result;

               result = (   O[0]*(        X[2] * Y[2] * V[2] )
                          + X[0]*( O[2]        * Y[2] * V[2] )
                          + Y[0]*( O[2] * X[2] *        V[2] )
                          + V[0]*( O[2] * X[2] * Y[2]        )
                        )/( 4 * O[2] * X[2] * Y[2] * V[2] );

               return result;
              }

             static scalar_type maxmin(  homogeneous_type const& O,  homogeneous_type X,  homogeneous_type const&Y,  homogeneous_type const& V )
              {
               scalar_type result;
             
               scalar_name min = std::min( { O[0]/O[2], X[0]/X[2], Y[0]/Y[2], V[0]/V[2] } );
               scalar_name max = std::max( { O[0]/O[2], X[0]/X[2], Y[0]/Y[2], V[0]/V[2] } );
               result = ( max + min ) / scalar_name(2);
             
               return result;
              }

           public:
               scalar_name m_center;
               scalar_name m_move;

          };

         }
       }
     }
   }
 }

#endif
