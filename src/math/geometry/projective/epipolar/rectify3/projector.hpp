#ifndef math_geometry_projective_epipolar_rectify3_projector
#define math_geometry_projective_epipolar_rectify3_projector

// ::math::geometry::projective::epipolar::rectify3::projector



#include  "./pbase.hpp"
#include  "../../../../linear/homography/construct2.hpp"


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
             typedef struct
              {
               uv_type m_0, m_X, m_Y, m_Z;
              }quad_type;
 
           public:
             projector()
              {
               ::math::linear::vector::load( m_0.m_0, -1,-1 ); 
               ::math::linear::vector::load( m_0.m_X, +1,-1 ); 
               ::math::linear::vector::load( m_0.m_Y, -1,+1 ); 
               ::math::linear::vector::load( m_0.m_Z, +1,+1 );
               m_epsilon = 1e-5;
              }

             bool process( affine_type const& left2world, affine_type const& right2world, pbase_type & pbase )
              {
               if( false == pbase.process( left2world, right2world ) )return false;;

               if( false == homography( m_L, m_Lq,  left2world, pbase.plane() ) ) return false;
               if( false == homography( m_R, m_Rq, right2world, pbase.plane() ) ) return false;
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
             bool homography( homography_type & H, quad_type & quad, affine_type const& to_world, plane_type const plane )
              {
               if( false == hit( quad.m_0, to_world, plane, m_0.m_0 ) ) return false;
               if( false == hit( quad.m_X, to_world, plane, m_0.m_X ) ) return false;
               if( false == hit( quad.m_Y, to_world, plane, m_0.m_Y ) ) return false;
               if( false == hit( quad.m_Z, to_world, plane, m_0.m_Z ) ) return false;

               return ::math::linear::homography::constructA
                (
                  H
                 , m_0.m_0, quad.m_0
                 , m_0.m_X, quad.m_X
                 , m_0.m_Y, quad.m_Y
                 , m_0.m_Z, quad.m_Z
                );
              }

             bool hit( uv_type & b, affine_type const& to_world, plane_type const plane, uv_type const& a )
              {
               direction_type ray;
               ray.origin() = to_world.vector();

               ::math::linear::matrix::transform( ray.direction(), to_world.matrix(), pinhole_type::reproject( a ) );

               scalar_type lambda;

               if( false == ::math::geometry::plane::intersect( lambda, b, plane, ray, m_epsilon ) )
                {
                 return false;
                }
               //auto p = ray.point( lambda );
               return true;
              }

           public:
             scalar_type m_epsilon;
             quad_type m_0, m_Lq, m_Rq;
           private:
             homography_type m_L, m_R;
          };

         }
       }
     }
   }
 }

#endif
