#ifndef math_geometry_projective_epipolar_rectify3_pcustom
#define math_geometry_projective_epipolar_rectify3_pcustom

// ::math::geometry::projective::epipolar::rectify3::pcustom<double>().process( left2world, right2world )


#include "../../../../linear/vector/vector.hpp"
#include "../../../../linear/matrix/structure.hpp"
#include "../../../../linear/matrix/column.hpp"
#include "../../../../linear/affine/structure.hpp"
#include "../../../../linear/homography/structure.hpp"
#include "./pbase.hpp"

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
           class pcustom    //!< An arbitrary plane defined by user
            : public ::math::geometry::projective::epipolar::rectify3::pbase<scalar_name>
            {
             public:
              typedef scalar_name       scalar_type;
              typedef ::math::linear::vector::structure<scalar_name,3>           vector_type, point_type;
              typedef ::math::linear::affine::structure< scalar_name, 3 >                    affine_type;

              typedef ::math::geometry::plane::parametric3d<scalar_name>                    plane_type;


              typedef ::math::geometry::projective::epipolar::rectify3::pbase<scalar_name>  pbase_type;

             public:
              pcustom()
               {
               }

             public:
              bool process( affine_type const& left2world, affine_type const& right2world )
               {
                return true;
               }

             public:
              using pbase_type::plane;

              void plane( plane_type const P )const
               {
                pbase_type::m_plane = P;
               }
            };

         }
       }
     }
   }
 }

#endif
