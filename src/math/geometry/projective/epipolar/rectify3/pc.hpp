#ifndef math_geometry_projective_epipolar_rectify3_pc
#define math_geometry_projective_epipolar_rectify3_pc

// ::math::geometry::projective::epipolar::rectify3::pc<double>().process( left2world, right2world )


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
           class pc    //!< Plane that is between left and right. This is true rectification.
            : public ::math::geometry::projective::epipolar::rectify3::pbase<scalar_name>
            {
             public:
               typedef scalar_name       scalar_type;

               typedef ::math::linear::vector::structure<scalar_name,3>           vector_type, point_type;
               typedef ::math::linear::affine::structure< scalar_name, 3 >                     affine_type;

               typedef ::math::geometry::projective::camera::pinhole< scalar_name >           pinhole_type;

               typedef ::math::geometry::projective::epipolar::rectify3::pbase<scalar_name>  pbase_type;

             public:
              explicit pc( scalar_type const& coefficient = 0.5 )
               {
                m_coefficient = coefficient; 
               }

             public:
              bool process( affine_type const& left2world, affine_type const& right2world )
               {
                auto & right = pbase_type::m_plane.x();
                auto & up    = pbase_type::m_plane.y();
                auto & origin= pbase_type::m_plane.origin();

              ::math::linear::vector::subtraction( right, right2world.vector(), left2world.vector() );

              ::math::linear::vector::length<scalar_type>( right, 1 );

              ::math::linear::matrix::column( m_leftForward,   left2world.matrix(), pinhole_type::forward() );
              ::math::linear::matrix::column( m_rightForward, right2world.matrix(), pinhole_type::forward() );

              ::math::linear::vector::cross( m_leftNewUp , right,  m_leftForward ); ::math::linear::vector::length<scalar_type>( m_leftNewUp,  1 );
              ::math::linear::vector::cross( m_rightNewUp, right, m_rightForward ); ::math::linear::vector::length<scalar_type>( m_rightNewUp, 1 );

              ::math::linear::vector::convex( up, m_coefficient, m_leftNewUp, m_rightNewUp );
              ::math::linear::vector::length<scalar_type>( up, 1 );

              ::math::linear::vector::cross( m_forward, up, right );  ::math::linear::vector::length<scalar_type>( m_forward, 1 );

              ::math::linear::vector::convex( origin, 0.5, left2world.vector(), right2world.vector() );
              ::math::linear::vector::addition( origin, m_forward );

                return true;
               }

            private:
              scalar_type m_coefficient;
              vector_type m_forward;
              vector_type m_leftForward, m_leftNewUp;
              vector_type m_rightForward, m_rightNewUp;
            };

         }
       }
     }
   }
 }

#endif
