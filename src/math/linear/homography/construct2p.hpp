#ifndef Dh_math_linear_homography_construct2p
#define Dh_math_linear_homography_construct2p

 // ::math::linear::homography::construct( plane2display, plane );
 // ::math::linear::homography::construct_invert( display2plane, plane );

#include "../vector/vector.hpp"
#include "../homography/structure.hpp"
#include "../matrix/column.hpp"
#include "../matrix/scale.hpp"
#include "../../geometry/plane/parametric3d.hpp"




namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template<  typename scalar_name >
       void construct //!< referent function
        (
          ::math::linear::homography::structure< scalar_name, 2 >          & plane2display
         ,::math::geometry::plane::parametric3d< scalar_name  >       const& plane
        ) // center=(0,0,0), display = N(0,0,1) + O(0,0,0)
        {
         ::math::linear::matrix::column( plane2display, 0, plane.x() );
         ::math::linear::matrix::column( plane2display, 1, plane.y() );
         ::math::linear::matrix::column( plane2display, 2, plane.origin() );
        }

      template<  typename scalar_name >
       void construct_invert
        (
          ::math::linear::homography::structure< scalar_name, 2 >          & display2plane
         ,::math::geometry::plane::parametric3d< scalar_name  >       const& plane
        ) // center=(0,0,0), display = N(0,0,1) + O(0,0,0)
        { // note from here it is easy to find horizon
         auto const & X = plane.x();
         auto const & Y = plane.y();
         auto const & O = plane.origin();

         ::math::linear::vector::cross( display2plane[0], O, Y );
         ::math::linear::vector::cross( display2plane[1], X, O );
         ::math::linear::vector::cross( display2plane[2], Y, X ); //!< it is horizon 
        }


      //template<  typename scalar_name >
      // bool construct
      //  (
      //    ::math::linear::homography::structure< scalar_name, 2 >          & result
      //   ,::math::linear::vector::structure< scalar_name  >           const& center
      //   ,::math::geometry::plane::parametric3d< scalar_name  >       const& target
      //   ,::math::geometry::plane::parametric3d< scalar_name  >       const& source
      //  )
      //  {
      //   return false;
      //  }

     }
   }
 }

#endif
