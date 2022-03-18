#ifndef math_geometry_projective_camera_frustum_structure
#define math_geometry_projective_camera_frustum_structure

// ::math::geometry::projective::camera::frustum::structure<double>

#include "../pinhole.hpp"
#include "../../../interval/structure.hpp"
#include "../../../../linear/vector/structure.hpp"







namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {
        namespace frustum
         {

          template < typename scalar_name >
           class structure
            {
             public:
                typedef scalar_name                                                     scalar_type;
                typedef ::math::linear::vector::point< scalar_name, 2 >                     uv_type;
                typedef ::math::linear::vector::point< scalar_name, 3 >                 vector_type;
                typedef ::math::geometry::interval::structure<scalar_name, 1 >           depth_type;
                typedef ::math::geometry::interval::structure<scalar_name, 2>           window_type;
                typedef ::math::geometry::projective::camera::pinhole< scalar_name >   pinhole_type;

             public:
                scalar_type const& near()const { m_depth[0]; }
                scalar_type const& far()const  { m_depth[1]; }
                depth_type  const& depth()const{ return m_depth; }
             private:
                depth_type m_depth;

             public:
                uv_type const& lo()const{ return m_window[0]; }
                uv_type const& hi()const{ return m_window[1]; }
                window_type const& window()const{ return m_window; }
             private:
                window_type m_window;
                
              // in
              // out
              // side
              // location
              // confine
            };

         }
       }
     }
   }
 }

#endif
