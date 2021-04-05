#ifndef math_geometry_plane_intersect_PL3P3D
#define math_geometry_plane_intersect_PL3P3D

// ::math::geometry::plane::intersect( parametric, no3d, no3d, epsilon );
// ::math::geometry::plane::PL3P3D<scalar_name>::process

#include "../../linear/vector/structure.hpp"
#include "../../linear/vector/combine.hpp"
#include "../../linear/vector/dot.hpp"
#include "../../linear/vector/cross.hpp"

#include "../direction/parametric.hpp"

#include "./no3d.hpp"



namespace math
 {
  namespace geometry
   {
    namespace plane
     {

      template<  typename scalar_name >
       struct PL3P3D  // Intersect plane and plane in 3D
        {
         public:
           typedef scalar_name scalar_type;

           typedef ::math::linear::vector::point<scalar_type,3>             point_type;
           typedef ::math::geometry::plane::no3d <scalar_type>              no3d_type;

           typedef ::math::geometry::direction::parametric<scalar_name, 3 > line_type;

           static bool process
            (
              line_type          & line
             ,no3d_type    const & left
             ,no3d_type    const & right
             ,scalar_type  const & epsilon = 1e-6
            )
            { //https://en.wikipedia.org/wiki/Intersection_curve
             ::math::linear::vector::cross( line.direction(), right.normal(), left.normal() );

             auto length = ::math::linear::vector::length( line.direction() );
             if( length < epsilon )
              {
               return false;
              }

             auto d1 = ::math::linear::vector::dot(  left.normal(),  left.origin() );
             auto d2 = ::math::linear::vector::dot( right.normal(), right.origin() );

             auto nL = ::math::linear::vector::dot( left.normal(),  left.normal() );
             auto nR = ::math::linear::vector::dot( right.normal(), right.normal() );
             auto nn = ::math::linear::vector::dot( left.normal(), right.normal() );

             auto sD = ( nL * nR - nn*nn );
             if( ( -epsilon  < sD ) && (sD < epsilon ) )
              {
               return false;
              }

             auto s1 = ( d1 * nR - d2 * nn )/sD;
             auto s2 = ( d2  *nL - d1 * nn )/sD;

             ::math::linear::vector::combine( line.origin(), s1, left.normal(), s2, right.normal() );

             //auto dL = ::math::geometry::plane::distance( line.origin(),  left );
             //auto dR = ::math::geometry::plane::distance( line.origin(), right );

             return true;
            }

        };

      template<  typename scalar_name >
       bool intersect
        (
          ::math::geometry::direction::parametric<scalar_name, 3 >         & line
         ,::math::geometry::plane::no3d <scalar_name>                const & left
         ,::math::geometry::plane::no3d <scalar_name>                const & right
         ,scalar_name                                                const & epsilon = 1e-6
        )
        {
         return ::math::geometry::plane::PL3P3D<scalar_name>::process( line, left, right, epsilon );
        }

     }
   }
 }

// Other methods http://geomalgorithms.com/a05-_intersect-1.html
#endif
