#ifndef Dh_math_linear_homography_construct3l
#define Dh_math_linear_homography_construct3l

 // ::math::linear::homography::construct( plane2display, s0, t0,s0, t1, s1, s2, t2 );

#include "../vector/vector.hpp"
#include "../homography/structure.hpp"
#include "../matrix/transpose.hpp"
#include "../matrix/invert.hpp"
#include "../../geometry/direction/abc.hpp"




namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template<  typename scalar_name >
       bool construct
        (
          ::math::linear::homography::structure< scalar_name, 2 >          & plane2display
         ,::math::geometry::direction::ABC2D< scalar_name  > const& s0 ,::math::geometry::direction::ABC2D< scalar_name  > const& t0
         ,::math::geometry::direction::ABC2D< scalar_name  > const& s1 ,::math::geometry::direction::ABC2D< scalar_name  > const& t1
         ,::math::geometry::direction::ABC2D< scalar_name  > const& s2 ,::math::geometry::direction::ABC2D< scalar_name  > const& t2
        )
        {
         ::math::linear::matrix::structure<scalar_name,3,3> source;

          ::math::linear::matrix::column( source, 0, s0.array() );
          ::math::linear::matrix::column( source, 1, s1.array() );
          ::math::linear::matrix::column( source, 2, s2.array() );

          ::math::linear::matrix::structure<scalar_name,3,3> target;
          ::math::linear::matrix::column( target, 0, t0.array() );
          ::math::linear::matrix::column( target, 1, t1.array() );
          ::math::linear::matrix::column( target, 2, t2.array() );

          ::math::linear::matrix::structure<scalar_name,3,3> itarget;
          if (false == ::math::linear::matrix::invert(itarget, target))
           {
            return false;
           }

          ::math::linear::matrix::multiply( plane2display, source, itarget );
          ::math::linear::matrix::transpose( plane2display );
          return true;
        }

     }
   }
 }

#endif
