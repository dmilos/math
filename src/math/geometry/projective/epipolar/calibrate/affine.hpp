#ifndef math_geometry_projective_epipolar_calibrate_affine
#define math_geometry_projective_epipolar_calibrate_affine

// ::math::geometry::projective::epipolar::calibrate( alpha, h_scale, v_scale )

//#include <utility>

#include "../../../../linear/affine/affine.hpp"
#include "../../../../linear/vector/structure.hpp"
#include "../../../plane/parametric3d.hpp"



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
           class affine
            {
             public:
               typedef scalar_name scalar_type;
               typedef ::math::linear::affine::structure< scalar_name, 3 > affine_type;

               bool process ( affine_type  & right_to_left_world, affine_type const& left_to_local, affine_type const& right_to_local )
                {
                 if( false == ::math::linear::affine::invert( m_right_to_world, right_to_local ) )
                  {
                   return false;
                  }

                 ::math::linear::affine::compose( right_to_left_world, left_to_local, m_right_to_world );
                 return true;
                }

               bool processLW( affine_type  & right_to_left_world, affine_type const& left_to_local, affine_type const& right_to_world )
                {
                 m_right_to_world = right_to_world;

                 ::math::linear::affine::compose( right_to_left_world, left_to_local, m_right_to_world );
                  return true;
                 }


              public:
                affine_type m_right_to_world;
             };

         }
       }
     }
   }
 }

#endif
