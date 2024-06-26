#ifndef Dh_math_linear_homography_construct1p
#define Dh_math_linear_homography_construct1p

 // ::math::linear::homography::construct( result, source );
 // ::math::linear::homography::construct_invert( result, source );
 // ::math::linear::homography::construct( result, target, source );
 // ::math::linear::homography::construct( result, center, target, source );

#include "../vector/vector.hpp"
#include "../homography/structure.hpp"
#include "../matrix/column.hpp"
#include "../matrix/scale.hpp"
#include "../matrix/invert.hpp"
#include "../../geometry/direction/parametric.hpp"




namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template<  typename scalar_name >
       void construct //!< REFERENT function. Essentially this is definition of homograph !!!
        (
          ::math::linear::homography::structure< scalar_name, 1 >          & result
         ,::math::geometry::direction::parametric<scalar_name, 2>       const& source
        ) //  center=(0,0), Target:display =  O(0,1) + D(1,0)
        {
         ::math::linear::matrix::column( result, 0, source.direction() );
         ::math::linear::matrix::column( result, 1, source.origin() );
        }

      template<  typename scalar_name >
       bool construct_invert
        (
          ::math::linear::homography::structure< scalar_name, 1 >          & result
         ,::math::geometry::direction::parametric<scalar_name, 2>     const& source
        ) //  center=(0,0), Target:display = O(0,1) + D(1,0)
        {
         ::math::linear::matrix::column( result, 0, source.direction() );
         ::math::linear::matrix::column( result, 1, source.origin() );
         return false; // TODO ::math::linear::matrix::invert( result );
        }


      template<  typename scalar_name >
       bool construct
        (
          ::math::linear::homography::structure< scalar_name, 1 >          & result
         ,::math::geometry::direction::parametric<scalar_name, 2>     const& target
         ,::math::geometry::direction::parametric<scalar_name, 2>     const& source
        )
        {
         ::math::linear::homography::structure< scalar_name, 1 > toOne, toWorld;

         ::math::linear::matrix::column( toWorld, 0, target.direction() );
         ::math::linear::matrix::column( toWorld, 1, target.origin() );

         if( false == ::math::linear::matrix::invert( toOne, toWorld ) )
          {
           return false;
          }

         ::math::linear::matrix::column( toWorld, 0, source.direction() );
         ::math::linear::matrix::column( toWorld, 1, source.origin() );

         ::math::linear::matrix::multiply( result, toOne, toWorld );

         return true;
        }

      template<  typename scalar_name >
       bool construct
        (
          ::math::linear::homography::structure< scalar_name, 1 >          & result
         ,::math::linear::vector::structure< scalar_name, 2 >         const& center
         ,::math::geometry::direction::parametric<scalar_name, 2>     const& target
         ,::math::geometry::direction::parametric<scalar_name, 2>     const& source
        )
        {
         typedef ::math::linear::vector::structure< scalar_name, 2 >  point_type;
         typedef ::math::geometry::direction::parametric<scalar_name, 2> direction_type;
         typedef ::math::linear::homography::structure< scalar_name, 1 > structure_type;

         direction_type  T = target;
         ::math::linear::vector::subtraction( T.origin(), center );

         direction_type  S = source;
         ::math::linear::vector::subtraction( S.origin(), center );

         return ::math::linear::homography::construct( result, T, S );
        }

     }
   }
 }

#endif
