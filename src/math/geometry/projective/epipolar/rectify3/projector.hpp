#ifndef math_geometry_projective_epipolar_rectify3_projector
#define math_geometry_projective_epipolar_rectify3_projector

// ::math::geometry::projective::epipolar::rectify3::projector



#include  "./pbase.hpp"
#include  "../../../../linear/homography/construct2.hpp"
#include  "../../../../linear/homography/construct2p.hpp"


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
         class projector
          {
           public:
             typedef scalar_name       scalar_type;

             typedef ::math::linear::vector::structure<scalar_name,2>     uv_type;

             typedef ::math::linear::homography::structure< scalar_name, 2 >             homography_type;
             typedef ::math::linear::affine::structure< scalar_name, 3 >                     affine_type;

             typedef  ::math::geometry::direction::parametric<scalar_name, 3 >             direction_type;
             typedef ::math::geometry::plane::parametric3d<scalar_name>                    plane_type;
                                                                                            
             typedef ::math::geometry::projective::camera::pinhole< scalar_name >           pinhole_type;

             typedef::math::geometry::projective::epipolar::rectify3::pbase<scalar_name> pbase_type;
 
           public:
             projector()
              {
              }

             bool process( affine_type const& left2world, affine_type const& right2world, pbase_type & pbase )
              {
               if( false == pbase.process( left2world, right2world ) )return false;;

               if( false == homography( m_L,  left2world, pbase.plane() ) ) return false;
               if( false == homography( m_R, right2world, pbase.plane() ) ) return false;
               return true;
              }

             bool left( homography_type & H ) const
              {
               H = m_L;
               return true;
              }
             bool right( homography_type & H ) const
              {
               H = m_R;
               return true;
              }

           private:
             bool homography( homography_type & H, affine_type const& to_world, plane_type const target )
              {
               plane_type source;
               ::math::linear::matrix::column( source.origin(), to_world.matrix(), pinhole_type::forward() );
               ::math::linear::vector::addition( source.origin(), to_world.vector()  );

               ::math::linear::matrix::column( source.x(), to_world.matrix(), pinhole_type::right() );
               ::math::linear::matrix::column( source.y(), to_world.matrix(), pinhole_type::up() );

               return ::math::linear::homography::construct( H, target, source );
              }

           public:
           private:
             homography_type m_L, m_R;
          };

         }
       }
     }
   }
 }

#endif
