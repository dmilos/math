#ifndef math_geometry_projective_camera_opd_homography
#define math_geometry_projective_camera_opd_homography

// ::math::geometry::projective::camera::opd::homography(width,height).process( R, t, K, H )


#include "../../../../linear/vector/structure.hpp"
#include "../../../../linear/vector/scale.hpp"
#include "../../../../linear/matrix/structure.hpp"
#include "../../../../linear/homography/structure.hpp"


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

        template < typename scalar_name >
         class homography
          {
           public:
             typedef scalar_name scalar_type;

             typedef  ::math::linear::matrix::structure<scalar_name,4,3>      matrix4x3_type;
             typedef  ::math::linear::matrix::structure<scalar_name,3,3>      matrix3x3_type;
             typedef  ::math::linear::homography::structure<scalar_name,2 >   homography_type;
             typedef  ::math::linear::vector::structure<scalar_name,3>        vector3_type;

           public:
             homography( scalar_name const& width/*, scalar_name const& height = width */)
              : m_width( width )/*, m_height( height )*/
              {
              }

           public:
             bool process
              (
                matrix3x3_type  const& K     //!< camera matrix
               ,homography_type const& H     //!< homograpphy
              )
              {
               if( false == ::math::linear::matrix::invert( m_kInvert, K ) )
                {
                 return false;
                }
               ::math::linear::matrix::multiply( m_hClean, m_kInvert, H );

               ::math::linear::matrix::column( m_x, m_hClean, 0 );
               ::math::linear::matrix::column( m_y, m_hClean, 1 );
               ::math::linear::matrix::column( m_t, m_hClean, 2 );

               m_l1 = m_width  / ::math::linear::vector::length( X() );
               m_l2 = m_width  / ::math::linear::vector::length( Y() );
               auto scale = ( m_l1 + m_l2 )/2;

               ::math::linear::vector::scale( m_x, scale );
               ::math::linear::vector::scale( m_y, scale );
               ::math::linear::vector::cross( m_z, X(), Y() );
               ::math::linear::vector::scale( m_t, scale/m_width );
               return true;
              }

             bool process
              (
                matrix3x3_type       & R     //!< rotation
               ,vector3_type         & t     //!< translation
               ,matrix3x3_type  const& K     //!< camera matrix
               ,homography_type const& H     //!< homograpphy
              )
              {
               if( false == this->process( K, H ) )
                {
                 return false;
                }

               ::math::linear::matrix::column( R, 0, X() );
               ::math::linear::matrix::column( R, 1, Y() );
               ::math::linear::matrix::column( R, 2, Z() );

               t = T();

               return true;
              }

            public:
              vector3_type const& X()const{ return m_x; }
              vector3_type const& Y()const{ return m_y; }
              vector3_type const& Z()const{ return m_z; }
              vector3_type const& T()const{ return m_t; }

            private:
             scalar_type m_width ;
             //scalar_type m_height;

             vector3_type m_x, m_y, m_z, m_t;
             scalar_type m_l1, m_l2;
             matrix3x3_type m_kInvert;
             homography_type  m_hClean;
          };

         }
       }
     }
   }
 }

#endif
