#ifndef math_geometry_projective_camera_finit
#define math_geometry_projective_camera_finit

// ::math::geometry::projective::camera::finite<scalar_name, size_name = std::size_t >

#include <cmath>
#include <tuple>

#include "../../../linear/vector/vector.hpp"
#include "../../../geometry/interval/interval.hpp"

#include "./frustum/side.hpp"


namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {

        template
         <
           typename  scalar_name
          ,typename    size_name = std::size_t
         >
         class finite //!< TODO rename to other
          {
           public:
             typedef scalar_name     scalar_type;
             typedef size_name         size_type;

             typedef ::math::linear::vector::structure< scalar_type , 2 >          uv_type;
             typedef ::math::linear::vector::structure< scalar_type , 3 >       point_type;

             typedef ::math::geometry::interval::structure<scalar_name,1>      depth_type;

             explicit finite( depth_type const& d = { 0, 1 } )
              {
               this->depth( d );
              }

           public:
              bool visible( point_type const& point )
               {
                if( point[0] < m_depth[0] ) return false;
                if( m_depth[1] < point[1] ) return false;
                return true;
               }

              size_type side(  point_type const& point, scalar_type const& zero =0 )
               {
                return  (size_type) ::math::geometry::projective::camera::frustum::side( point, m_depth );
               }

           public:
             depth_type const& depth()const
              {
               return m_depth;
              }
             bool depth( depth_type const& d )
              {
               if( d[1] < d[0] )
                {
                 return false;
                }
               m_depth = d;
               return true;
              }

           private:
             depth_type     m_depth;
          };

       }
     }
   }
 }

#endif
