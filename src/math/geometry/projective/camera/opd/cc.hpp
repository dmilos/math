#ifndef math_geometry_projective_camera_opd_cc
#define math_geometry_projective_camera_opd_cc

// ::math::geometry::projective::camera::opd::cc( center, f, r, A, B )
// ::math::geometry::projective::camera::opd::sphere_center( center, f, r, A, B )

#include "../../../../linear/vector/structure.hpp"



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

          /**************
                    /  circle  /
                   /         /
                  /        /
           - f---A---Cx---B-
             o  /       /
             c  /     /
             u /    /
             s /  /
             |/ /
             +/  (0,0)
         **************/
          template < typename scalar_name >
           bool
           cc
            (
              ::math::linear::vector::point<scalar_name,2>  & center  //!< center of circle in world
             ,scalar_name const& focus   //!< focus
             ,scalar_name const& radius  //!< radus of circle
             ,scalar_name const& A       //!< left point  on display
             ,scalar_name const& B       //!< right point on display
            )
            {
             scalar_name a = sqrt( A*A + focus*focus ) - A;
             scalar_name b = sqrt( B*B + focus*focus ) - B;

             center[0] = radius * ( focus*focus - a * b ) / ( focus* ( a -  b ) ) ;
             center[1] = radius * ( a  +  b ) / (  a  -  b ) ;

             return true;
            }

          template < typename scalar_name >
           bool
           cc
            (
              scalar_name      & center_x  //!< center of circle along display axis
             ,scalar_name const& focus     //!< focus
             ,scalar_name const& A         //!< left point  on display
             ,scalar_name const& B         //!< right point on display
            )
            {
             scalar_name a = sqrt( A*A + focus*focus ) - A;
             scalar_name b = sqrt( B*B + focus*focus ) - B;
             center_x  = ( focus * focus - a * b ) / ( a + b );

             return true;
            }

          template < typename scalar_name >
           bool
           sphere_center
            (
              ::math::linear::vector::point<scalar_name,3>  & center  //!< center of sphere
             ,scalar_name const& focus
             ,scalar_name const& radius
             ,::math::linear::vector::point<scalar_name,2> const& A   //!< left  point on display
             ,::math::linear::vector::point<scalar_name,2> const& B   //!< right point on display
            )
            {
             scalar_name a = ::math::linear::vector::length( A );
             scalar_name b = ::math::linear::vector::length( B );

             ::math::linear::vector::point<scalar_name,2>  C;
             if( false == ::math::geometry::projective::camera::opd::cc( C, focus, radius, a, b ) )
              {
               return false;
              }
             typedef ::math::geometry::projective::camera::pinhole< scalar_name >  pinhole_type;

             center[ pinhole_type::forward() ] = C[1];
             center[ pinhole_type::right() ]   = C[0] * A[0]/a;
             center[ pinhole_type::up() ]      = C[0] * A[1]/a;

             return true;
            }

         }
       }
     }
   }
 }

#endif
