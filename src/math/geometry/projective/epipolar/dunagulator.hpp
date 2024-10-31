#ifndef math_geometry_projective_camera_duangulate
#define math_geometry_projective_camera_duangulate

// ::math::geometry::projective::epipolar::duangulate<scalar>;

#include "../../../linear/vector/vector.hpp"
#include "../../../linear/affine/affine.hpp"
#include "../../../geometry/direction/distance/L2L.hpp"
#include "../camera/mobile.hpp"
#include "../camera/pinhole.hpp"

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {

        template< typename scalar_name, typename size_name = std::size_t >
         struct duangulate
          {
           public:
             typedef scalar_name   scalar_type;
             typedef size_name       size_type;

             typedef ::math::linear::vector::structure<scalar_type,2> pixel_type;
             typedef ::math::linear::vector::structure<scalar_type,3> point_type;

             typedef ::math::geometry::projective::camera::mobile<scalar_type,size_name>  camera_type;
             typedef ::math::geometry::projective::epipolar::rectify3::processor<scalar_type>  rectificator_type;
             typedef ::math::geometry::projective::epipolar::triangulate<scalar_type, size_name>  triangulate_type;


           public:
             duangulate( scalar_name const& n= 0.01, scalar_name const & f = 1000.0 )
              {
               m_near = n;
               m_far  = f;
              }

           public:
             bool process( point_type &point, scalar_type const& disparity, pixel_type const& pixel, camera_type const& sinister, camera_type const& dexter, rectificator_type const& rectificator )
              {
               if( 0 == disparity ) return false;
               auto left = rectificator.left_disparity2screen( pixel );
               if(
                   ( left[0] < -1 ) || ( 1 < left[0] )
                 ||( left[1] < -1 ) || ( 1 < left[1] )
                )
                {
                 return false;
                }

               auto right = rectificator.right_disparity2screen( { pixel[0] + disparity, pixel[1] } );
               if(
                     ( right[0] < -1 ) || ( +1 < right[0] )
                   ||( right[1] < -1 ) || ( +1 < right[1] )
                 )
                {
                 return false;
                }
               if( false == m_triangulator.processUV( sinister, left, dexter, right ) )
                {
                 return false;
                }

               bool far  =  ( ( m_far < m_triangulator.L2L().lambdaF() ) || ( m_far < m_triangulator.L2L().lambdaS() ) );
               bool near = ( ( m_triangulator.L2L().lambdaF() < m_near ) || ( m_triangulator.L2L().lambdaS() < m_near ) );
               if( ( true == far ) || ( true == near ) )
                {
                 return false;
                }

               point = m_triangulator.point();

               return true;
              }

           public:
             scalar_type m_near;
             scalar_type m_far;
             triangulate_type m_triangulator;
          };

       }
     }
   }
 }

#endif
