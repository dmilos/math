#ifndef math_geometry_projective_epipolar_rectify3_pbase
#define math_geometry_projective_epipolar_rectify3_pbase

// ::math::geometry::projective::epipolar::rectify3::pbase<double>.process( left2world, right2world )


#include "../../../../linear/vector/vector.hpp"
#include "../../../../linear/matrix/structure.hpp"
#include "../../../../linear/matrix/multiply.hpp"
#include "../../../../linear/matrix/invert.hpp"
#include "../../../../linear/matrix/column.hpp"
#include "../../../../linear/matrix/tb.hpp"
#include "../../../../linear/matrix/euler.hpp"
#include "../../../../linear/matrix/transform.hpp"
#include "../../../../linear/homography/structure.hpp"

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

        template < typename scalar_name >
         class pbase
          {
           public:
             typedef scalar_name       scalar_type;

             typedef ::math::linear::vector::structure<scalar_name,3>     vector_type, point_type;

             typedef ::math::linear::homography::structure< scalar_name, 2 >             homography_type;
             typedef ::math::linear::affine::structure< scalar_name, 3 >                     affine_type;
             typedef ::math::linear::matrix::structure< scalar_name, 3, 3 >                  matrix_type;

             typedef ::math::geometry::plane::parametric3d<scalar_name>                    plane_type;

           public:
             pbase()
              {
              }

           public:
             virtual bool process( affine_type const& left2world, affine_type const& right2world ) =0;

           public:
             plane_type const& plane()const
              {
               return m_plane;
              }

           protected:
              plane_type m_plane;
          };

         }
       }
     }
   }
 }

#endif
