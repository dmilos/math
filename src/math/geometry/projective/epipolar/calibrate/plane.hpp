#ifndef math_geometry_projective_epipolar_calibrate_plane
#define math_geometry_projective_epipolar_calibrate_plane

// ::math::geometry::projective::epipolar::calibrate::plane.process( to_world, left_in_local, right_in_local )

//#include <utility>

#include "../../../../linear/affine/affine.hpp"
#include "../../../../linear/vector/structure.hpp"
#include "../../../plane/parametric3d.hpp"
#include "./affine.hpp"


namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {
        namespace calibrate
         {

          template < typename scalar_name >
           class plane
            {
             public:
               typedef std::size_t size_type;
               typedef scalar_name scalar_type;
               typedef ::math::linear::vector::point<  scalar_name, 3 > point_type;
               typedef ::math::linear::vector::vector< scalar_name, 3 > vector_type;
               typedef ::math::linear::affine::structure< scalar_name, 3 > affine_type;

               typedef ::math::geometry::plane::parametric3d<scalar_name> parametric_type;
               typedef ::math::geometry::projective::epipolar::calibrate::affine<scalar_name> calibrate_affine_type;

               static void to_affine( affine_type  & system, parametric_type const& plane )
                {
                 vector_type normal;
                 vector_type x = plane.x(); ::math::linear::vector::unit( x );
                 vector_type y = plane.y(); ::math::linear::vector::unit( y );
                 ::math::linear::vector::cross( normal, x, y );
                 ::math::linear::affine::system( system, plane.origin(), x, y, normal );
                }

               bool process ( affine_type  & right_to_left_world, parametric_type const& left_in_local, parametric_type const& right_in_local )
                {
                 this->to_affine( m_left, left_in_local );
                 this->to_affine( m_right, right_in_local );

                 return m_affine.process( right_to_left_world, m_left, m_right );
                }
               public:
                calibrate_affine_type m_affine;
                affine_type m_left, m_right;
             };

         }
       }
     }
   }
 }

#endif
