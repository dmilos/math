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

           public:
             projector()
              {
               m_epsilon = 1e-5;
              }

             bool process( affine_type const& left2world, affine_type const& right2world, pbase_type & pbase )
              {
               pbase.process( left2world, right2world );

               homography( m_L, left2world,  pbase.plane() );
               homography( m_R, right2world, pbase.plane() );
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
             bool homography( homography_type & H, affine_type const& to_world, plane_type const plane )
              {
               uv_type   a0{-1,-1};
               uv_type   a1{+1,-1};
               uv_type   a2{-1,+1};
               uv_type   a3{+1,+1};

               uv_type b0;  if( false == hit( b0, to_world, plane, a0 ) ) return false;
               uv_type b1;  if( false == hit( b1, to_world, plane, a1 ) ) return false;
               uv_type b2;  if( false == hit( b2, to_world, plane, a2 ) ) return false;
               uv_type b3;  if( false == hit( b3, to_world, plane, a3 ) ) return false;

               return ::math::linear::homography::constructA
                (
                  H
                 , a0, b0
                 , a1, b1
                 , a2, b2
                 , a3, b3
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
             homography_type m_L, m_R;
          };

         }
       }
     }
   }
 }

#endif
